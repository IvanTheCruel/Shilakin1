#include <station.h>
using namespace ITC;

int station::sId = 0;
int station::quantity = 0;
int station::quantity_in_work = 0;

station::station():id(sId++){
    name="basic station "+std::to_string(id);
    efficiency =  78.22;
    quantity++;
    return;
}

station::station(bool change):station::station(){
    if (!change) return;
    else {
        std::cout << "name station\n";
        getline(std::cin,name);
        efficiency = check_idiot("efficiency");
        std::string a = check_idiot(ITC::yes,"if this station in work?");
        for (size_t i = 0; i < ITC::yes.size(); i) {
            if (ITC::yes[i] == a) {
                quantity_in_work++;
                me_in_work = true;
            }
            i+=2; //каждый четный элемент это правда
        }
    }
    return;
}

int station::get_id() const{
    return id;
}


station::~station(){
    std::cout<<"station id"<<id<<" is destructured"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const station& my_st)
{
    std::string temp = "is";
    if (!my_st.me_in_work) temp = "not";
    os << "\nstation id" << my_st.get_id() << " 'called "+ my_st.name
       << "\n"+temp+" in work\nefficiency score:\t" << my_st.efficiency
       << "\nall stations count:\t" << my_st.quantity
       << "\nstations in work:\t"<< my_st.quantity_in_work << "\n\n";
    return os;
}
