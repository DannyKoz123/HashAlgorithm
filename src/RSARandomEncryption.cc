#include "RSARandomEncryption.hpp"

void RSARandomEncryption::ReadFromFile(std::string file_name) {
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
int RSARandomEncryption::CheckPrime(unsigned long prime_number) {
    int return_value = -1;
    long int sqrt_prime_number = sqrt(prime_number);
    for(int i = 2; i < sqrt_prime_number + 1; ++i) {
        if(sqrt_prime_number % i != 0) {
            return_value = 1;
        } else {
            return_value = 0;
        }
    }
    return return_value;
}
int RSARandomEncryption::Normalize(int val) {
    int norm = 1;
    while(norm == 1) { // Will always execute until we hit return
        norm = norm + value;
        if(norm % val == 0) {
            int normalized_val = norm/val;
            return normalized_val;
        }
    }
}
void RSARandomEncryption::EncryptionKey() {
    // This function will generate a random encryption key
    // Which will be handy for the encryption
    int key = 0;
    for(int i = 2; i < value; ++i) {
        if(value % i == 0) {
            continue;
        }
        int check_prime = CheckPrime(i);
        if(check_prime == 1) {
            if(i != first_number) {
                if(i != second_number) {
                    key_string[key] = i;
                    check_prime = Normalize(key_string[key]);
                    if(check_prime <= 0) {
                        // do nothing
                    } else {
                        check_string[key] = check_prime;
                        ++key;
                    }
                }
            }
        }
    }   
}
void RSARandomEncryption::Encrypt() {
    int length_of_string = input.length();
    long int e_mech = 0;
    while(e_mech != length_of_string) {
        int p_check = input[e_mech];
        p_check -= 96;
        int key = 1;
        for(int i = 0; i < key; ++i) {
            key *= p_check;
            key = key % new_int;
        }
        temp[e_mech] = key;
        int c_check = key + 96;
        encrypted_string[e_mech] = c_check;
        ++e_mech;
    }
    encrypted_string[e_mech] = -1; // Resetting the value
    // to ensure not encrypting further than necessary
    // Signifies end of encryption
    std::cout << "Here is your RSA-encrypted message: ";
    for(int i = 0; encrypted_string[i] != -1; ++i) {
        std::cout << encrypted_string[i];
        if(encrypted_string[i + 1] == -1) {
            std::cout << std::endl;
        }
    }
}
void RSARandomEncryption::Decrypt() {
    // Do the opposite of what we did in Encrypt
    long int d_mech = 0;
    while(encrypted_string[d_mech] != -1) {
        long int check = temp[d_mech];
        int key = 1;
        for(int i = 0; i < key; ++i) {
            // Closely imitates the previous function
            key *= check;
            key = key % new_int;
        }
        int p_check = key + 96;
        input[d_mech] = p_check;
        ++d_mech;
    }
    input[d_mech] = -1; // Once we leave the loop, dignify end
    std::cout << "Here is the RSA-decrypted message: ";
    for(int i = 0; input[i] != -1; ++i) {
        std::cout << input[i];
        if(input[i + 1] == -1) {
            std::cout << std::endl;
        }
    }
}
