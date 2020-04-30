


#include "DijkstraAlgorithm.h"
//
//const int MAXINT = 2000000000;
//
//template<class Type, int MAXIMUM>
//std::multiset<Path> DijkstraAlgorithm::ShortestPath(const GrafList<Type, MAXIMUM> &G, int source) {
//    assert(source <= G.size());
//
//    std::multiset<Path, std::less<>> set;
//    std::multiset<Path> final;
//    for (auto i = 0; i < G.size(); i++) {
//        std::vector<int> Vec;
//        Vec.push_back(source);
//        if (i == source) {
//            Path P{source, 0, Vec};
//            set.insert(P);
//        } else {
//            Path P{i, MAXINT, Vec};
//            set.insert(P);
//        }
//    }
//    //ALL VERTEX DESPITE SOURCE HAVE INFINITE PATH'S WEIGHT
//
//    //FINAL = SET
//    for (const auto &a:set) {
//        final.insert(a);
//    }
//    int iter = 0;
//    while (!set.empty()) {
//        Path P = *(set.begin());//  EXTRACTING PATH OBJECT
//        set.erase(set.begin());
//        iter++;
//        for (auto n : G.neighbours(P.vertex)) {//CHECKING ADJENCENT VERTICES
//            int target = n;
//            int weight = P.value + G.getEdge(P.vertex, target);
//            for (const auto& Px : set) {            //CHECKING IF ITS UPDATING WHATEVER
//                if (Px.vertex == target && Px.value > weight && weight>=0) {
//                    std::vector<int> vec;
//                    vec = P.road;
//                    vec.push_back(target);
//                    set.insert(Path{target,weight,vec});
//                    for (auto f=final.begin();f!=final.end();f++) {//CHECKING IF THERE IS A SHORTER PATH
//                        if (f->vertex == target && f->value>weight){
//                            Path NPath{f->vertex,weight,vec};
//                            final.erase(f);
//                            final.insert(NPath);
//                        }
//                    }
//                }
//
//            }
//        }
//    }
//
//
//    return final;
//}
//
//template<class Type, int MAXIMUM>
//void DijkstraAlgorithm::ShortestPathtoFile(const GrafList<Type, MAXIMUM> &G, int source,const std::string& namefile) {
//    std::fstream file;
//    file.open(namefile, std::ios::out | std::ios::trunc);
//    auto Wynik = DijkstraAlgorithm::ShortestPath(G,source);
//    for(const auto& a : Wynik){
//        file<<a.vertex<<" == "<<a.value<<" | ";
//        for(auto v : a.road){
//            file<<v<<"->";
//        }file<<"\n";
//    }
//    file.close();
//}
//
//
//template<class Type, int MAXIMUM>
//void DijkstraAlgorithm::ShortestPathtoFile(const GrafMatrix<Type,MAXIMUM> &G, int source, const std::string& namefile) {
//    std::fstream file;
//    file.open(namefile, std::ios::out | std::ios::trunc);
//    auto Wynik = DijkstraAlgorithm::ShortestPath(G,source);
//    for(const auto& a : Wynik){
//        file<<a.vertex<<" == "<<a.value<<" | ";
//        for(auto v : a.road){
//            file<<v<<"->";
//        }file<<"\n";
//    }
//    file.close();
//}
//
//template<class Type, int MAXIMUM>
//std::multiset<Path> DijkstraAlgorithm::ShortestPath(const GrafMatrix<Type, MAXIMUM> &G, int source) {
//    assert(source <= G.size());
//
//    std::multiset<Path, std::less<>> set;
//    std::multiset<Path> final;
//    for (auto i = 0; i < G.size(); i++) {
//        std::vector<int> Vec;
//        Vec.push_back(source);
//        if (i == source) {
//            Path P{source, 0, Vec};
//            set.insert(P);
//        } else {
//            Path P{i, MAXINT, Vec};
//            set.insert(P);
//        }
//    }
//    //ALL VERTEX DESPITE SOURCE HAVE INFINITE PATH'S WEIGHT
//
//    //FINAL = SET
//    for (const auto &a:set) {
//        final.insert(a);
//    }
//    int iter = 0;
//    while (!set.empty()) {
//        Path P = *(set.begin());//  EXTRACTING PATH OBJECT
//        set.erase(set.begin());
//        iter++;
//        for (auto n : G.neighbours(P.vertex)) {//CHECKING ADJENCENT VERTICES
//            int target = n;
//            int weight = P.value + G.getEdge(P.vertex, target);
//            for (const auto& Px : set) {            //CHECKING IF ITS UPDATING WHATEVER
//                if (Px.vertex == target && Px.value > weight && weight>=0) {
//                    std::vector<int> vec;
//                    vec = P.road;
//                    vec.push_back(target);
//                    set.insert(Path{target,weight,vec});
//                    for (auto f=final.begin();f!=final.end();f++) {//CHECKING IF THERE IS A SHORTER PATH
//                        if (f->vertex == target && f->value>weight){
//                            Path NPath{f->vertex,weight,vec};
//                            final.erase(f);
//                            final.insert(NPath);
//                        }
//                    }
//                }
//
//            }
//        }
//    }
//
//
//    return final;
//}



//void DijkstraAlgorithm::TEST(){
//    double density[] = {0.25,0.5,0.75,0.1};
//    static const int sizes[]= {10,50,100,500,1000};
//    const int  i =50;
//    int examples = 100;
//    auto GrafMatrixData[20];
//    auto GrafListData[20];
//    std::string filename = "TEST_EXE_to_TXT";
//    std::fstream file;
//    file.open(filename, std::ios::out | std::ios::trunc);
//
//        for( double d:density){
//
//            for(int i =0;i<examples;i++){
//                std::vector<int> DataMatrix,DataList;
//                GrafMatrix<int,10> Gm;
//                Gm.fill(d);
//                auto start = std::chrono::high_resolution_clock::now();                            //start clock
//                DijkstraAlgorithm::ShortestPath(Gm,0);
//
//                auto end = std::chrono::high_resolution_clock::now();
//
//            }
//
//        }
//
//    file.close();
//std::cout<<"TEST";
//}


