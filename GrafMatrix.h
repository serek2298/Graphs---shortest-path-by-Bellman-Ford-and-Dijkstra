

#ifndef TEST0X2_GRAFMATRIX_H
#define TEST0X2_GRAFMATRIX_H

#include "Graf.cpp"


template <class Type, int MAXIMUM>
class GrafMatrix :public Graf<Type,MAXIMUM>{
private:
    int adjacencyMatrix [MAXIMUM][MAXIMUM]{};

public:
    GrafMatrix();
    ~GrafMatrix();

    void addVertex(const Type& value);
    void addEdge(int source, int target, int value = 1);

    void removeEdge(int source, int target);
    void fill(double density,int maxWeight = MAXIMUM);
    void print();
    int GetEdge(int source, int target)const;
    Type& operator [] (int vertex);
    Type operator [] (int vertex)const;
    bool isEdge(int source, int target);
    std::set<int> neighbours(int vertex)const;

};


#endif //TEST0X2_GRAFMATRIX_H
