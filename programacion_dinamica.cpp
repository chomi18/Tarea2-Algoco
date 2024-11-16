#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <climits>

#include "programacion_dinamica.hpp"
using namespace std;

void ImprimirTablaDP(const vector<vector<int>>& TablaDP) {
    // Iterar sobre las filas de la matriz
    for (size_t i = 0; i < TablaDP.size(); ++i) {
        // Iterar sobre las columnas de la fila actual
        for (size_t j = 0; j < TablaDP[i].size(); ++j) {
            // Imprimir el valor con un espacio de separación
            cout << TablaDP[i][j] << "\t";
        }
        // Saltar a la siguiente línea después de cada fila
        cout << endl;
    }
}

int EdicionMinimaDP(const string& cadena1, const string& cadena2){
    int size1 = cadena1.length();
    int size2 = cadena2.length();

    vector<vector<int>> TablaDP(size1 + 1, vector<int>(size2 + 1, 0));
    TablaDP[0][0] = 0;

    //Casos Base
    for(int i = 1; i <= size1; ++i) TablaDP[i][0] = TablaDP[i - 1][0] + costo_del(cadena1[i - 1]);
    for(int j = 1; j <= size2; ++j) TablaDP[0][j] = TablaDP[0][j - 1] + costo_ins(cadena2[j - 1]);

    //Rellenar la tabla
    for(int i = 1; i <= size1; ++i){
        for(int j = 1; j <= size2; ++j){
            if(cadena1[i-1] == cadena2[j-1]) TablaDP[i][j] = TablaDP[i-1][j-1];

            int insert = TablaDP[i][j-1] + costo_ins(cadena2[j-1]);
            int del = TablaDP[i-1][j] + costo_del(cadena2[i-1]);
            int sust = TablaDP[i-1][j-1] + costo_sub(cadena1[i-1], cadena2[j-1]);
            int trans = INT_MAX;
            if(i > 1 && j > 1 && cadena1[i - 1] == cadena2[j - 2] && cadena1[i - 2] == cadena2[j - 1]){
                trans = TablaDP[i-2][j-2] + costo_trans(cadena1[i-2], cadena1[i-1]);
            }
            TablaDP[i][j] = min({insert, del, sust, trans});
        }
    }
    ImprimirTablaDP(TablaDP);
    return TablaDP[size1][size2];
}