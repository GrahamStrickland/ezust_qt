#ifndef PUZZLEMODEL_H
#define PUZZLEMODEL_H

#include <QList>
#include <QObject>

class PuzzleModel : public QObject {
  Q_OBJECT
public:
  explicit PuzzleModel(int rows, int cols, QObject *parent = 0);

  int getNumTiles() const;
  // Function to return the number of tiles in the puzzle.
  // Postcondition: Returned m_Rows * m_Cols.

  int value(int r, int c);
  // Function to return the value of the tile at row r,
  // column c.
  // Postcondition: Returned int value between 1 and 15.

  bool slide(int tilenum);
  // Function to slide a tile to an available open space.
  // Postcondition: If tile has open neighbouring space,
  //	tile moved and returned true and gridChanged() called;
  //	otherwise returned false.

  bool neighbouring(int r, int c);
  // Function to check whether tile at row r, column c
  // has a neighbouring open space.
  // Postcondition: Returned true if tile has a neighbouring
  //	open space; otherwise returned false.

signals:
  void gridChanged();
  // Signal to indicate that grid layout must be changed.

public slots:

private:
  QList<int> m_Positions;
  int m_Rows;
  int m_Cols;
};

#endif // PUZZLEMODEL_H
