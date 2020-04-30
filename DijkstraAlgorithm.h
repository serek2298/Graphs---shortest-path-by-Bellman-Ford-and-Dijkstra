

#ifndef TEST0X2_DIJKSTRAALGORITHM_H
#define TEST0X2_DIJKSTRAALGORITHM_H

//#include "GrafMatrix.cpp"
//#include "GrafList.cpp"
//#include "Graf.cpp"
//#include <memory>
//#include <queue>
//#include <fstream>
//#include <iostream>
//#include <chrono>
//const int MAXINT = 2000000000;
//
//class DijkstraAlgorithm {
//public:
//
//    template<class Type,int MAXIMUM>
//    static /*std::multiset<Path>*/void ShortestPath(const GrafList<Type,MAXIMUM> &G,int source){
//        assert(source < G.size());
//
//        std::multiset<Path, std::less<>> set;
//        std::multiset<Path> final;
//        for (auto i = 0; i < G.size(); i++) {
//            std::vector<int> Vec;
//            Vec.push_back(source);
//            if (i == source) {
//                Path P{source, 0, Vec};
//                set.insert(P);
//            } else {
//                Path P{i, MAXINT, Vec};
//                set.insert(P);
//            }
//        }
//        //ALL VERTEX DESPITE SOURCE HAVE INFINITE PATH'S WEIGHT
//
//        //FINAL = SET
//        for (const auto &a:set) {
//            final.insert(a);
//        }
//        int iter = 0;
//        while (!set.empty()) {
//            Path P = *(set.begin());//  EXTRACTING PATH OBJECT
//            set.erase(set.begin());
//            iter++;
//            for (auto n : G.neighbours(P.vertex)) {//CHECKING ADJENCENT VERTICES
//                int target = n;
//                int weight = P.value + G.getEdge(P.vertex, target);
//                for (const auto& Px : set) {
//                    for (auto f=final.begin();f!=final.end();f++) {//CHECKING IF THERE IS A SHORTER PATH
//                    if (Px.vertex == target && Px.value > weight && weight>=0) {
//                        if (f->vertex == target && f->value>weight){
//                        std::vector<int> vec;
//                        vec = P.road;
//                        vec.push_back(target);
//                        set.insert(Path{target,weight,vec});//PATH UPDATED SO CHECK AGAIN
//                        Path NPath{f->vertex,weight,vec};
//                        final.erase(f);
//                        final.insert(NPath);//SWITCHING THE FINAL VERSION
//                            }
//                        }
//                    }
//
//                }
//            }
//        }
//
//
//     //   return final;
//    };
//
//    template<class Type,int MAXIMUM>
//    static void ShortestPathtoFile(const GrafList<Type,MAXIMUM> &G,int source,const std::string& namefile){
//        std::fstream file;
//        file.open(namefile, std::ios::out | std::ios::trunc);
//        auto Wynik = DijkstraAlgorithm::ShortestPath(G,source);
//        for(const auto& a : Wynik){
//            file<<a.vertex<<" == "<<a.value<<" | ";
//            for(auto v : a.road){
//                file<<v<<"->";
//            }file<<"\n";
//        }
//        file.close();
//    };
//
//    template<class Type,int MAXIMUM>
//    static /*std::multiset<Path>*/void ShortestPath(const GrafMatrix<Type,MAXIMUM> &G,int source){
//        assert(source <= G.size());
//
//        std::multiset<Path, std::less<>> set;
//        std::multiset<Path> final;
//        for (auto i = 0; i < G.size(); i++) {
//            std::vector<int> Vec;
//            Vec.push_back(source);
//            if (i == source) {
//                Path P{source, 0, Vec};
//                set.insert(P);
//            } else {
//                Path P{i, MAXINT, Vec};
//                set.insert(P);
//            }
//        }
//        //ALL VERTEX DESPITE SOURCE HAVE INFINITE PATH'S WEIGHT
//
//        //FINAL = SET
//        for (const auto &a:set) {
//            final.insert(a);
//        }
//        int iter = 0;
//        while (!set.empty()) {
//            Path P = *(set.begin());//  EXTRACTING PATH OBJECT
//            set.erase(set.begin());
//            iter++;
//            for (auto n : G.neighbours(P.vertex)) {//CHECKING ADJENCENT VERTICES
//                int target = n;
//                int weight = P.value + G.getEdge(P.vertex, target);
//                //std::cout<<"Vertex:"<<P.vertex<<" target: "<<target<<" weight: "<<weight<<"\n";
//                        for (auto f=final.begin();f!=final.end();f++) {//CHECKING IF THERE IS A SHORTER PATH
//                                if (f->vertex == target && f->value>weight && weight>0){
//                                    //std::cout<<"SET UPDATING("<<target<<","<<weight<<")";
//                                    std::vector<int> vec;
//                                    vec = P.road;
//                                    vec.push_back(target);
//                                    set.insert(Path{target,weight,vec});
//                                   //std::cout<<"FINAL UPDATING("<<target<<",new= "<<weight<<",old= "<<f->value<<"\n";
//                                    Path NPath{f->vertex,weight,vec};
//                                    final.erase(f);
//                                    final.insert(NPath);
//                                }
//
//
//
//                         }
//            }
//        }
//
//
//       // return final;
//    }
//    ;
//
//    template<class Type,int MAXIMUM>
//    static void ShortestPathtoFile(const GrafMatrix<Type,MAXIMUM> &G,int source,const std::string& namefile){
//        std::fstream file;
//        file.open(namefile, std::ios::out | std::ios::trunc);
//        auto Wynik = DijkstraAlgorithm::ShortestPath(G,source);
//        for(const auto& a : Wynik){
//            file<<a.vertex<<" == "<<a.value<<" | ";
//            for(auto v : a.road){
//                file<<v<<"->";
//            }file<<"\n";
//        }
//        file.close();
//    };
//
//    static void TEST(){
//        double density[] = {0.25,0.5,0.75,0.1};
//        //const int sizes[]= {10,50,100,500,1000};
//        int examples = 100;
//        std::string filename = "TEST_to100_to.txt";
//        std::fstream file;
//       file.open(filename, std::ios::out | std::ios::trunc);
// //      GrafMatrix<int,500> G;
// //      G.fill(1);
////        auto startmatrix10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(G,0);
////               auto endmatrix10 = std::chrono::high_resolution_clock::now();
////               file << std::chrono::duration<double, std::milli>(endmatrix10 - startmatrix10).count()<< "\t";
//
////       //================================10================================
////        file<<"Matrix\tList\t\n";
////        for( double d:density){
////           file<<"Density= \t"<<d<<"\n";
////            for(int i =0;i<examples;i++){
////
////                GrafMatrix<int,10> Gm10;
////                Gm10.fill(d);
////                auto startmatrix10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gm10,0);
////                auto endmatrix10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endmatrix10 - startmatrix10).count()<< "\t";
////                GrafList<int,10> Gl0;
////                Gl0.fill(d);
////                auto startlist10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gl0,0);
////               auto endlist10 = std::chrono::high_resolution_clock::now();
////               file << std::chrono::duration<double, std::milli>(endlist10 - startlist10).count()<< "\t\n";
////            }
////        }
//        //================================50================================
//        file<<"Matrix\tList\t\n";
//       // for( double d:density){
//          //  file<<"Density=\t"<<d<<"\n";
//            for(int i =0;i<examples;i++){
//
//                GrafList<int,100> Gm10;
//                Gm10.fill(1);
//                auto startmatrix10 = std::chrono::high_resolution_clock::now();                            //start clock
//                DijkstraAlgorithm::ShortestPath(Gm10,0);
//                auto endmatrix10 = std::chrono::high_resolution_clock::now();
//                file << std::chrono::duration<double, std::milli>(endmatrix10 - startmatrix10).count()<< "\t";
////                GrafList<int,50> Gl0;
////                Gl0.fill(d);
////                auto startlist10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gl0,0);
////                auto endlist10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endlist10 - startlist10).count()<< "\t\n";
//
//
//
//          //  }
//
//        }
////        //================================100================================
////        file<<"Matrix\tList\t\n";
////        for( double d:density){
////            file<<"Density=\t"<<d<<"\n";
////            for(int i =0;i<examples;i++){
////
////                GrafMatrix<int,100> Gm10;
////                Gm10.fill(d);
////                auto startmatrix10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gm10,0);
////                auto endmatrix10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endmatrix10 - startmatrix10).count()<< "\t";
////                GrafList<int,100> Gl0;
////                Gl0.fill(d);
////                auto startlist10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gl0,0);
////                auto endlist10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endlist10 - startlist10).count()<< "\t\n";
////
////
////
////            }
////
////      }
////        //================================500================================
////        file<<"Matrix\tList\t\n";
////        for( double d:density){
////            file<<"Density=\t"<<d<<"\n";
////            for(int i =0;i<examples;i++){
////
////                GrafMatrix<int,500> Gm10;
////                Gm10.fill(d);
////                auto startmatrix10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gm10,0);
////                auto endmatrix10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endmatrix10 - startmatrix10).count()<< "\t";
////                GrafList<int,500> Gl0;
////                Gl0.fill(d);
////                auto startlist10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gl0,0);
////                auto endlist10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endlist10 - startlist10).count()<< "\t\n";
////
////
////
////            }
////
////        }
////        //================================1000================================
////        file<<"Matrix\tList\t\n";
////        for( double d:density){
////            file<<"Density=\t"<<d<<"\n";
////            for(int i =0;i<examples;i++){
////
////                GrafMatrix<int,1000> Gm10;
////                Gm10.fill(d);
////                auto startmatrix10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gm10,0);
////                auto endmatrix10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endmatrix10 - startmatrix10).count()<< "\t";
////                GrafList<int,1000> Gl0;
////                Gl0.fill(d);
////                auto startlist10 = std::chrono::high_resolution_clock::now();                            //start clock
////                DijkstraAlgorithm::ShortestPath(Gl0,0);
////                auto endlist10 = std::chrono::high_resolution_clock::now();
////                file << std::chrono::duration<double, std::milli>(endlist10 - startlist10).count()<< "\t\n";
////
////
////
////            }
////
////        }
//
//
//        file.close();
//        std::cout<<"TEST IS DONE ";
//    };

//};


#endif //TEST0X2_DIJKSTRAALGORITHM_H
