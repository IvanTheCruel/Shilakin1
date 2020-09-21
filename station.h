#pragma once

#include <check_idiot.h>

struct ITC::station
{
public:
    static int sId;
    int id;

    std::string name;
    static int quantity;
    static int quantity_in_work;
    float efficiency;
    bool under_repair = false;

    station();
    ~station();
};
