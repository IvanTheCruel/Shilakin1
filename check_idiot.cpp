#include <check_idiot.h>
using namespace std;

void ITC::check_idiot(vector<string> a, string name_element){

    cout << "Enter " << name_element << "(";
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i];
        if(i+1 < a.size()) cout << "/";
    }
    cout << ")\n";
    //перечисляем подходящие значения


    string n;                         //ввод пользователя
    bool idiot = true;                //по умолчанию пользователь идиот
    getline(cin,n);

    for (size_t i = 0; i < a.size() && idiot; i++){
        if (n == a[i]) idiot = false; //если ответ пользователя совпадает с желаемым, он не идиот
    }

    if(idiot){
        cout << "ERROR: wrong value!\n";
        ITC::check_idiot(a, name_element); //если пользователь все же идиот, просим его ввести еще раз
    } else {
        return;
    }



}
