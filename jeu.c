#include "jeu.h"

void gravite(int nb, int n, int m, char tab[n][m]){
  int i,j,c=1;
  char tmp=' ',al, al1,al2;
  char tabSVal[]={'%', '#', '$', '&', '@', '~' };
  do{
  c=0;
  for (i=0; i<=n; i++){
    for(j=0; j<m; j++){
        
      if(i>1 && tab[i][j]==' '){ //si on a un espace
        tab[i][j]=tab[i-1][j]; // l'espace va etre remplacé par le symbole du dessus et le symboles du dessus est remplacé par l'espace
        tab[i-1][j]=tmp;
        c++;
      }
      if(i==1 && tab[i][j]==' '){ // quand on arrive sur la première ligne du tableau c'est de nouveau symboles qui sont générés
        al=rand()%nb;
        al=tabSVal[al];
        tab[i][j]=al;
      }
    }
  }
}while(c!=0); 
}

int suppSymb(int nb, int n, int m, char tab[n][m]){
  int i,j,a=0,c=1,k=0;
  char b='a';
  printf("test ");
  printf("ca me les pète \n");
  
  do{
      
  for (i=0; i<=n; i++){
    for(j=0; j<m; j++){
      int al=0;
      c=0;
      if (j<=m-2 && tab[i][j] == tab[i][j+1] && tab[i][j]==tab[i][j+2]){ // si alignement on supprime remplaces les symboles par des espaces 
        tab[i][j+1] =' ';
        tab[i][j+2] =' ';
        al=1;
        c++;
        k++; // augmentation pour le score 
      } 
      if ( i<=n-2 && tab[i][j]==tab[i+1][j] && tab[i][j]==tab[i+2][j]) {
        tab[i+1][j] =' ';
        tab[i+2][j] =' ';
        al=1;
        c++;
        k++;
      }
      if( j>=2 && i<=n-2 && tab[i][j]==tab[i+1][j-1] && tab[i][j]==tab[i+2][j-2]){
        tab[i+1][j-1] =' ';
        tab[i+2][j-2] =' ';     
        al=1;
        c++;
        k++;
      }
      if( j<=m-2 && i<=n-2 && tab[i][j]==tab[i+1][j+1] && tab[i][j]==tab[i+2][j+2]){
        tab[i+1][j+1] =' ';
        tab[i+2][j+2] =' ';
        al=1;
        c++;
        k++;
       }
       
      if(al==1){ // on a âs supprimé le troisieme symboles on le supprime maintenant  
        tab[i][j]=' ';
       }
    }
  }
  }while(c!=0); // on supprime jusqu'a ce qu'on rentre plus dans aucune boucle
  
  
  impressionTab(nb,n,m,tab); //on imprime le tableau
  
  gravite(nb, n, m, tab); // on fait descendre de nouveaux symboles  
   
  impressionTab(nb, n, m, tab); // on imprime le tableau
  
  return k;
}