#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    float puntos[4][3] = {{0, 0, 3}, {3, 0, 0}, {0, 0, 0}, {1, 7, 1}};
    float per1, per2, per3, per4, l1, l2, l3, l4, l5, l6;

    calcularPerimetro(puntos, &per1, &per2, &per3, &per4, &l1, &l2, &l3, &l4, &l5, &l6);
    float areaBase = per1 * per2;

    float areatotal = calcularArea(per1, per2, per3, per4, l1, l2, l3, l4, l5, l6);

    float altura = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);

    float volumen = calcularVolumen(areaBase, altura);

    printf("El perimetro es de: %f\n", per1 + per2 + per3 + per4);
    printf("El area es de: %f\n", areatotal);
    printf("El volumen es de: %f\n", volumen);

    return 0;
}

float calcularDistancia(float x1, float y1, float z1, float x2, float y2, float z2) {
    float distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
    return distancia;
}

void calcularPerimetro(float puntos[4][3],
                       float *per1, float *per2, float *per3, float *per4,
                       float *l1, float *l2, float *l3, float *l4, float *l5, float *l6) {
    *l1 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l2 = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l3 = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l4 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l5 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l6 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    
    *per1 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *per2 = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *per3 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *per4 = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[0][0], puntos[0][1], puntos[0][2]);

}

float calcularArea(float per1, float per2, float per3, float per4,
                   float l1, float l2, float l3, float l4, float l5, float l6) {
    float s1 = (per1 + per2 + l1) / 2;
    float s2 = (per3 + per4 + l2) / 2;
    float s3 = (per1 + per3 + l3) / 2;
    float s4 = (per2 + per4 + l4) / 2;
    float s5 = (l5 + l6 + l3) / 2;

    float areaBase = sqrt(s1 * (s1 - per1) * (s1 - per2) * (s1 - l1));
    float areaLateral1 = sqrt(s2 * (s2 - per3) * (s2 - per4) * (s2 - l2));
    float areaLateral2 = sqrt(s3 * (s3 - per1) * (s3 - per3) * (s3 - l3));
    float areaLateral3 = sqrt(s4 * (s4 - per2) * (s4 - per4) * (s4 - l4));
    float areaLateral4 = sqrt(s5 * (s5 - l5) * (s5 - l6) * (s5 - l3));

    float areaTotal = areaBase + areaLateral1 + areaLateral2 + areaLateral3 + areaLateral4;
    return areaTotal;
}

float calcularVolumen(float areaBase, float altura) {
    float volumen = (areaBase * altura) / 3;
    return volumen;
}

