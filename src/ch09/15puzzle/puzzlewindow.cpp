#include "puzzlewindow.h"
#include <QButtonGroup>
#include <QGridLayout>

PuzzleWindow::PuzzleWindow(PuzzleView *view, QWidget *parent)
    : QMainWindow(parent), m_PuzzleView(view) {
  // Body deliberately blank.
}
