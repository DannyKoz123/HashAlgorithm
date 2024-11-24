#ifndef XORENCRYPTOR_HPP
#define XORENCRYPTOR_HPP

#include <iostream>
#include <fstream>
#include <string>

class XOREncryptor{
    public:
        //Constructors
        XOREncryptor(std::string message, std::string key);
        XOREncryptor(std::string file_name); // format is asumed to be a line containing the password, and then the message.

        //Encryptor and helper functions
        void FixPassword();
        void Encrypt();

        //Getters
        std::string GetText();
        std::string GetPassword(); //for catch2 testing, doesn't make sense to actually include


    private:
        std::string text;
        std::string password;
};

#endif