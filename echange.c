#include "echange.h"


int rechercheSym(int nb,int n,int m, char tab[n][m]){ // on teste l'alignement
  int i,j;
  int res=0;
  for( i=0; i<=n; i++){
    for(j=0; j<m; j++){
  if (i>2 && tab[i][j]==tab[i-1][j] && tab[i-1][j]==tab[i-2][j]){ // colonne
    res=1;
  } 
  if(j<m-1 && tab[i][j]==tab[i][j+1] && tab[i][j+1]==tab[i][j+2]){ // ligne
    res= 6;
  }
  if(i>2 && j<m-2 && tab[i][j]==tab[i-1][j+1] && tab[i][j]==tab[i-2][j+2]){ // diagonale vers le haut
    res= 9;
  } 
if(j<m-2 && i<n-1 && tab[i][j]==tab[i+1][j+1] && tab[i][j]==tab[i+2][j+2]){ // diagonale vers le bas 
  res= 10;
}
    }
  }
  return res;
}

void echangeSymb(int nb, int n, int m, char tab[n][m]){
  int i,j,a=0,test,res,res2,res3,disti,distl,verif1,verif2,verif3,verif4;
  int l=n,l2=n,tmp;
  char c=' ',c2=' ',sym=' ',b='a';
  char tab1[l][c], tab2[l][c];
  do{


  do{
  verif1=1;
  printf("Indiquez la ligne de la première case a echanger");
  verif1=scanf("%d",&l);
  videbuffer();
  }while(l<=0 || l>n || verif1!=1 );
  do{
  verif2=1;
  printf("choisir la colonne de la premiere case");
  verif2= scanf(" %c",&c);
  videbuffer();
  c=c-'a';
  }while( c<0|| c>=m || verif2!=1);

  do{
  do{
  verif3=1;
  printf("Indiquez la ligne de la seconde case a echanger");
  verif3=scanf("%d",&l2);
  videbuffer();
  }while(l2<=0 || l2>n|| verif3!=1 );
  do{
  verif4=1;
  printf("choisir la colonne de la seconde case");
  verif4= scanf(" %c",&c2);
  videbuffer();
  c2=c2-'a';
  }while( c<0|| c>=m || verif4!=1);
  disti=abs(c-c2);
  distl=abs(l-l2);
  printf("%d,%d",disti,distl);
  }while( (disti!=1 && disti!=0 )|| (distl!=0 && distl!=1) || (l!=l2 && c!=c2));

  sym=tab[l][c];
  tab[l][c]=tab[l2][c2];
  tab[l2][c2]=sym;

  tab1[l][c]=tab[l][c];
  tab2[l2][c2]=tab[l2][c2];

  res=rechercheSym(nb,n,m,tab); // on teste l'alignement pour les deux symboles
  res2=rechercheSym(nb,n,m,tab);
  if(res2==0 && res==0){
    res3=0;
  }
    else {
      res3=1;
    }
  }while(res3==0); // si ce n'est pas aligné on redemande

  impressionTab(nb,n,m,tab); // on imprime le tableau

}
