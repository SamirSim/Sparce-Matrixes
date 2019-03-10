#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "GRAPHIQUE.h"

/** 1- Graphique d'entrer ******************************************************************/
void graphique_entrer()
{
    int i , d=65 , c = 15;

    cadre_aff(120,30,d-33,c-5);
    textcolor(255);
    gotoxy(d+20,2+c);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(d+28,2+c);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(d+36,2+c);
    textcolor(17);
    printf("%c%c%c",219,219,219);
    gotoxy(d+20,3+c);
    textcolor(255);
    printf("%c",219);
    gotoxy(d+28,3+c);
    printf("%c",219);
    gotoxy(d+20,4+c);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(d+28,4+c);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(d+36,4+c);
    printf("%c%c%c",219,219,219);
    gotoxy(d+20,5+c);
    printf("%c",219);
    gotoxy(d+33,5+c);
    printf("%c",219);
    gotoxy(d+36,5+c);
    printf("%c%c%c",219,219,219);
    gotoxy(d+20,6+c);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(d+28,6+c);
    printf("%c%c%c%c%c%c",219,219,219,219,219,219);
    gotoxy(d+36,6+c);
    printf("%c%c%c",219,219,219);
    printf("\n");
    for (i=0 ; i<=100 ; i++)
    {
        if ( i<44 || i>60)
        {
            textcolor(17);
            gotoxy(d+i-24,10+c);
            printf("%c%c",219,219);
            delay(10);
        }
        textcolor(31);
        gotoxy(d+21,10+c);
        printf("chargement: %d %c\r",i,37);
        delay(5);
    }
    gotoxy(d-7,c+14);
    textattr(207);
    printf("Bienvenue dans notre programme de manipulation des 'Matrices creuses' !");
    gotoxy(d+8,c+20);
    textattr(15);
    system("pause");
}

/** 2- writeCh ****************************************************************************************************/

void writeCh(char ch[],int temps) // Ecrit une chaine de caractere avec un temps d'arret entre chaque caractere
{
    int i;
    for (i=0 ; i < strlen(ch); i++)
    {
        printf("%c",ch[i]);
        delay(temps);
    }
}

/** 3- Dessine menu ************************************************************************************************/

