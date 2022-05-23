#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TV_LLC_BIBLIO.h"



  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  le programme principale
int main (int argc, char *argv[])
{
     struct maillon_eq * tete_eq=NULL;
     Pointeur match1;
     printf("\n\n_______________________________________________________________________________________________\n\n");
     creationDeLaListeCalendrier(&match1); // creer la liste calendrier 8 maillons et affecter sa tete a match1
 tete_eq=creationDeLaListeEqAPartirDuFichierRang();
   tete_eq=triDeLaListe(tete_eq);
    Trr=creationDuTableauDesEquipes();
       T = malloc(16 * 255  * sizeof(string255));
       for (int _Izw3=0; _Izw3<16; ++_Izw3)
       T[_Izw3]= malloc(255 * sizeof(string255));
       int i=1, NombreDeFichier=1;
       char NomDuFichier[50];
       while (i==1)
  {
     sprintf(NomDuFichier,"rang%d.txt",NombreDeFichier);
     NombreDeFichier++;
    for (int g=0;g < 16; ++g)
     {
       strcpy(T[g],Trr[g]);
     }
  affecterLesMatchsDansLaListeCalendrier(match1,T);
  afficherLesMatchsDeLaJournee(match1);
  leMatchaDeffuse(match1,tete_eq);
  affecterLesResultatsDansLaListeCalendrier(match1);
  afficherLesResultatDeLaJournee(match1) ;
  misAJourDeLaListeEq(match1,tete_eq,NomDuFichier);      // et affichage du classement et creation d'un nouveau fichier rang
  i=0;
  printf("\nVoulez vous passer a la journee suivante\n\t");
  printf("1:oui             2:non \n\t");
  scanf("%d",&i);
  }

return 0 ;}
