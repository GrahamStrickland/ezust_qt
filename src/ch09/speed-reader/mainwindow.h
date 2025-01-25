#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "randomstring.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow {
  Q_OBJECT
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

protected:
  void changeEvent(QEvent *e);
  void processTrial();

private:
  Ui::MainWindow *ui;
private slots:
  void on_nextButton_clicked();
  void on_responseString_returnPressed();
  void on_startButton_clicked();
  void on_lengthSlider_valueChanged(int value);
  void on_exposureSlider_valueChanged(int value);
  void on_timeSlider_valueChanged(int value);
  void timerDisplayRandStr();
  void inputTimedDisplay();

private:
  int m_expInterval;
  int m_inputTime;
  RandomString m_randStr;
  int m_trials;
  int m_correctChars;
  int m_totTrials;
  int m_totCorrectChars;
};
#endif // MAINWINDOW_H
