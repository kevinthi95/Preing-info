#include "choix.h"
#include "echange.h"
#include "jeu.h"
#include "save.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <math.h>
#include <unistd.h>
#include <string.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"


unsigned long getTimeMicroSec() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    unsigned long microseconds = (tv.tv_sec * 1000000) + (tv.tv_usec);
    return microseconds;
}

void videbuffer(){ // pour limitier les possibilité dans les do while
  while(getchar()!='\n');
}

void impressionTab(int nb, int n, int m, char tab[n][m]){ // fonction qui imprime le tableau
  int i,j,a=0;
  char b='a';
  for (i=0; i<=n; i++){
    printf("%2d ",a);// imprime colone d'indice
    a=a+1;
    for(j=0; j<m; j++){
      if(i==0){
       printf("%c ",b);// imprime ligne d'indice
       b=b+1;
      }
     
      if (i>0){
      printSymbolWithColor(tab[i][j]); // imprime le tableau
    }
    }
    printf("\n");
  }
}


int main(void) {
  int i=0, j=0, n, m, nb,k=0,a,gam,verif,t,t1,t2,score[9];
  char prn[10];
  printf("\n Bonjour, vous voici dans le monde merveilleux de copicrush.Le but de ce jeux est de parvenir à reunir 3 mêmes symboles, facile non ? A chaque fois que 3 symboles sont alignés ils disparaitront et vous gagnerez des points.\nA vous de jouer !!! \n \nComment veux tu t'appeler : ");
  scanf("%s" ,prn);
  
  do{
  verif=1;
  printf("Si vous voulez prendre une nouvelle partie taper 1. Si vous voulez prendre une ancienne taper 2\n ");
  verif=scanf("%d" ,&gam);
  videbuffer();
  }while(gam!=1 && gam!=2 || verif!=1);
  
  if(gam==1){// si nouvelle partie
  choisirInfo(&n, &m, &nb);
  }
  
  char tab[n][m];
  
  if (gam==1){
  carre(nb, n, m, tab);
  }
  
  if (gam==2){ // si ancienne partie
      if(enregistrement2(&nb,&n,&m,tab,&k)==1){ // on recupère l'ancienne partie
      printf("score : %d" ,k);
      for(i=0; i<=n; i++){
          for(j=0; j<m; j++){
             printf("%d" ,tab[i][j]);
         }
      }
      impressionTab(nb,n,m,tab);
  }
  
  }

  t=getTimeMicroSec(); // on démarre le chrono 
  
  do{
  echangeSymb(nb, n, m, tab); // on echange deux symboles 
  do{
  for (i=0; i<=n; i++){
    for(j=0; j<m; j++){
      if((j<=m-2 && tab[i][j] == tab[i][j+1] && tab[i][j] == tab[i][j+2]) || (i<=n-2 && tab[i][j] == tab[i+1][j] && tab[i][j] == tab[i+2][j]) || (i<=n-2 && j>=2 && tab[i][j] == tab[i+1][j-1] && tab[i][j] == tab[i+2][j-2]) || (i<n-1 && j<=m-2 && tab[i][j] == tab[i+1][j+1] && tab[i][j] == tab[i+2][j+2])){ // si trois symboles identiques 
    a=suppSymb(nb, n, m, tab); // on supprime ces symboles 
    k=k+a; // on incrémente le score
     }
   }
 }
 //printf("score : %d \n ",k);
 
  }while(rechercheSym(nb,n,m,tab)!=0); // on supprime les symboles tant que trois symboles identiques sont à cotés
    enregistrement(nb,n,m,tab,k); // on enregistre la partie
    t1=getTimeMicroSec();
    t2=(t1-t)/1000000;
    printf("temps : %ds \n" ,t2);
  }while(verif1(nb,n,m,tab)==0); // on echange les symboles tant que des échanges sont en encore possible
//}
t1=getTimeMicroSec();
t2=t1-t;
printf("%d \n ",k);
  printf("Super %s , tu as marqué au total %d points ! " ,prn,k);
  enregistrement3a(k,score);// j'enregistre mon score
  enregistrement3b(&k,score);// je donne les meilleurs score effectués
  //prinft("Veux tu refaire une partie ? " ,nvlP); 
  return 0;
}

