#ifndef RANDOMENCRYPTION_HPP
#define RANDOMENCRYPTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>

class RandomEncryption {
    public:
    void ReadFromFile(std::string file_name);
    void Encrypt();
    private:
    std::string input;
};

#endif
