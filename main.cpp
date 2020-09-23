#include <iostream>
#include <station.h>
#include <pipe.h>
using namespace std;

int main(){
    using namespace ITC;

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
        {
            vector<string> temp = {"add_new","delete_old"};
            if("delete_old" == check_idiot(temp,"add new from file to exisiting or delete old?")){
                pipes.clear();
                stations.clear();
                pipe::kill_sId();
                station::kill_sId();
            }
            for(int i = 0; i<ITC::max_row("pipes.txt"); i++){
                pipes.emplace_back("pipes.txt",i);
            }
            for(int i = 0; i<ITC::max_row("stations.txt"); i++){
                stations.emplace_back("stations.txt",i);
            }
        }
            break;
        case '0':
            cnt = false;
            break;
        }

    }

    return 0;
}
