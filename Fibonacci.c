#include <stdio.h>

unsigned long long int Fibonacci(unsigned long long int n) {
  if (n == 0) 
    return 0;
  else if(1 == n)
    return 1;
  else if(n > 1){
    return (Fibonacci(n-2) + Fibonacci(n-1));
  }
}
int main() {
  unsigned long long int n;
  printf("Ingresa un numero:\n");
  scanf("%llu", &n);
  printf("Los elementos de la serie son:\n");
  printf("%llu\n", Fibonacci(n));
  return 0;
}


