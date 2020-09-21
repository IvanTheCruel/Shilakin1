#pragma once

#include <check_idiot.h>

struct ITC::pipe
{
public:
    static int sId;
    int id;

    float length, diameter;
    bool under_repair = false;

    pipe();
    ~pipe();
};
