#pragma once
bool exitCond();
void InputClean();

template <typename t>
void print(t& text) {

    std::cout << text << std::endl;

}
std::vector<std::string> splitstring(const std::string& profileData, char seperator);
bool isWhitespace(unsigned char c);


std::vector<std::vector<std::string>> searchForNames();

std::vector<std::vector<std::string>> match(std::vector<std::string> searchFileNames, std::vector<std::string> SearchFilePaths, std::vector<std::string> materialList);

std::vector<std::string> CollectMaterialList();