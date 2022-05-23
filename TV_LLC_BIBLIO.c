#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "TV_LLC_BIBLIO.h"

// liste eq et ses fonctions
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  1
void allouer_eq ( struct maillon_eq * *p)
{ *p = malloc(sizeof (struct maillon_eq)) ;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  2
struct maillon_eq * suivant_eq(  struct maillon_eq * p)
    { return( p->suivant ) ;  }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 struct maillon_eq * precedant_eq(  struct maillon_eq * p ,  struct maillon_eq * tete) // donne l'adresse de l'element situé avant p
   {
    maillon_eq h;
    h=tete;
      while(suivant_eq(h)!=p)
      {
         h=suivant_eq(h);
      }
      return(h);
   }

   // ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   struct maillon_info * suivant_info(  struct maillon_info * p)
    { return( p->suivant ) ; }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    struct maillon_info * precedant_info(  struct maillon_info * p ,  struct maillon_info * tete) // donne l'adresse de l'element situé avant p
   {
    maillon_info h;
    h=tete;
      while(suivant_info(h)!=p)
      {
         h=suivant_info(h);
      }
      return(h);
   }
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 3
 void aff_adr_eq( struct maillon_eq * p,  struct maillon_eq * Q)
    {
      p->suivant = Q ;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////4
void allouer_info ( struct maillon_info * *p)
{ *p = malloc(sizeof (struct maillon_info)) ;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////6
 void aff_adr_info( struct maillon_info * p,  struct maillon_info * Q)
    {
      p->suivant = Q ;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      //  calendrier
      // tableau des equipes
  /** Implémentation **\: TABLEAU DE CHAINES DE CARACTERES**/

  /** Tableaux **/


  Typeelem_V16s Element_V16s ( Typevect_V16s V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V16s ( Typevect_V16s V  , int I1 ,  Typeelem_V16s Val )
    {
     strcpy( *(V + I1-1 ) , Val );
    }

    void supprimer ( Typevect_V16s V , int indice ,int nbrElem)   // supprime un element donné d'un tableau
   {
    int i;
    for (i=indice ; i<nbrElem ; i++)
    {
      if (i<(nbrElem-1))
      {
        strcpy(V[i],V[i+1]);
      }
      else {
        strcpy(V[i],"");
      }
    }
   }
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// tableaux des noms des équipes
  Typevect_V16s T;
  Typevect_V16s Trr;

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// la liste calendrier
Pointeur Allouer_calendrier (Pointeur *P)
    {
      *P = (struct calendrier *) malloc( sizeof( struct calendrier)) ;
      (*P)->suiv = NULL;
    }

  void aff_adr_calendrier ( calendrier * P , calendrier * Q)
  {
    P->suiv=Q;
  }

  Pointeur suivant_calendrier( Pointeur *p)
    { return( (*p)->suiv) ;  }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    Pointeur creationDeLaListeCalendrier(Pointeur *match1)  // creer la liste calendrier 8 maillons et affecter la tete de LLC a match1
    { int a;
   Pointeur z,x;
   *match1=NULL;
   for (a=1 ;a<9;a++)
   {
    Allouer_calendrier(&z);
    if(*match1==NULL){
      *match1=z;
      x=z;
    }
    else
    {
      aff_adr_calendrier(x,z);
      x=z;
    }
   }
   aff_adr_calendrier(z,NULL);
    }
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
     struct maillon_info * adress_info(struct maillon_eq * tete, char eq[11]) /*retourne l'adresse du maillon qui
     contient le nom d'une equipe donné eq (la liste_eq) */
   {  struct maillon_eq * p;
    struct maillon_info * j;
    p=tete;
      while ((p->alpha)!=(eq[0]))
     {
          p=suivant_eq(p);
     }
     j=p->equipes;
     while (strcmp((j->eq),(eq))!=0)
     {
        j=suivant_info(j);
     }
     return j;
   }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   void maj (calendrier *z , struct maillon_eq * tete_eq) // mis à jour de la liste_eq mais sans le nouveau rang des equipes
   { struct maillon_info * j;
    if ((z->ResEq1)>(z->ResEq2))    // equipe 1 a gagne
   {
     j=adress_info(tete_eq,z->eq1);
     j->npt+=3;
     j->nbj++;
     j->nbg++;
     j->bp+=(z->ResEq1);
     j->bc+=(z->ResEq2);
     j->diff=((j->bp)-(j->bc));

     j=adress_info(tete_eq,z->eq2);
     j->nbp++;
     j->nbj++;
     j->bp+=(z->ResEq2);
     j->bc+=(z->ResEq1);
     j->diff=((j->bp)-(j->bc));
    }


    if ((z->ResEq2)>(z->ResEq1))          // equipe 2 a gagne
   {
     j=adress_info(tete_eq,z->eq2);
     j->npt+=3;
     j->nbj++;
     j->nbg++;
     j->bp+=(z->ResEq2);
     j->bc+=(z->ResEq1);
     j->diff=((j->bp)-(j->bc));

     j=adress_info(tete_eq,z->eq1);
     j->nbp++;
     j->nbj++;
     j->bp+=(z->ResEq1);
     j->bc+=(z->ResEq2);
     j->diff=((j->bp)-(j->bc));
    }


    if ((z->ResEq2)==(z->ResEq1))     // match nul
   {
     j=adress_info(tete_eq,z->eq2);
     j->npt++;
     j->nbj++;
     j->nbn++;
     j->bp+=(z->ResEq2);
     j->bc+=(z->ResEq1);
     j->diff=((j->bp)-(j->bc));                                                   // pour verifier
     j=adress_info(tete_eq,z->eq1);
     j->npt++;
     j->nbj++;
     j->nbn++;
     j->bp+=(z->ResEq2);
     j->bc+=(z->ResEq1);
     j->diff=((j->bp)-(j->bc));                                                   // pour verifier
    }
   }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void  afficherLesMatchsDeLaJournee(calendrier * tete)    // afficher les matchs de la journee
 { calendrier *z;
   z=tete;
   printf("______________________________________________________________________________\n\n\n");
   printf("///////////////////////les matchs de la journee ////////////////////////\n\n");
    while (z!=NULL)
    {
      printf("\t\t\t    %s VS %s \n",z->eq1,z->eq2 );
      z=suivant_calendrier(&z);
    } printf("\n______________________________________________________________________________\n");
 }
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void afficherLesResultatDeLaJournee(calendrier * tete)  // le choix de l'affichage des resultats de la journée
 { calendrier * z; int g;
    z=tete; printf("\n\n______________________________________________________________________________\n");
    printf("\n\nVoulez-vous afficher les resultats de la journee ? \n");
    printf("\t1:oui\t\t2:non\n\t");
    scanf("%d",&g);
    if (g==1){  printf(" \n\n////////////////////////// Les resultats des matchs /////////////////////\n\n\n");
    while (z!=NULL)
    {
      printf("\t\t\t    %s   %d  %d  %s \n",z->eq1,z->ResEq1 ,z->ResEq2,z->eq2  );
      z=suivant_calendrier(&z);
    }}}
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    void affecterLesMatchsDansLaListeCalendrier(calendrier * tete,  Typevect_V16s T)
    /*Remplir la liste calendrier (generer les matchs de la journée) soit manuellement ou Automatiquement
    selon le choix de l'utilisateur */
    { calendrier * z;
      int e=0,a;
   int b,n;
      z=tete;
   srand(time(NULL));
   printf("\t\tsaisir les matchs de la journee :\n");
   printf("\t\t\t1:Manuellement\t\t2:Automatiquement\n\t");
   scanf("%d",&a);
   if (a==1)              // generer les matchs manuellement
   { int y=0; printf("______________________________________________________________________________\n");
    while(z!= NULL)
    {
       b=0;

       printf("    le numero des equipes disponible :  \n");
      while(strcmp(T[b],"")!=0)
      {
        printf("       %d %s\n",b+1,T[b] );
        b++;
        if (b==16)
        {
          goto premierMatch;
        }
      }
      premierMatch: printf("\n match numero %d \n",y+1 );
       do{ printf("le numero de l'equipe 1 = ");
       scanf("%d",&b);} while((b==0) || (b>(16-y*2)));
        strcpy(z->eq1,T[b-1]);
         do{ printf("le numero de l'equipe 2 = "); scanf("%d",&n);} while ((n==b) || n==0 || (n>(16-y*2)));
        strcpy(z->eq2,T[n-1]);
        b=0;
        while (strcmp(T[b],z->eq1)!=0) b++;
        supprimer(T,b,16);
          b=0;
        while (strcmp(T[b],z->eq2)!=0) b++;
        supprimer(T,b,16);
        printf("\n\t  match %d \n",(y+1) );
       printf("\t%s VS %s \n\n",z->eq1,z->eq2 );
       printf("______________________________________________________________________________\n");
       z=suivant_calendrier(&z); y++;
     }}

   else           // generer les matchs aléatoirement
   {
   while (z!=NULL)
   {
     b=rand()%(16-e);
     strcpy(z->eq1 , T[b]);
     supprimer(T,b,16);
     e++;
      b=rand()%(16-e);
     strcpy(z->eq2, T[b]);
     supprimer(T,b,16);
     e++;
     z=suivant_calendrier(&z);}
    }}

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  void leMatchaDeffuse(calendrier * match1,struct maillon_eq * tete_eq)  // choisir le match a deffuser
  { Typevect_V8i Tab;
    struct maillon_eq *p;
    calendrier * z;
    struct maillon_info * j;
     int e,b,a;
     printf("\n/////////////////////////////// le match a deffuser /////////////////////////////////// \n\n");
   Tab = malloc(8 * sizeof(int));
   z=match1; p = tete_eq ;
   for ( a = 0; a < 8; ++a)            // affecter le la somme de points de chaque match au tableau Tab pour faciliter la recherche du max
   {
     j=adress_info(tete_eq,z->eq1);
      e=j->npt;
     j=adress_info(tete_eq,z->eq2);
     Tab[a]=(e+(j->npt));
     p=tete_eq;
     z=suivant_calendrier(&z);
   }
   int max=Tab[0]; e=0;                  //  chercher le somme de points maximal
   for (a = 1; a < 8; ++a)
   {
    if (max < Tab[a])
    {
      max=Tab[a];
      e=a;
    }
   }
      b=0;                            //  verifier si le nombre de points max est unique
      for (a = 0; a < 8; ++a)
      {
        if (max==Tab[a])
        {
          b++;
        }
      }

    if (b==1)                                  //  si le nombre de points max est unique
    { z=match1;
      if (e==0)
      {
      printf("\t\t\t\t  %s VS %s \n",z->eq1,z->eq2 );                    // afficher le matchs a deffuser
      }
      else{
      for ( a = 0; a < e; ++a)
      {
      z=suivant_calendrier(&z);
       }
       printf("\t\t\t\t   %s VS %s \n",z->eq1,z->eq2 );              // afficher le matchs a deffuser
      }}

      else                                                 // si egalité
      { int min=10000000 ; int fd=0;
          for (a = 0; a < 8; ++a)
      {  p=tete_eq;
        if (max==Tab[a])
        {
           z=match1;
            for (int ff = 0; ff < a; ++ff)
            {
              z=suivant_calendrier(&z);                   // chercher le meilleur classement de l'equipe recevante
            }
            j=adress_info(tete_eq,z->eq1);
           if (min > j->rang)
           {
             min = j->rang;
             fd=a;
           }
        }
      } z=match1;
        for (a = 0; a < fd; ++a)
        {
          z=suivant_calendrier(&z);
        }
       printf("\t\t\t\t   %s VS %s \n",z->eq1,z->eq2 );         // afficher le matchs a deffuser
      } printf("\n______________________________________________________________________________\n\n");
  }
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 struct maillon_eq * triDeLaListe (struct maillon_eq * tete_eq)  // trier la liste_eq en ordre alphabetique (comme le schema demandé)
 {  struct maillon_eq  *p=NULL , *q=NULL , *r=NULL ;
  struct maillon_info *j=NULL ,*k=NULL , *w=NULL ,*tete_info=NULL ;
  int boolean,tete;
      boolean=1;
        if (suivant_eq(tete_eq)!=NULL)         // si la liste contient au moins 2 elements
          { while (boolean==1)

     {
         tete=0;
      p=suivant_eq(tete_eq); boolean=0; q=suivant_eq(p);
      if ((p->alpha)<=(tete_eq->alpha))                          // permutation
         {
            aff_adr_eq(tete_eq,suivant_eq(p));
            aff_adr_eq(p,tete_eq);
            tete_eq=p;
            boolean=1;
            tete=1;
            }
        if (tete==1)
        {p=suivant_eq(p);}

      while (q!=NULL)
          {
           if ((q->alpha)<=(p->alpha))
            {
            r=precedant_eq(p,tete_eq);
            aff_adr_eq(r,q);
            aff_adr_eq(p,suivant_eq(q));
            aff_adr_eq(q,p);
            boolean=1;
            q=suivant_eq(p);
            }
         else
         {
            q=suivant_eq(q);
            p=suivant_eq(p);
         }

           }

       } }
//  TRI DE LA LISTE INFO
 p = tete_eq ;
 while (p!=NULL){
  tete_info=p->equipes;
     boolean=1;
        if (suivant_info(tete_info)!=NULL)         // si la liste contient au moins 2 elements
         {  while (boolean==1)
        { tete=0;
      k=suivant_info(tete_info); boolean=0; j=suivant_info(k);
      if (strcmp((tete_info->eq),(k->eq))==1)                          // permutation du 1er element avec le 2eme
          {
            aff_adr_info(tete_info,suivant_info(k));
            aff_adr_info(k,tete_info);
            p->equipes=k;
            tete_info=p->equipes;
            boolean=1;
            tete=1;}

        if (tete==1)
        {k=suivant_info(k);}

      while (j!=NULL)     // les autres elements
          {
           if (strcmp((k->eq),(j->eq))==1)

           { w=precedant_info(k,tete_info);
            aff_adr_info(w,j);
            aff_adr_info(k,suivant_info(j));
            aff_adr_info(j,k);
            boolean=1;
            j=suivant_info(k);}

         else
         {
            j=suivant_info(j);
            k=suivant_info(k);
         }}
         }}

        p=suivant_eq(p);}
   return tete_eq;
 }
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct maillon_eq * creationDeLaListeEqAPartirDuFichierRang()   // creer la liste_eq a partir du fichier Rang
{
  FILE *fichier = fopen("rang.txt","r");
  if (fichier==0)
  {
    printf("\nERREUR\nPas de fichier rang.txt\n");
  }
  else{
  struct maillon_eq  *p=NULL , *q=NULL , *r=NULL , *s=NULL ,*tete_eq=NULL ;
  struct maillon_info *j=NULL ,*k=NULL , *w=NULL ,*tete_info=NULL ;
  int trouve = 0 ;
         //  cree les listes a partir du fichier rang
  while (!feof(fichier))
  {   allouer_info(&j);
      fscanf(fichier,"%d %s %d %d %d %d %d %d %d %d ",&(j->rang),(j->eq),&(j->npt),&(j->nbj),&(j->nbg),&(j->nbn),&(j->nbp),&(j->bp),&(j->bc),&(j->diff)) ;

      aff_adr_info(j,NULL);
      if (tete_eq==NULL)
      {
          allouer_eq(&p);
          p->equipes = j;
          p->alpha = j->eq[0];
          aff_adr_eq(p,NULL);
          tete_eq=p;
          trouve=1;
      }
      else {
        trouve=0 ;
        r=tete_eq;
        while (r!=NULL)
        {
            if (r->alpha==j->eq[0])
            {
                trouve=1 ;
            }
            r=suivant_eq(r);
        }
        r=tete_eq;
        if (trouve==1)
        {
            while (r->alpha!=j->eq[0])
            {
                r=suivant_eq(r);
            }
            if (r->equipes==NULL)
            {
                r->equipes=j;
            }
            else{
                k=r->equipes;
                while (suivant_info(k)!=NULL)
                {
                    k=suivant_info(k);
                }
                aff_adr_info(k,j);
                aff_adr_info(j,NULL);
            }
        }

        if (trouve==0)
        {
            allouer_eq(&q);
            aff_adr_eq(q,NULL);
            q->alpha=j->eq[0];
            q->equipes=j;
            s=tete_eq ;
            while(suivant_eq(s)!=NULL)
            {
                s=suivant_eq(s);
            }
            aff_adr_eq(s,q);
            aff_adr_eq(q,NULL);

        }

      }

  }fclose(fichier);
  return tete_eq;}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void affecterLesResultatsDansLaListeCalendrier (calendrier * match1)
 {
     int f,NbrButMax;       /*le choix du type de l'affectation des resultats*/
   calendrier *z=match1;
    printf("       Voulez vous affecter les resultats des matchs \n      ");
    printf("       1:Manuellement         2: Automatiquement ? \n\t");
  scanf("%d", &f);
    if (f==1)        /* affecter les resultats Manuellement */
    {
      while (z!=NULL){
      printf("%s VS %s \n",z->eq1,z->eq2 );
      printf("%s : ",z->eq1 );
      scanf("%d",&(z->ResEq1));
      printf("%s : ",z->eq2 );
      scanf("%d",&(z->ResEq2));
      printf("\n");
      z=suivant_calendrier(&z);
    }}
    else            /* affecter les resultats Automatiquement */
{  printf("Le nombre de buts maximal dans un match : ");
   scanf("%d",&NbrButMax);
  while (z!=NULL){
      z->ResEq1=rand()%(NbrButMax+1);
      z->ResEq2=rand()%(NbrButMax+1);
      z=suivant_calendrier(&z);
    }
}
 }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void misAJourDeLaListeEq(calendrier *match1, struct maillon_eq * tete_eq, char NomDuFichier[50])
 {  /* mettre à jour la liste_eq à la fin de la journée (avec le nouveau rang) , mettre à jour le fichier rang
 (creer un nouveau fichier à chaque journée ) et afficher le nouveau classement (selon le choix de l'utilisateur)*/
 int a;
  struct maillon_eq *p;
  struct maillon_info *j;
  calendrier *z=match1;
 for (a = 0; a < 8; ++a)         // mettre à jour chaque equipe (sans leur nouveau rang)
 {
    maj(z,tete_eq);
    z=suivant_calendrier(&z);
 }
  struct majRang Tmaj[16];        /* tableau à 3 champs : nom de l'equipe, ses points et la difference de buts
  (pour pouvoir trier les equipes selon leur points alors trouver leurs classement selon l'indice du tableau)*/
     a=0;
    int difftemp, pointstemp;
    char eqtemp[11];
     p = tete_eq ;
while (p!=NULL)
{    j=p->equipes;
    p=suivant_eq(p);
    while (j!=NULL)
    {
        strcpy(Tmaj[a].nomEq,j->eq);
        Tmaj[a].points=j->npt;
        Tmaj[a].diff=j->diff;
        j=suivant_info(j);
        a++;
    }
}
  int max=0, e=16,g;
for ( g = 0; g < 16; ++g)
{ max=0;
  for (a = g; a < 16; ++a)
   {
    if (max < Tmaj[a].points)
    {
      max=Tmaj[a].points;
      e=a;
    }}
    if (e!=g)                              // permutation
    {
      pointstemp=Tmaj[e].points;
      difftemp=Tmaj[e].diff;
      strcpy(eqtemp,Tmaj[e].nomEq);

      Tmaj[e].points=Tmaj[g].points;
      Tmaj[e].diff=Tmaj[g].diff;
      strcpy(Tmaj[e].nomEq,Tmaj[g].nomEq);

      Tmaj[g].points=pointstemp;
      Tmaj[g].diff=difftemp;
      strcpy(Tmaj[g].nomEq,eqtemp);
    }
}

int b=1;
while(b==1)
{b=0;
  for ( g = 0; g < 16; ++g)
  {
    if (Tmaj[g+1].points==Tmaj[g].points)                    // si il y a  égalité des points
    {
      if (Tmaj[g+1].diff>Tmaj[g].diff)                      // on permute selon le critere de difference
      {
      pointstemp=Tmaj[g+1].points;
      difftemp=Tmaj[g+1].diff;
      strcpy(eqtemp,Tmaj[g+1].nomEq);

      Tmaj[g+1].points=Tmaj[g].points;
      Tmaj[g+1].diff=Tmaj[g].diff;
      strcpy(Tmaj[g+1].nomEq,Tmaj[g].nomEq);

      Tmaj[g].points=pointstemp;
      Tmaj[g].diff=difftemp;
      strcpy(Tmaj[g].nomEq,eqtemp); b=1;
      }
      if (Tmaj[g+1].diff==Tmaj[g].diff)                     // si il y a   égalité de la difference
      {
        if (strcmp(Tmaj[g+1].nomEq,Tmaj[g].nomEq)==-1)     // on permute selon l'ordre alphabétique
        {
           pointstemp=Tmaj[g+1].points;
           difftemp=Tmaj[g+1].diff;
           strcpy(eqtemp,Tmaj[g+1].nomEq);

           Tmaj[g+1].points=Tmaj[g].points;
           Tmaj[g+1].diff=Tmaj[g].diff;
           strcpy(Tmaj[g+1].nomEq,Tmaj[g].nomEq);

           Tmaj[g].points=pointstemp;
           Tmaj[g].diff=difftemp;
           strcpy(Tmaj[g].nomEq,eqtemp);
           b=1;
        }
      }
    }
  }
}
FILE *fichier = fopen(NomDuFichier,"w");

for ( a = 0; a < 16; ++a)                                         // creer un nouveau fichier rang
{
  j=adress_info(tete_eq,Tmaj[a].nomEq);
  j->rang=a+1;
  if (fichier == NULL){ printf("\nErreur dans la creation du fichier\n");}  
  fprintf(fichier,"%d %s %d %d %d %d %d %d %d %d \n",(j->rang),(j->eq),(j->npt),(j->nbj),(j->nbg),(j->nbn),(j->nbp),(j->bp),(j->bc),(j->diff));
}
fclose(fichier);                                      // afficher le classement
int choix ;
printf("\n\n______________________________________________________________________________\n");
printf("\nVoulez vous afficher le classement ? \n\t1:oui              2:non\n\t");
scanf("%d",&choix);
printf("\n");
if (choix==1){
  FILE *fichier = fopen(NomDuFichier,"r");
  printf("\n/////////////////////////////// classement////////////////////////////\n\n");
while (!feof(fichier))
{
printf("%c",fgetc(fichier));
}
printf("\n\n\n");
fclose(fichier);
printf("\n\n______________________________________________________________________________\n\n");
}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 Typevect_V16s creationDuTableauDesEquipes()        /* creer un tableau qui contient le noms des équipes pour remplir

                                                    la liste calendrier (sois manuellement ou automatiquement )*/
{
  int g=0;
      FILE *fich;
     fich=fopen ("Equipes.txt" , "r");
     if (fich==0)
     {
       printf("\nERREUR\npas de fichier Equipes.text");
     }
     else{
     Trr = malloc(16 * 255  * sizeof(string255));
     int _Izw3;for (_Izw3=0; _Izw3<16; ++_Izw3)
       Trr[_Izw3]= malloc(255 * sizeof(string255));
while (!feof(fich))
     {
      fscanf(fich,"%s",Trr[g]);
      g++;
     }
       fclose(fich);
       return Trr;}
}
