#include <algorithm>
#include "auxiliares.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

const double pi = 3.14;
double radioTierra = 6378;

double obtenerLatitud(gps posicion) {
    return get<0>(posicion);
}

double obtenerLongitud(gps posicion) {
    return get<1>(posicion);
}

gps obtenerPosicion(tuple<tiempo, gps> medicion) {
    return get<1>(medicion);
}

tiempo obtenerTiempo(tuple<tiempo, gps> medicion) {
    return get<0>(medicion);
}
double distEnKM(gps posicion1, gps posicion2) {
    double latitud1 = obtenerLatitud(posicion1);
    double latitud2 = obtenerLatitud(posicion2);
    double longitud1 = obtenerLongitud(posicion1);
    double longitud2 = obtenerLongitud(posicion2);

    // obtengo la distancia
    double distanciaLatitud = (latitud2 - latitud1) * pi / 180.0;
    double distanciaLongitud = (longitud2 - longitud1) * pi / 180.0;

    // paso las latitudes a radianes
    latitud1 = (latitud1) * pi / 180.0;
    latitud2 = (latitud2) * pi / 180.0;

    // aplico la formula
    double a = pow(sin(distanciaLatitud / 2), 2) +
               pow(sin(distanciaLongitud / 2), 2) *
               cos(latitud1) * cos(latitud2);

    double c = 2 * asin(sqrt(a));
    return radioTierra * c;
}

gps desviarPunto(gps p, double desvioMtsLatitud, double desvioMtsLongitud){
    double lat = obtenerLatitud(p);
    double lon = obtenerLongitud(p);

    double dx = desvioMtsLatitud / 1000;
    double dy = desvioMtsLongitud / 1000;
    double new_latitude = lat + (dx / radioTierra) * (180 / pi);
    double new_longitude = lon + (dy / radioTierra) * (180 / pi) / cos(lat * pi / 180);
    return puntoGps(new_latitude, new_longitude);

}


gps puntoGps(double latitud, double longitud) {
    return make_tuple(latitud, longitud);
}

tuple<tiempo, gps> medicion(tiempo t, gps g) {
    return make_tuple(t, g);
}

void guardarGrillaEnArchivo(grilla g, string nombreArchivo){
    ofstream myfile;
    float esq1_lat, esq2_lat, esq1_lng, esq2_lng;
    int name_0, name_1;

    myfile.open(nombreArchivo);
    myfile << std::fixed << std::setprecision(5);
    for(int i = 0; i < g.size(); i++){
        esq1_lat = get<0>(get<0>(g[i]));
        esq1_lng = get<1>(get<0>(g[i]));

        esq2_lat = get<0>(get<1>(g[i]));
        esq2_lng = get<1>(get<1>(g[i]));

        name_0 = get<0>(get<2>(g[i]));
        name_1 = get<1>(get<2>(g[i]));

        myfile << esq1_lat << "\t"
               << esq1_lng << "\t"
               << esq2_lat << "\t"
               << esq2_lng << "\t"
               << "(" << name_0 << "," << name_1 << ")"
               << endl;

    }
    myfile.close();

}

void guardarRecorridosEnArchivo(vector<recorrido> recorridos, string nombreArchivo){
    ofstream myfile;
    float lat, lng;

    myfile.open(nombreArchivo);
    myfile << std::fixed << std::setprecision(5);
    for(int i = 0; i < recorridos.size(); i++){
        for(int k = 0; k < recorridos[i].size(); k++){
            lat= get<0>(recorridos[i][k]);
            lng= get<1>(recorridos[i][k]);

            myfile << i << "\t"
                   << lat << "\t"
                   << lng << endl;
        }
    }
    myfile.close();

}

