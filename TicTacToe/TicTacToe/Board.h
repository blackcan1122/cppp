#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
class Board
{
private:

    std::vector<std::vector<std::string>> vPlayboard;
    std::vector<std::string> isTaken;



public:
    Board();

    // Method for generating the Playboard in a given size  (Standard should be 2Xrows and 2 Yrows)
    void generatePlayboard();


    void updatePlayboard(std::string input);


    // Get Methods

    std::vector<std::string> getIsTaken();

    std::vector<std::vector<std::string>> getvPlayboard();



    // Set Methods

    std::vector<std::vector<std::string>> setvPlayboard(std::vector<std::vector<std::string>> newvPlayboard);

    std::vector<std::string> addItemtoIsTaken(std::string itemToAdd);

    void printBoard();
    
};

