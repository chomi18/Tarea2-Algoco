#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

#include "fuerza_bruta.hpp"
using namespace std;

int EdicionMinimaBF(const string& cadena1, const string& cadena2, size_t cursor1, size_t cursor2){
    // Dejar la cadena1 igual que la cadena2
    //if(cursor1 >= cadena1.length() && cursor2 >= cadena2.length())return 0;
    //Casos base

    //Si cadena1 es vacía
    if(cursor1 >= cadena1.length()){
        int costoInsert = 0;
        while(cursor2 < cadena2.length()){
            costoInsert += costo_ins(cadena2[cursor2]);
            ++cursor2;
        }
        return costoInsert;
    }  
    //Si cadena2 es vacia
    if(cursor2 >= cadena2.length()){
        int costoDelete = 0;
        while(cursor1 < cadena1.length()){
            costoDelete += costo_del(cadena1[cursor1]);
            ++cursor1;
        }
        return costoDelete;
    } 
    //Resto de los casos

    int costoInsert = EdicionMinimaBF(cadena1, cadena2, cursor1, cursor2 + 1) + costo_ins(cadena2[cursor2]);
    int costoDelete = EdicionMinimaBF(cadena1, cadena2, cursor1 + 1, cursor2) + costo_del(cadena1[cursor1]);
    int costoTrans = INT_MAX;
    if(cursor1 + 1 < cadena1.length() && cadena1[cursor1 + 1] == cadena2[cursor2] && cursor2 < cadena2.length() && cadena2[cursor2+1] == cadena1[cursor1]){
        costoTrans = EdicionMinimaBF(cadena1, cadena2, cursor1 + 2, cursor2 + 2) + costo_trans(cadena1[cursor1], cadena1[cursor1 + 1]);
    }
    int costoSust = EdicionMinimaBF(cadena1, cadena2, cursor1 + 1, cursor2 + 1) + costo_sub(cadena1[cursor1], cadena2[cursor2]);


    return min({costoInsert, costoDelete, costoSust, costoTrans});
}

