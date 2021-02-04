#include <stdio.h>
#include <stdlib.h>

typedef struct car
{
  char name[20];
  char color[20];
  float mass;
  int price;
} Cars;

int main()
{
  int i, n;
  Cars *cars;
  // READ:
  FILE *in = fopen("cars_in.txt", "r");
  fscanf(in, "%i", &n);                    //read how many cars are in the file
  cars = (Cars *)malloc(n * sizeof(Cars)); //allocate memory

  for (i = 0; i < n; ++i) //read data
  {
    fscanf(in, "%s", cars[i].name);
    fscanf(in, "%s", cars[i].color);
    fscanf(in, "%f", &cars[i].mass);
    fscanf(in, "%i", &cars[i].price);
  }

  fclose(in);

  ///////////// WRITE:
  FILE *out = fopen("cars_out.txt", "w");
  fprintf(out, "%d\n", n);
  for (i = 0; i < n; ++i)
  {
    fprintf(out, "%s ", cars[i].name);
    fprintf(out, "%s ", cars[i].color);
    fprintf(out, "%f ", cars[i].mass);
    fprintf(out, "%i\n", cars[i].price);
  }

  fclose(out);
  free(cars);
  return 0;
}