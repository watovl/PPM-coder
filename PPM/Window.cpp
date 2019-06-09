#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFileInfo>
#include <QErrorMessage>
#include <QThread>

#include "Window.h"

Window::Window(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	settingConnect();
}

// настройки сигналов (подключений)
void Window::settingConnect() {
	connect(ui.selectPathButton, SIGNAL(clicked()), this, SLOT(on_selectPathButton()));
	connect(ui.lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(setOutPath(const QString &)));
	connect(ui.compressButton, SIGNAL(clicked()), this, SLOT(on_compressButton()));
	connect(ui.decompressButton, SIGNAL(clicked()), this, SLOT(on_decompressButton()));
}

// установка пути для выходного файла с контролем кнопок сжатия
void Window::setOutPath(const QString &path) {
	QString inPath = path;
	if (!inPath.isEmpty()) {
		// выбран текстовый файл. Процедура сжатия
		if (inPath.section(".", -1) == "txt") {
			// выходной файл
			ui.lineEdit_2->setText(inPath.left(inPath.size() - 3) + "ppm");
			// активация кнопки сжатия
			ui.compressButton->setEnabled(true);
			// делаем вторую кнопку неактивной
			ui.decompressButton->setEnabled(false);
		}
		// выбран сжатый текст. Процедура разжатия
		else if (inPath.section(".", -1) == "ppm") {
			// выходной файл
			ui.lineEdit_2->setText(inPath.left(inPath.size() - 3) + "txt");
			// активация кнопки разжатия
			ui.decompressButton->setEnabled(true);
			// делаем вторую кнопку неактивной
			ui.compressButton->setEnabled(false);
		}
		// файл не выбран
		else {
			// кнопки не активны
			ui.compressButton->setEnabled(false);
			ui.decompressButton->setEnabled(false);
		}
	}
}

// установка значений процесса
void Window::setPercentageCompleted(qint64 value) {
	ui.progressBar->setValue(100 * value / ui.labelSizeInputFile->text().section(" ", 0, 0).toInt());
	ui.labelProcessed->setText(QString::number(value));
}

// устанавка значения размера входного файла
void Window::setSizeInputFile(qint64 value) {
	ui.labelSizeInputFile->setText(QString::number(value) + QApplication::translate("WindowClass", " \320\261\320\260\320\271\321\202", nullptr));
}

// устанавка значения размера выходного файла
void Window::setSizeOutputFile(qint64 value) {
	ui.labelSizeOutputFile->setText(QString::number(value) + QApplication::translate("WindowClass", " \320\261\320\260\320\271\321\202", nullptr));
}

// кнопка выбора файла
void Window::on_selectPathButton() {
	// получение пути засчёт диалогового окна
	QString inPath = QFileDialog::getOpenFileName(this,
		QApplication::translate("PPMClass", "\320\222\321\213\320\261\320\276\321\200 \321\204\320\260\320\271\320\273\320\260", nullptr), /* надпись "Выбор файла" */	
		"C:\\Users\\" + QApplication::translate("PPMClass", "\320\224\320\235\320\241", nullptr) + "\\Desktop\\", /* Путь к рабочему столу */
		"*.txt *.ppm");
	// задаём указанный путь
	ui.lineEdit->setText(inPath);
	setOutPath(inPath);
}

