#ifndef HASHCALCULATOR_H
#define HASHCALCULATOR_H

#include <iostream>
#include <cerrno>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>
#include <openssl/sha.h>

std::string GetFileHash(std::string filename);

#endif
