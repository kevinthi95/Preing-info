#include "save.h"

void enregistrement(int nb, int n, int m, char tab[n][m], int k){ // enregistre la partie en cours
    int i,j;
  FILE* fichier = fopen("sauvegarde.txt", "w");
  if (fichier == NULL){
     printf("erreur lors de l'ouverture");
     return;
  }
  fprintf(fichier, "nb de symbole: %d\n", nb);
  fprintf(fichier, "nb de ligne: %d\n", n);
  fprintf(fichier, "nb de colone: %d\n", m);
  fprintf(fichier, "score: %d\n", k);
  
    for (i=1; i<=n; i++){
        for(j=0; j<m; j++){
            fprintf(fichier, "%c", tab[i][j]);
        }
        fprintf(fichier, "\n");
    }
    
  fclose(fichier);
  printf("partie sauvegardée avec succes \n");
}

int enregistrement2(int *nb, int *n, int *m, char tab[*n][*m], int *k ){ // pour renvoyer la partie en cours 
    int i,j;
    char al;
    FILE* fichier = fopen("sauvegarde.txt", "r");
    if (fichier == NULL){
     printf("aucune partie sauvegardée\n");
     return 0;
    }
fscanf(fichier, "nb symbole: %d\n", nb);
fscanf(fichier, "nb ligne: %d\n", n);

fscanf(fichier, "nb colone: %d\n", m);
fscanf(fichier, "score: %d\n", k);
  for (i=0; i<=*n; i++){
    for(j=0; j<*m; j++){
fscanf(fichier, "%c", &tab[i][j]); //pk &
}
}
char ligne[256]; // Définissez une taille appropriée pour la ligne
while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
    printf("%s", ligne); // Affiche la ligne
}

fclose(fichier);
printf("partie chargée avec succes \n");
return 1;
}

void enregistrement3a(int k, int score[9]){// on enregistre le score et on le compare aux autres scores enregistrés
    int i,x=0;
  FILE* fichier = fopen("score.txt", "w");
 if (fichier == NULL){
     printf("erreur lors de l'ouverture");
     return;
  }
  
fprintf(fichier, "score: %d\n", k);
for (i=9; i>=0; i--){
  if (k>score[i]){
    score[i+1]=score[i];
    
  }
  else if (k>score[i] && i==0){
      score[i]=k;
  }
  else if (k<score[i] && x==0) { 
    score[i+1]=k;
    x=1;
  }  
}
for (i=0; i<=9; i++){
fprintf(fichier, "%d /n ",score[i]);
}
fclose(fichier);
printf("score chargée avec succes \n");
}

int enregistrement3b(int *k, int score[9]){ // on récupère le score
int i,j;
FILE* fichier = fopen("sauvegarde.txt", "r");
    if (fichier == NULL){
     printf("aucune partie sauvegardée\n");
     return 0;
    }
    for (i=0; i<=9; i++){
     fscanf(fichier, "%d /n ",&score[i]);
    }
fclose(fichier);
printf("partie chargée avec succes \n");
return 1;
}