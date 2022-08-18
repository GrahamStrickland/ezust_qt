#include "puzzleview.h"

PuzzleView::PuzzleView(QWidget *parent, PuzzleModel* model) :
    QWidget(parent), m_Model(model)
{
    m_Model->setParent(&this);

    QObject::connect(sender, SIGNAL(m_Model->gridChanged()), this, SLOT(refresh());

    m_Layout = new QGridLayout();

    m_Buttons = new QButtonGroup();

}
