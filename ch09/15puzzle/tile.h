#ifndef TILE_H
#define TILE_H

#include <QPushButton>

class Tile : public QPushButton
{
    Q_OBJECT
public:
    explicit Tile(QObject *parent = 0, int tileNumber);

    int m_Number;
};

#endif // TILE_H
