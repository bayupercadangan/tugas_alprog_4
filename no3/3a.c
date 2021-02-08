/*
Dynamic Memory, memungkinkan sebuah program untuk lebih fleksibel mendapatkan ruang memory.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
  int* ptr;
  int n;
  printf("Angka yang digunakan: ");
  scanf("%d", &n);

  ptr = (int*)malloc(n * sizeof(int));

  if (ptr == NULL) {
    printf("Memory not allocated. \n");
    exit(0);
  } else {
    printf("Sukses mengalokasikan memory dengan menggunakan malloc. \n");
    for (int i = 0; i < n; i++) {
      ptr[i] = i + 1;
    }

    printf("Isi dari Arraynya adalah: ");
    for (int i = 0; i < n; i++) {
      printf("%d ", ptr[i]);
    }
  }

  printf("\n");
  return 0;
}