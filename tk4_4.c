#include <stdio.h>
#include <string.h>

// Initiate size of file
#define DATA_SIZE 1000

// DataMinuman...
typedef struct DataMinuman {
  char nama[20];
  char size[10];
  char serve[10];
  int price;
} DMinuman ;

// Initiate Function
void menu1(DMinuman *pData);
void menu2(DMinuman *pData);
void menu3(DMinuman *pData, int index);
void menu4(DMinuman *pData);

int main() {
  int menu;
  char data[DATA_SIZE];
  FILE *fPtr;

  fPtr = fopen("dataminuman.txt", "w");

  if (fPtr == NULL) {
    fPtr = fopen("dataminuman.txt", "a");
  }

  printf("PROGRAM INPUT HISTORY JUALAN TOKO\n");
  printf("==========================================\n");

  do {
    printf("Pilih Menu Program: \n");
    printf("[1] Input Data \n");
    printf("[2] View History \n");
    printf("[3] Delete History \n");
    printf("[4] Exit \n");
    printf("Masukkan pilihan menu: ");
    scanf("%d", &menu);
    
    switch (menu) {
      case 1:
        printf("Input Data");
        break;
      case 2:
        printf("View History");
        break;
      case 3:
        printf("Delete History");
        break;
      case 4:
        printf("Exit!");
        break;
      default:
        break;
    }
  } while (menu != 4);
  

  return 0;
}