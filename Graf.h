

#ifndef TEST0X2_GRAF_H
#define TEST0X2_GRAF_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <fstream>


struct Edge{

    int source;
    int target;
    int weight;
};

template <class Type,int MAXIMUM>
class Graf {
protected:
    Type labels[MAXIMUM];
    int VertexCount = 0;

public:
    Graf()= default;
    ~Graf()= default;

    virtual void addVertex(const Type& value) = 0;
    virtual void addEdge(int source, int target, int value) = 0;
    virtual void removeEdge(int source, int target) = 0;
    virtual void fill(double density,int maxValue) = 0;
    virtual void print() = 0;
    virtual Type& operator [] (int vertex) = 0;
    virtual Type operator [] (int vertex)const = 0;
    int size()const{
        return this->VertexCount;
    };
    Type GetVertex(int vertex)const{
        return this->labels[vertex];
    };
    virtual bool isEdge(int source, int target) = 0;
    virtual std::vector<int> neighbours(int vertex)const = 0;




};


#endif //TEST0X2_GRAF_H
