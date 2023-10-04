#pragma once
bool exitCond();
std::string InputClean();

template <typename t>
void print(t& text) {

    std::cout << text << std::endl;

}
std::vector<std::string> splitstring(const string& profileData);
bool isWhitespace(unsigned char c);