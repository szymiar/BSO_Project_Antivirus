#ifndef HASHCALCULATOR_H
#define HASHCALCULATOR_H


#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <openssl/sha.h>
#include <sstream>
#include <stdexcept>
#include <string>

std::string GetFileHash(std::string filename);

#endif
