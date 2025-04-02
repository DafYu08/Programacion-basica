#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(distanciaTotalTEST, viajeDesordenado){
    gps p1 = puntoGps(-33, -34);
    gps p2 = desviarPunto(p1, 2000, 0);
    gps p3 = desviarPunto(p2, 2000, 0);

    viaje v = {medicion(1.6, p2),
               medicion(1.5, p1),
               medicion(1.7, p3)};

    EXPECT_NEAR(distanciaTotal(v), 4.0, 0.01);
}
TEST(distanciaTotalTEST, viajeOrdenado){
    gps p1 = puntoGps(-33, -34);
    gps p2 = desviarPunto(p1, 2000, 0);
    gps p3 = desviarPunto(p2, 2000, 0);

    viaje v = {medicion(1.5, p1),
               medicion(1.6, p2),
               medicion(1.7, p3)};

    EXPECT_NEAR(distanciaTotal(v), 4.0, 0.01);
}
