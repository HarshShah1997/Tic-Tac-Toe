#include <iostream>
#include <vector>
#include <GL/glut.h>

class Board {
    private:
        std::vector< std::vector<int> > board;
    
    public:
        Board(int rows, int cols);
        int getXY(int x, int y);
        void setXY(int x, int y, int val);
};


