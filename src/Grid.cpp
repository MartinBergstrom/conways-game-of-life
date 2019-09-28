#include <iostream>
#include "Grid.h"
#include <fstream>
#include <string>

using namespace std;


const int GRID_WIDTH = 30;
const int GRID_HEIGHT = 20;

Grid::Grid()
{
    grid = new int*[GRID_HEIGHT];
    for(int i = 0; i < GRID_HEIGHT; ++i)
    {
        grid[i] = new int[GRID_WIDTH];
    }
}

Grid::~Grid()
{
    for(int i = 0; i < GRID_WIDTH; ++i) {
        delete [] grid[i];
    }
    delete [] grid;
}

void Grid::loadGrid(string fileName)
{
    string line;
    ifstream myfile (fileName);
    int index = 0;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            loadLineIntoGridArr(index, line);
            index++;
            //cout << line << '\n';
        }
        myfile.close();
    }
    else cout << "Unable to open file";
}

void Grid::loadLineIntoGridArr(int index, string line)
{
    // each 3rd char represents a cell
    // MAX length = 30 (30*3 = 90 chars width)
    //grid[index][i] = something;
    if (line.empty() || index > 19)
    {
        cout << "Line is empty";
        return;
    }
    string formattedStr;
    for(int x = 0; x <line.length(); x += 3)
    {
        if (line.at(x) == '|')
        {
            formattedStr += '0';
        }
        else if (line.at(x) == 'X')
        {
            formattedStr += '1';
        }
    }
    for (int x = 0; x<GRID_WIDTH; x++)
    {
        grid[index][x] = (int)formattedStr.at(x) - 48; // because ASCII numbers start at 48
    }
}

void Grid::updateCoordinate(int x, int y)
{
    testString = "hello";
}

void Grid::printGrid()
{
    for(int y=0; y<GRID_HEIGHT; y++)
    {
        for(int x=0; x<GRID_WIDTH; x++)
        {
           cout << grid[y][x];
        }
        cout<<endl;
    }
}

int** Grid::getGrid()
{
    return grid;
}


