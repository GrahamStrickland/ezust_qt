#include "puzzleview.h"
#include "puzzlemodel.h"
#include "tile.h"
#include <QMessageBox>
#include <cmath>
#include <cstdlib>
#include <ctime>

int PuzzleView::s_ShuffleMax = 50;

PuzzleView::PuzzleView(PuzzleModel *model, QWidget *parent) : QWidget(parent) {
  m_Model = model;

  // Set parent of model and connect signal to slot.
  m_Model->setParent(this);
  m_NumTiles = m_Model->getNumTiles();

  QObject::connect(m_Model, SIGNAL(gridChanged()), this, SLOT(refresh()));

  // Create QButtonGroup and add buttons; connect signals and slots.
  m_Buttons = new QButtonGroup();
  for (int tileNum = 1; tileNum <= m_NumTiles; tileNum++) {
    Tile *tile = new Tile(tileNum);
    m_Buttons->addButton(tile);
  }
  QObject::connect(m_Buttons, SIGNAL(buttonClicked(QAbstractButton *)), this,
                   SLOT(tryToSlide(QAbstractButton *)));
  QPushButton *shuffleButton = new QPushButton("Shuffle");
  QObject::connect(shuffleButton, SIGNAL(clicked()), this, SLOT(shuffle()));
  m_Buttons->addButton(shuffleButton);
  QPushButton *quitButton = new QPushButton("Quit");
  QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(close()));
  m_Buttons->addButton(quitButton);

  // Add buttons to QGridLayout.
  m_Layout = new QGridLayout();
  addTiles();
}
void PuzzleView::refresh() { addTiles(); }

void PuzzleView::shuffle() {
  int tileNum = 0;
  srand(time(0));

  // Shuffle tiles s_ShuffleMax times.
  for (int i = 0; i < s_ShuffleMax; i++)
    do
      tileNum = rand() % m_NumTiles;
    while (!m_Model->slide(tileNum));
}

void PuzzleView::tryToSlide(QAbstractButton *button) {
  if (!m_Model->slide(m_Buttons->id(button))) {
    QMessageBox errorMsg(this);
    errorMsg.addButton(QMessageBox::information(
        this, tr("Error"),
        tr("Tile %1 has no empty neighbours.\n").arg(QString(button->text())),
        QMessageBox::Cancel));
    errorMsg.exec();
  }
}

void PuzzleView::addTiles() {
  for (int id = 0; id < m_NumTiles; id++)
    m_Layout->removeWidget(m_Buttons->button(id));

  for (int row = 0; row < ceil(sqrt(m_NumTiles)); row++)
    for (int col = 0; col < ceil(sqrt(m_NumTiles)); col++)
      m_Layout->addWidget(m_Buttons->button(m_Model->value(row, col)), row,
                          col);
}
