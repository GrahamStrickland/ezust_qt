#include "puzzlemodel.h"
#include <QtGlobal>

PuzzleModel::PuzzleModel(int rows, int cols, QObject *parent) :
    QObject(parent), m_Rows(rows), m_Cols(cols)
{
    for (int i = 0; i < m_Rows * m_Cols; i++)
        m_Positions.append(i+1);
    m_Positions.append(0);
}

int PuzzleModel::getNumTiles() const
{
    return m_Rows * m_Cols;
}

int PuzzleModel::value(int r, int c)
{
    Q_ASSERT(r < m_Rows && c < m_Cols);

    return m_Positions.at(r * m_Rows + c);
}

bool PuzzleModel::slide(int tilenum)
{
    int pos = 0, row, col, empty;

    pos = m_Positions.indexOf(tilenum);
    col = pos % m_Rows;
    row = (pos - col) / m_Rows;
    if (neighbouring(row, col)) {
        empty = m_Positions.indexOf(0);
        m_Positions.replace(empty, tilenum);
        m_Positions.replace(pos, 0);
        emit gridChanged();
        return true;
    }
    else
        return false;
}

bool PuzzleModel::neighbouring(int r, int c)
{
    Q_ASSERT(r < m_Rows && c < m_Cols);

    int emptyRow, emptyCol, empty;

    empty = m_Positions.indexOf(0);
    emptyCol = empty % m_Rows;
    emptyRow = (empty - emptyCol) / m_Rows;

    return (r > 1 && r == emptyRow - 1)
            || (r < m_Rows - 1 && r == emptyRow + 1)
            || (c > 1 && c == emptyCol - 1)
            || (c < m_Cols - 1 && c == emptyCol + 1);
}
