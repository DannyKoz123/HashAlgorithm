#include "HashAlgorithm.hpp"
// #include "XOREncryptor.hpp"
// #include "RandomEncryption.hpp"
// #include "RSARandomEncryption.hpp"

int main() {
    std::cout << "Hash Implementation" << std::endl;
    std::string input_string = "jacob";
    
    std::cout << "HashV1(" + input_string + "): " << HashV1(input_string) << std::endl << std::endl;
    std::cout << "HashV2(" + input_string + "): " << HashV2(input_string) << std::endl << std::endl;
    std::cout << "HashV3(" + input_string + "): " << HashV3(input_string) << std::endl << std::endl;

    // XOREncryptor my_encryptor = XOREncryptor("AlphabetSoup", "qwerty");
    // my_encryptor.FixPassword();
    // my_encryptor.Encrypt();
    // std::cout << "PlainText: " << my_encryptor.GetPlainText() << std::endl;
    // std::cout << "Password: " << my_encryptor.GetPassword() << std::endl;
    // std::cout << "EncryptedText: " << my_encryptor.GetEncryptedText() << std::endl;
    
    // // Adnan Noorullah
    // // Random Encryption:
    // std::string string_file = "Encryption.txt";
    // RandomEncryption r;
    // r.ReadFromFile(string_file);
    // r.Encrypt();
    // // RSA Random Encryption:
    // RSARandomEncryption rsa;
    // rsa.ReadFromFile(string_file);
    // rsa.value = 5;
    // rsa.new_int = 7;
    // rsa.CheckPrime(23);
    // rsa.Normalize(3);
    // rsa.EncryptionKey();
    // rsa.Encrypt();
    // rsa.Decrypt();
    return 0;
}
