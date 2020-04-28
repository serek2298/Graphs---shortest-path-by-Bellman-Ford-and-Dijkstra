#ifndef TEST0X2_GRAFLIST_H
#define TEST0X2_GRAFLIST_H
#include "Graf.h"
#include "GrafMatrix.cpp"g

template <typename Type,int MAXIMUM>
class GrafList:public Graf<Type,MAXIMUM>  {
private:
    std::vector<Edge> Edges;

public:
    GrafList();
    ~GrafList();

    void addVertex(const Type& value);
    void addEdge(int source, int target, int value = 1);
    void removeEdge(int source, int target); //jesli jest wiecej krawędzi o zadanych paramtrach - usunie wszystkie
    void fill(double density,int maxWeight = MAXIMUM);//
    void print();
    Type& operator [] (int vertex);
    Type operator [] (int vertex)const;
    GrafList &operator =(GrafMatrix<Type,MAXIMUM> &G);
    bool isEdge(int source, int target);
    std::set<int> neighbours(int vertex)const;//lista wierzchołków do których można dojść z danego wierzchołka
    std::vector<Type> ShortestPath(int source); //do wszystkich
    std::vector<Type> ShortestPath(int source,int target); // do docelowego

};


#endif //TEST0X2_GRAFLIST_H
