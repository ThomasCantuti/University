#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pigreco 3.14

#include "Figure.h"

void quadrato(Figura *pf, float l){
    pf->tipo_figura = Quadrato;
    pf->dati_figura.datiQuadrato.lato = l;
}

void rettangolo(Figura *pf, float b, float h){
    pf->tipo_figura = Rettangolo;
    pf->dati_figura.datiRettangolo.base = b;
    pf->dati_figura.datiRettangolo.altezza = h;
}

void triangolo(Figura *pf, float a, float b, float c){
    pf->tipo_figura = Triangolo;
    pf->dati_figura.datiTriangolo.a = a;
    pf->dati_figura.datiTriangolo.b = b;
    pf->dati_figura.datiTriangolo.c = c;
}

void cerchio(Figura *pf, float r){
    pf->tipo_figura = Cerchio;
    pf->dati_figura.datiCerchio.raggio = r;
}

float perimetro(Figura *pf){
    switch (pf->tipo_figura)
    {
    case Quadrato:
        return pf->dati_figura.datiQuadrato.lato*4;
        break;
    case Rettangolo:
        return (pf->dati_figura.datiRettangolo.altezza + 
        pf->dati_figura.datiRettangolo.base) * 2;
        break;
    case Triangolo:
        return  pf->dati_figura.datiTriangolo.a + 
                pf->dati_figura.datiTriangolo.b +
                pf->dati_figura.datiTriangolo.c;
        break;
    case Cerchio:
        return pf->dati_figura.datiCerchio.raggio * pigreco * 2;
        break;
    default:
        break;
    }
}

float area(Figura *pf){
    switch (pf->tipo_figura)
    {
    case Quadrato:
        return pf->dati_figura.datiQuadrato.lato * pf->dati_figura.datiQuadrato.lato;
        break;
    case Rettangolo:
        return pf->dati_figura.datiRettangolo.base * pf->dati_figura.datiRettangolo.altezza;
        break;
    case Triangolo:
        return  sqrt(perimetro(pf)/2 * 
        (perimetro(pf)/2 - pf->dati_figura.datiTriangolo.a) *
        (perimetro(pf)/2 - pf->dati_figura.datiTriangolo.b) *
        (perimetro(pf)/2 - pf->dati_figura.datiTriangolo.c));
        break;
    case Cerchio:
        return pf->dati_figura.datiCerchio.raggio * 
        pf->dati_figura.datiCerchio.raggio * 
        pigreco;
        break;
    default:
        break;
    }
}