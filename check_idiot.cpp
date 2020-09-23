#include <check_idiot.h>
using namespace std;

string ITC::check_idiot(vector<string> a, string name_element){

    cout << name_element << "(";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i+1 < a.size()) cout << "/";
    }
    cout << ")\n";
    //перечисляем подходящие значения


    string temp;                      //ввод пользователя
    bool idiot = true;                //по умолчанию пользователь идиот
    cin >> temp;
    //getline(cin,temp) можно сломать просто нажав enter

    for (size_t i = 0; i < a.size() && idiot; i++){
        if (temp == a[i]) idiot = false; //если ответ пользователя совпадает с желаемым, он не идиот
    }

    if(idiot){
        cout << "ERROR: wrong value!\n";
        return ITC::check_idiot(a, name_element); //если пользователь все же идиот, просим его ввести еще раз
    } else {
        return temp; //верни значение пользователя
    }
}

float ITC::check_idiot(string name_element){
    cout << "Enter number of " << name_element << endl;
    //Просим число

    string temp;                      //ввод пользователя
    bool idiot = true;                //по умолчанию пользователь идиот
    cin >> temp;
    //getline(cin,temp) можно сломать просто нажав enter

    idiot = !is_double_or_int(temp); //проверяем введенное

    if(idiot){
        cout << "ERROR: wrong value!\n";
        return ITC::check_idiot(name_element); //если пользователь все же идиот, просим его ввести еще раз
    } else {
        return stof(temp);
    }
}

bool ITC::check_ans(std::string q){
    bool tans = false;
    std::string ans = ITC::check_idiot(ITC::yes, q);
    for (size_t i = 0; i < ITC::yes.size(); i) {
        if (ITC::yes[i] == ans) tans = true;
        i+=2; //каждый четный элемент это правда
    }
    return tans;
}

bool ITC::check_id(std::string link, int _id){
    using namespace std;
    ifstream fin;
    string str;
    bool id_is_real = false;

    int num_rows = ITC::max_row(link);

    fin.open(link);
    for(int i = 0; i < num_rows && !id_is_real; i++) {
        getline(fin, str, '|'); //берем id
        id_is_real = stoi(str)==_id; //id существует, если он есть в файл
        getline(fin, str);  //пропускам не нужную строку
    }
    fin.close();

    return id_is_real;
}

int ITC::max_row(std::string link){
    using namespace std;
    ifstream fin(link);

    if(fin.is_open()){
        int num_rows = 0;

        string trash;
        while (getline(fin, trash)) num_rows++;
        fin.close();

        return num_rows;
    }
    else {
        cout << "ERROR: invalid file name!\n";
        return 0;
    }
}

bool ITC::is_double_or_int(string str){
    bool Dbl = true;
    int amount_points = 0;
    //bool find_char;

    for (size_t i = 0; i < str.length() && Dbl && amount_points < 2; i++){
//        find_char = !isdigit(str[i]) || (!(i != 0 && i != str.length()) && (str[i] == '.' || str[i] == ','));
//        if (find_char) Dbl = false;
        Dbl = isdigit(str[i]) || ((i != 0 && i != str.length()-1) && str[i] == '.');
        if (str[i] == '.') amount_points++;
        //проверяем число на отстутствие букв и несколько точек
    }
    Dbl = Dbl && amount_points < 2;
    return Dbl;
}

//ITC::std::vector<std::string> yes = {"Y","N","y","n","yes","no","oui"};


