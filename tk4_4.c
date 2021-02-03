// #include <stdio.h>
// #include <string.h>

// struct Alamat
// {
//   char namaJalan[30];
//   char nomorRumah[15];
//   char kota[15];
//   char provinsi[30];
// };

// struct TanggalLahir
// {
//   int tgl;
//   char bulan[15];
//   int tahun;
// };

// struct Dosen
// {
//   int noDosen;
//   char nidn[50];
//   char nama[50];
//   struct Alamat alamat;
//   char tempatLahir[50];
//   struct TanggalLahir tanggalLahir;
// };

// int main()
// {
//   struct Dosen dosen[5];

//   printf("Masukkan 5 Data Dosen");
//   for (int i = 0; i < 1; i++)
//   {
//     int index = i + 1;
//     //Data Dosen
//     printf("Masukkan Data Dosen ke %d \n", index);
//     printf("\nNo. Dosen\t: ");
//     scanf("%d", &dosen[i].noDosen);
//     printf("NIDN\t\t: ");
//     scanf("%s", dosen[i].nidn);
//     printf("Nama\t\t: ");
//     scanf(" %[^\t\n]s", dosen[i].nama);

//     //Alamat Dosen
//     printf("\nMasukkan Alamat Dosen ke %d\n", index);
//     printf("\nNama Jalan\t: ");
//     scanf(" %[^\t\n]s", dosen[i].alamat.namaJalan);
//     printf("Nomor Rumah\t: ");
//     scanf(" %[^\t\n]s", dosen[i].alamat.nomorRumah);
//     printf("kota Tinggal\t: ");
//     scanf(" %[^\t\n]s", dosen[i].alamat.kota);
//     printf("provinsi\t: ");
//     scanf(" %[^\t\n]s", dosen[i].alamat.provinsi);

//     //Tanggal lahir Dosen
//     printf("\nMasukkan Tanggal Lahir Dosen ke %d", index);
//     printf("\nMasukkan Tempat Lahir\t: ");
//     scanf(" %[^\t\n]s", dosen[i].tempatLahir);
//     printf("Masukkan Tanggal \t: (ex: 09) ");
//     scanf("%d", &dosen[i].tanggalLahir.tgl);
//     printf("Masukkan Bulan \t\t: (ex: 12) ");
//     scanf("%s", dosen[i].tanggalLahir.bulan);
//     printf("Masukkan Tahun \t\t: (ex: 1999) ");
//     scanf("%d", &dosen[i].tanggalLahir.tahun);
//     printf("\n=================== Data ke %d selesai ===================\n", index);
//   }

//   //Menampilkan list data dosen
//   printf("\nHasil Record 5 Data Dosen :");

//   for (int i = 0; i < 1; i++)
//   {
//     int index = i + 1;
//     printf("\n=================== Data ke %d ===================\n", index);
//     printf("\nNo. Dosen          : %d\n", dosen[i].noDosen);
//     printf("NIDN                 : %s\n", dosen[i].nidn);
//     printf("Nama                 : %s\n", dosen[i].nama);
//     printf("Alamat               : %s No. %s, %s, %s\n", dosen[i].alamat.namaJalan, dosen[i].alamat.nomorRumah, dosen[i].alamat.kota, dosen[i].alamat.provinsi);
//     printf("Tempat Tanggal Lahir : %s, %d %s %d\n", dosen[i].tempatLahir, dosen[i].tanggalLahir.tgl, dosen[i].tanggalLahir.bulan, dosen[i].tanggalLahir.tahun);
//   }

//   return 0;
// }

#include <stdio.h>
#include <string.h>

int main() {
  int menu;

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
        printf("Input Menu");
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