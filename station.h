#pragma once

#include <check_idiot.h>

struct ITC::station
{
private:
    static int sId;
    int id;
public:
    std::string name;
    static int quantity;
    static int quantity_in_work;
    float efficiency;
    //bool under_repair = false;
    bool me_in_work = false;

    int get_id() const;
    void set();
    void on();
    void off();

    station();
    station(bool);
    ~station();
};

std::ostream& operator<<(std::ostream&, const ITC::station&);
//аналогично pipe


