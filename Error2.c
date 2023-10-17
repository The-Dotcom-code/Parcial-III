#include <stdio.h>

float perimetroFigura(float numero){
  float perimetro;
  perimetro= 4*numero;
  return (perimetro);

}

float areafigura(float numero){
  float area;
  area=numero*numero;
  return(area);
}

int main(){
  float num;
  printf("Lado de un cuadrado: ");
  scanf(" %f", &num);
  printf("Perimetro: %f\n", perimetroFigura(num));
  printf("Area: %f\n", areafigura(num));
  return 0;
}