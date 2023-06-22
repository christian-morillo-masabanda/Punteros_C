#include <stdio.h>
#include <math.h>

float calcularDistancia(float x1, float x2, float y1, float y2, float z1, float z2);
void calcularPerimetro(float puntos[4][3] , 
                       float *per1, float *per2, float *per3, float *per4,
                       float *l1, float *l2, float *l3, float *l4, float *l5, float *l6);
float calcularArea(float per1, float per2, float per3, float per4,
                   float l1, float l2, float l3, float l4, float l5, float l6);

int main (int argc, char *argv[]) {
    
    float puntos[4][3]={(0,0,3),(3,0,0),(0,0,0),(1,7,1)};
    float per1, per2, per3, per4, perimetro, l1, l2, l3, l4, l5, l6; 

    calcularPerimetro(puntos, &per1, &per2, &per3, &per4, &l1, &l2, &l3, &l4, &l5, &l6); 
    float area = calcularArea(per1, per2, per3, per4, l1, l2, l3, l4, l5, l6);
    printf("El perimetro es de: %f\n", perimetro);
    printf("El area es de: %f\n", area); 

    return 0;
}

float calcularDistancia(float x1, float x2, float y1, float y2, float z1, float z2){
    float dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2)+pow(z1-z2,2));
    return dist;
}

void calcularPerimetro(float puntos[4][3] , 
                       float *per1, float *per2, float *per3, float *per4,
                       float *l1, float *l2, float *l3, float *l4, float *l5, float *l6){
    *l1 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l2 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l3 = calcularDistancia(puntos[2][0], puntos[2][1], puntos[2][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l4 = calcularDistancia(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l5 = calcularDistancia(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l6 = calcularDistancia(puntos[3][0], puntos[3][1], puntos[3][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *per1 = *l1 + *l2 + *l3;
    *per2 = *l2 + *l4 + *l6;
    *per3 = *l3 + *l5 + *l6; 
    *per4 = *l1 + *l5 + *l4; 
}


float calcularArea(float per1, float per2, float per3, float per4,
                   float l1, float l2, float l3, float l4, float l5, float l6){
    float perimetro = per1+per2+per3+per4; 
    float s = per1/2;
    float area1 = sqrt(s*(s-l1)*(s-l2)*(s-l3));
    float s1 = per2/2;
    float area2 = sqrt(s*(s1-l2)*(s1-l4)*(s1-l6));
    float s2 = per3/2;
    float area3 = sqrt(s*(s2-l3)*(s2-l5)*(s2-l6));
    float s3 = per4/2;
    float area4 = sqrt(s*(s3-l1)*(s3-l5)*(s3-l4));
    float areatotal = area1 + area2 + area3 + area4;  
    return areatotal;
}
