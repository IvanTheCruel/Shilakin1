#include <pipe.h>
using namespace ITC;

int pipe::sId = 0;

pipe::pipe():id(sId++){}

pipe::~pipe(){
    std::cout<<id<<std::endl;
}
