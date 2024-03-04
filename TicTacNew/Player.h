#pragma once
#include <string>
#include <vector>
#include "Board.h"
#include <algorithm>

class Player
{
    bool isPlayer; // AI or Human
    int scoreCount;
    int loopCount;

public:

    Player(bool isPlayer) : isPlayer(isPlayer)
    {
    }

    void setScore(int Score);

    std::string calcMove(Board& currentBoard);

    bool isPlayerOrHuman();

    bool validInputAI(std::string input, Board& currentboard);

    int minimax(Board& currentBoard, int depth, int alpha, int beta, bool isMaximizing);

    int winCond(Board& currentboard);

};
