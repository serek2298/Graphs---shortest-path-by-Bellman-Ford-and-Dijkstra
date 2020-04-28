#include <iostream>

#include "GrafMatrix.h"
#include "Graf.cpp"
#include "GrafMatrix.cpp"
#include "GrafList.cpp"
#include "GrafList.h"
#include "Graf.h"
#include <memory>
#include <queue>

template<class Type,int MAXIMUM>
void DijkstraAlgorithm (Graf<Type,MAXIMUM> G,int source )
{
        std::unique_ptr<std::priority_queue<int>> V(new std::priority_queue<int>);
        std::priority_queue<int> Vs;
        for(auto n : G.neighbours(source)){

        }

}

template<class Type,int MAXIMUM>
void printPath(Graf<Type,MAXIMUM> G, std::unique_ptr<std::vector<int>>Path)
{

}


int main() {
    GrafMatrix<int,30> Gm;
    Gm.fill(0.5);
    GrafList<int,30> G;
    G = Gm;
    std::priority_queue<int> Vs;


    return 0;
}
