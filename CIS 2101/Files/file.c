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
  printf("%5s", "====");
}

int main()
{
  displayHeader();
  return 0;
}