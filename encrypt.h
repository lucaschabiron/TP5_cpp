#pragma once
#include <string>

class Encrypt
{
protected:
    std::string _plain;
    std::string _cipher;
    std::string _decoded;

public:
    Encrypt();
    std::string plain();
    std::string cipher();
    virtual void encode() = 0;
    virtual void decode() = 0;
    std::string decoded();
    void setCipher(std::string cipher);
    void setPlain(std::string plain);
};
