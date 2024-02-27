#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
class Board
{
private:

    std::vector<std::vector<std::string>> vPlayboard;
    std::vector<std::vector<std::string>> savedPlayboard;

    std::vector<std::string> savedIsTakenX;
    std::vector<std::string> savedIsTakenO;

    std::vector<std::string> isTakenX;
    std::vector<std::string> isTakenO;
    
    //Attribute für Valide Rows and cols
    std::vector<char> vRows;
    std::vector<char> vCol;



public:
    Board();

    // Method for generating the Playboard in a given size  (Standard should be 2Xrows and 2 Yrows)
    void generatePlayboard();


    void updatePlayboard(std::string input, bool PlayerOne);


    // Get Methods

    std::vector<std::string> getIsTaken();
    std::vector<std::string> getIsTakenX();
    std::vector<std::string> getIsTakenO();
    std::vector<std::vector<std::string>> getvPlayboard();

        // Methods for Getting Valid Row and Cols
    std::vector<char>getValidRows();
    std::vector<char>getValidCols();



    // Set Methods

    std::vector<std::string> addItemtoIsTakenX(std::string itemToAdd);
    std::vector<std::string> addItemtoIsTakenO(std::string itemToAdd);
    bool saveCurrentPlayboard();
    bool resetSavedPlayboard();

    void printBoard();

    // Calculate Methods

    //Methods to calculate ValidRows and Collumns
    void validRows();
    void validCol();

    std::vector<std::string> validRowsStr();
    std::vector<std::string> validColStr();
    

    
};

