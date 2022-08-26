#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include "puzzleview.h"
#include <QMainWindow>

class PuzzleWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PuzzleWindow(PuzzleView* view, QWidget *parent = 0);
        //Constructor with parameters.
        //Postcondition: m_PuzzleView = view.

private:
    PuzzleView* m_PuzzleView;
};

#endif // PUZZLEWINDOW_H