void dessine_menu (int x , int y) // Dessine le mot menu à partir du point M(x,y) de la console
{

 gotoxy(x,y);
 printf("%c%c%c%c%c   %c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+1);
 printf("%c%c%c%c%c%c %c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c    %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+2);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c        %c%c%c%c%c%c   %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+3);
 printf("%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c  %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+3);
 printf("%c%c%c  %c%c%c  %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c %c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+4);
 printf("%c%c%c   %c   %c%c%c   %c%c%c        %c%c%c%c  %c%c%c%c%c%c%c   %c%c%c   %c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+5);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c    %c%c%c%c%c   %c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219); gotoxy(x,y+6);
 printf("%c%c%c       %c%c%c   %c%c%c%c%c%c%c%c   %c%c%c%c     %c%c%c%c    %c%c%c%c%c%c%c ",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
}

/** 4- cadre_aff ************************************************************************************************************************************/

void cadre_aff ( int l , int L , int x , int y ) // Dessine un cadre de longeur == L et de largeur == l à partir du point M(x,y) de la console
{
    int i ;

    gotoxy(x,y);
    printf("%c",201);
    gotoxy(x,y + L);
    printf("%c",200);
    gotoxy(x+l,y);
    printf("%c",187);
    gotoxy(x+l,y+L);
    printf("%c",188);
    for (i=1 ; i <= l-1 ; i++  )
    {
        gotoxy(x+i,y);
        printf("%c",205);
        gotoxy(x+i,y+L);
        printf("%c",205);
    }
    for (i=1 ; i <= L-1; i++ )
    {
        gotoxy(x,y+i);
        printf("%c",186);
        gotoxy(x+l,y+i);
        printf("%c",186);
    }

}

/** 6- dessine_fleche *****************************************************************************************/
void dessine_fleche (int x, int y ) // Dessine une fleche à partir du point M(x,y) de la console

{
  int i ;
  gotoxy(x,y);
  printf("%c",218);
  gotoxy(x,y+5);
  printf("%c ",192);
  gotoxy(x+11,y);
  printf("%c",217);
  gotoxy(x+11,y+5);
  printf("%c",191);

  for ( i= 1 ; i <= 10 ; i++)
  {
      gotoxy(x+i,y);
      printf("%c",196);
      gotoxy(x+i,y+5);
      printf("%c",196);

      if ( i<=5)
      {
          gotoxy(x+11+i,y-3+i);
          printf("%c",92);
          gotoxy(x+11+i,y+8-i);
          printf("%c",47);
      }

      if ( i<= 4)
      {
          gotoxy(x,y+i);
          printf("|");
      }

      if ( i <= 2)
      {
          gotoxy(x+11,y-i);
          printf("|");
          gotoxy(x+11,y+5+i);
          printf("|");
      }
  }
}

/** 6 - retour menu ************************************************************************************************/

void retourMenu() // Affiche un message pour retourner au menu
{
    printf("APPUYEZ SUR N'IMPORTE QUELLE TOUCHE POUR RETOURNER AU MENU!\n");
    getch();
}

/** 7 - Menu d'affichage *******************************************************************************************/
int menu_affichage () //Affiche le menu d'affichageet donne le choix de l'utilisateur

{
    chaine t [] = {  "1-  AFFICHER LA MATRICE                                                       ",
                     "2-  AFFICHER LA SOMME DE DEUX MATRICE                                         ",
                     "3-  AFFICHER LE PRODUIT DE DEUX MATRICES                                      ",
                     "4-  AFFICHER LE PRODUIT D'UNE MATRICE PAR UN SCALAIRE                         ",
                     "5-  AFFICHER LA MATRICE TRANSPOSEE DE LA MATRICE                              ",
                     "6-  AFFICHER LE DETERMINANT DE LA MATRICE                                     ",
                     "7-  AFFICHER LA MATRICE INVERSE DE LA MATRICE                                 ",
                     "8-  AFFICHER LES SOLUTIONS DU SYSTEME D'ESUATIONS                             ",
                  };
    int  n = 8 ; // TAILLE DU TABLEAU DE CHAINE
    int i , j , quite = 1, quite2 , y = 8 , x= 53 ;
    char c1,c2 ,c3 , c4 ;

    textcolor(15);
    for( i = 0 ; i< n ; i++)
    {
        if (i==0) textbackground(1);
        else textbackground(0);
        gotoxy(x,y+i);
        printf("%s\n",t[i]);
    }
    i=0;
    while( quite)
    {
        c1 = getch();
        if( c1 == 13 ) quite =0 ;

        else if( c1 == -32 )
        {
            c2 = getch();
            if (c2 == 72 )
            {
                if(i > 0)
                {
                    gotoxy(x,i-1+y);
                    textbackground(1);
                    printf("%s\n",t[i-1]);
                    textbackground(0);
                    gotoxy(x,i+y);
                    printf("%s\n",t[i]);
                    i--;
                }
                else
                {
                    gotoxy(x,y+n-1);
                    textbackground(1);
                    printf("%s\n",t[n-1]);
                    gotoxy(x,y);
                    textbackground(0);
                    printf("%s\n",t[0]);
                    i=n-1;
                }
            }
            else if (c2 == 80)
            {
                if( i < n-1)
                {
                    gotoxy(x,y+i+1);
                    textbackground(1);
                    printf("%s\n",t[i+1]);
                    textbackground(0);
                    gotoxy(x,y+i);
                    printf("%s\n",t[i]);
                    i++;
                }
                else
                {
                    gotoxy(x,y);
                    textbackground(1);
                    printf("%s\n",t[0]);
                    gotoxy(x,y+i);
                    textbackground(0);
                    printf("%s\n",t[i]);
                    i=0 ;
                }
            }
        }
    }
    system("cls");
    return i+1;

}

/** 8 - Menu principal **********************************************************************************************/

int menu() // Affiche le menu principal et donne le choix de l'utilisateur
{

    chaine t [] = {  "1-  CREER LA MATRICE                                                          ",
                     "2-  AFFICHAGE                                                                 ",
                     "3-  CALCULER LA SOMME DE DEUX MATRICES                                        ",
                     "4-  CALCULER LE PRODUIT DE DEUX MATRICES                                      ",
                     "5-  CALCULER LE PRODUIT DE LA MATRICE PAR UN SCALAIRE                         ",
                     "6-  CALCULER LA MATRICE TRANSPOSEE DE LA MATRICE                              ",
                     "7-  CALCULER LE DETERMINANT DE LA MATRICE                                     ",
                     "8-  CALCULER LA MATRICE INVERSE DE LA MATRICE                                 ",
                     "9-  RESOUDRE UN SYSTEME D'EQUATION BASE UNE MATRICE CREUSE                    ",
                     "10-  AFFICHER LA COMPLEXITE DES ALGORITHMES                                   ",
                     "11-  SAUVEGARDER/RESTAURER UNE MATRICE                                        ",
                     "12-  LE GUIDE DU MENU                                                         ",
                  };

    int n = 12 ; // TAILLE DU TABLEAU DE CHAINE
    int i , j , quite = 1, quite2 , y = 20  , x= 55 , y1= n+4 , x1 =  strlen(t[0])+6 , choix ;
    char c1,c2 ,c3 , c4 ;
    debut :
    entete();
    pied_de_page();
    textattr(15);
    dessine_menu(68,8);
    textattr(255);
    for (i=1 ; i<= x1 ; i++)
    {
        for ( j=1 ; j<= y1 ; j++)
        {
            gotoxy(x-4+i,y-3+j);
            printf("%c",219);
        }

    }
    printf("\n");
    textcolor(15);

    for( i = 0 ; i< n ; i++)
    {
        if (i==0) textbackground(1);
        else textbackground(0);
        gotoxy(x,y+i);
        printf("%s\n",t[i]);
    }
    i=0;
    while( quite)
    {
        c1 = getch();
        if( c1 == 13 || c1 == 27 )
        {
            if ( c1 == 27 )
            {
                quite2 = 1 ;
                choix = 1 ;
                gotoxy(1,y);
                textattr(0);
                system("cls");
                textattr(204);
                for (i=1 ; i<= 46  ; i++)
                {
                    for ( j=1 ; j<= 4 ; j++)
                    {
                        gotoxy(x+13+i,y-3+j);
                        printf("%c",219);
                    }

                }
                textattr(207);
                gotoxy(x+15,y);
                printf("ETES VOUS SURE DE VOULOIR QUITTER ?!  (Y%cN) ",92);
                gotoxy(109,y);
                textattr(143);
                printf("O");
                while(quite2)
                {
                    c3 = getch();
                    if ( c3 == 13) quite2 = 0 ;
                    else if ( c3 == -32)
                    {
                        c4 = getch();
                        if (c4 == 77 && choix == 1 )
                        {
                            gotoxy(111,y);
                            textattr(143);
                            printf("N");
                            gotoxy(109,y);
                            textattr(207);
                            printf("O");
                            choix -- ;
                        }
                        if (c4 == 75 && choix == 0)
                        {
                            gotoxy(109,y);
                            textattr(143);
                            printf("O");
                            gotoxy(111,y);
                            textattr(207);
                            printf("N");
                            choix ++ ;
                        }
                    }

                }

                textattr(15);
                if ( choix == 1)
                {
                    i = -1 ;
                    quite = 0 ;
                }
                else  goto debut ;
            }
            else quite = 0 ;
        }

        else if( c1 == -32 )
        {
            c2 = getch();
            if (c2 == 72 )
            {
                if(i > 0)
                {
                    gotoxy(x,i-1+y);
                    textbackground(1);
                    printf("%s\n",t[i-1]);
                    textbackground(0);
                    gotoxy(x,i+y);
                    printf("%s\n",t[i]);
                    i--;
                }
                else
                {
                    gotoxy(x,y+n-1);
                    textbackground(1);
                    printf("%s\n",t[n-1]);
                    gotoxy(x,y);
                    textbackground(0);
                    printf("%s\n",t[0]);
                    i=n-1;
                }
            }
            else if (c2 == 80)
            {
                if( i < n-1)
                {
                    gotoxy(x,y+i+1);
                    textbackground(1);
                    printf("%s\n",t[i+1]);
                    textbackground(0);
                    gotoxy(x,y+i);
                    printf("%s\n",t[i]);
                    i++;
                }
                else
                {
                    gotoxy(x,y);
                    textbackground(1);
                    printf("%s\n",t[0]);
                    gotoxy(x,y+i);
                    textbackground(0);
                    printf("%s\n",t[i]);
                    i=0 ;
                }
            }
        }
    }
    return i+1;
}

/** 9- Guide du menu *******************************************************************************************/
void guide_menu (int x , int y )
{
  FILE *f = NULL ;
  char c ;
  f = fopen("guide_menu.txt","r");
  if ( f != NULL)
  {
    gotoxy(x,y);
    do
       {
          c = fgetc(f);
          if (wherex() == x+67) gotoxy(x,wherey()+1);
          printf("%c",c);
       }
    while ( c!= EOF);
  }
  fclose(f);
}

/** 10- L'ENTETE *************************************************************************************************/
void entete ()
{
    int i ;
    gotoxy(69,1);
    printf("REPUBLIQUE ALGERIENNE DEMOCRATIQUE ET POPULAIRE ");
    gotoxy(74,3);
    printf("ECOLE SUPERIEURE D'INFORMATIQUE (ESI)\n");
    for (i=1 ; i <= 189 ; i++) printf("_");
    printf("\n") ;
}

/** 11- PIED DE PAGE ********************************************************************************************/
void pied_de_page ()

{
    int i ;
    gotoxy(1,35);
    for (i=1 ; i <= 189 ; i++) printf("_");
    gotoxy(89,37);
    printf("REALISE PAR:");
    gotoxy(72,39);
    printf("AHMED BACHA Ibrahim   |   SI MOHAMMED Samir M'hammed");
    gotoxy(82,41);
    printf("SECTION B   |   GROUPE 6");
    gotoxy(80,47);
    printf("ANNEE UNIVERSITAIRE : 2015/2016\n");
    for (i=1 ; i <= 189 ; i++) printf("_");

}
