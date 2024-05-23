#pragma once
#include <string>
#include <vector>
#include "contstants.h"

class Translator {
private:
    const std::string digits = FORNUMBER;
    const std::string brackets = BRACKETS;

    std::string input;
    
    std::string join(std::vector<std::string>& parts);
public:
    Translator(const std::string& input);

    std::string translate();
};
