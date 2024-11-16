#include <bits/stdc++.h>

#include "programacion_dinamica.hpp"
#include "fuerza_bruta.hpp"
#include "costos.hpp"

using namespace std;
using namespace std::chrono;

int main(){
    string archivo1 = "cost_insert.txt";
    string archivo2 = "cost_delete.txt";
    string archivo3 = "cost_replace.txt";
    string archivo4 = "cost_transpose.txt"; 
    CargarCostosInsertar(archivo1);
    CargarCostosEliminar(archivo2);
    CargarCostosSustitucion(archivo3);
    CargarCostosTransponer(archivo4);
    /*ImprimirCostosInsertar();
    ImprimirCostosEliminar();
    ImprimirCostosSustitucion();
    ImprimirCostosTransponer();*/

    string cadena1;
    string cadena2;
    getline(cin, cadena1);
    getline(cin, cadena2);

    auto inicio = steady_clock::now();
    cout << EdicionMinimaBF(cadena1, cadena2, 0, 0) << endl;
    auto fin = steady_clock::now();

    auto duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "Edición mínima por fuerza bruta tuvo una duración de " << duracion.count() << " milisegundos" << endl;

    inicio = steady_clock::now();
    cout << EdicionMinimaDP(cadena1, cadena2) << endl;
    fin = steady_clock::now();

    duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "Edición mínima por programación Dinámica tuvo una duración de " << duracion.count() << " milisegundos" << endl;



}
