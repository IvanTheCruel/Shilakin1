#include <pipe.h>
using namespace ITC;

int pipe::sId = 0;

pipe::pipe():id(sId++){
    length = 100;
    diameter = 2.5;
}

pipe::pipe(bool change):pipe::pipe(){
    if (!change) return;
    else {
        length=check_idiot("length");
        diameter=check_idiot("diameter");
        std::string a = check_idiot(ITC::yes,"under repair");
        for (size_t i = 0; i < ITC::yes.size(); i) {
            if (ITC::yes[i] == a) under_repair = true;
            i+=2; //каждый четный элемент это правда
        }
        return;
    }
}


pipe::~pipe(){
    std::cout<<"p:"<<id<<std::endl;
}

const int pipe::get_id(){
    return id;
}


std::ostream& operator<<(std::ostream& os, const pipe& mypipe)
{
    os << mypipe.get_id();
    return os;//itos(
}
