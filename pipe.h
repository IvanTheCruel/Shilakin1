#pragma once

#include <check_idiot.h>

struct ITC::pipe
{
    friend std::ostream& operator<<(std::ostream&, const ITC::pipe&); //взял из своего старого проекта, откуда брал тогда не помню
    //переопределяем оператор вывода, позволив ему общаться со всеми частями нашей структуры
private:
    static int sId;
    int id;

public:
    float length, diameter;
    bool under_repair = false;
    int get_id();

    pipe();
    pipe(bool);
    ~pipe();
};


