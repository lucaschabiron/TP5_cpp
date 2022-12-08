#include "encrypt.h"

Encrypt::Encrypt()
{
    _plain = "HELLO";
    _cipher = "";
}

std::string Encrypt::plain()
{
    return _plain;
}

std::string Encrypt::cipher()
{
    return _cipher;
}

std::string Encrypt::decoded()
{
    return _decoded;
}

void Encrypt::setCipher(std::string cipher)
{
    _cipher = cipher;
}
