#include "puzzlewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PuzzleModel model;
    PuzzleView view(&model);
    PuzzleWindow w(&view);
    w.show();

    return a.exec();
}
