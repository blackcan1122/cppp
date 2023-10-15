#pragma once
#include <string>
#include <vector>
class Player
{
    bool isPlayer; // AI or Human
    int scoreCount;

public:

    Player(bool isPlayer) : isPlayer(isPlayer)
    {
    }

    void setScore(int Score);

    std::string calcMove(std::vector<std::vector<std::string>> vPlayerboard);

    bool isPlayerOrHuman(Player& PlayerController);
};

