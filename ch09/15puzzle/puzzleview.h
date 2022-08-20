#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include "puzzlemodel.h"
#include "tile.h"
#include <QWidget>
#include <QAbstractButton>
#include <QLayout>

class PuzzleView : public QWidget
{
    Q_OBJECT
public:
    explicit PuzzleView(QWidget *parent = 0, PuzzleModel* model);
        //Constructor with parameters.
        //Postcondition: m_Model = model.

public slots:
    void refresh();
        //Slot to adapt the display when gridChanged() called from
        //m_Model.

    void shuffle();
        //Slot to shuffle tiles when shuffleButton clicked.

    void tryToSlide(QAbstractButton* button);
        //Slot to attempt a slide to an empty cell neighbouring
        //button

private:
    PuzzleModel* m_Model;
    QGridLayout* m_Layout;
    QButtonGroup m_Buttons;
    static int s_NumTiles;
    static int s_ShuffleMax;
};

#endif // PUZZLEVIEW_H
