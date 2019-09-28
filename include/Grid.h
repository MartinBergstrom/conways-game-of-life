#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <array>

using namespace std;


class Grid
{
    public:
        Grid();
        virtual ~Grid();
        void loadGrid(string fileName);
        void updateCoordinate(int x, int y);
        void printGrid();
        int** getGrid();

    private:
        void loadLineIntoGridArr(int index, string line);

        int** grid;
        string testString;
};

#endif // GRID_H
