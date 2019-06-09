#ifndef RANGECODER_H
#define RANGECODER_H

#include <stdio.h>

#pragma warning(disable : 4996) // отключение предупреждения

typedef unsigned int  uint;

#define  DO(n)	   for (int _=0; _<n; _++)
#define  TOP	   (1<<24)

class RangeCoder
{
	uint code, range, FFNum, Cache;
	__int64 low;
	FILE *f;

public:
	// считывание символа и увеличения счётчика символов
	int readSymbol(long long &count) {
		++count;
		return getc(f);
	}

	void StartEncode(FILE *out)
	{
		low = FFNum = Cache = 0;  range = (uint)-1;
		f = out;
	}

	void StartDecode(FILE *in, long long &count)
	{
		code = 0;
		range = (uint)-1;
		f = in;
		DO(5) code = (code << 8) | readSymbol(count);
	}

	void FinishEncode(long long &count)
	{
		low += 1;
		DO(5) ShiftLow(count);
	}

	void FinishDecode(void) {}

	void encode(uint cumFreq, uint freq, uint totFreq, long long &count)
	{
		low += cumFreq * (range /= totFreq);
		range *= freq;
		while (range < TOP) ShiftLow(count), range <<= 8;
	}

	inline void ShiftLow(long long &count)
	{
		if ((low >> 24) != 0xFF) {
			putc(Cache + (low >> 32), f);
			++count;
			int c = 0xFF + (low >> 32);
			while (FFNum) putc(c, f), FFNum--, ++count;
			Cache = uint(low) >> 24;
		}
		else FFNum++;
		low = uint(low) << 8;
	}

	uint get_freq(uint totFreq) {
		return code / (range /= totFreq);
	}

	void decode_update(uint cumFreq, uint freq, uint totFreq, long long &count)
	{
		code -= cumFreq * range;
		range *= freq;
		while (range < TOP) { 
			code = (code << 8) | readSymbol(count);
			range <<= 8;
		}
	}
};

#endif