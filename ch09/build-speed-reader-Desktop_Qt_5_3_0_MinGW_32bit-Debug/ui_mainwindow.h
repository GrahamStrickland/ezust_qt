/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QSpinBox *trialsSpinBox;
    QLabel *label_5;
    QLabel *label_2;
    QLCDNumber *exposureLCD;
    QSlider *exposureSlider;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_9;
    QLCDNumber *timeLCD;
    QSlider *timeSlider;
    QLabel *label_6;
    QLabel *label_4;
    QSlider *lengthSlider;
    QLCDNumber *lengthLCD;
    QGroupBox *groupBox_2;
    QWidget *scoreWidget;
    QLabel *label;
    QLabel *label_7;
    QLabel *correctCharFraction;
    QLabel *cumulativeFraction;
    QGroupBox *groupBox_3;
    QPushButton *startButton;
    QLabel *responseLabel;
    QLabel *displayLabel;
    QPushButton *nextButton;
    QLineEdit *targetString;
    QLineEdit *responseString;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(689, 395);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(290, 10, 381, 161));
        trialsSpinBox = new QSpinBox(groupBox);
        trialsSpinBox->setObjectName(QStringLiteral("trialsSpinBox"));
        trialsSpinBox->setGeometry(QRect(160, 30, 55, 31));
        trialsSpinBox->setMinimum(1);
        trialsSpinBox->setValue(5);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 70, 51, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 121, 17));
        exposureLCD = new QLCDNumber(groupBox);
        exposureLCD->setObjectName(QStringLiteral("exposureLCD"));
        exposureLCD->setGeometry(QRect(250, 70, 41, 23));
        exposureLCD->setProperty("value", QVariant(100));
        exposureLCD->setProperty("intValue", QVariant(100));
        exposureSlider = new QSlider(groupBox);
        exposureSlider->setObjectName(QStringLiteral("exposureSlider"));
        exposureSlider->setGeometry(QRect(99, 70, 141, 20));
        exposureSlider->setMinimum(100);
        exposureSlider->setMaximum(3000);
        exposureSlider->setSingleStep(10);
        exposureSlider->setValue(100);
        exposureSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 71, 17));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(300, 100, 31, 17));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 100, 61, 17));
        timeLCD = new QLCDNumber(groupBox);
        timeLCD->setObjectName(QStringLiteral("timeLCD"));
        timeLCD->setGeometry(QRect(250, 100, 41, 23));
        timeLCD->setDigitCount(5);
        timeLCD->setProperty("value", QVariant(500));
        timeLCD->setProperty("intValue", QVariant(500));
        timeSlider = new QSlider(groupBox);
        timeSlider->setObjectName(QStringLiteral("timeSlider"));
        timeSlider->setGeometry(QRect(99, 100, 141, 20));
        timeSlider->setMinimum(5);
        timeSlider->setMaximum(50);
        timeSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(300, 130, 31, 17));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 61, 17));
        lengthSlider = new QSlider(groupBox);
        lengthSlider->setObjectName(QStringLiteral("lengthSlider"));
        lengthSlider->setGeometry(QRect(99, 130, 141, 20));
        lengthSlider->setMinimum(5);
        lengthSlider->setMaximum(50);
        lengthSlider->setOrientation(Qt::Horizontal);
        lengthLCD = new QLCDNumber(groupBox);
        lengthLCD->setObjectName(QStringLiteral("lengthLCD"));
        lengthLCD->setGeometry(QRect(250, 130, 41, 23));
        lengthLCD->setDigitCount(2);
        lengthLCD->setProperty("intValue", QVariant(5));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 180, 381, 181));
        scoreWidget = new QWidget(groupBox_2);
        scoreWidget->setObjectName(QStringLiteral("scoreWidget"));
        scoreWidget->setGeometry(QRect(10, 30, 361, 151));
        label = new QLabel(scoreWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 161, 17));
        label_7 = new QLabel(scoreWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 60, 141, 17));
        correctCharFraction = new QLabel(scoreWidget);
        correctCharFraction->setObjectName(QStringLiteral("correctCharFraction"));
        correctCharFraction->setGeometry(QRect(180, 30, 71, 17));
        cumulativeFraction = new QLabel(scoreWidget);
        cumulativeFraction->setObjectName(QStringLiteral("cumulativeFraction"));
        cumulativeFraction->setGeometry(QRect(180, 60, 71, 17));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 271, 351));
        startButton = new QPushButton(groupBox_3);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(52, 120, 171, 27));
        responseLabel = new QLabel(groupBox_3);
        responseLabel->setObjectName(QStringLiteral("responseLabel"));
        responseLabel->setGeometry(QRect(10, 170, 161, 21));
        displayLabel = new QLabel(groupBox_3);
        displayLabel->setObjectName(QStringLiteral("displayLabel"));
        displayLabel->setGeometry(QRect(10, 30, 141, 21));
        nextButton = new QPushButton(groupBox_3);
        nextButton->setObjectName(QStringLiteral("nextButton"));
        nextButton->setGeometry(QRect(80, 310, 93, 27));
        targetString = new QLineEdit(groupBox_3);
        targetString->setObjectName(QStringLiteral("targetString"));
        targetString->setEnabled(true);
        targetString->setGeometry(QRect(10, 67, 241, 31));
        targetString->setFocusPolicy(Qt::NoFocus);
        responseString = new QLineEdit(groupBox_3);
        responseString->setObjectName(QStringLiteral("responseString"));
        responseString->setGeometry(QRect(10, 210, 251, 41));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        label_5->setText(QApplication::translate("MainWindow", "msec", 0));
        label_2->setText(QApplication::translate("MainWindow", "Number of trials", 0));
        label_3->setText(QApplication::translate("MainWindow", "Exposure", 0));
        label_8->setText(QApplication::translate("MainWindow", "msec", 0));
        label_9->setText(QApplication::translate("MainWindow", "Typing time", 0));
        label_6->setText(QApplication::translate("MainWindow", "char", 0));
        label_4->setText(QApplication::translate("MainWindow", "Length", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Summary", 0));
        label->setText(QApplication::translate("MainWindow", "Characters correct", 0));
        label_7->setText(QApplication::translate("MainWindow", "Total chars correct", 0));
        correctCharFraction->setText(QApplication::translate("MainWindow", "--", 0));
        cumulativeFraction->setText(QApplication::translate("MainWindow", "--", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "SpeedReader", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start the trials", 0));
        responseLabel->setText(QApplication::translate("MainWindow", "Response String", 0));
        displayLabel->setText(QApplication::translate("MainWindow", "Target String", 0));
        nextButton->setText(QApplication::translate("MainWindow", "Next", 0));
        targetString->setText(QApplication::translate("MainWindow", "Get ready to watch this space", 0));
        responseString->setText(QApplication::translate("MainWindow", "Type the target string here", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
