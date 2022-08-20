#include "puzzleview.h"
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

int puzzleView::s_NumTiles = 15;
int puzzleView::s_ShuffleMax = 50;

PuzzleView::PuzzleView(QWidget *parent, PuzzleModel* model) :
    QWidget(parent), m_Model(model)
{
    //Set parent of model and connect signal to slot.
    m_Model->setParent(&this);

    QObject::connect(m_Model,
                     SIGNAL(gridChanged()),
                     this,
                     SLOT(refresh()));

    //Create QButtonGroup and add buttons; connect signals and slots.
    m_Buttons = new QButtonGroup();
    for (int tileNum = 1; tileNum <= s_NumTiles; tileNum++)
    {
        Tile* tile = new Tile(tileNum);
        m_Buttons.addButton(tile);
    }
    QObject::connect(m_Buttons,
                     &QButtonGroup::buttonClicked,
                     this,
                     SLOT(tryToSlide(sender)));
    QPushButton* shuffleButton = new QPushButton("Shuffle");
    QObject::connect(shuffleButton,
                     SIGNAL(QPushButton::clicked()),
                     this,
                     SLOT(shuffle()));
    m_Buttons.addButton(shuffleButton);
    QPushButton* quitButton = new QPushButton("Quit");
    QObject::connect(quitButton,
                     SIGNAL(QPushButton::clicked()),
                     this,
                     SLOT(close()));
    m_Buttons.addButton(quitButton);

    //Create column and row layouts and add to QGridLayout.
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

    m_Layout = new QGridLayout();
    setLayout(m_Layout);

    m_Layout->addLayout(col);

    col = new QVBoxLayout();
    col->addWidget(m_Buttons.button(16));
    col->addWidget(m_Buttons.button(17));

    m_Layout->addLayout(col);
}

void PuzzleView::refresh()
{
    QVBoxLayout tiles = m_Layout->itemAtPosition(0, 0);
    QHBoxLayout row = tiles->itemAtPosition(0, 0);
}

void PuzzleView::shuffle()
{
    int tileNum = 0;
    srand(time(0));

    //Shuffle tiles s_ShuffleMax times.
    for (int i = 0; i < s_ShuffleMax; i++)
        do
            tileNum = rand % s_NumTiles;
        while (!m_Model->slide(m_Buttons.id(tileNum)));
}

void PuzzleView::tryToSlide(QAbstractButton *button)
{
    if (!m_Model->slide(m_Buttons.id(button)))
    {
        QMessageBox errorMsg = QMessageBox::information(
                    &this,
                    tr("Error"),
                    tr("Tile " + button->text() + " has no empty neighbours.\n"),
                    QMessageBox::Cancel);
        errorMsg.exec();
    }
}
