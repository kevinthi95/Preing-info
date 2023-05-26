#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>

void enregistrement(int nb, int n, int m, char tab[n][m], int k);
int enregistrement2(int *nb, int *n, int *m, char tab[*n][*m], int *k );
void enregistrement3a(int k, int score[9]);
int enregistrement3b(int *k, int score[9]);

#endif