//ejercicio 2
void swap(viaje &v, int i, int j){

    tuple<tiempo,gps> aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

void ordenar(viaje &v){

    for (int i = 0; i<v.size(); i++)
    {
        for (int j = i+1; j<(v.size()); j++)
        {
            if ((obtenerTiempo(v[j])) < (obtenerTiempo(v[i])))
            {
                swap(v,i,j);
            }
        }
    }
}
//ejercicio 3
double velocidad (viaje v, int i, int j){
    double tiempo = obtenerTiempo(v[j]) - obtenerTiempo(v[i]);
    tiempo = tiempo/3600;
    double distancia = distEnKM((obtenerPosicion(v[i])),(obtenerPosicion(v[j])));

    return (distancia/tiempo);
}
//ejercicio 4
bool cubierto(viaje v, double u, gps p){
    bool res = false;
    int i=0;
    double distancia;

    while((i<v.size()) && !res)
    {
        distancia = distEnKM(p, obtenerPosicion(v[i]));
        if(distancia < u)
        {
            res = true;
        }
        i++;
    }
    return res;
}
//ejercicio 5
tiempo tMin(viaje v){

    tiempo min = obtenerTiempo(v[0]);
    for (int i=0;i<v.size();i++)
    {
        if(obtenerTiempo(v[i])<min)
        {
            min = obtenerTiempo(v[i]);
        }
    }
    return min;
}

tiempo tMax(viaje v){

    tiempo max = obtenerTiempo(v[0]);
    for (int i=0;i<v.size();i++)
    {
        if(obtenerTiempo(v[i])>max)
        {
            max = obtenerTiempo(v[i]);
        }
    }
    return max;
}

bool viajeEnFranjaHoraria(viaje v,tiempo t0, tiempo tf){
    bool enFranja = false;
    tiempo max = tMax(v);
    tiempo min = tMin(v);
    if(!((max<t0) || (min > tf)))
    {
        enFranja = true;
    }

    return (enFranja);
}
//ejercicio 6
double longceldax (gps esq1,gps esq2,int m){
    double longitudgrillax = obtenerLongitud(esq2) - obtenerLongitud(esq1);
    double res = longitudgrillax/m ;
    return res;
}

double longcelday (gps esq1,gps esq2, int n){
    double longitudgrillay = obtenerLatitud(esq2) - obtenerLatitud(esq1);
    double res = longitudgrillay/n ;
    return res;
}
//ejercicio 7
int filas(grilla g){
    int filastotales = 0;
    for (int i=0;i<g.size();i++)
    {
        int fila = get<0>(get<2>(g[i]));
        if(filastotales < fila)
        {
            filastotales = fila;
        }
    }
    return filastotales;
}

int columnas(grilla g){
    int columnastotales = 0;
    for (int i=0;i<g.size();i++)
    {
        int columna = get<1>(get<2>(g[i]));
        if(columnastotales < columna)
        {
            columnastotales = columna;
        }
    }
    return columnastotales;
}

gps esquina1(grilla g){
    double lat = get<0>(get<0>(g[0]));
    double lng = get<1>(get<0>(g[0]));
    for (int i=0;i<g.size();i++)
    {
        double latAux = get<0>(get<0>(g[i]));
        double lngAux = get<1>(get<0>(g[i]));
        if ((latAux >= lat) && (lngAux <= lng))
        {
            lat = latAux;
            lng = lngAux;
        }
    }
    return(puntoGps(lat,lng));
}

gps esquina2(grilla g){
    double lat = get<0>(get<0>(g[0]));
    double lng = get<1>(get<0>(g[0]));
    for (int i=0;i<g.size();i++)
    {
        double latAux = get<0>(get<0>(g[i]));
        double lngAux = get<1>(get<0>(g[i]));
        if ((latAux <= lat) && (lngAux >= lng))
        {
            lat = latAux;
            lng = lngAux;
        }
    }
    return(puntoGps(lat,lng));
}

nombre nombredeCelda(gps p, gps esq1,double alto,double ancho){

    double distLatitudinal = obtenerLatitud(esq1) - obtenerLatitud(p);
    double distLongitudinal = obtenerLongitud(p) - obtenerLongitud(esq1);
    int a = round(distLatitudinal/alto);
    int b = round(distLongitudinal/ancho);

    return(make_tuple(a+1,b+1));

}
bool esSalto(nombre n1, nombre n2){
    distancia distX = abs(get<1>(n1) - get<1>(n2));
    distancia distY = abs(get<0>(n2) - get<0>(n1));

    return(pow((distX),2)+(pow((distY),2)) > 1);
}
//ejercicio 8
bool hayError(tiempo t, vector<tiempo> errores){
    bool res = false;
    for (int i=0;i<errores.size();i++)
    {
        if(errores[i] == t)
        {
            res = true;
        }
    }
    return res;
}

gps puntoCorregido(viaje v,tiempo t,vector<tiempo> errores){
    ordenar(v);
    int indice = 0;
    for (int i=0;i<v.size();i++)
    {
        if(get<0>(v[i]) == t)
        {
            indice = i;
        }
    }
    gps masCercanoPrevio;
    gps masCercanoSiguiente;
    tiempo t1;


    for(int j=indice+1;j<v.size();j++)
    {
        if(!hayError(get<0>(v[j]),errores))
        {
            masCercanoSiguiente = get<1>(v[j]);
            t1 = get<0>(v[j]);
            j=v.size();
            // o break?
        }
    }

    tiempo t2;

    for(int j=indice-1;j>0;j--)
    {
        if(!hayError(get<0>(v[j]),errores))
        {
            masCercanoPrevio = get<1>(v[j]);
            t2 = get<0>(v[j]);
            j=0;
            // o break?
        }
    }
    double latCorregido = get<0>(masCercanoPrevio) + (get<0>(masCercanoSiguiente)-get<1>(masCercanoPrevio)) * (t-t2)/(t1-t2);
    double lngCorregido = get<1>(masCercanoPrevio) + (get<1>(masCercanoSiguiente)-get<1>(masCercanoPrevio)) * (t-t2)/(t1-t2);
    return make_tuple(latCorregido,lngCorregido);
}
