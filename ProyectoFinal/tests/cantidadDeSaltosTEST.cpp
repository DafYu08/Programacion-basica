#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;


TEST(cantidadDeSaltosTEST, todosSaltosOrdenados){
    grilla g = construirGrilla(puntoGps(0.0,0.0),desviarPunto(puntoGps(0,0), 3000, 3000), 6, 6);

    gps p1 = puntoGps(0, 0);
    gps p2 = desviarPunto(p1, 2000, 2000);
    gps p3 = desviarPunto(p1, 100, 100);

    viaje v = {medicion(1.5, p1),
               medicion(1.6, p2),
               medicion(1.7, p3)};

    EXPECT_EQ(cantidadDeSaltos(g,v),2);
}
TEST(cantidadDeSaltosTEST, todosSaltosDesrdenados){
    grilla g = construirGrilla(puntoGps(0.0,0.0),desviarPunto(puntoGps(0,0), 3000, 3000), 6, 6);

    gps p1 = puntoGps(0, 0);
    gps p2 = desviarPunto(p1, 2000, 2000);
    gps p3 = desviarPunto(p1, 100, 100);

    viaje v = {medicion(1.5, p1),
               medicion(1.6, p3),
               medicion(1.7, p2)};

    EXPECT_EQ(cantidadDeSaltos(g,v),1);
}

TEST(cantidadDeSaltosTEST, noHaySaltos){
    grilla g = construirGrilla(puntoGps(0.0,0.0),desviarPunto(puntoGps(0,0), 3000, 3000), 6, 6);

    gps p1 = puntoGps(0, 0);
    gps p2 = desviarPunto(p1, 50, 50);
    gps p3 = desviarPunto(p1, 100, 100);

    viaje v = {medicion(1.5, p1),
               medicion(1.6, p2),
               medicion(1.7, p3)};

    EXPECT_EQ(cantidadDeSaltos(g,v),0);
}
