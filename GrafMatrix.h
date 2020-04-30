

#ifndef TEST0X2_GRAFMATRIX_H
#define TEST0X2_GRAFMATRIX_H

#include <cassert>
#include "Graf.h"


template <class Type, int MAXIMUM>
class GrafMatrix : public Graf<Type,MAXIMUM> {
private:
    int adjacencyMatrix [MAXIMUM][MAXIMUM]{};

public:
    explicit GrafMatrix()= default;
    ~GrafMatrix()= default;

    void addVertex(const Type& value){
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

    };
    void addEdge(int source, int target, int value = 1){
        assert(source < this->size() && target < this->size());
        adjacencyMatrix[source][target] = value;
    };

    void removeEdge(int source, int target){
        assert(source < this->size() && target < this->size());
        adjacencyMatrix[source][target] = 0;

    };
    void fill(double density,int maxWeight = MAXIMUM){
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
    };
    void print(){
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
    };
    int getEdge(int source, int target)const{
        assert(source <this->size() && target <this->size());
        return this->adjacencyMatrix[source][target];
    };
    Type& operator [] (int vertex){
        assert(vertex < this->size());
        return this->labels[vertex];
    };
    Type operator [] (int vertex)const{

        assert(vertex < this->size());
        return this->labels[vertex];
    };

    //GrafMatrix &operator =(GrafList<Type,MAXIMUM> &G);
    bool isEdge(int source, int target){
        assert(source < this->size() && target < this->size());
        bool isAnEdge = adjacencyMatrix[source][target];
        return isAnEdge;
    };
    std::vector<int> neighbours(int vertex)const{
        assert(vertex < this->size());
        std::vector<int> vertexNeighbours;
        for(int it = 0; it < this->size();it++){
            if(adjacencyMatrix[vertex][it]!=0){
                vertexNeighbours.push_back(it);
            }
        }
        return vertexNeighbours;
    };
    int CopyFromFile(const std::string &path){
        std::fstream file;
        file.open(path, std::ios::in | std::ios::out);
        int a,b,c, start = 0;
        std::string GraphData;
        int k=0;
        while (file>>a) {
            if(k==0){
                file>>b;
                file>>c;
                start = c;
                assert(a <=b*b && b<=MAXIMUM);
                for(int i=0;i<b;i++)
                {
                    this->addVertex(i);
                }}
            else{
                file>>b;
                file>>c;
                assert(a<this->size() && b<this->size());
                this->addEdge(a,b,c);
            }
            k++;
        }

        return start;
    };

};



#endif //TEST0X2_GRAFMATRIX_H
