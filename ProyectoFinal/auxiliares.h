#ifndef TRANSPORTEURBANO_AUXILIARES_H
#define TRANSPORTEURBANO_AUXILIARES_H

#include "definiciones.h"
#include "string"

double obtenerLatitud(gps posicion);
double obtenerLongitud(gps posicion);
gps obtenerPosicion(tuple<tiempo, gps> medicion);
tiempo obtenerTiempo(tuple<tiempo, gps> medicion);
double distEnKM(gps posicion1, gps posicion2);
gps desviarPunto(gps p, double desvioMtsLatitud, double desvioMtsLongitud);
gps puntoGps(double latitud, double longitud);
tuple<tiempo, gps> medicion(tiempo t, gps g);

void guardarGrillaEnArchivo(grilla g, string nombreArchivo);
void guardarRecorridosEnArchivo(vector<recorrido> recorridos, string nombreArchivo);

//ejercicio 2
void swap(viaje &v, int i, int j);
void ordenar(viaje &v);
//ejercicio 3
double velocidad (viaje v, int i, int j);
//ejercicio 4
bool cubierto(viaje v, double u, gps p);
//ejercicio 5
tiempo tMin(viaje v);
tiempo tMax(viaje v);
bool viajeEnFranjaHoraria(viaje v,tiempo t0, tiempo tf);
//ejercicio 6
double longceldax (gps esq1,gps esq2,int m);
double longcelday (gps esq1,gps esq2, int n);
//ejercicio 7
int filas(grilla g);
int columnas(grilla g);
gps esquina1(grilla g);
gps esquina2(grilla g);
nombre nombredeCelda(gps p, gps esq1,double alto,double ancho);
bool esSalto(nombre n1, nombre n2);
//ejercicio 8
bool hayError(tiempo t, vector<tiempo> errores);
gps puntoCorregido(viaje v,tiempo t,vector<tiempo> errores);


#endif //TRANSPORTEURBANO_AUXILIARES_H
