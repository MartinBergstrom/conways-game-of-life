#include <iostream>
#include "Grid.h"
#include <fstream>
#include <string>

using namespace std;

Grid::Grid()
{}

Grid::~Grid()
{
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
        myGrid[index][x] = (int)formattedStr.at(x) - 48; // because ASCII numbers start at 48
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
            string formattedStr;
            if (myGrid[y][x] == 0)
            {
                formattedStr = "|| ";
            } else
            {
                formattedStr = "XX ";
            }
            cout << formattedStr;
        }
        cout<<endl;
    }
}

GridArr& Grid::getArr()
{
    return myGrid;
}



