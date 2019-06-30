#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <QString>
#include <QVector>
#include<bits/stdc++.h>
using namespace std;

class Contact {
private:
    QList <QString> _numbers;
    QString _name;

public:
    Contact(QString name,  QList<QString> numbers):_numbers(numbers), _name(name){}
    QString getNumbersQString(){
        QString stringNumbers = "";
        for (QString number: _numbers)
            stringNumbers += number + " \n";
        return stringNumbers;
    }

    //selectors
    QList<QString> phonesToQString() const{
        return _numbers;
    }
    const QString name() const{
        return _name;
    }
};

#endif // PERSON_H
