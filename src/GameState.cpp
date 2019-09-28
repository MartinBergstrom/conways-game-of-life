#include "GameState.h"


const int GRID_WIDTH = 30;
const int GRID_HEIGHT = 20;

GameState::GameState(Grid &inputGrid): grid(inputGrid)
{
}

void GameState::updateGameState()
{
    std::cout << "updateGameState" <<std::endl;
    int** gridMatrix = grid.getGrid();

    // create new Grid
    int ** newGrid = new int*[GRID_HEIGHT];
    for(int i = 0; i < GRID_HEIGHT; ++i)
    {
        newGrid[i] = new int[GRID_WIDTH];
    }
    for(int y=0; y<GRID_HEIGHT; y++)
    {
        for(int x=0; x<GRID_WIDTH; x++)
        {
           newGrid[y][x] = gridMatrix[y][x];
        }
    }

    for(int y=0; y<GRID_HEIGHT; y++)
     {
        for(int x=0; x<GRID_WIDTH; x++)
        {
            int aliveNeighBours = 0;
            // check above
            if (y > 0)
                aliveNeighBours += findNeighboursOnRow(gridMatrix, y - 1, x, false);
            // check same row
            aliveNeighBours += findNeighboursOnRow(gridMatrix, y, x, true);
            // check below
            if (y < (GRID_HEIGHT - 1))
                aliveNeighBours += findNeighboursOnRow(gridMatrix, y + 1, x, false);

            if (aliveNeighBours < 2 || aliveNeighBours > 3)
                newGrid[y][x] = 0;

            if (aliveNeighBours == 3)
                newGrid[y][x] = 1;
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

int GameState::findNeighboursOnRow(int** gridMatrix, int yIndex, int xIndex, bool excludeMiddle)
{
    int count = 0;
    if (!excludeMiddle && gridMatrix[yIndex][xIndex] == 1)
        count++;

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

