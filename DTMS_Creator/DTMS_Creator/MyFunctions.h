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

std::vector<std::vector<std::string>> match(const std::vector<std::string>& searchFileNames, const std::vector<std::string>& SearchFilePaths, const std::vector<std::string>& materialList);

std::vector<std::string> CollectMaterialList();

void saveDTMS(std::vector<std::vector<std::string>> inputLists);