#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <array>

using namespace std;

const int GRID_WIDTH = 30;
const int GRID_HEIGHT = 20;

using GridArr = array<array<int, GRID_WIDTH>, GRID_HEIGHT>;


class Grid
{
    public:
        Grid();
        virtual ~Grid();
        void loadGrid(string fileName);
        void updateCoordinate(int x, int y);
        void printGrid();
        GridArr& getArr();

    private:
        void loadLineIntoGridArr(int index, string line);

        GridArr myGrid;
        string testString;
};

#endif // GRID_H
