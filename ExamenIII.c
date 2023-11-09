#include <stdio.h>

int main() {
  int i, j, cont = 0, com = 0, n=0 , arr2[3002]={0};
  char c;
  char arr1[3002][30]; 

  FILE *arc=fopen("emails.csv", "r");
  if (arc == NULL) {
    perror("Error al abrir el archivo");
    return 1;
  }

  while ((c = fgetc(arc)) != EOF) {
    if(c == '\n') {
      cont++;
      com = 0;
    } 
    else if (c == ',') {
      com++;
    }

    if (cont == 0) {
      if (com <= 3002 && com>=1 ) {
        arr1[com][0] = c;
      }
    }

  if (cont >= 732 && cont <= 782) {
      fscanf(arc, "%d", &n);
      if (com <= 3002 && com>=1 ) {
        arr2[com] += n;
      }
    }
  }

  fclose(arc);

  FILE *arch;
  arch=fopen("180732.txt","w");

  if(arch==NULL){
    perror("Error al crear archivo");
    return 1;
  }

  for (i = 0; i <=3002; i++) {
    fprintf(arch,"%s, %d\n ", arr1[i], arr2[i]);
  }

  fclose(arch);
  return 0;
}
