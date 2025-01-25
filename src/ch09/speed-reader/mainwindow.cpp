#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), m_expInterval(0),
      m_inputTime(0), m_randStr(), m_trials(0), m_correctChars(0),
      m_totTrials(0), m_totCorrectChars(0) {
  // Initialize UI.
  ui->setupUi(this);
  ui->displayLabel->hide();
  ui->responseLabel->hide();
  ui->nextButton->hide();
  m_randStr.setStringLength(5);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::changeEvent(QEvent *e) {
  QMainWindow::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void MainWindow::on_exposureSlider_valueChanged(int value) {
  ui->exposureLCD->display(value);
  m_expInterval = value;
}

void MainWindow::on_timeSlider_valueChanged(int value) {
  ui->timeLCD->display(value);
  m_inputTime = value;
}

void MainWindow::on_lengthSlider_valueChanged(int value) {
  ui->lengthLCD->display(value);
  m_randStr.setStringLength(value);
}

void MainWindow::on_startButton_clicked() {
  // Hide start button.
  ui->startButton->hide();

  // Show game panel.
  ui->displayLabel->show();
  ui->targetString->show();
  ui->responseLabel->show();
  ui->responseString->show();
  ui->nextButton->show();

  // Disable settings.
  ui->groupBox->setEnabled(false);
  m_trials = 0;

  // Initialize the score system.
  m_correctChars = 0;

  // Start trials.
  processTrial();
}

void MainWindow::processTrial() {
  // Clear response text editor.
  ui->responseString->setText("");

  // Display the random string.
  ui->targetString->setText(m_randStr.generateString());
  ui->responseString->setEnabled(false);
  ui->nextButton->setEnabled(false);

  // Count the number of trials.
  m_trials++;
  m_totTrials++;
  ui->nextButton->setText(QString("String %1").arg(m_trials));

  // Begin exposure.
  QTimer::singleShot(m_expInterval, this, SLOT(timerDisplayRandStr()));
}

void MainWindow::timerDisplayRandStr() {
  ui->targetString->setText(QString(""));

  // Enable the response line editor and next button.
  ui->responseString->setEnabled(true);
  ui->responseString->setFocus();
  ui->nextButton->setEnabled(true);

  // Call function to begin input timer.
  QTimer::singleShot(m_inputTime, this, SLOT(inputTimedDisplay()));
}

void MainWindow::inputTimedDisplay() {
  on_nextButton_clicked(); // End of timer, proceed to next.
}

void MainWindow::on_responseString_returnPressed() {
  on_nextButton_clicked(); // Pressing return has same effect as clicking next.
}

void MainWindow::on_nextButton_clicked() {
  int goodChars(m_randStr.numCorrectChars(ui->responseString->text()));
  int lenTarget(ui->lengthLCD->value());
  m_correctChars += goodChars;
  m_totCorrectChars += goodChars;
  ui->correctCharFraction->setText(
      QString("%1 / %2").arg(m_correctChars).arg(lenTarget * m_trials));
  ui->cumulativeFraction->setText(
      QString("%1 / %2").arg(m_totCorrectChars).arg(lenTarget * m_totTrials));

  if (m_trials == ui->trialsSpinBox->value()) {
    // Hide game panel.
    ui->startButton->show();

    // Show start button.
    ui->displayLabel->hide();
    ui->targetString->hide();
    ui->responseLabel->hide();
    ui->responseString->hide();
    ui->nextButton->hide();

    // Enble settings.
    ui->groupBox->setEnabled(true);
  } else
    processTrial();
}
