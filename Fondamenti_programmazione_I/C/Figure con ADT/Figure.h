#include <math.h>

typedef struct{
    float lato;
} DatiQuadrato;

typedef struct{
    float base, altezza;
} DatiRettangolo;

typedef struct{
    float a, b, c;
} DatiTriangolo;

typedef struct{
    float raggio;
} DatiCerchio;

typedef struct{
    enum{
        Quadrato, Rettangolo,
        Triangolo, Cerchio
    }tipo_figura;

    union{
        DatiQuadrato datiQuadrato;
        DatiRettangolo datiRettangolo;
        DatiTriangolo datiTriangolo;
        DatiCerchio datiCerchio;
    } dati_figura;
}Figura;

void quadrato(Figura *pf, float l);
void rettangolo(Figura *pf, float b, float h);
void triangolo(Figura *pf, float a, float b, float c);
void cerchio(Figura *pf, float r);
float perimetro(Figura *pf);
float area(Figura *pf);