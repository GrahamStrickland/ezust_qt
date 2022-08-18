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

    bool tryToSlide(QAbstractButton* button);
        //Function to attempt a slide to an empty cell neighbouring
        //button
        //Postcondition: If neighbouring cell is empty, returned
        //	true and called m_Model->slide() with button as argument;
        //	otherwise returned false.

public slots:
    void refresh();
        //Slot to adapt the display when gridChanged() called from
        //m_Model.

private:
    PuzzleModel* m_Model;
    QGridLayout* m_Layout;
    QButtonGroup m_Buttons;
    static int s_NumTiles;
};

#endif // PUZZLEVIEW_H
