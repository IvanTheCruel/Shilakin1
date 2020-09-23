#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>



namespace ITC {
    struct pipe;
    struct station;
    const std::vector<std::string> yes = {"y","n"};//,"Y","N","yes","no","oui","nope"};
    std::string check_idiot(std::vector<std::string>, std::string);
    bool check_ans(std::string);
//    bool check_id(std::string, int);
//    int max_row(std::string);
    double check_idiot(std::string); //просим число
//    bool is_double_or_int(std::string);
}

