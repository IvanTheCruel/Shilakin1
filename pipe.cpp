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


void pipe::set(){
    length=check_idiot("length");
    diameter=check_idiot("diameter");
    std::string a = check_idiot(ITC::yes,"under repair");
    for (size_t i = 0; i < ITC::yes.size(); i) {
        if (ITC::yes[i] == a) under_repair = true;
        i+=2; //каждый четный элемент это правда
    }
    return;
}


int pipe::get_id() const{
    return id;
}

pipe::~pipe(){
    std::cout<<"pipe id"<<id<<" is destructured"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const pipe& mypipe)
{
    std::string temp = "is";
    if (!mypipe.under_repair) temp = "not";
    os << "\npipe id" << mypipe.get_id()
       << "\n"+temp+" under repair\nlength:\t\t" << mypipe.length
       << "\ndiameter:\t"<< mypipe.diameter << "\n\n";
    return os;
}
