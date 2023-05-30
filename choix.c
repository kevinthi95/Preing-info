#include "choix.h"

void printSymbolWithColor(char al) { // pour choisir des couleurs 
switch (al) { // on associe chaque symbole à une couleur
        case '%':
          printf(RED "%c " RESET, al); // reset pour rénitialiser le style de texte par defaut 
          break;
        case '$':
          printf(GREEN "%c " RESET, al);
          break;
        case '#':
          printf(YELLOW "%c " RESET, al);
          break;
        case '&':
          printf(BLUE "%c " RESET, al);
          break;
        case '@':
          printf(MAGENTA "%c " RESET, al);
          break;
        case '~':
          printf(CYAN "%c " RESET, al);
          break;
        default:
          printf("%c ", al);
        break;
      }
    }


void carre(int nb, int n, int m, char tab[n][m]){ // fonction pour imprimer notre forme de base
  int i,j,a=0;
  char al,aled,b='a';
  char tabS[n][m];
  char tabSVal[]={'%', '#', '$', '&', '@', '~' }; // deuxieme tableau pour stocker les symboles 

  srand(time(NULL));
  for (i=0; i<=n; i++){
    printf("%2d ",a); // on imprime la colone d'indice
    a=a+1;
    for (j=0; j<m; j++){
      if(i==0){
       printf("%c ",b); // on imprime la ligne d'indice
       b=b+1;
      }
     
      if (i>0){
      al=rand()%nb;
      al=tabSVal[al];
      aled=al; // on remplis le tableau avec les symboles choisis aléatoirement
      //if(j>=3 || i>=3){
      do{
      al = rand() % nb;
      al=tabSVal[al];
      tabS[i][j]=al;
      aled=tabS[i][j];
      }while ((tabS[i][j-2] == tabS[i][j] && tabS[i][j-1]==tabS[i][j]) || (tabS[i-2][j]==tabS[i][j] && tabS[i-1][j]==tabS[i][j]) || (tabS[i-2][j-2]==tabS[i][j]&& tabS[i-1][j-1]==tabS[i][j]) || (tabS[i-1][j+1]==tabS[i][j] && tabS[i-2][j+2]==tabS[i][j]) || (verif1(nb,n,m,tab)!=0));
      //}
      printSymbolWithColor(aled); // On associe chaque symbole à une couleur
      }
    }
    printf("\n");
  }
  for (i=0; i<=n; i++){
    for(j=0; j<m; j++){
      tab[i][j]=tabS[i][j];
    }
  }
  
}

void choisirInfo(int *n,int *m, int *nb){
  int verif1,verif2,verif3;
  do{//pour limiter les cas ( pour la taille du tableau et pour que ce soit un nombre)
  verif1 =1;
  printf("\n Combien voulez-vous de ligne : ");
  verif1=scanf("%d" ,n);
  videbuffer();
  }while(*n<5 || *n>50 || verif1!=1);
  
  do{
  verif2=1;
  printf("Combien voulez-vous de colonne : ");
  verif2=scanf("%d" ,m);
  videbuffer();
  }while( *n<5 || *m>50 || verif2!=1); 
  // rajouter pour caractère aussi
  
  do{
  verif3=1;
  printf("Combien voulez-vous de symbole (entre 4 et 6):");
  verif3=scanf("%d" ,nb);
  videbuffer();
  }while (*nb<4 || *nb>6 || verif3!=1); //changer pour quand symbole 
  
}
