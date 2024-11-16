#include <map>
#include <string>
#include <utility>
using namespace std;

extern map<pair<char, char>, int> costos_transponer;
extern map<char, int> costos_escribir;
extern map<char, int> costos_eliminar;
extern map<pair<char, char>, int> costos_sustitucion;

void CargarCostosTransponer(const string& archivo);
void ImprimirCostosTransponer();

void CargarCostosInsertar(const string& archivo);
void ImprimirCostosInsertar();

void CargarCostosEliminar(const string& achivo);
void ImprimirCostosEliminar();

void CargarCostosSustitucion(const string& archivo);
void ImprimirCostosSustitucion();

int costo_sub(char a, char b);
int costo_ins(char a);
int costo_del(char a);
int costo_trans(char a, char b);


