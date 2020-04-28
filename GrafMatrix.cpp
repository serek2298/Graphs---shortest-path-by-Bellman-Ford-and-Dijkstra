

#include "GrafMatrix.h"
#include <cassert>


template <typename Type,int MAXIMUM>
void GrafMatrix<Type,MAXIMUM>::addVertex(const Type& value)
{
    assert(this->size() < MAXIMUM);
    int VertexNum = this->VertexCount;
    this->VertexCount++;
    for(int i = 0;i<this->VertexCount;i++)
    {
        adjacencyMatrix[i][VertexNum] = 0; // 0 - brak krawędzi
        adjacencyMatrix[VertexNum][i] = 0; // 0 - brak krawędzi
    }
    if(sizeof(Type) == sizeof(char))this->labels[VertexNum]  = value+65;
        else this->labels[VertexNum]  = value;

}
template <typename Type,int MAXIMUM>
void GrafMatrix<Type,MAXIMUM>::addEdge(int source, int target, int value)
{
    assert(source < this->size() && target < this->size());
    adjacencyMatrix[source][target] = value;
}


template <typename Type,int MAXIMUM>
void GrafMatrix<Type,MAXIMUM>::removeEdge(int source, int target)
{
    assert(source < this->size() && target < this->size());
    adjacencyMatrix[source][target] = 0;

}
template <typename Type,int MAXIMUM>
bool GrafMatrix<Type,MAXIMUM>::isEdge(int source, int target)
{
    assert(source < this->size() && target < this->size());
    bool isAnEdge = adjacencyMatrix[source][target];
    return isAnEdge;
}


template <typename Type,int MAXIMUM>
Type& GrafMatrix<Type,MAXIMUM>::operator[](int vertex)
{
    assert(vertex < this->size());
    return this->labels[vertex];
}

template <typename Type,int MAXIMUM>
Type GrafMatrix<Type,MAXIMUM>::operator[](int vertex)const
{
    assert(vertex < this->size());
    return this->labels[vertex];
}

template <typename Type,int MAXIMUM>
std::set<int> GrafMatrix<Type,MAXIMUM> :: neighbours(int vertex) const
{
    assert(vertex < this->size());
    std::set<int> vertexNeighbours;
    for(int it = 0; it < this->size();it++){
        if(adjacencyMatrix[vertex][it]){
            vertexNeighbours.insert(it);
        }
    }
    return vertexNeighbours;
}

template<typename Type, int MAXIMUM>
void GrafMatrix<Type, MAXIMUM>::fill(double density, int maxWeight) {
    assert(density <=1 && density >= 0);
    while(this->size()<MAXIMUM)
    {
        int i= this->VertexCount;
        this->addVertex(i);
    }
    int n = this->size()*(this->size()-1);
    int EdgesToCreate = (int)(n * density);
    while(EdgesToCreate>0){
        int weight = std::rand()%maxWeight + 1;//waga nie może byc 0 (wtedy nie krawędź nie istnieje)
        int a = std::rand()%MAXIMUM, b = std::rand()%MAXIMUM;
        if(!this->isEdge(a,b)  && a!=b) //nie chcemy cykli jednoelementowych
        {
            this->addEdge(a, b, weight);
            EdgesToCreate--;
        }
    }
}

template<typename Type, int MAXIMUM>
void GrafMatrix<Type, MAXIMUM>::print() {
std::cout<<"PRINTING ADJACENCY MATRIX\n";
    for(int i = 0;i<this->size();i++){
        std::cout<<"\t"<<this->labels[i];
    } std::cout<<"\n";

    for(int i=0;i<this->size();i++){
        std::cout<<this->labels[i];
        for(int j = 0;j<this->size();j++){
            std::cout<<"\t"<<this->adjacencyMatrix[i][j];
        }std::cout<<"\n";
    }
}

template<class Type, int MAXIMUM>
GrafMatrix<Type, MAXIMUM>::GrafMatrix() {
    std::cout <<"GrafM konstr\n";
}

template<class Type, int MAXIMUM>
GrafMatrix<Type, MAXIMUM>::~GrafMatrix() {
    std::cout <<"GrafM destr\n";
}

template<class Type, int MAXIMUM>
int GrafMatrix<Type, MAXIMUM>::GetEdge(int source, int target) const {
    return this->adjacencyMatrix[source][target];
}

template <typename Type,int MAXIMUM>
bool isEdge(int source, int target);

