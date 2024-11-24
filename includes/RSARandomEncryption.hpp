#ifndef RSARANDOMENCRYPTION_HPP
#define RSARANDOMENCRYPTION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <fstream>

class RSARandomEncryption {
    public:
    void ReadFromFile(std::string file_name);
    int CheckPrime(unsigned long prime_number);
    // Specific for RSA Method: Must check using a prime number
    int Normalize(int val);
    void EncryptionKey();
    void Encrypt();
    void Decrypt();
    private:
    std::string input = "";
    int value; // This integer will be defined in the main file
    int new_int; // This integer will be defined in the main file
    srand((unsigned)time(0));
    int first_number = rand();
    int second_number = first_number + 5;
    int temp[50]; // integer array
    char key_string[100]; 
    // Have to make this like this so that we don't encounter
    // trouble with empty string errors
    // Essentially a string represented as an array of characters
    char check_string[100];
    char encrypted_string[100];
};


#endif
