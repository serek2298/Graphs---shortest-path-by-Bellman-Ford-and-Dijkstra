#ifndef TEST0X2_GRAFLIST_H
#define TEST0X2_GRAFLIST_H

#include <cassert>
#include "Graf.h"


template <typename Type,int MAXIMUM>
class GrafList:public Graf<Type,MAXIMUM>  {
private:
    std::vector<Edge> Edges;

public:
    explicit GrafList()= default;
    ~GrafList()= default;




    void addVertex(const Type &value) {
        assert(this->size() < MAXIMUM);
        if(sizeof(Type) == sizeof(char))this->labels[this->VertexCount]  = value+65;
        else this->labels[this->VertexCount]  = value;
        this->VertexCount++;

    };


    void addEdge(int source, int target, int value) {
        assert(source<this->size() && target < this->size() && value > 0); //dla djikstry maja byc nie ujemne + 0 to brak krawędzi
        Edge E = {source,target,value};
        this->Edges.push_back(E);
    }


    void removeEdge(int source, int target) {
        assert(source<this->size() && target < this->size());
        for(int i = 0;i<this->Edges.size();i++){
            if(this->Edges.at(i).source  == source && this->Edges.at(i).target == target) {
                this->Edges.erase((Edges.begin() + i));
                this->VertexCount--;
            }
        }
    }


    void fill(double density, int maxValue = MAXIMUM) {
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


    void print() {
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


    bool isEdge(int source, int target) {
        int a=0;
        for(int i = 0;i<this->Edges.size();i++){
            if(this->Edges.at(i).source == source && this->Edges.at(i).target == target)
                a++;
        }return a;
    }


    Type &operator[](int vertex) {
        assert(vertex < this->size());
        return this->labels[vertex];
    }


    Type operator[](int vertex) const {
        assert(vertex < this->size());
        return this->labels[vertex];
    }



    std::vector<int> neighbours(int vertex) const {
        std::vector<int> Vs;
        for(auto E : Edges){
            if(E.source == vertex){
                Vs.push_back(E.target);
            }
        }

        return Vs;
    }


    std::vector<Type> ShortestPath(int source, int target) {

        return std::vector<Type>();
    }


    std::vector<Type>ShortestPath(int source) {

        return std::vector<Type>();
    }


    void CopyFromFile(const std::string& path) {
        std::fstream file;
        file.open(path, std::ios::in | std::ios::out);
        int a,b,c;
        std::string GraphData;
        int k=0;
        while (file>>a) {
            if(k==0){
                file>>b;
                file>>c;
                assert(a <=b*b && b<=MAXIMUM);
                for(int i=0;i<b;i++)
                {
                    this->addVertex(i);
                }}
            else{
                file>>b;
                file>>c;
                this->addEdge(a,b,c);
            }
            k++;
        }
    }


    int getEdge(int source, int target)const{
        assert(source<this->size() && target < this->size());
        for(int i = 0;i<this->Edges.size();i++){
            if(this->Edges.at(i).source == source && this->Edges.at(i).target == target)return Edges.at(i).weight;
        }return 0;
    }
};


#endif //TEST0X2_GRAFLIST_H
