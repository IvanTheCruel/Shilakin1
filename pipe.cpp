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

        under_repair = ITC::check_ans("under repair?");

        return;
    }
}

pipe::pipe(std::ifstream& ifs):id(sId++){
    using namespace std;
    ifstream fin;
    string str;


    getline(ifs, str, '|');//взяли id

    getline(ifs, str, '|');
    length=stod(str);

    getline(ifs, str, '|');
    diameter=stod(str);

    getline(ifs, str, '|');
    if (str == ITC::yes[0]) under_repair=true;
    else under_repair=false;
//    cout<<str;
//    getline(ifs, str, '|');
//    cout<<str;

    return;
}



void pipe::set(){
    length=check_idiot("length");
    diameter=check_idiot("diameter");

    under_repair = ITC::check_ans("under repair?");

    return;
}


int pipe::get_id() const{
    return id;
}

int pipe::get_max_id(){
    return pipe::sId;
}

void pipe::kill_sId(){
    pipe::sId = 0;
    return;
}

pipe::~pipe(){
    std::cout<<"pipe id"<<id<<" is destructured"<<std::endl;
}

std::ostream& operator<<(std::ostream& os, const pipe& mypipe){

    std::string temp = "is";
    if (!mypipe.under_repair) temp = "not";
    os << "\npipe id" << mypipe.get_id()
       << "\n"+temp+" under repair\nlength:\t\t" << mypipe.length
       << "\ndiameter:\t"<< mypipe.diameter << "\n\n";
    return os;
}

std::ofstream& operator<<(std::ofstream& ofs, const pipe& mypipe){

    using namespace std;
    string a = ITC::yes[1];
    if (mypipe.under_repair) a = ITC::yes[0];
    string ans = to_string(mypipe.get_id())+"|"+to_string(mypipe.length)
            +"|"+to_string(mypipe.diameter)+"|"+a+"|\n";
    ofs << ans;
    return ofs;
}
