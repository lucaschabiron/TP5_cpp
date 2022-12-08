#pragma once
#include "encrypt.h"
#include <string>

class Enigma : public Encrypt
{
private:
    std::string _rotor;
    std::string _rotor2;
    std::string useRotor(std::string rotor, std::string text);
    void reverseRotor(std::string rotor);
    char goThroughRotor(std::string rotor, char c);
    std::string rotateRotor(std::string rotor);
    char goBackThroughRotor(std::string rotor, char c);

public:
    Enigma();
    void encode();
    void decode();
    std::string rotor1();
    std::string rotor2();
    void setRotor1(std::string rotor);
    void setRotor2(std::string rotor);
    void setPlain(std::string plain);
};