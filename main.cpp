#include <bits/stdc++.h>

#include "programacion_dinamica.hpp"
#include "fuerza_bruta.hpp"
#include "costos.hpp"

using namespace std;
using namespace std::chrono;

void ProcesarCasos(const string& archivo_entrada, const string& archivo_salida) {
    ifstream input(archivo_entrada);
    ofstream output(archivo_salida);

    string linea;
    while (getline(input, linea)) {
        size_t coma = linea.find(',');
        if (coma == string::npos) continue;  // Salta líneas inválidas

        string cadena1 = linea.substr(0, coma);
        string cadena2 = linea.substr(coma + 1);

        auto inicio = steady_clock::now();
        int costoBF = EdicionMinimaBF(cadena1, cadena2, 0, 0);
        auto fin = steady_clock::now();
        auto duracionBF = duration_cast<microseconds>(fin - inicio).count();

        inicio = steady_clock::now();
        int costoDP = EdicionMinimaDP(cadena1, cadena2);
        fin = steady_clock::now();
        auto duracionDP = duration_cast<microseconds>(fin - inicio).count();

        output << "Cadena1: " << cadena1 << ", Cadena2: " << cadena2 << endl;
        output << "Costo BF: " << costoBF << ", Tiempo BF: " << duracionBF << " microseconds" << endl;
        output << "Costo DP: " << costoDP << ", Tiempo DP: " << duracionDP << " microseconds" << endl;
        output << "-------------------------------------" << endl;
    }

    input.close();
    output.close();
}

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

     string archivo_casos = "casos_prueba.txt";
    string archivo_resultados = "resultados.txt";

    ProcesarCasos(archivo_casos, archivo_resultados);

    cout << "Resultados guardados en " << archivo_resultados << endl;
    return 0;

}
