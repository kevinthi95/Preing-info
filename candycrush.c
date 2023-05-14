#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

// des fois ca met pas l 'espace je capte pas pourquoi et faute faire une boucle pour que une fois supp ca repasse et ressupp les nouveaux trois alignés ( j'ai essayé 30 sec ca n' a pas marché) ++ ( des fois quand ca supp une ligne plus diago la gravité marche pas super bien (j'ai capté pourquoi donc j'ai mis des else if au lieu des if partout mais du coup quand on ehcnage deux symboles et que ca crée deux alignement a la fois ca en enlève qu'un seul))

// A FAIRE : -do while x2( limiter les risques )  - -timer qui faudra mettre aussi

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

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
    printf("%2d ",a);
    a=a+1;
    for (j=0; j<m; j++){
      if(i==0){
       printf("%c ",b);
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
      }while ((tabS[i][j-2] == tabS[i][j] && tabS[i][j-1]==tabS[i][j]) || (tabS[i-2][j]==tabS[i][j] && tabS[i-1][j]==tabS[i][j]) || (tabS[i-2][j-2]==tabS[i][j]&& tabS[i-1][j-1]==tabS[i][j]) || (tabS[i-1][j+1]==tabS[i][j] && tabS[i-2][j+2]==tabS[i][j]));
      //}
      printSymbolWithColor(aled); // procéédure couleur + printf
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
  char nb1,nb2;
  do{
  printf("Choisir le nombre de ligne : "); // faire do while pour eviter les crashs
  scanf("%d" ,n);
  }while(*n<=0);
  do{
  printf("Choisir le nombre de colonne : ");
  scanf("%d" ,*&m);
  }while(*m<=0 ); 
  // rajouter pour caractère aussi
  do{
  printf("Choisir le nombre de symbole (entre 4 et 6):");
  scanf("%d" ,nb);
  }while (*nb<4 || *nb>6 ); //changer pour quand symbole 
  
}

int rechercheSym(int nb,int n,int m,int l, int c, char tab[n][m]){
  int res=0;
  if (l>2 && tab[l][c]==tab[l-1][c] && tab[l-1][c]==tab[l-2][c]){
    res=1;
  } 
if(l>=2 && l<n && tab[l][c]==tab[l-1][c] && tab[l-1][c]==tab[l+1][c]){
  res=2;
} 
if( l<n-1 && tab [l][c]==tab[l+1][c] && tab[l+1][c]==tab[l+2][c]){
  res=3;
} 
  if(c>=2 && tab[l][c]==tab[l][c-1] && tab[l][c-1]==tab[l][c-2]){
    res=4;
  } //ca rentre toujours dans cette boucle
  if (c>=2 && c<m && tab[l][c]==tab[l][c-1] && tab[l][c-1]==tab[l][c+1]){
    res=5;
  } if(c<m-1 && tab[l][c]==tab[l][c+1] && tab[l][c+1]==tab[l][c+2]){
    res=6;
  }// on a fait pour ligne et colonne on fait maintenant pour diagonale croisons les doigts (spoil ca marche pas je pleure viens m'aider)
  if (l>2 && c>=2 && tab[l][c]==tab[l-2][c-2] && tab[l][c]==tab[l+1][c-1]){
    res=7;
  } 
  if(l>1 && c>=1 && l<n && c<m && tab[l][c]==tab[l+1][c-1] && tab[l][c]==tab[l-1][c+1]){
    res=8;
  } 
  if(l>2 && c<m-2 && tab[l][c]==tab[l-1][c+1] && tab[l][c]==tab[l-2][c+2]){
    res=9;
  } 
if(c<m-2 && l<n-1 && tab[l][c]==tab[l+1][c+1] && tab[l][c]==tab[l+2][c+2]){
  res=10;
} if(l>1 && c>=1 && l<n && c<m && tab[l][c]==tab[l+1][c+1] && tab[l+1][c+1]==tab[l-1][c-1]){
  res=11;
} 
  if(l>2 && c>=2 && tab[l][c]==tab[l-1][c-1] && tab[l-1][c-1]==tab[l-2][c-2]){
    res=12;
  }
  return res;
}

