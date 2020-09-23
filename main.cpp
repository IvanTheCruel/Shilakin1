#include <iostream>
#include <station.h>
#include <pipe.h>
using namespace std;

int main(){
    using namespace ITC;
/*    setlocale(0, "");
//    pipe p1;
//    pipe p2(true);

//    station s1(true);
//    station s2(false);
//    station s3(false);

//    //cout << p1 << p2 << s1 << s2 << s3;
//    s2.on();
//    cout << s2;

//    ofstream fout("pipes.txt");
//    fout << p1;
//    cout << p1;
//    fout.close();
//    pipe p3("pipes.txt",0);
//    cout << p3; */

    vector<pipe> pipes;
    vector<station> stations;
    vector<string> q = {"1","2","3","4","5","6","7","0"};
    vector<string> q2 = {"add pipe","add station","see all","edit pipe","edit station","save","load","exit"};
    int id = 0; bool cnt = true;
    string ans;
    ofstream fout;
    ifstream fin;

    cout<<"options: ";
    for (size_t i = 0; i < q.size(); i++){
        cout<<q[i]+'-'+q2[i]+", ";
    }
    cout<<endl;

    while(cnt){

        ans = check_idiot(q, "choose option");

        switch(ans[0])
        {
        case '1':
            pipes.emplace_back();
            break;
        case '2':
            stations.emplace_back();
            break;
        case '3':
            for (size_t i = 0; i < pipes.size(); i++) {
                cout << pipes[i];
            }
            for (size_t i = 0; i < stations.size(); i++) {
                cout << stations[i];
            }
            break;
        case '4':
            id = check_idiot("enter ID");
            pipes[id].set();
            break;
        case '5':
            id = check_idiot("enter ID");
            if(check_ans("want to edit all parameters?"))
                stations[id].set();
            else if (check_ans("is station on?"))
                stations[id].on();
            else
                stations[id].off();
            break;
        case '6':
            fout.open("stations.txt");
            for (size_t i = 0; i < stations.size(); i++) {
                fout << stations[i];
            }
            fout.close();
            fout.open("pipes.txt");
            for (size_t i = 0; i < pipes.size(); i++) {
                fout << pipes[i];
            }
            fout.close();
            break;
        case '7':

            break;
        case '0':
            cnt = false;
            break;
        }

    }



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
