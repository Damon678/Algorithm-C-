//
// Created by 王守正 on 2020-02-07.
//

#ifndef SORTS_STUDENT_H
#define SORTS_STUDENT_H

#include <iostream>
using namespace std;

struct Stuedent{
    int score;
    string name;

    bool operator >(const Stuedent& otherStudent){
        return this->score!=otherStudent.score ?this->score>otherStudent.score:this->name>otherStudent.name;
    }

    friend ostream& operator <<(ostream &os, const Stuedent &stuedent){

        os<<"Student:"<<stuedent.name<<" "<<stuedent.score<<endl;
        return os;
    }
};

#endif //SORTS_STUDENT_H
