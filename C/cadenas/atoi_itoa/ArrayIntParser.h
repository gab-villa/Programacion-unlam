#ifndef ARRAYINTPARSER_H_INCLUDED
#define ARRAYINTPARSER_H_INCLUDED


#define BASEDEC 10
#define BASEMAX 16
#define BASEMIN 2
#define VACIO '\0'

int miAtoi(const char* cad);
char* miItoa(char* cad, int num, int base);
char itoc(int num);
int ctoi(char car);
void invertirCad(char* cad);
#endif // ARRAYINTPARSER_H_INCLUDED
