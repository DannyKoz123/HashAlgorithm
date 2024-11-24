#include "catch.hpp"

#include "XOREncryptor.hpp"
 
 //make tests doesn't work for some reason
 

 //------------------------------------------------------------------------------------------------
 //XOREncryptor tests
TEST_CASE("key fixer", "[FixPassword()]") {
  XOREncryptor my_encryptor = XOREncryptor("TheMostInterestingGroupInTheWorld", "qwerty");
  my_encryptor.FixPassword();
  REQUIRE(my_encryptor.GetPassword() == "qwertyqwertyqwertyqwertyqwertyqe");
}

TEST_CASE("File constructor", "[XOREncryptor(file_name)]"){
  XOREncryptor my_encryptor = XOREncryptor("message.txt");
  REQUIRE(my_encryptor.GetPassword() == "bee");
  REQUIRE(my_encryptor.GetText() == "According to all known laws of aviation, there is no way that a bee should be able to fly.");
}

TEST_CASE("Encryption", "[XOREncryptor.Encrypt()]"){
  XOREncryptor my_encryptor = XOREncryptor("codeiscode", "ABC");
  my_encryptor.FixPassword();
  my_encryptor.Encrypt();
  REQUIRE(my_encryptor.GetText() == "\"-\'$+0\"-\'$");
  my_encryptor.Encrypt();
  REQUIRE(my_encryptor.GetText() == "codeiscode");
}