#include <stdio.h>

typedef struct {
  char FN[24]; //firstname
  char MI; //middle initial
  char LN[16]; //lastname
}Nametype;

typedef struct {
  Nametype name;
  int ID;
  char course[8]; //BSCS, BSIS, BSIT
  int yrLevel;
}Studtype;

void displayHeader();
void displayStudent(Studtype S);
void readFile();

void displayStudent(Studtype S) {
  printf("%-10d", S.ID);
  printf("%-16s", S.name.LN);
  printf("%-24s", S.name.FN);
  printf("%-3c", S.name.MI);
  printf("%-8s", S.course);
  printf("%5d", S.yrLevel);
  printf("\n");
}

void displayHeader() {
  printf("\n\n");
  printf("%-10s", "ID No.");
  printf("%-16s", "Lastname");
  printf("%-24s", "Firstname");
  printf("%-3s", "MI");
  printf("%-8s", "Course");
  printf("%5s", "Year");
  printf("\n");
  printf("%-10s", "======");
  printf("%-16s", "========");
  printf("%-24s", "=========");
  printf("%-3s", "==");
  printf("%-8s", "======");
  printf("%5s", "====\n");
}

int main()
{
  FILE *fp;
  fp = fopen("students.dat", "rb");
  Studtype buffer;

  displayHeader();
  while(fread(&buffer, sizeof(Studtype), 1, fp) != 0){
    displayStudent(buffer);
  }

  fclose(fp);
  return 0;
}