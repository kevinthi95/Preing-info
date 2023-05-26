#ifndef FONCTIONS_H_
#define FONCTIONS_H_


#include <stdio.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


void gravite(int nb, int n, int m, char tab[n][m]);

int suppSymb(int nb, int n, int m, char tab[n][m]);
#endif