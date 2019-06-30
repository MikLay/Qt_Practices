#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <QString>
#include<bits/stdc++.h>
using namespace std;




class Person
{
private:
    vector <string> _phones;
    string _name;
    static vector<string> _nameList;
    static vector<string> _defaultPhones;

public:
    Person(string name):_name(name){}
    string getName(){return _name;}
    const char* name(){
        return _name.c_str();
    }
    static Person generatePerson(){
        auto it = _nameList.begin();
        std::advance(it, rand() % _nameList.size());
        string name = *it;
       return Person(name);
    }
};

vector <string> Person::_nameList = {"Rodney Blackmore",
                                     "Tanner Justice",
                                     "Ollie Rooney",
                                     "Mali Legge",
                                     "Levison Barry",
                                     "Usamah Kirkland",
                                     "Hajra Hamilton",
                                     "Declan Goodwin",
                                     "Eira Yu",
                                     "Manraj Nixon",
                                     "Yehuda Travers",
                                     "Joel Rosales",
                                     "Enrico Connelly",
                                     "Rea Hall",
                                     "Corrie Montes",
                                     "Shelbie Johns",
                                     "Atlanta Bell",
                                     "Benjamin Parsons",
                                     "Kye Higgs",
                                     "Reema Hook"};
#endif // PERSON_H
