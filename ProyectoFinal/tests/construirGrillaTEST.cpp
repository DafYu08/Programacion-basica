#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

TEST(construirGrillaTEST, nombresCorrectosDistanciaParNParMImparArg){

    int n = 2;
    int m = 3;

    gps esq1 = puntoGps(-33.0,-58.0);
    gps esq2 = puntoGps(-33.9,-57.1);

    grilla gres = {make_tuple(puntoGps(-33.0,-58.0), puntoGps(-33.45,-57.7), make_tuple(1,1)),
                  make_tuple(puntoGps(-33.0,-57.7), puntoGps(-33.45,-57.4), make_tuple(1,2)),
                  make_tuple(puntoGps(-33.0,-57.4), puntoGps(-33.45,-57.1), make_tuple(1,3)),
                  make_tuple(puntoGps(-33.45,-58.0), puntoGps(-33.9,-57.7), make_tuple(2,1)),
                  make_tuple(puntoGps(-33.45,-57.7), puntoGps(-33.9,-57.4), make_tuple(2,2)),
                  make_tuple(puntoGps(-33.45,-57.4), puntoGps(-33.9,-57.1), make_tuple(2,3))
                  };


    grilla g = construirGrilla(esq1,esq2,n,m);

    EXPECT_EQ(n*m, g.size());
}
TEST(construirGrillaTEST, nombresIncorrectosDistanciaParNParMImparArg){

    int n = 2;
    int m = 3;

    gps esq1 = puntoGps(-33.0,-58.0);
    gps esq2 = puntoGps(-33.9,-57.1);

    grilla gres = {make_tuple(puntoGps(-33.0,-58.0), puntoGps(-33.45,-57.7), make_tuple(1,2)),
                   make_tuple(puntoGps(-33.0,-57.7), puntoGps(-33.45,-57.4), make_tuple(1,1)),
                   make_tuple(puntoGps(-33.0,-57.4), puntoGps(-33.45,-57.1), make_tuple(1,3)),
                   make_tuple(puntoGps(-33.45,-58.0), puntoGps(-33.9,-57.7), make_tuple(2,1)),
                   make_tuple(puntoGps(-33.45,-57.7), puntoGps(-33.9,-57.4), make_tuple(2,2)),
                   make_tuple(puntoGps(-33.45,-57.4), puntoGps(-33.9,-57.1), make_tuple(2,3))
    };


    grilla g = construirGrilla(esq1,esq2,n,m);

    EXPECT_EQ(n*m, g.size());
}
TEST(construirGrillaTEST, nombresCorrectosDistanciaParNImparMParArg){

    int n = 3;
    int m = 2;

    gps esq1 = puntoGps(-33.0,-58.0);
    gps esq2 = puntoGps(-33.9,-57.1);

    grilla gres = {make_tuple(puntoGps(-33.0,-58.0), puntoGps(-33.30,-57.55), make_tuple(1,1)),
                   make_tuple(puntoGps(-33.0,-57.55), puntoGps(-33.30,-57.1), make_tuple(1,2)),
                   make_tuple(puntoGps(-33.30,-58.0), puntoGps(-33.60,-57.55), make_tuple(2,1)),
                   make_tuple(puntoGps(-33.30,-57.55), puntoGps(-33.60,-57.1), make_tuple(2,2)),
                   make_tuple(puntoGps(-33.60,-58.0), puntoGps(-33.90,-57.55), make_tuple(3,1)),
                   make_tuple(puntoGps(-33.60,-57.55), puntoGps(-33.90,-57.1), make_tuple(3,2))
    };


    grilla g = construirGrilla(esq1,esq2,n,m);

    EXPECT_EQ(n*m, g.size());
}



TEST(construirGrillaTEST, nombresIncorrectosDistanciaParNImparMParArg){

    int n = 3;
    int m = 2;

    gps esq1 = puntoGps(-33.0,-58.0);
    gps esq2 = puntoGps(-33.9,-57.1);

    grilla gres = {make_tuple(puntoGps(-33.0,-58.0), puntoGps(-33.30,-57.55), make_tuple(1,2)),
                   make_tuple(puntoGps(-33.0,-57.55), puntoGps(-33.30,-57.1), make_tuple(1,1)),
                   make_tuple(puntoGps(-33.30,-58.0), puntoGps(-33.60,-57.55), make_tuple(2,1)),
                   make_tuple(puntoGps(-33.30,-57.55), puntoGps(-33.60,-57.1), make_tuple(2,2)),
                   make_tuple(puntoGps(-33.60,-58.0), puntoGps(-33.90,-57.55), make_tuple(3,1)),
                   make_tuple(puntoGps(-33.60,-57.55), puntoGps(-33.90,-57.1), make_tuple(3,2))
    };


    grilla g = construirGrilla(esq1,esq2,n,m);

    EXPECT_EQ(n*m, g.size());
}


TEST(construirGrillaTEST, nombresCorrectosDistanciaParNImParMImparArg){

    int n = 3;
    int m = 3;

    gps esq1 = puntoGps(-33.0,-58.0);
    gps esq2 = puntoGps(-33.9,-57.1);

    grilla gres = {make_tuple(puntoGps(-33.0,-58.0), puntoGps(-33.3,-57.7), make_tuple(1,1)),
                   make_tuple(puntoGps(-33.0,-57.7), puntoGps(-33.3,-57.4), make_tuple(1,2)),
                   make_tuple(puntoGps(-33.0,-57.4), puntoGps(-33.3,-57.1), make_tuple(1,3)),
                   make_tuple(puntoGps(-33.3,-58.0), puntoGps(-33.6,-57.7), make_tuple(2,1)),
                   make_tuple(puntoGps(-33.3,-57.7), puntoGps(-33.6,-57.4), make_tuple(2,2)),
                   make_tuple(puntoGps(-33.3,-57.4), puntoGps(-33.6,-57.1), make_tuple(2,3)),
                   make_tuple(puntoGps(-33.6,-58.0), puntoGps(-33.9,-57.7), make_tuple(3,1)),
                   make_tuple(puntoGps(-33.6,-57.7), puntoGps(-33.9,-57.4), make_tuple(3,2)),
                   make_tuple(puntoGps(-33.6,-57.4), puntoGps(-33.9,-57.1), make_tuple(3,3))
                   };


    grilla g = construirGrilla(esq1,esq2,n,m);

    EXPECT_EQ(n*m, g.size());
}
