#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DataMinuman...
typedef struct DataMinuman {
  char nama[20];
  char size[10];
  char serve[10];
  int price;
} DMinuman ;

// Initiate Function
void menu1(DMinuman *pData, int *pLength);
void menu2(DMinuman *pData, int pLength);
void menu3(DMinuman *pData, int *pLength);
void menu4(DMinuman *pData);

int main() {
  int menu; // Pilihan Menu
  int length; // Panjang data
  DMinuman *data; // Menampung dat
  FILE *myFile; // Menampung file

  myFile = fopen("dataminuman.txt", "r"); // Membaca file

  // Pengecekan file
  if (myFile == NULL) {
    printf("File tidak ditemukan, gua buat dulu filenya nih...! \n");
    exit(1);
  } else {
    fscanf(myFile, "%i", &length); // Mendapatkan jumlah data
    for (int i = 0; i < length; i++) { // Looping menyimpan data dari file ke variable data
      fscanf(myFile, "%s", data[i].nama);
      fscanf(myFile, "%s", data[i].size);
      fscanf(myFile, "%s", data[i].serve);
      fscanf(myFile, "%d", &data[i].price);
    }
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
        menu1(&data[length], &length);
        break;
      case 2:
        menu2(data, length);
        break;
      case 3:
        menu3(data, &length);
        break;
      case 4:
        printf("Exit!");
        exit(1);
        break;
      default:
        exit(1);
        break;
    }
  } while (menu != 4);
  
  fclose(myFile);
  return 0;
}

void menu1(DMinuman *pData, int *pLength) {
  int length = *pLength, price;
  length += 1;
  DMinuman *data;
  *data = *pData;

  printf("\n=============== Input Data ===============\n");

  printf("Masukkan Nama Minuman (kopi / teh / coklat / soda): ");
  scanf("%s", data[length].nama);
  printf("Masukkan Size (small / medium / large): ");
  scanf("%s", data[length].size);
  printf("Masukkan Penyajian (dingin / panas / hangat: ");
  scanf("%s", data[length].serve);
  printf("Total Harga: ");
  scanf("%d", &data[length].price);

  *pLength = length;
  *pData = data[length];
  printf("Sukses Menambahkan data!\n");
};

// View History
void menu2(DMinuman *pData, int pLength) {
  printf("\n=============== View History ===============\n");
  for (int i; i < pLength; i++) {
    printf("%d. ", i+1);
    printf("%s, %s, %s, Rp. %d \n", pData[i].nama, pData[i].size, pData[i].serve, pData[i].price);
  }
  printf("\n=============== Selesai menampilkan History, silakan pilih menu lagi \n");
}

// Delete data by Index
void menu3(DMinuman *pData, int *pLength) {
  int position, length;
  length = *pLength;

  printf("\n=============== Delete Data ===============\n");
  printf("Masukkan posisi data yang akan dihapus: ");
  scanf("%d", &position);

  if (position < 0 || position > length) {
    printf("Invalid Position! Masukkan posisi antara 1 dengan %d", length);
  } else {
    for (int i = position - 1; i < length - 1; i++) {
      pData[i] = pData[i+1];
    }
    length--;
    printf("Data ke %d berhasil dihapus\n", position);
  }

  *pLength = length;
}