#pragma once
bool exitCond();
void InputClean();

template <typename t>
void print(t& text) {

    std::cout << text << std::endl;

}
std::vector<std::string> splitstring(const std::string& profileData, char seperator);
bool isWhitespace(unsigned char c);