#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int aup = *a;
  *a = *b;
  *b = aup;
}

void printfarray(int arr[], int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d: ", arr[i]);
  }
}

void selectsort(int arr[], int n) {
  int i, j, min;
  for (i=0; i < n-1; i++) {
    min = i;
    for (j=i + 1; j<n; j++) {  
      if (arr[min] > arr[j]) {
        min = j;
      }
    }
    swap(&arr[min], &arr[i]);
  }
}

float media(int arr[], int n) {
  float sum = 0;
  int i;
  for (i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum / n;
}

float mediana(int arr[], int n) {
  int d;
  float sum;  
  if (n % 2 == 0) {
    d=n/2;
    sum = (arr[d-1]+arr[d])/2;  
  } else {
    d=n/2;
    sum = arr[d];  
  }
  return sum;
}

int max(int arr[], int n) {
  int i, index=0, a=-10000;
  for(i=0; i<n; i++) {
    if(arr[i] > a) {
      index=i;
      a=arr[i];
    }
  }
  return index;
}

void histograma(float aux[30],int n){
  int i,j;
  for(i=0; i<30; i++){
    printf("%d: ", i+1);
    for(j=0; j< round((aux[i]/n)*100); j++){
      printf("* ");
    }
    printf("\n");
  }
}

void moda(int arr[], int n) {
  int i, j, f=0, num, cont=0;
  float aux[30];
  for (i=0; i<30; i++) {
    num = i+1;
    for (j=0; j<n; j++) {
      if (arr[j] == num) {
        f++;
      }
    }
  aux[i]=f;
  f=0;
}
  for(i=0; i<30; i++){
    if(aux[i]==aux[max(aux, 30)]){
      printf("Moda: %d\n", i+1);
      printf("Numero de veces: %.0f\n", aux[max(aux, 30)]);
    }
  }
  if(aux[max(aux, 30)]==1){
    printf("No hay moda\n");
  }
  printf("Histograma\n");
  histograma(aux,n);
}


int main() {
  int i, j, k, n, aux[30];

  printf("Numero de elementos en su arreglo: ");
  scanf("%d", &n);
  int arr[n];

  srand(time(NULL));
  for (i = 0; i < n; i++) {
    arr[i] = rand() % 30 + 1;
  }

  printf("Sin ordenar\n");
  printfarray(arr, n);
  printf("\n\n");
  
  selectsort(arr, n);

  printf("Ordenado\n");
  printfarray(arr, n);
  printf("\n\n");

  printf("Valor minimo: %d", arr[0]);
  printf(", Valor maximo: %d\n", arr[n - 1]);

  printf("\n\n");
  printf("Media: %f", media(arr, n));
  printf(", Mediana: %f\n", mediana(arr, n));  
  moda(arr, n);
  return 0;
}
