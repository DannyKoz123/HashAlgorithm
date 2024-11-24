#include "XOREncryptor.hpp"

using namespace std;

XOREncryptor::XOREncryptor(std::string message, std::string key){
    text = message;
    password = key;
}

XOREncryptor::XOREncryptor(std::string file_name) {
    string line;
    ifstream my_stream(file_name);
    if(!my_stream.is_open()) {
        throw std::runtime_error("File could not be opened!");
    }
    getline(my_stream, line);
    password = line;
    while(getline(my_stream, line)) {
        text.append(line);
        }
    my_stream.close();
}

void XOREncryptor::FixPassword(){
    // Password needs to be same length as message for XOR encryption to work, but this is impractical in most situations.
    // Instead, password is added to itself recursively until the lengths match:
    if(password.length() == text.length()){
        return;
    }
    if(password.length() > text.length()){
        password = password.substr(0, text.length());
        return;
    }
    password += password;
    FixPassword();
}

void XOREncryptor::Encrypt(){
    for(int i = 0; i < (int)text.length(); i++){
        text[i] = text.at(i) ^ password.at(i);
    }
}


std::string XOREncryptor::GetPassword(){
    return password;
}

std::string XOREncryptor::GetText(){
    return text;
}