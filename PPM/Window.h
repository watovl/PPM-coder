#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_PPM.h"
#include "PPMCoder.h"

class PPMCoder;

class Window : public QMainWindow
{
	Q_OBJECT

public:
	Window(QWidget *parent = Q_NULLPTR);

signals:
	void getPath(const std::string &, const std::string &, const char &);

private slots:
	void setOutPath(const QString &path);
	void setPercentageCompleted(qint64 value);
	void setSizeOutputFile(qint64 value);
	void setSizeInputFile(qint64 value);

	void on_selectPathButton();
	void on_compressButton();
	void on_decompressButton();

	void closeEvent(QCloseEvent *event);

private:
	Ui::WindowClass ui;
	PPMCoder *ppm;

	void settingConnect();
};

#endif