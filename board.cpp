#include <vector>

#include "board.h"

Board::Board(int rows, int cols)
{
    board.resize(rows, std::vector<int> (cols, 0));
}

int Board::getXY(int x, int y)
{
    return board[x][y];
}

void Board::setXY(int x, int y, int val)
{
    board[x][y] = val;
}

