#include "GameState.h"

using GridArr = array<array<int, GRID_WIDTH>, GRID_HEIGHT>;


GameState::GameState(Grid &inputGrid): grid(inputGrid)
{
}

void GameState::updateGameState()
{
    GridArr& gridMatrix = grid.getArr();

    // create new Grid
    GridArr newGrid = gridMatrix;

    for(int y=0; y<GRID_HEIGHT; y++)
     {
        for(int x=0; x<GRID_WIDTH; x++)
        {
            int aliveNeighBours = 0;
            // check above
            if (y > 0)
                aliveNeighBours += findNeighboursOnRow(gridMatrix, y - 1, x, true);
            // check same row
            aliveNeighBours += findNeighboursOnRow(gridMatrix, y, x, false);
            // check below
            if (y < (GRID_HEIGHT - 1)) {
                int neighboursBelow = findNeighboursOnRow(gridMatrix, y + 1, x, true);
                aliveNeighBours += neighboursBelow;
            }

            if (aliveNeighBours == 4 && gridMatrix[y][x] == 1) {
                   cout << "4 neighbours: " << endl;
            }
            if (aliveNeighBours < 2 || aliveNeighBours > 3)
                newGrid[y][x] = 0;
            else if (aliveNeighBours == 3)
                newGrid[y][x] = 1;
            else
                newGrid[y][x] = gridMatrix[y][x];
        }
    }

    for(int y=0; y<GRID_HEIGHT; y++)
    {
        for(int x=0; x<GRID_WIDTH; x++)
        {
           gridMatrix[y][x] = newGrid[y][x];
        }
    }
}

int GameState::findNeighboursOnRow(GridArr gridMatrix, int yIndex, int xIndex, bool includeMiddle)
{
    int count = 0;
    if (includeMiddle == true && gridMatrix[yIndex][xIndex] == 1)
    {
        count++;
    }

    if (xIndex > 0)
    {
        if (gridMatrix[yIndex][xIndex - 1] == 1)
            count++;
    }
    if (xIndex < GRID_HEIGHT - 1)
    {
        if (gridMatrix[yIndex][xIndex + 1] == 1)
            count++;
    }
    return count;
}

