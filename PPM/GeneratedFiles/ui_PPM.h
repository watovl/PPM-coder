/********************************************************************************
** Form generated from reading UI file 'PPM.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PPM_H
#define UI_PPM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QToolButton *selectPathButton;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_2;
    QPushButton *compressButton;
    QPushButton *decompressButton;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_4;
    QLabel *labelSizeInputFile;
    QLabel *label_11;
    QLabel *labelProcessed;
    QLabel *label_6;
    QLabel *labelSizeOutputFile;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QProgressBar *progressBar;
    QPushButton *pushButton;

    void setupUi(QMainWindow *WindowClass)
    {
        if (WindowClass->objectName().isEmpty())
            WindowClass->setObjectName(QString::fromUtf8("WindowClass"));
        WindowClass->setWindowModality(Qt::NonModal);
        WindowClass->resize(444, 440);
        WindowClass->setMinimumSize(QSize(444, 440));
        WindowClass->setMaximumSize(QSize(445, 441));
        WindowClass->setToolButtonStyle(Qt::ToolButtonIconOnly);
        WindowClass->setTabShape(QTabWidget::Rounded);
        WindowClass->setDockNestingEnabled(false);
        centralWidget = new QWidget(WindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 421, 381));
        verticalLayout = new QVBoxLayout(gridLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setUnderline(false);
        font.setKerning(false);
        font.setStyleStrategy(QFont::PreferDefault);
        label->setFont(font);
        label->setFrameShape(QFrame::Box);
        label->setFrameShadow(QFrame::Sunken);
        label->setLineWidth(1);
        label->setMidLineWidth(0);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(false);
        label->setMargin(0);
        label->setIndent(-1);

        verticalLayout->addWidget(label);

        groupBox = new QGroupBox(gridLayoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox->setAcceptDrops(false);
        groupBox->setLayoutDirection(Qt::LeftToRight);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8("/*QGroupBox {\n"
"	border: 1px groove gray;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	subcontrol-origin: margin; \n"
"    left: 10px;\n"
"	padding: 0 3px 0 3px; \n"
"}*/"));
        groupBox->setInputMethodHints(Qt::ImhNone);
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 401, 81));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(gridLayoutWidget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setToolTipDuration(3000);

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 4);

        lineEdit = new QLineEdit(gridLayoutWidget_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setToolTipDuration(3000);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 3);

        selectPathButton = new QToolButton(gridLayoutWidget_2);
        selectPathButton->setObjectName(QString::fromUtf8("selectPathButton"));
        selectPathButton->setPopupMode(QToolButton::DelayedPopup);
        selectPathButton->setToolButtonStyle(Qt::ToolButtonIconOnly);

        gridLayout->addWidget(selectPathButton, 0, 4, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 1);
        gridLayout->setColumnStretch(3, 1);
        gridLayout->setColumnStretch(4, 1);
        gridLayoutWidget_3 = new QWidget(groupBox);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(60, 100, 301, 31));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        compressButton = new QPushButton(gridLayoutWidget_3);
        compressButton->setObjectName(QString::fromUtf8("compressButton"));
        compressButton->setEnabled(false);

        gridLayout_2->addWidget(compressButton, 0, 0, 1, 1);

        decompressButton = new QPushButton(gridLayoutWidget_3);
        decompressButton->setObjectName(QString::fromUtf8("decompressButton"));
        decompressButton->setEnabled(false);

        gridLayout_2->addWidget(decompressButton, 0, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(gridLayoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 309, 61));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        labelSizeInputFile = new QLabel(formLayoutWidget);
        labelSizeInputFile->setObjectName(QString::fromUtf8("labelSizeInputFile"));

        formLayout->setWidget(0, QFormLayout::FieldRole, labelSizeInputFile);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_11);

        labelProcessed = new QLabel(formLayoutWidget);
        labelProcessed->setObjectName(QString::fromUtf8("labelProcessed"));

        formLayout->setWidget(1, QFormLayout::FieldRole, labelProcessed);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        labelSizeOutputFile = new QLabel(formLayoutWidget);
        labelSizeOutputFile->setObjectName(QString::fromUtf8("labelSizeOutputFile"));

        formLayout->setWidget(2, QFormLayout::FieldRole, labelSizeOutputFile);

        horizontalLayoutWidget = new QWidget(groupBox_2);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 80, 401, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout->addWidget(label_10);

        progressBar = new QProgressBar(horizontalLayoutWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setEnabled(false);
        progressBar->setValue(0);

        horizontalLayout->addWidget(progressBar);


        verticalLayout->addWidget(groupBox_2);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(340, 400, 91, 31));
        WindowClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(lineEdit, selectPathButton);
        QWidget::setTabOrder(selectPathButton, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, compressButton);
        QWidget::setTabOrder(compressButton, decompressButton);
        QWidget::setTabOrder(decompressButton, pushButton);

        retranslateUi(WindowClass);
        QObject::connect(pushButton, SIGNAL(clicked()), WindowClass, SLOT(close()));

        QMetaObject::connectSlotsByName(WindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *WindowClass)
    {
        WindowClass->setWindowTitle(QApplication::translate("WindowClass", "PPM \321\201\320\266\320\260\321\202\320\270\320\265 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
#ifndef QT_NO_STATUSTIP
        WindowClass->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        WindowClass->setWhatsThis(QApplication::translate("WindowClass", "A", nullptr));
#endif // QT_NO_WHATSTHIS
        label->setText(QApplication::translate("WindowClass", "<html><head/><body><p style=\"line-height:1\"><span>\320\224\320\260\320\275\320\275\320\260\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \321\200\320\265\320\260\320\273\320\270\320\267\321\203\320\265\321\202 PPMC \321\201\320\266\320\260\321\202\320\270\320\265.<br><br>\320\247\321\202\320\276\320\261\321\213 \321\201\320\266\320\260\321\202\321\214 \321\204\320\260\320\271\320\273, \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\275\321\203\320\266\320\275\321\213\320\271 \321\204\320\260\320\271\320\273 \321\201 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\320\265\320\274 .txt, \321\203\320\272\320\260\320\266\320\270\321\202\320\265<br>\320\277\321\203\321\202\321\214 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \321\201\320\266\320\260\321\202\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260 \320\270 \320\275\320\260\320\266\320\274\320\270\321"
                        "\202\320\265 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\241\320\266\320\260\321\202\321\214\".<br>\320\247\321\202\320\276\320\261\321\213 \321\200\320\260\320\267\320\266\320\260\321\202\321\214 \321\204\320\260\320\271\320\273, \320\262\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\275\321\203\320\266\320\275\321\213\320\271 \321\204\320\260\320\271\320\273 \321\201 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\320\265\320\274 .ppm, \321\203\320\272\320\260\320\266\320\270\321\202\320\265<br>\320\277\321\203\321\202\321\214 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217 \321\200\320\260\320\267\320\266\320\260\321\202\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260 \320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 \320\272\320\275\320\276\320\277\320\272\321\203 \"\320\240\320\260\320\267\320\266\320\260\321\202\321\214\".</span></p></body></html>", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        groupBox->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        groupBox->setTitle(QApplication::translate("WindowClass", "\320\244\320\260\320\271\320\273", nullptr));
        label_3->setText(QApplication::translate("WindowClass", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271:", nullptr));
        label_2->setText(QApplication::translate("WindowClass", "\320\222\321\205\320\276\320\264\320\275\320\276\320\271:", nullptr));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("WindowClass", "\320\237\321\203\321\202\321\214 \320\264\320\273\321\217 \320\262\321\213\321\205\320\276\320\264\320\275\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        lineEdit->setToolTip(QApplication::translate("WindowClass", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        lineEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        lineEdit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        selectPathButton->setText(QApplication::translate("WindowClass", "\320\262\321\213\320\261\321\200\320\260\321\202\321\214...", nullptr));
        compressButton->setText(QApplication::translate("WindowClass", "\320\241\320\266\320\260\321\202\321\214", nullptr));
        decompressButton->setText(QApplication::translate("WindowClass", "\320\240\320\260\320\267\320\266\320\260\321\202\321\214", nullptr));
        groupBox_2->setTitle(QApplication::translate("WindowClass", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
        label_4->setText(QApplication::translate("WindowClass", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\262\321\205\320\276\320\264\320\275\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260: ", nullptr));
        labelSizeInputFile->setText(QApplication::translate("WindowClass", "0 \320\261\320\260\320\271\321\202", nullptr));
        label_11->setText(QApplication::translate("WindowClass", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\260\320\275\320\276 \320\261\320\260\320\271\321\202:", nullptr));
        labelProcessed->setText(QApplication::translate("WindowClass", "0", nullptr));
        label_6->setText(QApplication::translate("WindowClass", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\262\321\213\321\205\320\276\320\264\320\275\320\276\320\263\320\276 \321\204\320\260\320\271\320\273\320\260:", nullptr));
        labelSizeOutputFile->setText(QApplication::translate("WindowClass", "0 \320\261\320\260\320\271\321\202", nullptr));
        label_10->setText(QApplication::translate("WindowClass", "\320\237\321\200\320\276\321\206\320\265\321\201\321\201: ", nullptr));
        pushButton->setText(QApplication::translate("WindowClass", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WindowClass: public Ui_WindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PPM_H
