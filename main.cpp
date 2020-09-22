#include <iostream>
#include <station.h>
#include <pipe.h>
using namespace std;

int main(){
    using namespace ITC;
    pipe p1;
    pipe p2(true);

    station s1(true);
    station s2(false);
    station s3(false);

    //cout << p1 << p2 << s1 << s2 << s3;
    s2.on();
    cout << s2;

    ofstream fout("pipes.txt");
    fout << p1;
    cout << p1;
    fout.close();
    pipe p3("pipes.txt",0);
    cout << p3;


    /*vector<pipe> pipes;
    vector<station> stations;
    string pipes_file="pipes.txt";
    string stat_file="stations.txt";
    while(true){
        int id;

        if (!check_ans("want to do something?")){
            break;
        } else if (check_ans("want to load?")){
            if (check_ans("station?")){
                id = check_idiot("enter id");
                stations.emplace_back(stat_file,id);
            } else if (check_ans("pipe?")){
                id = check_idiot("enter id");
                pipes.emplace_back(pipes_file,id);
            }
        } else if (check_ans("want to create?")){
            if (check_ans("station?")){
                stations.emplace_back(check_ans("want to edit?"));

            } else if (check_ans("pipe?")){
                pipes.emplace_back(check_ans("want to edit?"));

            }
        } else if (check_ans("want to edit?")){
            id = check_idiot("enter id");
            if (check_ans("station?")){
                stations[id].set();
            } else if (check_ans("pipe?")){
                pipes[id].set();
            }
        } else if (check_ans("want to see?")){
            id = check_idiot("enter id");
            if (check_ans("station?")){
                if (id > station::get_max_id()) id = station::get_max_id();
                cout << stations[id];
            } else if (check_ans("pipe?")){
                if (id > pipe::get_max_id()) id = pipe::get_max_id();
                cout << pipes[id];
            }
        } else if (check_ans("want to save?")){
            if (check_ans("station?")){
                fstream fin(stat_file);
                for (auto x: stations) {
                    fin << x;
                }
                fin.close();

            } else if (check_ans("pipe?")){
                fstream fin(pipes_file);
                for (auto x: pipes) {
                    fin << x;
                }
                fin.close();

            }

        }
    }*/

//    station s1;
//    station s2;
//    cout << s1;

//    s1.set();
   //cout << pipes[0];



    return 0;
}
