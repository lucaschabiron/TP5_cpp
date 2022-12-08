#include "enigma.h"
#include <iostream>

Enigma::Enigma()
{
    _plain = "HELLO WEEE IZKVGAEJBKAEOVOMVEJJB KJBJHJKBLAEBABEJ";
    _cipher = "";
    _decoded = "";
    _rotor = "AZERTYUIOPQSDFGHJKLMWCXVBN";
    _rotor2 = "ZAERYTUIOPQSFDGHJKLMWCXVNB";
}

// SETTERS
char Enigma::goThroughRotor(std::string rotor, char c)
{
    // RETURN THE CORRESPONDING CHAR IN THE ROTOR
    return rotor[c - 'A'];
}

void Enigma::setPlain(std::string plain)
{
    _plain = plain;
}

void Enigma::setRotor1(std::string rotor)
{
    _rotor = rotor;
}

void Enigma::setRotor2(std::string rotor)
{
    _rotor2 = rotor;
}

// GETTERS
//
//
//

std::string Enigma::rotor1()
{
    return _rotor;
}

std::string Enigma::rotor2()
{
    return _rotor2;
}

std::string Enigma::rotateRotor(std::string rotor)
{
    rotor.insert(0, 1, rotor[rotor.length() - 1]);
    rotor.pop_back();
    return rotor;
}

//
//
//
// ENCODE

void Enigma::encode()
{
    // ENCODE THE PLAIN TEXT
    for (int i = 0; i < 24; i++)
    {
        int iteration = 0;
        std::string result = "";
        for (int i = 0; i < _plain.length(); i++)
        {
            // USE ROTOR TO ENCODE THE CHARACTER AND ADD IT TO THE RESULT
            char c = _plain[i];
            if (c >= 'A' && c <= 'Z')
            {
                result += goThroughRotor(_rotor2, goThroughRotor(_rotor, c));
                _rotor = rotateRotor(_rotor);
                if (iteration == 26)
                {
                    _rotor2 = rotateRotor(_rotor2);
                    iteration = 0;
                }
                else
                    iteration += 1;
            }
            else
            {
                result += c;
            }
            iteration += 1;

            // ROTATE THE ROTOR
        }
        _cipher = result;
    }
}

char Enigma::goBackThroughRotor(std::string rotor, char c)
{
    // RETURN THE CORRESPONDING CHAR IN THE ROTOR
    for (int i = 0; i < rotor.length(); i++)
    {
        if (rotor[i] == c)
        {
            return i + 'A';
        }
    }
    return c;
}

//
//
//
// DECODE
void Enigma::decode()
{
    // DECODE THE PLAIN TEXT
    for (int i = 0; i < 24; i++)
    {
        int iteration = 0;
        std::string result = "";
        for (int i = 0; i < _cipher.length(); i++)
        {
            // USE ROTOR TO DECODE THE CHARACTER AND ADD IT TO THE RESULT
            char c = _cipher[i];
            if (c >= 'A' && c <= 'Z')
            {
                result += goBackThroughRotor(_rotor, goBackThroughRotor(_rotor2, c));
                _rotor = rotateRotor(_rotor);
                if (iteration == 26)
                {
                    _rotor2 = rotateRotor(_rotor2);
                    iteration = 0;
                }
                else
                    iteration += 1;
            }
            else
            {
                result += c;
            }

            // ROTATE THE ROTOR
        }
        _decoded = result;
    }
}
