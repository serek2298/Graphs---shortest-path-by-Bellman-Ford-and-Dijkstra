

#include <cassert>
#include <cstdlib>
#include "GrafList.h"


template<typename Type, int MAXIMUM>
void GrafList<Type, MAXIMUM>::addVertex(const Type &value) {
    assert(this->size() < MAXIMUM);
    if(sizeof(Type) == sizeof(char))this->labels[this->VertexCount]  = value+65;
    else this->labels[this->VertexCount]  = value;
    this->VertexCount++;

}

template<typename Type, int MAXIMUM>
void GrafList<Type, MAXIMUM>::addEdge(int source, int target, int value) {
    assert(source<this->size() && target < this->size() && value > 0); //dla djikstry maja byc nie ujemne + 0 to brak krawędzi
    Edge E = {source,target,value};
    this->Edges.push_back(E);
}

template<typename Type, int MAXIMUM>
void GrafList<Type, MAXIMUM>::removeEdge(int source, int target) {
    assert(source<this->size() && target < this->size());
    for(int i = 0;i<this->Edges.size();i++){
        if(this->Edges.at(i).source  == source && this->Edges.at(i).target == target) {
            this->Edges.erase((Edges.begin() + i));
            this->VertexCount--;
        }
    }
}

template<typename Type, int MAXIMUM>
void GrafList<Type, MAXIMUM>::fill(double density, int maxValue) {
    assert(density <=1 && density >= 0);
    while(this->size()<MAXIMUM)
    {
        int i= this->VertexCount;
        this->addVertex(i);
    }
    int n = this->size()*(this->size()-1);
    int EdgesToCreate = (int)(n * density);
    while(EdgesToCreate>0){
        int weight = std::rand()%maxValue + 1;
        int a = std::rand()%MAXIMUM, b = std::rand()%MAXIMUM;
        if(!this->isEdge(a,b)  && a!=b) //nie chcemy cykli jednoelementowych skoro nie są ujemne i tak zostaną pominięte.
        {
            this->addEdge(a, b, weight);
            EdgesToCreate--;
        }
    }
}

template<typename Type, int MAXIMUM>
void GrafList<Type, MAXIMUM>::print() {
    std::cout<<"\t\t\tEDGES\n";
std::cout<<"\tLABELS\tSOURCE\tTARGET\tWEIGHT\n";
int l =0,e = 0;
while(l <this->size() || e < this->Edges.size()){
    std::cout<<"\t";
    if(l < this->size()){
        std::cout<<this->labels[l];
        l++;
    }std::cout<<"\t";
    if(e<Edges.size()){
        std::cout<<this->Edges.at(e).source;
        std::cout<<"\t";
        std::cout<<this->Edges.at(e).target;
        std::cout<<"\t";
        std::cout<<this->Edges.at(e).weight;
        std::cout<<"\t";
        e++;
    }std::cout<<"\n";

}
}

template<typename Type, int MAXIMUM>
bool GrafList<Type, MAXIMUM>::isEdge(int source, int target) {
    int a=0;
    for(int i = 0;i<this->Edges.size();i++){
        if(this->Edges.at(i).source == source && this->Edges.at(i).target == target)
            a++;
    }return a;
}

template<typename Type, int MAXIMUM>
Type &GrafList<Type, MAXIMUM>::operator[](int vertex) {
    assert(vertex < this->size());
    return this->labels[vertex];
}

template<typename Type, int MAXIMUM>
Type GrafList<Type, MAXIMUM>::operator[](int vertex) const {
    assert(vertex < this->size());
    return this->labels[vertex];
}


template<typename Type, int MAXIMUM>
std::set<int> GrafList<Type, MAXIMUM>::neighbours(int vertex) const
{
    std::set<int> Vs;
    for(auto E : Edges){
        if(E.source == vertex){
         Vs.insert(E.target);
        }
    }

    return Vs;
}

template<typename Type, int MAXIMUM>
std::vector<Type> GrafList<Type, MAXIMUM>::ShortestPath(int source, int target) {

    return std::vector<Type>();
}

template<typename Type, int MAXIMUM>
std::vector<Type> GrafList<Type, MAXIMUM>::ShortestPath(int source) {

    return std::vector<Type>();
}


template<typename Type, int MAXIMUM>
GrafList<Type,MAXIMUM> &GrafList<Type, MAXIMUM>::operator=(GrafMatrix<Type, MAXIMUM> &G) {

   assert(G.size()<=MAXIMUM);
    for(int i = 0;i<G.size();i++){
        this->addVertex(G.GetVertex(i));
    }
    for(int i = 0; i<G.size();i++){
        for(int j = 0; j<G.size();j++){
            if(G.GetEdge(i,j) > 0)this->addEdge(i,j,G.GetEdge(i,j));
        }
    }
    return *this;
}


template<typename Type, int MAXIMUM>
GrafList<Type, MAXIMUM>::~GrafList() = default;
template<typename Type, int MAXIMUM>
GrafList<Type, MAXIMUM>::GrafList() = default;

