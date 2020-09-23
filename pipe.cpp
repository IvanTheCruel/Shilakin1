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

pipe::pipe(std::string link, int _id):id(sId++){
    using namespace std;
    ifstream fin;
    string str;

    if (check_id(link,_id)) {
        fin.open(link);
        getline(fin, str, '|');//взяли id первого
        while(stoi(str)!=_id && !fin.eof()){ //продолжаем проверять id пока не найдем нужный или найдем конец конец файла
            getline(fin, str); //пропускам не нужную строку
            getline(fin, str, '|'); //опять берем id
        }

        getline(fin, str, '|');
        length=stof(str);
        getline(fin, str, '|');
        diameter=stof(str);
        getline(fin, str, '|');
        if (str == "y") under_repair=true;
        else under_repair=false;

        fin.close();
    }
    else {
        cout<<"ID not found! Founded basic pipe instead\n";
        length = 100;
        diameter = 2.5;
    }
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
    string a = "n";
    if (mypipe.under_repair) a = "y";
    string ans = to_string(mypipe.get_id())+"|"+to_string(mypipe.length)
            +"|"+to_string(mypipe.diameter)+"|"+a+"|\n";
    ofs << ans;
    return ofs;
}
