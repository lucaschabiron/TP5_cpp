#include <iostream>
#include "encrypt.h"
#include "enigma.h"

int main()
{
    while (true)
    {
        std::cout << "1. Encode" << std::endl;
        std::cout << "2. Decode" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Choose an option: ";
        int option;
        std::cin >> option;
        std::cin.ignore();
        if (option == 1)
        {
            std::cout << "Enter the text to encode: ";
            std::string plain;
            std::getline(std::cin, plain);
            Enigma enigma;
            enigma.setPlain(plain);
            enigma.encode();
            std::cout << "Encoded text: " << enigma.cipher() << std::endl;
        }
        else if (option == 2)
        {
            std::cout << "Enter the text to decode: ";
            std::string cipher;
            std::getline(std::cin, cipher);
            Enigma enigma;
            enigma.setCipher(cipher);
            enigma.decode();
            std::cout << "Decoded text: " << enigma.decoded() << std::endl;
        }
        else if (option == 3)
        {
            break;
        }
        else
        {
            std::cout << "Invalid option" << std::endl;
        }
    }

    return 0;
}