#include <iostream>
#include <station.h>
#include <pipe.h>
using namespace std;

int main()
{
    ITC::pipe Pipe_0;

    ITC::station Station_0(true);
    Station_0.off();
    Station_0.set();
    Station_0.set();



    cout << Pipe_0;
    cout << Station_0;
    return 0;
}
