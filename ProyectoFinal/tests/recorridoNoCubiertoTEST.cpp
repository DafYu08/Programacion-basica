#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

template<typename T>
bool included(T elem, vector<T> container){
    for (int i = 0; i < container.size(); ++i) {
        if (container[i] == elem){return true;}
    }
    return false;
}

template<typename T>
void ASSERT_ELEMENTS(vector<T> container, vector<T> elems) {
    for(int i = 0; i < elems.size(); i++ ) {
        ASSERT_TRUE(included(elems[i], container));
    }

}

using namespace std;

const gps P = puntoGps(-31.465027, -64.212973);
const recorrido R = {P,
                     desviarPunto(P, 1000, 0),
                     desviarPunto(P, 2000, 0),
                     desviarPunto(P, 3000, 0),
                     desviarPunto(P, 4000, 0),
                     desviarPunto(P, 5000, 0),
                     desviarPunto(P, 6000, 0),
                     desviarPunto(P, 7000, 0),
                     desviarPunto(P, 8000, 0),
                     desviarPunto(P, 9000, 0),
                      };

const recorrido RRulos = {P,
                     desviarPunto(P, 1000, 0),
                     desviarPunto(P, 2000, 0),
                     desviarPunto(P, 3000, 0),
                     desviarPunto(P, 4000, 0),
                     desviarPunto(P, 5000, 0),
                     desviarPunto(P, 5000, 100),
                     desviarPunto(P, 4000, 100),
                     desviarPunto(P, 3000, 100),
                     desviarPunto(P, 2000, 100),
                     desviarPunto(P, 1000, 100),
                     desviarPunto(P, 0, 0)
};



TEST(recorridoNoCubiertoTEST, viajePerfecto){
    viaje v = {};
    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i, R[i]));
    }

    EXPECT_EQ(recorridoNoCubierto(v, R, 10).size(), 0);
}

TEST(recorridoNoCubiertoTEST, viajeConImperfeccionesMayoresAlUmbral){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[0] = 390;
    desvios[1] = 30;
    desvios[2] = -190;
    desvios[3] = -390;

    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i, desviarPunto(R[i], 0, desvios[i])));
    }

    vector<gps> res = recorridoNoCubierto(v, R, 0.1);
    EXPECT_EQ(res.size(), 3);
    ASSERT_ELEMENTS(res, {R[3], R[0], R[2]});

}
TEST(recorridoNoCubiertoTEST, viajeConImperfeccionesMenoresAlUmbral){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[0] = 390;

    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i, desviarPunto(R[i], 0, desvios[i])));
    }

    vector<gps> res = recorridoNoCubierto(v, R, 0.1);
    EXPECT_EQ(res.size(), 1);
    ASSERT_ELEMENTS(res, {R[0]});

}

TEST(recorridoNoCubiertoTEST, viajeConImperfeccionesIgualesAlUmbral){
    viaje v = {};
    vector<int> desvios(R.size(), 0);
    desvios[0] = 390;
    desvios[1] = 30;
    desvios[2] = -190;

    for(int i = 0; i < R.size(); i++){
        v.push_back(medicion(i, desviarPunto(R[i], 0, desvios[i])));
    }

    vector<gps> res = recorridoNoCubierto(v, R, 0.1);
    EXPECT_EQ(res.size(), 2);
    ASSERT_ELEMENTS(res, {R[0], R[2]});
}