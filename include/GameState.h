#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <Grid.h>

class GameState
{
    public:
        GameState();
        GameState(Grid &grid);
        void updateGameState();
        int findNeighboursOnRow(GridArr gridMatrix, int yIndex, int xIndex, bool includeMiddle);

    private:
        Grid &grid;
};

#endif // GAMESTATE_H
