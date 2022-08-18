#include "puzzleview.h"

int puzzleView::s_NumTiles = 15;

PuzzleView::PuzzleView(QWidget *parent, PuzzleModel* model) :
    QWidget(parent), m_Model(model)
{
    m_Model->setParent(&this);

    QObject::connect(m_Model,
                     SIGNAL(gridChanged()),
                     this,
                     SLOT(refresh()));

    m_Buttons = new QButtonGroup();
    for (int tileNum = 1; tileNum <= s_NumTiles; tileNum++)
    {
        Tile* tile = new Tile(tileNum);
        QObject::connect(tile,
                         SIGNAL(QPushButton::clicked()),
                         this,
                         SLOT(tryToSlide(sender)));
        m_Buttons.addButton(tile);
    }

    m_Layout = new QGridLayout();

    QVBoxLayout* col = new QVBoxLayout();

    QHBoxLayout* row = new QHBoxLayout();
    row->addWidget(m_Buttons.button(1));
    row->addWidget(m_Buttons.button(2));
    row->addWidget(m_Buttons.button(3));
    row->addWidget(m_Buttons.button(4));
    col->addLayout(row);

    row = new QHBoxLayout();
    row->addWidget(m_Buttons.button(5));
    row->addWidget(m_Buttons.button(6));
    row->addWidget(m_Buttons.button(7));
    row->addWidget(m_Buttons.button(8));
    col->addLayout(row);

    row = new QHBoxLayout();
    row->addWidget(m_Buttons.button(9));
    row->addWidget(m_Buttons.button(10));
    row->addWidget(m_Buttons.button(11));
    row->addWidget(m_Buttons.button(12));
    col->addLayout(row);

    row = new QHBoxLayout();
    row->addWidget(m_Buttons.button(13));
    row->addWidget(m_Buttons.button(14));
    row->addWidget(m_Buttons.button(15));
    col->addLayout(row);

    m_Layout->addLayout(col);
}
