

#ifndef TEST0X2_DIJKSTRAALGORITHM_H
#define TEST0X2_DIJKSTRAALGORITHM_H

#include "GrafMatrix.cpp"
#include "GrafList.cpp"
#include <memory>
#include <queue>

class DijkstraAlgorithm {
public:
    template<class Type,int MAXIMUM>
    std::priority_queue<int>ShortestPath(GrafMatrix<Type,MAXIMUM> G,int source);

    template<class Type,int MAXIMUM>
    std::priority_queue<int>ShortestPath(GrafList<Type,MAXIMUM> G,int source);
};




#endif //TEST0X2_DIJKSTRAALGORITHM_H