// кнопка сжатия файла
void Window::on_compressButton() {
	QFileInfo checkInPath(ui.lineEdit->text());
	QFileInfo checkOutPath(ui.lineEdit_2->text().left(ui.lineEdit_2->text().size() - ui.lineEdit_2->text().section("/", -1).size() - 1));
	// для входного путь существует и это файл
	if (checkInPath.exists() && checkInPath.isFile()) {
		// для выходного проверка расширения и существования пути
		if (ui.lineEdit_2->text().section(".", -1) == "ppm" && checkOutPath.exists()) {
			// устанавливаем значение размера входного файла
			setSizeInputFile(checkInPath.size());
			// обнуление значения размера выходного файла
			setSizeOutputFile(0);
			// сжатие PPM кодером
			std::string inPath = ui.lineEdit->text().toLocal8Bit().constData();
			std::string outPath = ui.lineEdit_2->text().toLocal8Bit().constData();
			QThread *thread = new QThread;
			ppm = new PPMCoder();
			ppm->moveToThread(thread);
			
			connect(ppm, SIGNAL(percentageCompleted(qint64)), this, SLOT(setPercentageCompleted(qint64)));
			connect(ppm, SIGNAL(getSizeOutputFile(qint64)), this, SLOT(setSizeOutputFile(qint64)));
			connect(this, SIGNAL(getPath(const std::string &, const std::string &, const char &)), 
				ppm, SLOT(process(const std::string &, const std::string &, const char &)), Qt::DirectConnection);
			connect(thread, SIGNAL(started()), ppm, SLOT(empty()));
			
			emit getPath(inPath, outPath, 'c');
			
			thread->start();

			delete ppm;
		}
		else {										// "В заданный файл невозможно сохранить сжатые данные"
			(new QErrorMessage(this))->showMessage(QApplication::translate("WindowClass", "\320\222 \320\267\320\260\320\264\320\260\320\275\320\275\321\213\320\271 \321\204\320\260\320\271\320\273 \320\275\320\265\320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276 \321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\266\320\260\321\202\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
		}
	}
	else {											// "Файл для сжатия невозможно открыть"
		(new QErrorMessage(this))->showMessage(QApplication::translate("WindowClass", "\320\244\320\260\320\271\320\273 \320\264\320\273\321\217 \321\201\320\266\320\260\321\202\320\270\321\217 \320\275\320\265\320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276 \320\276\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
	}
}

// кнопка разжатия файла
void Window::on_decompressButton() {
	QFileInfo checkInPath(ui.lineEdit->text());
	QFileInfo checkOutPath(ui.lineEdit_2->text().left(ui.lineEdit_2->text().size() - ui.lineEdit_2->text().section("/", -1).size() - 1));
	// для входного путь существует и это файл
	if (checkInPath.exists() && checkInPath.isFile()) {
		// для выходного проверка расширения и существования пути
		if (ui.lineEdit_2->text().section(".", -1) == "txt" && checkOutPath.exists()) {
			// устанавливаем значение размера входного файла
			setSizeInputFile(checkInPath.size());
			// обнуление значения размера выходного файла
			setSizeOutputFile(0);
			// сжатие PPM кодером
			ppm = new PPMCoder();
			QThread *thread = new QThread;
			ppm = new PPMCoder();
			ppm->moveToThread(thread);

			connect(ppm, SIGNAL(percentageCompleted(qint64)), this, SLOT(setPercentageCompleted(qint64)));
			connect(ppm, SIGNAL(getSizeOutputFile(qint64)), this, SLOT(setSizeOutputFile(qint64)));
			connect(this, SIGNAL(getPath(const std::string &, const std::string &, const char &)),
				ppm, SLOT(process(const std::string &, const std::string &, const char &)), Qt::DirectConnection);
			connect(thread, SIGNAL(started()), ppm, SLOT(empty()));

			emit getPath(ui.lineEdit->text().toLocal8Bit().constData(), ui.lineEdit_2->text().toLocal8Bit().constData(), 'd');

			thread->start();

			delete ppm;
		}
		else {										// "В заданный файл невозможно сохранить сжатые данные"
			(new QErrorMessage(this))->showMessage(QApplication::translate("WindowClass", "\320\222 \320\267\320\260\320\264\320\260\320\275\320\275\321\213\320\271 \321\204\320\260\320\271\320\273 \320\275\320\265\320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276 \321\201\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \321\201\320\266\320\260\321\202\321\213\320\265 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
		}
	}
	else {											// "Файл для сжатия невозможно открыть"
		(new QErrorMessage(this))->showMessage(QApplication::translate("WindowClass", "\320\244\320\260\320\271\320\273 \320\264\320\273\321\217 \321\201\320\266\320\260\321\202\320\270\321\217 \320\275\320\265\320\262\320\276\320\267\320\274\320\276\320\266\320\275\320\276 \320\276\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
	}
}

// переопределение закрытия окна
void Window::closeEvent(QCloseEvent *event)
{
	QMessageBox::StandardButton ret;
	ret = QMessageBox::question(this, QApplication::applicationName(), 
		QApplication::translate("PPMClass", "\320\222\321\213 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\320\276 \321\205\320\276\321\202\320\270\321\202\320\265 \320\267\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265?", nullptr),
		QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
	if (ret == QMessageBox::No)
		event->ignore();
}