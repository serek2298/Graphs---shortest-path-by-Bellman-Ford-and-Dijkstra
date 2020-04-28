

#include "Graf.h"

template <class Type,int MAXIMUM>
int Graf<Type,MAXIMUM>::size() const{
    return this->VertexCount;
}

template<class Type, int MAXIMUM>
Type Graf<Type, MAXIMUM>::GetVertex(int vertex) const {
    return this->labels[vertex];
}

template<class Type, int MAXIMUM>
Graf<Type, MAXIMUM>::~Graf() = default;

template<class Type, int MAXIMUM>
Graf<Type, MAXIMUM>::Graf() = default;
