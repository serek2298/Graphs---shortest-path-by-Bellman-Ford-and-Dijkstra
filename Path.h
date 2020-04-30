//
// Created by Mirek on 30.04.2020.
//

#include <vector>
#include "MyVec.h"
#ifndef TEST0X2_PATH_H
#define TEST0X2_PATH_H

 struct Path{
    int vertex;
    int value;
    MyVec<int> road;
    bool operator <(const Path &P1)const {return value<P1.value;}
    bool operator >(const Path &P1)const {return value>P1.value;}
};

#endif //TEST0X2_PATH_H
