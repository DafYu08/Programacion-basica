#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

const gps P = puntoGps(-33.5, -58.89996);


TEST(tiempoTotalTEST, viajeLargo){
    viaje v = {medicion(1.1, P),
               medicion(1.5, P),
               medicion(1.2, P),
               medicion(2.2, P),
               medicion(2.3, P),
               medicion(5.2, P),
               medicion(5.4, P),
               medicion(5.5, P),
               medicion(7.2, P),
               medicion(1.9, P)};
    EXPECT_DOUBLE_EQ(tiempoTotal(v),6.1);
}

TEST(tiempoTotalTEST, tiemposMaximosyMinimosRepetidos){
    viaje v = {medicion(1.1, P),
               medicion(1.1, P),
               medicion(1.2, P),
               medicion(2.2, P),
               medicion(2.3, P),
               medicion(7.2, P),
               medicion(5.4, P),
               medicion(5.5, P),
               medicion(7.2, P),
               medicion(1.9, P)};
    EXPECT_DOUBLE_EQ(tiempoTotal(v),6.1);
}
TEST(tiempoTotalTEST, apareceMaxAntesQueMin){
    viaje v = {medicion(7.2, P),
               medicion(1.5, P),
               medicion(1.2, P),
               medicion(2.2, P),
               medicion(2.3, P),
               medicion(5.2, P),
               medicion(5.4, P),
               medicion(5.5, P),
               medicion(1.1, P),
               medicion(1.9, P)};
    EXPECT_DOUBLE_EQ(tiempoTotal(v),6.1);
}
