#include "vectores.h"

// Función para probar en main.cpp si este módulo fue cargado correctamente
void holaModuloVectores(){
    cout << "El módulo vectores fue cargado correctamente" << endl;
}


//Ejercicio 1
bool divide(vector<int> v, int a){
	bool res = true;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i]%a != 0){
            res = false;
        }
    }
    return res;
}

//Ejercicio 2
int mayor(vector<int> v){
	int max = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (max<v[i]){
            max = v[i];
        }
    }
    return max;
}

//Ejercicio 3
vector<int> reverso(vector<int> v){
	vector <int> aux (0);
    for (int i = v.size() - 1; i >= 0; ++i) {
        aux.push_back(v[i]);
    }
    return aux;
}

//Ejercicio 4 //CORREGIR
vector<int> rotar(vector<int> v, int k){
	int rot = k%v.size();
    vector <int> res = v;
    for (int i = 0; i < rot; ++i) {
        int primera = res[0];
        res.pop_back();
        res.push_back(primera);
    }
    return res;
}

//Ejercicio 5
bool estaOrdenado (vector <int> v){
    bool res = true;
    if (v.size() > 1 && v[0]<v[1]){
        for (int i = 1; i < v.size(); ++i) {
            if (v[i]>v[i+1]){
                res = false;
                i = v.size();
            }
        }
    } else if (v.size() > 1 && v[0]>v[1]){
        for (int i = 1; i < v.size(); ++i) {
            if (v[i]< v[i+1]){
                res = false;
                i = v.size();
            }
        }
    }
    return res;
}
//Ejercicio 6

bool esPrimo (int div){
    bool res = true;
    for (int i = 2; i < div; ++i) {
        if (div%i == 0){
            res = false;
            i = div;
        }
    }
    return res;
}
vector<int> factoresPrimos(int n){
	vector <int> factores (0);
    for (int i = 2; i < n; ++i) {
        if (n%i == 0 && esPrimo(i)){
            factores.push_back(i);
            n = n / i;
        }
    }
    return factores;
}

//Ejercicio 7
void mostrarVector(vector<int> v){
	cout<< "(";
    for (int i = 0; i < v.size(); ++i) {
        cout<< v[i]<< ", ";
    }
    cout<< ")";
}
