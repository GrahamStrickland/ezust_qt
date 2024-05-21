#ifndef TILE_H
#define TILE_H

#include <QPushButton>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    explicit Tile(int tileNumber, QWidget *parent = 0);

    int m_Number;
};

#endif // TILE_H
