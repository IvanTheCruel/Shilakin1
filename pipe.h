#pragma once

struct pipe
{
public:
    static int id;
    float length, diameter;
    bool under_repair = false;

    pipe();
    ~pipe();
};
