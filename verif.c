#include "verif.h"

int verif1(int nb, int n, int m, char tab[n][m]){ // pour verifier qu'il n'y a plus de symbole à échanger
int i,j;
  for (i=0; i<=n-1; i++){
    for(j=0; j<m-1; j++){
      if (j<m && tab[i][j] == tab[i][j+1]){ // on regarde quand deux symboles sont identiques 
        if((i>=2 && j>1 && tab[i][j]== tab[i-1][j-1]) || (j>=2 && tab[i][j]==tab[i][j-2])|| (i<n && j>=1 && tab[i][j]==tab[i+1][j-1]) ||(j<m-1 && i>=2 && tab[i][j]==tab[i-1][j+2])|| (j<m-2 && tab[i][j]==tab[i][j+3]) || (i<n && j<=m-2 && tab[i][j]==tab[i+1][j+2])){ // on fait tous les cas de déplacement possible //  verif ligne
          return 0; //si c'est possible on renvoit 0
        }
        //return 1;
      }
      if (i<n && tab[i][j] == tab[i+1][j]){
        if((i>1 && j>=1 && tab[i][j] == tab[i-1][j-1]) || (i>2 && tab[i][j]==tab[i-2][j]) || (i>1 && j<m && tab[i][j]==tab[i-1][j+1]) || (i<n-1 && j>=1 && tab[i][j]==tab[i+2][j-1]) || (i<n-2 && tab[i][j]==tab[i+3][j]) || (i<n-1 && j<m && tab[i][j]==tab[i+2][j+1])){ // verif colonne
          return 0;
        }
        //return 1;
      }
      if (i<n && j<m && tab[i][j] == tab[i+1][j+1]){
        if((j>=1 && tab[i][j]== tab[i][j-1]) || (i>1 && j>=2 && tab[i][j]==tab[i-1][j-2]) || (i>=1 && j>=1 && tab[i][j]==tab[i-2][j-1]) || (i>1 && tab[i][j]==tab[i-1][j])|| (i>1 && j<m && tab[i][j]==tab[i-1][j+1]) || (j<m-1 && tab[i][j]==tab[i][j+2]) || (i<n && j<m-1 && tab[i][j]==tab[i+1][j+2]) || (i<n-1 && tab[i][j]==tab[i+2][j]) || (i<n && j>=1 && tab[i][j]==tab[i+1][j-1]) || (i<n-1 && j<m && tab[i][j]==tab[i+2][j+1]) || (i<n-2 && j<m-1 && tab[i][j]==tab[i+3][j+2]) || (i<n-1 && j<m-2 && tab[i][j]==tab[i+2][j+3]) ){// verifi diagonale 1
          return 0;
        }
        //return 1;
      }
      if (i<n && j>=1 && tab[i][j] == tab[i+1][j-1]){
        if((i>=2 && tab[i][j]== tab[i-1][j]) || (i>2 && j<m && tab[i][j]==tab[i-2][j+1]) || (i>1 && j<m-1 && tab[i][j]==tab[i-1][j+2]) || (j<m && tab[i][j]==tab[i][j+1])|| (i<n && j<m && tab[i][j]==tab[i+1][j+1]) || (i>1 && j>=1 && tab[i][j]==tab[i-1][j-1]) || (j>=2 && tab[i][j]==tab[i][j-2]) || (i<n-1 && tab[i][j]==tab[i+2][j]) || (i<n-1 && j>=1 && tab[i][j]==tab[i+2][j-1]) || (i<n && j>=2 && tab[i][j]==tab[i+1][j-2]) || (i<n-1 && j>=3 && tab[i][j]==tab[i+2][j-3]) || (i<n-2 && j>=2 &&tab[i][j]==tab[i+3][j-2])){//verif diagonale 2
          return 0;
        }
        //return 1;
      }    
    }
  }
  return 1; // so ca ne rentre pas dans les conditions on renvoit 0
}