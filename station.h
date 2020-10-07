#pragma once

#include <check_idiot.h>

class ITC::station
{
private:
    static int sId;
    int id;
public:
    std::string name;
    static int quantity;
    static int quantity_in_work;
    double efficiency;
    //bool under_repair = false;
    bool me_in_work = false;

    int get_id() const;
    static int get_max_id();
    static void kill_sId();
    void set();
    void on();
    void off();

    station();
    station(bool);
    station(std::ifstream&);
    ~station();
};

std::ostream& operator<<(std::ostream&, const ITC::station&);
//аналогично pipe
std::ofstream& operator<<(std::ofstream&, const ITC::station&);
std::ifstream& operator>>(std::ifstream&, ITC::station&);

