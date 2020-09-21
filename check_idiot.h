#pragma once

#include <iostream>
#include <string>
#include <vector>



namespace ITC {
    struct pipe;
    struct station;
    const std::vector<std::string> yes = {"Y","N","y","n","yes","no","oui","nope"};
    std::string check_idiot(std::vector<std::string>, std::string);
    float check_idiot(std::string);
    bool is_double_or_int(std::string);
}

