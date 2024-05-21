#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include <QAbstractButton>
#include <QButtonGroup>
#include <QLayout>
#include <QWidget>

class PuzzleModel;

class PuzzleView : public QWidget
{
    Q_OBJECT
public:
    explicit PuzzleView(PuzzleModel* model, QWidget *parent = 0);
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
    QButtonGroup* m_Buttons;
    int m_NumTiles;
    static int s_ShuffleMax;

    void addTiles();
        //Function to add all tiles to m_Layout in the order specified
        //by m_Model.
        //Postcondition: s_NumTiles widgets added to m_Layout.
};

#endif // PUZZLEVIEW_H