void testouille(int nb, int n, int m, char tab[n][m]){
  int i,j,a=0;
  char b='a';
  for (i=0; i<=n; i++){
    printf("%2d ",a);
    a=a+1;
    for(j=0; j<m; j++){
      if(i==0){
       printf("%c ",b);
       b=b+1;
      }
     
      if (i>0){
      printSymbolWithColor(tab[i][j]);
    }
    }
    printf("\n");
  }
}


void echangeSymb(int nb, int n, int m, char tab[n][m]){
  int i,j,a=0,test,res,res2,res3;
  int l=n,l2=n,tmp;
  char c=' ',c2=' ',sym=' ',b='a';
  char tab1[l][c], tab2[l][c];
  do{
  printf("Indiquez la ligne de la première case à échanger puis sa colonne:");
  scanf("%d",&l);
  scanf(" %c",&c);
  c=c-'a';
  printf("c=%d \n" ,c);
  }while(l<=0 || l>n || c<0|| c>=m);

  do{
  printf("Indiquez la ligne de la seconde case à échanger puis sa colonne::");
  scanf("%d",&l2);
  scanf(" %c",&c2);
  c2=c2-'a';
  }while(l2<=0 || l2>n || c2<0|| c2>=m || (l!=l2 && c!=c2));
  printf("%d \n" ,c2);
  sym=tab[l][c];
  printf("sym=%c \n" ,sym);
  tab[l][c]=tab[l2][c2];
  printf("tab[l][c]=%c \n" ,tab[l][c]);
  tab[l2][c2]=sym;
  printf("tab[l2][c2]%c \n" ,tab[l2][c2]);

  tab1[l][c]=tab[l][c];
    printf("tab1=%c \n" ,tab1[l][c]);
  tab2[l2][c2]=tab[l2][c2];
    printf("tab2=%c\n" ,tab2[l2][c2]);
    
  //res=rechercheSym(nb,n,m,l,c,tab1);
  res2=rechercheSym(nb,n,m,l2,c2,tab2); 
  if(res2==0 && res==0){
    res3=0;
  }
    else {
      res3=1;
    }
    printf("res1=%d res2=%d res3=%d \n" ,res,res2,res3);
  //}while((res3==0));

  testouille(nb,n,m,tab);

}

void suppSymb(int nb, int n, int m, char tab[n][m]){
  int i,j,a=0;
  char b='a';
  printf("test ");
  printf("ca me les pète \n");
  for (i=2; i<=n-1; i++){
    for(j=2; j<m-1; j++){
      if (j>1 && tab[i][j] == tab[i][j-1] && tab[i][j]==tab[i][j-2]){
        tab[i][j] = ' ';
        tab[i][j-1] =' ';
        tab[i][j-2] =' ';
        break;
      } 
      else if (i>2 && tab[i][j]==tab[i+1][j] && tab[i][j]==tab[i+2][j]) {
        tab[i][j] = ' ';
        tab[i+1][j] =' ';
        tab[i+2][j] =' ';
        break;
      }
      else if(i>2 && j>1 && tab[i][j]==tab[i+1][j+1] && tab[i][j]==tab[i+2][j+2]){
        tab[i][j] = ' ';
        tab[i+1][j+1] =' ';
        tab[i+2][j+2] =' ';     
        break;
      }
      else if(i>2 && j>1 && tab[i][j]==tab[i-1][j+1] && tab[i][j]==tab[i-2][j+2]){
        tab[i][j] = ' ';
        tab[i-1][j+1] =' ';
        tab[i-2][j+2] =' ';
        break;
       }
        
    }
  } 
  testouille(nb,n,m,tab);
  
  printf("tu sors ? \n");
}


