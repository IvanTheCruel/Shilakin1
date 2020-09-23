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
    vector<string> temp = {"1","0"};
    size_t id = 0; bool cnt = true;
    string ans, tl;
    char test='/';
    ofstream fout;
    ifstream fin;

    cout<<"options: ";
    for (size_t i = 0; i < q.size(); i++){
        cout<<q[i]+'-'+q2[i]+", ";
    }
    cout<<endl;

    //    double n = check_idiot("123");
    //    cout << n;

    while(cnt){

        ans = check_idiot(q, "choose option");

        switch(ans[0]){
        case '0':
            cnt = false;
            break;
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
            if(id > pipe::get_max_id()) cout<<"no pipe with such ID\n";
            else pipes[id].set();
            break;
        case '5':
            id = check_idiot("enter ID");
            if(id > station::get_max_id()) cout<<"no pipe with such ID\n";
            else if(check_ans("want to edit all parameters?"))
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
            fin.open("pipes.txt");
            if (fin.is_open()){
                if("delete_old" == check_idiot(temp,"add new from file to exisiting or delete old?")){
                    pipes.clear();
                    stations.clear();
                    pipe::kill_sId();
                    station::kill_sId();
                }
                while(!fin.eof()){
                    pipes.emplace_back(fin);
//                    cout<<fin.eof();
//                    pipes.emplace_back(fin);
//                    cout<<fin.eof();


//          getline(fin,tl);
//                    cout<<tl;



                }
//                while(!fin.eof( )){
//                    if (fin.eof()) break;
//                    pipes.emplace_back(fin);
//                }
            } else cout<<"ERROR:file isn't open!";
            fin.close();
            break;
        }
    }


    return 0;
}
