#include <check_idiot.h>
using namespace std;

string ITC::check_idiot(vector<string> a, string name_element){

    cout << "Enter " << name_element << "(";
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
        ITC::check_idiot(a, name_element); //если пользователь все же идиот, просим его ввести еще раз
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
        ITC::check_idiot(name_element); //если пользователь все же идиот, просим его ввести еще раз
    } else {
        return stof(temp);
    }
}


bool ITC::is_double_or_int(string str){
    bool Dbl = true;
    int amount_points = 0;
    //bool find_char;

    for (size_t i = 0; i < str.length() && Dbl && amount_points < 2; i++){
//        find_char = !isdigit(str[i]) || (!(i != 0 && i != str.length()) && (str[i] == '.' || str[i] == ','));
//        if (find_char) Dbl = false;
        Dbl = isdigit(str[i]) || ((i != 0 && i != str.length()-1) && (str[i] == '.' || str[i] == ','));
        if (str[i] == '.' || str[i] == ',') amount_points++;
        //проверяем число на отстутствие букв и несколько точек
    }
    Dbl = Dbl && amount_points < 2;
    return Dbl;
}

//ITC::std::vector<std::string> yes = {"Y","N","y","n","yes","no","oui"};


