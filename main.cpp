#include <iostream>
#include <windows.h>
#include <Grid.h>
#include <GameState.h>

using namespace std;

string const SAMPLE_FILE = "sampleGrid.txt";

void runGameLoop(Grid &g, GameState &gState);

int main()
{
    Grid g;
    g.loadGrid(SAMPLE_FILE);
    g.printGrid();
    GameState state(g);
    state.updateGameState();
    g.printGrid();

    while(true) {
        runGameLoop(g, state);
    }
    return 0;
}

void runGameLoop(Grid &g, GameState &gState)
{
    g.printGrid();
    gState.updateGameState();
    Sleep(800);
}
