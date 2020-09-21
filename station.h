#pragma once

#include <string>
#include <iostream>

struct station
{
public:
    static int id;

    std::string name;
    static int quantity;
    static int quantity_in_work;
    float efficiency;
    bool under_repair = false;

    station();
    ~station();
};
