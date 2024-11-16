#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

#include "costos.hpp"

using namespace std;

map<pair<char, char>, int> costos_transponer;
map<char, int> costos_escribir;
map<char, int> costos_eliminar;
map<pair<char, char>, int> costos_sustitucion;

int costo_sub(char a, char b){
    pair<char, char> clave = {a , b};
    int costo;
    auto iterador = costos_sustitucion.find(clave);
    if(iterador != costos_sustitucion.end()){
        costo = iterador->second;
        return costo;
    }else{
        return -1;
    }
}

int costo_ins(char a){
    int costo;
    auto iterador = costos_escribir.find(a);
    if(iterador != costos_escribir.end()){
        costo = iterador->second;
        return costo;
    }else{
        return -1;
    }
    return 0;
}

int costo_del(char a){
    int costo;
    auto iterador = costos_eliminar.find(a);
    if(iterador != costos_eliminar.end()){
        costo = iterador->second;
        return costo;
    }else{
        return -1;
    }
    return 0;
}

int costo_trans(char a, char b){
    pair<char, char> clave = {a , b};
    int costo;
    auto iterador = costos_transponer.find(clave);
    if(iterador != costos_transponer.end()){
        costo = iterador->second;
        return costo;
    }else{
        return -1;
    }
    return 0;
}

void CargarCostosTransponer(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
    }
    string linea;
    int costo;
    char c1 = 'a';
    while(getline(archivo, linea)){
        istringstream stream(linea);
        char c2 = 'a';
        while(stream >> costo && c2 <= 'z'){
            costos_transponer[{c1, c2}] = costo;
            ++c2;
        }
        ++c1;
    }
    archivo.close();
}

void ImprimirCostosTransponer(){
    cout << "\ncostos_transponer:" << endl;
    for (const auto& elemento : costos_transponer) {
        cout << "Claves: (" << elemento.first.first << ", " << elemento.first.second << "), Valor: " << elemento.second << endl;
    }
}

void CargarCostosInsertar(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    string linea;
    getline(archivo, linea);
    istringstream stream(linea);
    int costo;
    char c = 'a';
    while(stream >> costo && c <= 'z'){
        costos_escribir[c] = costo;
        ++c;
    }
    archivo.close();
}
void ImprimirCostosInsertar(){
    cout << "\ncostos_escribir:" << endl;
    for(const auto& elemento : costos_escribir){
        cout << "Clave: " << elemento.first << ", Valor: " << elemento.second << endl;
    }
}

void CargarCostosEliminar(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
        return;
    }
    string linea;
    getline(archivo, linea);
    istringstream stream(linea);
    int costo;
    char c = 'a';
    while(stream >> costo && c <= 'z'){
        costos_eliminar[c] = costo;
        ++c;
    }
    archivo.close();
}

void ImprimirCostosEliminar(){
    cout << "\ncostos_eliminar:" << endl;
    for (const auto& elemento : costos_eliminar) {
        cout << "Clave: " << elemento.first << ", Valor: " << elemento.second << endl;
    }
}

void CargarCostosSustitucion(const string& nombreArchivo){
    ifstream archivo(nombreArchivo);
    if(!archivo.is_open()){
        cout << "Error al abrir el archivo" << endl;
    }
    string linea;
    int costo;
    char c1 = 'a';
    while(getline(archivo, linea)){
        istringstream stream(linea);
        char c2 = 'a';
        while(stream >> costo && c2 <= 'z'){
            costos_sustitucion[{c1, c2}] = costo;
            ++c2;
        }
        ++c1;
    }
    archivo.close();
}

void ImprimirCostosSustitucion(){
    cout << "\ncostos_sustitucion:" << endl;
    for (const auto& elemento : costos_sustitucion) {
        cout << "Claves: (" << elemento.first.first << ", " << elemento.first.second << "), Valor: " << elemento.second << endl;
    }
}

