#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

vector<viaje> f = {{
                   medicion(1.5,puntoGps(2.5, 2.89996)),
                   medicion(1.7,puntoGps(2.5, 2.89997)),
                   medicion(1.9,puntoGps(2.5, 2.89998))},
                   {
                    medicion(2.5,puntoGps(2.5, 2.89996)),
                    medicion(2.6,puntoGps(2.5, 2.89997)),
                    medicion(2.7,puntoGps(2.5, 2.89998))},
                   {
                    medicion(0.5,puntoGps(2.5, 2.89996)),
                    medicion(0.6,puntoGps(2.5, 2.89997)),
                    medicion(0.7,puntoGps(2.5, 2.89998))},
                   };
vector<viaje> j = {{
                           medicion(1.9,puntoGps(2.5, 2.89998)),
                           medicion(1.5,puntoGps(2.5, 2.89996)),
                           medicion(1.7,puntoGps(2.5, 2.89997))},
                   {
                           medicion(2.5,puntoGps(2.5, 2.89996)),
                           medicion(2.6,puntoGps(2.5, 2.89997)),
                           medicion(2.7,puntoGps(2.5, 2.89998))},
                   {
                           medicion(0.6,puntoGps(2.5, 2.89997)),
                           medicion(0.7,puntoGps(2.5, 2.89998)),
                           medicion(0.5,puntoGps(2.5, 2.89996))},
};

TEST(flotaTotalTEST, todosAntesDeFranja){
    EXPECT_EQ(flota(f,3.0,5.0),0);
}

TEST(flotaTotalTEST, AlgunosAdentro){
    EXPECT_EQ(flota(f, 1.8,2.55),2);
}

TEST(flotaTotalTEST, todosDespuesDeFranja){
    EXPECT_EQ(flota(j,0.1,0.4),0);
}
TEST(flotaTotalTEST, AlgunosAdentroMezclado){
    EXPECT_EQ(flota(j, 0.55,1.8),2);
}