#include <station.h>
using namespace ITC;

int station::sId = 0;

station::station():id(sId++){

}

station::~station(){
    std::cout<<"s:"<<id<<std::endl;
}