void gravite(int nb, int n, int m, char tab[n][m]){
  int i,j,c;
  char tmp=' ',al, al1,al2;
  char tabSVal[]={'%', '#', '$', '&', '@', '~' };
  for (i=0; i<=n; i++){
    for(j=0; j<m; j++){

      if (j>1 && i>1 && tab[i][j] == ' ' && tab[i][j-1] ==' ' && tab[i][j-2] ==' '){
        tab[i][j]=tab[i-1][j];
        tab[i-1][j]=tmp;
        tab[i][j-1]=tab[i-1][j-1];
        tab[i-1][j-1]=tmp;
        tab[i][j-2]=tab[i-1][j-2];
        tab[i-1][j-2]=tmp;
      } 

      else if ( tab[i][j] == ' ' && tab[i][j-1] ==' ' && tab[i][j-2] ==' '){
        al = rand() % nb;
        al=tabSVal[al];
        tab[i][j]=al;
        al1=rand() % nb;
        al1=tabSVal[al1];
        tab[i][j-1]=al1;
        al2=rand() % nb;
        al2=tabSVal[al2];
        tab[i][j-2]=al2;
      }

      else if (i>3 && i<=8 && tab[i][j] == ' ' && tab[i+1][j] == ' ' && tab[i+2][j] == ' '){
        tab[i][j]=tab[i-3][j];
        tab[i-3][j]=tmp;
        tab[i+1][j]=tab[i-2][j];
        tab[i-2][j]=tmp;
        tab[i+2][j]=tab[i-1][j];
        tab[i-1][j]=tmp;
      }

      else if ( tab[i][j] == ' ' && tab[i+1][j] == ' ' && tab[i+2][j] == ' '){
        al = rand() % nb;
        al=tabSVal[al];
        tab[i][j]=al;
        al1=rand() % nb;
        al1=tabSVal[al1];
        tab[i+1][j]=al1;
        tab[i+2][j]=tab[i-1][j];
      }
      
      else if(i>3 && j>2 && tab[i][j] == ' ' && tab[i-1][j-1] == ' ' && tab[i-2][j-2] == ' '){  
        tab[i][j]=tab[i-1][j];
        tab[i-1][j]=tmp;
        tab[i-1][j-1]=tab[i-2][j-1];
        tab[i-2][j-1]=tmp;
        tab[i-2][j-2]=tab[i-3][j-2];
        tab[i-3][j-2]=tmp;
      }

      else if( tab[i][j] == ' ' && tab[i-1][j-1] == ' ' && tab[i-2][j-2] == ' '){ 
        
        tab[i][j]=tab[i-1][j];
        tab[i-1][j-1]=tab[i-2][j-1];
        al1=rand() % nb;
        al1=tabSVal[al1];
        tab[i-2][j-2]=al1;
      }
      
      else if (i>3 && j<=8 && tab[i][j] == ' ' && tab[i-1][j+1] ==' ' && tab[i-2][j+2] ==' '){
        tab[i][j]=tab[i-1][j];
        tab[i-1][j]=tmp;
        tab[i-1][j+1]=tab[i-2][j+1];
        tab[i-2][j+1]=tmp;
        tab[i-2][j+2]=tab[i-3][j+2]; 
        tab[i-3][j+2]=tmp;
       }

      else if ( tab[i][j] == ' ' && tab[i-1][j+1] ==' ' && tab[i-2][j+2] ==' '){
        tab[i][j]=tab[i-1][j];
        tab[i-1][j+1]=tab[i-2][j+1];
        al1=rand() % nb;
        al1=tabSVal[al1];
        tab[i-2][j+2]=al1;
      }
      
    }
  }
}

int main(void) {
  int i, j, n, m, nb;
  choisirInfo(&n, &m, &nb);
  char tab[n][m];
  carre(nb, n, m, tab);
  echangeSymb(nb, n, m, tab);
  do {
    suppSymb(nb, n, m, tab);

    do {
      for (i = 0; i <= n; i++) {
        for (j = 0; j < m; j++) {
          gravite(nb, n, m, tab);
        }
      }
      
    } while ((i > 2 && j > 1 && tab[i][j] == ' ' && tab[i-1][j+1] == ' ' && tab[i-2][j+2] == ' ')
           || (i > 2 && j > 1 && tab[i][j] == ' ' && tab[i-1][j-1] == ' ' && tab[i-2][j-2] == ' ')
           || (i > 2 && tab[i][j] == ' ' && tab[i+1][j] == ' ' && tab[i+2][j] == ' ')
           || (i > 2 && j > 2 && tab[i][j] == ' ' && tab[i][j-1] == ' ' && tab[i][j-2] == ' '));

    testouille(nb, n, m, tab);


  } while ((i > 2 && j > 1 && tab[i][j] == tab[i][j-1] && tab[i][j] == tab[i][j-2])
         || (i > 2 && tab[i][j] == tab[i-1][j] && tab[i][j] == tab[i-2][j])
         || (i > 2 && j > 1 && tab[i][j] == tab[i-1][j-1] && tab[i][j] == tab[i-2][j-2])
         || (i > 2 && j > 1 && tab[i][j] == tab[i-1][j+1] && tab[i][j] == tab[i-2][j+2]));


  return 0;
}

