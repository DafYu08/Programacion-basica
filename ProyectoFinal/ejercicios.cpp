#include "ejercicios.h"
#include "auxiliares.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

/******++++**************************** EJERCICIO tiempoTotal ***********+++***********************/
// Si n representa la longitud del viaje, la funcion tiempoTotal en el peor caso cumplirá O(n)
// ya que el peor caso es en el que el mayor o menor valor de tiempo es el ultimo elemento de la secuencia.

tiempo tiempoTotal(viaje v) {

    tiempo t;
    tiempo tMax= obtenerTiempo(v[0]);
    tiempo tMin= obtenerTiempo(v[0]);

    for(int i=0; i<v.size();i++)
    {
        if ((obtenerTiempo(v[i])) <  tMin)
        {
            tMin = obtenerTiempo(v[i]);
        }

        if ((obtenerTiempo(v[i])) > tMax)
        {
            tMax = obtenerTiempo(v[i]);
        }
    }

    t = tMax - tMin;

            return t;
}


/************++*********************** EJERCICIO distanciaTotal ************++*********************/
// Siendo n la longitud del viaje, el peor caso de la funcion distanciaTotal es en el que,
// al ordenar los tiempos tengo que realizar n(n-1)/2 operaciones.
// Este sería el caso en el que los tiempos están ordenados al revés.

// El ordenamiento lo resolvimos utilizando bubblesort, cuyo algoritmo tiene complejidad de peor caso O(n^2)


distancia distanciaTotal(viaje v) {

    distancia d;
    ordenar(v);

    d = distEnKM((obtenerPosicion(v[0])),(obtenerPosicion(v[v.size()-1])));

    return d;
}

/*****************************+***** EJERCICIO excesoDeVelocidad **********************************/
bool excesoDeVelocidad(viaje v) {
    bool resp = false;
    ordenar(v);

    for(int i=0; i<v.size()-1;i++)
    {
        double vel = velocidad(v,i,i+1);
        if(vel>80)
        {
            resp=true;
        }
    }

    return resp;
}

/************************************ EJERCICIO recorridoCubierto *******************************/
// Siendo n la longitud de viaje, y m la longitud del recorrido, el peor caso de la funcion recorridoCubierto
// es en el que debo comparar la distancia entre todos los puntos gps del recorrido y todas las posiciones en el viaje con el umbral.
// En ese caso, debo ver todos los valores del recorrido y del viaje, entonces la complejidad es de O(n x m)

vector<gps> recorridoNoCubierto(viaje v, recorrido r, distancia u) {
    vector<gps> resp;
    for(int i=0; i<r.size(); i++)
    {

        if(!cubierto(v, u, r[i]))
        {
            resp.push_back(r[i]);
        }
    }

    return resp;
}
/***************************************** EJERCICIO flota ***************************************/

int flota(vector<viaje> f, tiempo t0, tiempo tf) {
    int resp=0;
    int i=0;

    while(i<f.size())
    {
        if(viajeEnFranjaHoraria(f[i], t0, tf))
        {
            resp++;
        }
        i++;
    }
    return resp;
}

/************************************** EJERCICIO construirGrilla *******************************/

grilla construirGrilla(gps esq1, gps esq2, int n, int m) {
    grilla g = {};

    double anchocelda = longceldax(esq1,esq2,m);
    double altocelda = longcelday(esq1,esq2,n);

    double latesquina1 = obtenerLatitud(esq1);
    double latesquina2 = latesquina1 - altocelda;
    double lonesquina1 = obtenerLongitud(esq1);
    double lonesquina2 = lonesquina1 + anchocelda;

    int fila=1;
    int columna=1;
    int i=-1;
    while(i<=m*n)
    {
        if(columna<=m)
        {
            celda c = make_tuple(puntoGps(latesquina1,lonesquina1), puntoGps(latesquina2,lonesquina2), make_tuple(fila,columna));
            g.push_back(c);
            latesquina1 = latesquina1 - altocelda;
            latesquina2 = latesquina2 - altocelda;
            columna++;
        }
        else
        {
            columna=1;
            latesquina1 = obtenerLatitud(esq1);
            latesquina2 = latesquina1 - altocelda;
            lonesquina1 = lonesquina1 + anchocelda;
            lonesquina2 = lonesquina2 + anchocelda;
            fila++;
        }
        i++;
    }

    return g;
}

/************************************* EJERCICIO cantidadDeSaltos ******************************/

int cantidadDeSaltos(grilla g, viaje v) {
    int resp=0;

    int n = filas(g);
    int m = columnas(g);
    gps esq1 = esquina1(g);
    gps esq2 = esquina2(g);

    double latTotal = get<0>(esq1) - get<0>(esq2);
    double lngTotal = get<1>(esq2) - get<1>(esq2);

    double alto = latTotal/n;
    double ancho = lngTotal/m;

    ordenar(v);

    for(int i=0;i<v.size()-1;i++)
    {
        nombre c1 = nombredeCelda(get<1>(v[i]),esq1,alto,ancho);
        nombre c2 = nombredeCelda(get<1>(v[i+1]),esq1,alto,ancho);
        if(esSalto(c1,c2))
        {
            resp++;
        }
    }
    return resp;
}
/************************************* EJERCICIO corregirViaje ******************************/

void corregirViaje(viaje& v, vector<tiempo> errores){
    for(int i=0;i<v.size();i++)
    {
        if(hayError(obtenerTiempo(v[i]),errores))
        {
            v[i] = make_tuple(obtenerTiempo(v[i]), puntoCorregido(v,obtenerTiempo(v[i]),errores));
        }
    }
}
