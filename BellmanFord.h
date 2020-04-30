//
// Created by Mirek on 29.04.2020.
//

#ifndef TEST0X2_BELLMANFORD_H
#define TEST0X2_BELLMANFORD_H

#include "GrafMatrix.h"
#include "GrafList.h"
#include "Graf.h"
#include "Path.h"
#include <memory>
#include <fstream>
#include <iostream>
#include <chrono>
const int MAXINT = 2000000000;



class BellmanFord {
public:

    template <class Type,int MAXIMUM>
    static MyVec<Path> ShortestPath(const GrafMatrix<Type,MAXIMUM> &G,int start) {
        auto *Vec = new MyVec<Path>;

        for (int i = 0; i < G.size(); i++) {
            auto *V = new MyVec<int>;
            if (i == start) {
                V->push_back(start);
                auto *P = new Path{i, 0, *V};
                Vec->push_back(*P);
            } else {
                auto *P = new Path{i, MAXINT, *V};
                Vec->push_back(*P);
            }
        }

            for (int k = 0; k < G.size(); k++) {
                for (int j = 0; j < G.size(); j++) {
                    for (int i = 0; i < G.size(); i++) {
                        int val = G.getEdge(i, j);
                        if (val > 0) { //FOR EVERY EDGE
                            int weight = Vec->at(i)->value+val;
                            if(Vec->at(i)->value<MAXINT && Vec->at(j)->value>weight) {
                                Vec->at(j)->value = weight;
                                Vec->at(j)->road = Vec->at(i)->road;
                                Vec->at(j)->road.push_back(j);
                            }
                        }


                    }
                }

            }

        return *Vec;
    }
    template <class Type,int MAXIMUM>
    static void ShortestPathtoFile(GrafMatrix<Type,MAXIMUM> &G,int start, const std::string& namefile){
        std::fstream file;
        file.open(namefile, std::ios::out | std::ios::trunc);
        auto Wynik = ShortestPath(G,start);
        for(const auto& a : Wynik){
            file<<a.vertex<<" == "<<a.value<<" | ";
            for(auto v : a.road){
                file<<v<<"->";
            }file<<"\n";
        }
        file.close();
    }
    template <class Type,int MAXIMUM>
    static MyVec<Path> ShortestPath(const GrafList<Type,MAXIMUM> &G,int start) {
        auto *Vec = new MyVec<Path>;

        for (int i = 0; i < G.size(); i++) {
            auto *V = new MyVec<int>;
            if (i == start) {
                V->push_back(start);
                auto *P = new Path{i, 0, *V};
                Vec->push_back(*P);
            } else {
                auto *P = new Path{i, MAXINT, *V};
                Vec->push_back(*P);
            }
        }
        int iter = 1;
        for (int k = 0; k < G.size(); k++) {
            if(iter ==0)break;
                else iter=0;
            for (int j = 0; j < G.size(); j++) {
                for (int i = 0; i < G.size(); i++) {
                    int val = G.getEdge(i, j);
                    if (val > 0) { //FOR EVERY EDGE
                        int weight = Vec->at(i)->value+val;
                        if(Vec->at(i)->value<MAXINT && Vec->at(j)->value>weight) {
                            Vec->at(j)->value = weight;
                            Vec->at(j)->road = Vec->at(i)->road;
                            Vec->at(j)->road.push_back(j);
                            iter++;
                        }
                    }


                }
            }

        }

        return *Vec;
    }
    template <class Type,int MAXIMUM>
    static void ShortestPathtoFile(GrafList<Type,MAXIMUM> &G,int start, const std::string& namefile){
        std::fstream file;
        file.open(namefile, std::ios::out | std::ios::trunc);
        auto Wynik = ShortestPath(G,start);
        for(const auto& a : Wynik){
            file<<a.vertex<<" == "<<a.value<<" | ";
            for(auto v : a.road){
                file<<v<<"->";
            }file<<"\n";
        }
        file.close();
    }
    static void TEST(){
        double density[] = {0.25,0.5,0.75,0.1};
        const int sizes[]= {10,50,100,500,1000};
        int examples = 100; //NUMBER OF EXAMPLES TO COPY
        int const begin = 0; // STARTING WERTEX
        std::string filename;
        filename = "TESTFINAL2.txt";
        std::fstream file;
       file.open(filename, std::ios::out | std::ios::trunc);
        //================================10================================
        file<<"========================\n===========10========\n========================\n";
        std::cout<<"\nRozmiar:10 \ndensity: ";
        file<<"Matrix\tList\t\n";
        for( double d:density){
            file<<"=====================\n";
           file<<"Density= \t"<<d<<"\n";
           std::cout<<d<<"=>";
            for(int i =0;i<examples;i++){
                auto GM = new GrafMatrix<int,10>;
                GM->fill(d);
                auto start = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GM,begin);
                auto end = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(end - start).count()<< "\t";
                std::cout<<i<<",";
                delete GM;
               auto GL= new GrafList<int,10>;
                GL->fill(d);
                auto startlist10 = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GL,begin);
               auto endlist10 = std::chrono::high_resolution_clock::now();
               file << std::chrono::duration<double, std::milli>(endlist10 - startlist10).count()<< "\n";
                std::cout<<i<<",";
            }
        }
        //================================50================================
        file<<"========================\n========================\n";
        file<<"Matrix\tList\t\n";
        std::cout<<"\nRozmiar:50 \ndensity: ";
        for( double d:density){
            file<<"=====================\n";
            file<<"Density= \t"<<d<<"\n";
            std::cout<<d<<"=>";
            for(int i =0;i<examples;i++){
                auto GM = new GrafMatrix<int,50>;
                GM->fill(d);
                auto start = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GM,begin);
                auto end = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(end - start).count()<< "\t";
                delete GM;
                std::cout<<i<<",";
                auto GL= new GrafList<int,50>;
                GL->fill(d);
                auto startlist50 = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GL,begin);
                auto endlist50 = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(endlist50 - startlist50).count()<< "\t\n";
                std::cout<<i<<",";
                delete GL;
            }
        }

        //================================100================================
        file<<"========================\n========================\n";
        file<<"Matrix\tList\t\n";
        std::cout<<"\nRozmiar:100 \ndensity: ";
        for( double d:density){
            file<<"=====================\n";
            file<<"Density= \t"<<d<<"\n";
            std::cout<<d<<"=>";
            for(int i =0;i<examples;i++){
                auto GM = new GrafMatrix<int,100>;
                GM->fill(d);
                auto start = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GM,begin);
                auto end = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(end - start).count()<< "\t";
                delete GM;
                std::cout<<i<<",";
                auto GL= new GrafList<int,100>;
                GL->fill(d);
                auto startlist100 = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GL,begin);
                auto endlist100 = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(endlist100 - startlist100).count()<< "\t\n";
                delete GL;
                std::cout<<i<<",";
            }
        }

        //================================500================================
        file<<"========================\n========================\n";
        std::cout<<"\nRozmiar:100 \ndensity: ";
        file<<"Matrix\tList\t\n";
        for( double d:density){
            file<<"=====================\n";
            file<<"Density= \t"<<d<<"\n";
            std::cout<<d<<"=>";
            for(int i =0;i<examples;i++){
                auto GM = new GrafMatrix<int,500>;
                GM->fill(d);
                auto start = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GM,begin);
                auto end = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(end - start).count()<< "\t";
                delete GM;
                std::cout<<i<<",";
                auto GL= new GrafList<int,500>;
                GL->fill(d);
                auto startlist500 = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GL,begin);
                auto endlist500 = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(endlist500 - startlist500).count()<< "\t\n";
                delete GL;
                std::cout<<i<<",";
            }
        }
        //================================1000================================
        file<<"========================\n========================\n";
        file<<"Matrix\tList\t\n";
        std::cout<<"\nRozmiar:100 \ndensity: ";
        for( double d:density){
            file<<"=====================\n";
            file<<"Density= \t"<<d<<"\n";
            std::cout<<d<<"=>";
            for(int i =0;i<examples;i++){
                auto GM = new GrafMatrix<int,1000>;
                GM->fill(d);
                auto start = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GM,begin);
                auto end = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(end - start).count()<< "\t";
                delete GM;
                auto GL= new GrafList<int,1000>;
                GL->fill(d);
                auto startlist1000 = std::chrono::high_resolution_clock::now();                            //start clock
                ShortestPath(*GL,begin);
                auto endlist1000 = std::chrono::high_resolution_clock::now();
                file << std::chrono::duration<double, std::milli>(endlist1000 - startlist1000).count()<< "\t\n";
                delete GL;
                std::cout<<i<<",";
            }
        }
        file.close();


    }
};


#endif //TEST0X2_BELLMANFORD_H
