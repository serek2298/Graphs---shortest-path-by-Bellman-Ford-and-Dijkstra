

#ifndef TEST0X2_MYVEC_H
#define TEST0X2_MYVEC_H

template <class T> class MyVec{
private:
    int size = 0;
    int max_size=16;
    T* tab;
    T* iter_to_first;

    void resize(){
    if(this->size >= max_size-1){
        max_size*=2;
        T* ntab = new T[max_size];
        for(int i=0;i<size;i++){
            ntab[i] = tab[i];
        }
        tab = ntab;
    }
        else if (this->size< (max_size/2)-1){
        max_size/=2;
        T* ntab = new T[max_size];
        for(int i=0;i<size;i++){
            ntab[i] = tab[i];
        }
        }
    }

public:
    MyVec(){
        tab = new T[max_size];
    }
    ~MyVec() = default;

    void push_back(const T& value){
        tab[size] = value;
        size++;
        resize();
    }

    T* at(int i){
        return &tab[i];
    }
    T * begin() const {
        return &tab[0];
    }
    T * end() const {
        return &tab[size];
    }
    int rozmiar() const{
        return this->size;
    }
    int maxrozmiar() const{
        return this->max_size;
    }
     MyVec<T>&operator=(const MyVec<T> &Vec){
        if(&Vec != this) {
            this->size = Vec.rozmiar();
            this->max_size = Vec.maxrozmiar();
            delete this->tab;
            this->tab = new T[max_size];
            for(auto i =0; i<Vec.rozmiar();i++){
                tab[i] = Vec.tab[i];
            }
            return *this;
        }
    }
};

#endif //TEST0X2_MYVEC_H
