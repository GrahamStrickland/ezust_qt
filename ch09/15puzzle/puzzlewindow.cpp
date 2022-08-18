#include "puzzlewindow.h"
#include <QGridLayout>
#include <QButtonGroup>

PuzzleWindow::PuzzleWindow(QWidget *parent, PuzzleView* view) :
    QMainWindow(parent), m_PuzzleView(view)
{
    //Body deliberately blank.
}
