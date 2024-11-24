#include "RandomEncryption.hpp"
// clang-format off
// Using the Caeser Cypher Algorithm (Super Simple Encryption/Decryption):
// The Caeser Cypher Algorithm uses a random key value 
// for encryption and decryption

void RandomEncryption::ReadFromFile(std::string file_name) {
    // This will be used to read the string from the file
    std::string line;
    std::ifstream original_file(file_name);
    if(!original_file.is_open()) {
        throw std::runtime_error("The file is not open!");
    } else {
        while(std::getline(original_file,line)) {
            input.append(line);
            if(original_file.eof()) {
                break;
            }
        }
    }
    original_file.close();
}

void RandomEncryption::Encrypt() {
    // This function will perform both the encryption and decryption
    // Random number generator
    srand((unsigned) time(0));
    // Generate a random number between 1 and 100
    // For the purposes of this program:
    int random_number = rand();
    // std::cout << random_number << std::endl; 
    // Just to test if random number is generated
    // Now use the random number to encrypt the original message
    for(int i = 0; input[i] != '\0'; ++i) {
        input[i] += random_number;
    }
    std::cout << "Encrypted String: " << input << std::endl;
    // Decryption:
    for(int j = 0; input[j] != '\0'; ++j) {
        input[j] -= random_number;
    }
    std::cout << "Decrypted String: " << input << std::endl;
}

// clang-format on
