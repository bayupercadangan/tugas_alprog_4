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
void menu4(DMinuman *pData, int pLength);

int main() {
  int menu; // Pilihan Menu
  int length; // Panjang data
  DMinuman *data; // Menampung dat
  FILE *myFile; // Menampung file

  // Pengecekan file
  myFile = fopen("dataminuman.txt", "r");
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
    fclose(myFile);
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
        menu4(data, length);
        exit(1);
        break;
      default:
        printf("Menu yang anda masukkan tidak tersedia!\n");
        exit(1);
        break;
    }
  } while (menu != 4);
  
  return 0;
}

void menu1(DMinuman *pData, int *pLength) {
  int length = *pLength, price, sizePrice;
  int isContinue;
  char validate = 'n';
  DMinuman *data = pData;
  length += 1;

  printf("\n=============== Input Data ===============\n");

  printf("Masukkan Nama Minuman (kopi / teh / coklat / soda): ");
  scanf("%s", data[length].nama);
  if (strcmp("kopi", data[length].nama) == 0 || strcmp("kopi", data[length].nama) == 0 || strcmp("coklat", data[length].nama) == 0 || strcmp("soda", data[length].nama) == 0) {
    isContinue = 1;
  } else isContinue = 0;

  printf("Masukkan Size (small = 1 / medium = 2 / large = 3): ");
  scanf("%s", data[length].size);
  if (strcmp("small", data[length].size) == 0 || strcmp("medium", data[length].size) == 0 || strcmp("medium", data[length].size) == 0) {
    isContinue = 1;
  } else isContinue = 0;

  printf("Masukkan Penyajian (dingin / panas / hangat): ");
  scanf("%s", data[length].serve);
  if (strcmp("dingin", data[length].serve) == 0 || strcmp("panas", data[length].serve) == 0 || strcmp("hangat", data[length].serve) == 0) {
    isContinue = 1;
  } else isContinue = 0;
  
  // Calculate price
  if (isContinue) {
    if (strcmp("small", data[length].size) == 0) sizePrice = 1;
    else if (strcmp("medium", data[length].size) == 0) sizePrice = 2;
    else if (strcmp("large", data[length].size) == 0) sizePrice = 3;
    else isContinue = 0;
    price = sizePrice * strlen(data[length].nama) * strlen(data[length].serve) * 100;
    data[length].price = price;

    printf("========= RESULT =========\n");
    printf("Nama      : %s \n", data[length].nama);
    printf("Size      : %s \n", data[length].size);
    printf("Penyajian : %s \n", data[length].serve);
    printf("Harga     : %d \n", data[length].price);

    printf("\nYaqueen mau nambahin data diatas?: (y / n)");
    scanf(" %c", &validate);

    if ('y' == validate) {
      *pLength = length;
      *pData = data[length];
      printf("Sukses Menambahkan data!\n\n");
    } else {
      printf("Yaah kok nggak jadi? Tapi bisa kok ntar milih input lagi\n\n");
    }
  } else {
    printf("TERDAPAT INPUT YANG TIDAK SESUAI!\n");
    printf("Pastikan input nama / size / penyajian sesuai dari yang ada!\n\n");
  }
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

// Exit and save data to dataminuman.txt
void menu4(DMinuman *pData, int length) {
  printf("\n=============== Exit Data ===============\n");
  FILE *fileOut = fopen("dataminuman.txt", "w");

  fprintf(fileOut, "%d\n", length); // Menulis jumlah data ke dataminuman.txt
  for (int i = 0; i < length; i++) { // Menulis 1/1 data ke dataminuman.txt
    fprintf(fileOut, "%s ", pData[i].nama);
    fprintf(fileOut, "%s ", pData[i].size);
    fprintf(fileOut, "%s ", pData[i].serve);
    fprintf(fileOut, "%d\n", pData[i].price);
  }

  fclose(fileOut);
  printf("DATA BERHASIL DISIMPAN!\n");
  exit(1);
}