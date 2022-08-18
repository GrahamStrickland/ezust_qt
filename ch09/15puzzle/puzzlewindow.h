#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include <QMainWindow>

class PuzzleWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit PuzzleWindow(QWidget *parent = 0, PuzzleView* view);
        //Constructor with parameters.
        //Postcondition: m_PuzzleView = view.

private:
    PuzzleView* m_PuzzleView;
};

#endif // PUZZLEWINDOW_H
