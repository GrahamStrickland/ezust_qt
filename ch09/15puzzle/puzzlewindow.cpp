#include "puzzlewindow.h"
#include <QGridLayout>
#include <QButtonGroup>

PuzzleWindow::PuzzleWindow(PuzzleView* view, QWidget *parent) :
    QMainWindow(parent), m_PuzzleView(view)
{
    //Body deliberately blank.
}
