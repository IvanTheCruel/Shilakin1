#include <iostream>
#include <station.h>
#include <pipe.h>
using namespace std;

int main(){
    using namespace ITC;

    vector<pipe> pipes;
    vector<station> stations;








    while(1){

        switch(menu()){
        case 0:
            return 0;
            break;
        case 1:
            pipes.emplace_back();
            break;
        case 2:
            stations.emplace_back();
            break;
        case 3:
            for (auto p: pipes) {
                cout << p;
            }
            for (auto s: stations) {
                cout << s;
            }
            break;
        case 4:
        {
            size_t id = check_idiot("enter ID");
            if(id > pipe::get_max_id()) cout<<"no pipe with such ID\n";
            else pipes[id].set();
            break;
        }
        case 5:
        {
            size_t id = check_idiot("enter ID");
            if(id > station::get_max_id()) cout<<"no pipe with such ID\n";
            else if(check_ans("want to edit all parameters?"))
                stations[id].set();
            else if (check_ans("is station on?"))
                stations[id].on();
            else
                stations[id].off();
            break;
        }
        case 6:
        {
            ofstream fout;
            fout.open("newbase.txt");
            if (fout.is_open()){
                for (size_t i = 0; i < stations.size(); i++) {
                    fout << stations[i];
                }
                for (size_t i = 0; i < pipes.size(); i++) {
                    fout << pipes[i];
                }
                fout.close();
            } else cout<<"ERROR:file isn't open!";
            break;
        }
        case 7:
        {
            ifstream fin;
            fin.open("newbase.txt");
            if (fin.is_open()){
                char t;
                string temp;
                pipes.clear();
                stations.clear();
                pipe::kill_sId();
                station::kill_sId();
                fin >> t;
                while(t != 'e'){
                    if (t=='S') {
                        stations.emplace_back(fin);
                    } else if (t=='P') {
                        pipes.emplace_back(fin);
                    }
                    fin >> t;
                }
            } else cout<<"ERROR:file isn't open!";
            fin.close();
            break;
        }
        }
    }


    return 0;
}
