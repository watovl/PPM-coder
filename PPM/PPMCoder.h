#ifndef PPMCODER_H
#define PPMCODER_H

#include <string>
#include <stdio.h>
#include "RangeCoder.h"
#include "Window.h"

class Window;

/* Класс для организации ввода/вывода данных */
class DFile {
	FILE *f;
public:
	int ReadSymbol(void) {
		return getc(f);
	};
	int WriteSymbol(int c) {
		return putc(c, f);
	};
	FILE* GetFile(void) {
		return f;
	}
	void SetFile(FILE *file) {
		f = file;
	}
};


struct ContextModel {
	int	esc,
		TotFr;
	int	count[256];
};

/* реализация компрессора */
class PPMCoder : public QObject {
	Q_OBJECT

signals:
	void percentageCompleted(qint64);
	void getSizeOutputFile(qint64);

public slots:
	void empty() {};

	void process(const std::string &inPath, const std::string &outPath, const char &type) {
		if (type == 'c') {
			compress(inPath, outPath);
		}
		else if (type == 'd') {
			decompress(inPath, outPath);
		}
	}

private:
	ContextModel cm[257];
	ContextModel *stack[2];
	int	context[1];
	int	SP;
	const int MAX_TotFr = 0x3fff;
	DFile DataFile;
	DFile CompressedFile;
	RangeCoder AC;

	void init_model() {
		for (int j = 0; j < 256; j++)
			cm[256].count[j] = 1
			;
		cm[256].TotFr = 256;
		cm[256].esc = 1;
		context[0] = SP = 0;
	}

	int encode_sym(ContextModel *CM, int c, qint64 &count) {
		stack[SP++] = CM;
		if (CM->count[c]) {
			int CumFreqUnder = 0;
			for (int i = 0; i < c; i++)
				CumFreqUnder += CM->count[i];
			AC.encode(CumFreqUnder, CM->count[c],
				CM->TotFr + CM->esc, count);
			return 1;
		}
		else {
			if (CM->esc) {
				AC.encode(CM->TotFr, CM->esc, CM->TotFr +
					CM->esc, count);
			}
			return 0;
		}
	}

	int decode_sym(ContextModel *CM, int *c, long long &count) {
		stack[SP++] = CM;
		if (!CM->esc) return 0;

		int cum_freq = AC.get_freq(CM->TotFr + CM->esc);
		if (cum_freq < CM->TotFr) {
			int CumFreqUnder = 0;
			int i = 0;
			for (;;) {
				if ((CumFreqUnder + CM->count[i]) <= cum_freq)
					CumFreqUnder += CM->count[i];
				else break;
				i++;
			}
			AC.decode_update(CumFreqUnder, CM->count[i], CM->TotFr + CM->esc, count);
			*c = i;
			return 1;
		}
		else {
			AC.decode_update(CM->TotFr, CM->esc, CM->TotFr + CM->esc, count);
			return 0;
		}
	}

	void rescale(ContextModel *CM) {
		CM->TotFr = 0;
		for (int i = 0; i < 256; i++) {
			CM->count[i] -= CM->count[i] >> 1;
			CM->TotFr += CM->count[i];
		}
	}

	void update_model(int c) {
		while (SP) {
			SP--;
			if (stack[SP]->TotFr >= MAX_TotFr)
				rescale(stack[SP]);
			stack[SP]->TotFr += 1;
			if (!stack[SP]->count[c])
				stack[SP]->esc += 1;
			stack[SP]->count[c] += 1;
		}
	}

	void encode() {
		int	c,
			success;
		long long countInputSymbol = 0;
		long long countOutputSymbol = 0;
		init_model();
		AC.StartEncode(CompressedFile.GetFile());
		while ((c = DataFile.ReadSymbol()) != EOF) {
			success = encode_sym(&cm[context[0]], c, countOutputSymbol);
			if (!success)
				encode_sym(&cm[256], c, countOutputSymbol);
			update_model(c);
			context[0] = c;
			// обновляем на каждый третий символ
			if (++countInputSymbol % 100 == 0) emit percentageCompleted(countInputSymbol);
		}
		if (cm[context[0]].TotFr)
			AC.encode(cm[context[0]].TotFr, cm[context[0]].esc,
				cm[context[0]].TotFr + cm[context[0]].esc, countOutputSymbol)
			;
		AC.encode(cm[256].TotFr, cm[256].esc,
			cm[256].TotFr + cm[256].esc, countOutputSymbol);
		AC.FinishEncode(countOutputSymbol);

		emit percentageCompleted(countInputSymbol);
		emit getSizeOutputFile(countOutputSymbol);
	}

	void decode() {
		int	c,
			success;
		long long countInputSymbol = 0;
		long long countOutputSymbol = 0;
		init_model();
		AC.StartDecode(CompressedFile.GetFile(), countInputSymbol);
		for (;;) {
			success = decode_sym(&cm[context[0]], &c, countInputSymbol);
			if (!success) {
				success = decode_sym(&cm[256], &c, countInputSymbol);
				if (!success) break;
			}
			update_model(c);
			context[0] = c;
			DataFile.WriteSymbol(c);
			if (countInputSymbol % 100 == 0) emit percentageCompleted(countInputSymbol);
			++countOutputSymbol;
		}
		emit percentageCompleted(countInputSymbol);
		emit getSizeOutputFile(countOutputSymbol);
	}

public:
	void compress(const std::string &inPath, const std::string &outPath) {
		FILE *inf, *outf;

		inf = fopen(inPath.c_str(), "rb");
		outf = fopen(outPath.c_str(), "wb");
		DataFile.SetFile(inf);
		CompressedFile.SetFile(outf);
		encode();
		fclose(inf);
		fclose(outf);
	}

	void decompress(const std::string &inPath, const std::string &outPath) {
		FILE *inf, *outf;

		inf = fopen(inPath.c_str(), "rb");
		outf = fopen(outPath.c_str(), "wb");
		CompressedFile.SetFile(inf);
		DataFile.SetFile(outf);
		decode();
		fclose(inf);
		fclose(outf);
	}
};

#endif