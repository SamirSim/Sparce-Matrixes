#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "Modules_Mat_Creuses.h"
#include "GRAPHIQUE.h"

/**1- Lire la matrice **************************************************************/

void Lire_Mat (typeval t[MAX][MAX],int *lig,int *col)
{
    int i,j;
    typeval v;
    gotoxy(55,8);
    printf("Entrer le nombre de ligne de votre matrice : ");
    scanf("%d",lig);
    gotoxy(55,9);
    printf("Entrer le nombre de colonne de votre matrice : ");
    scanf("%d",col);
    for (i=0;i<(*lig);i++)
    {
        for (j=0;j<(*col);j++)
        {
            gotoxy(55,10+j+i*(*col));
            printf("T[%d][%d] = ",i,j);
            scanf("%f",&v);
            t[i][j]=v;
        }
    }
}

/** 2- Ecrire la matrice *************************************************************************************/

void Ecrit_Mat (typeval t[MAX][MAX],int lig,int col)
{
    int i,j,k;
    printf("\n");
    for (i=0;i<lig;i++)
    {
        gotoxy(55,11+i*col);
        for (j=0;j<col;j++)
        {
            if (j==col-1)
            {
                printf("||  %.2f  ||",t[i][j]);
            }
            else
            {
                printf("||  %.2f  ",t[i][j]);
            }
        }
    }
}

/**3 - Convertir La matrice en tabLLC ************************************************************************************/

void Mat_LLC (typeval t[MAX][MAX],int lig,int col,struct tabllc tl[MAX])
{
    int i,j,cpt;
    struct Maillon *q=NULL,*s=NULL,*p=NULL;
    for (i=0;i<lig;i++)
    {
        cpt=0;
        s=NULL;
        for (j=0;j<col;j++)
        {
            if (t[i][j]!=0)
            {
                Allouer(&q);
                Aff_Adr(q,p);
                Aff_Val(q,t[i][j]);
                Aff_Col(q,j);
                if (cpt==0)
                {
                    tl[i].adr=q;
                }
                else
                {
                    Aff_Adr(s,q);
                }
                s=q;
                cpt++;
            }
        }
        tl[i].taille=cpt;
    }
}

/**4-Convertir Le tabLLC en matrice **********************************************************************************************/

void LLC_Mat (struct tabllc tl[MAX],typeval t[MAX][MAX],int lig,int col)
{
    int i,j;
    struct Maillon *p=NULL;
    for (i=0;i<lig;i++)
    {
        for (j=0;j<col;j++)
        {
            t[i][j]=0;
        }
    }
    for (i=0;i<lig;i++)
    {
        p=tl[i].adr;
        while (p!=NULL)
        {
            t[i][Colonne(p)]=Valeur(p);
            p=Suivant(p);
        }
    }
}

/** 5- Calculer la somme de deux matrices (représenté en deux tabLLC) ***********************************************************/

void som_mat (struct tabllc A[MAX],struct tabllc B[MAX],struct tabllc C[MAX],int lig)
{
    int i,val,col,cpt;
    struct Maillon *p=NULL,*p2=NULL,*p1=NULL,*q=NULL;
    for (i=0;i<lig;i++)
    {
        p1=A[i].adr;
        p2=B[i].adr;
        p=NULL;
        cpt=0;
        while ((p1!=NULL) && (p2!=NULL))
        {
            if (Colonne(p1)==Colonne(p2))
            {
                val=Valeur(p1)+Valeur(p2);
                col=Colonne(p1);
                p1=Suivant(p1);
                p2=Suivant(p2);
            }
            else
            {
                if (Colonne(p1)<Colonne(p2))
                {
                    val=Valeur(p1);
                    col=Colonne(p1);
                    p1=Suivant(p1);
                }
                else
                {
                    val=Valeur(p2);
                    col=Colonne(p2);
                    p2=Suivant(p2);
                }
            }
            if (val!=0)
            {
                Allouer(&q);
                Aff_Adr(q,NULL);
                Aff_Val(q,val);
                Aff_Col(q,col);
                if (p!=NULL)
                {
                    Aff_Adr(p,q);
                }
                else
                {
                   C[i].adr=q;
                }
                p=q;
                cpt++;
            }
        }
        while (p1!=NULL)
        {
            Allouer(&q);
            Aff_Adr(q,NULL);
            Aff_Val(q,Valeur(p1));
            Aff_Col(q,Colonne(p1));
            if (p!=NULL)
            {
                Aff_Adr(p,q);
            }
            else
            {
                C[i].adr=q;
            }
            p1=Suivant(p1);
            p=q;
            cpt++;
        }
        while (p2!=NULL)
        {
            Allouer(&q);
            Aff_Adr(q,NULL);
            Aff_Val(q,Valeur(p2));
            Aff_Col(q,Colonne(p2));
            if (p!=NULL)
            {
                Aff_Adr(p,q);
            }
            else
            {
                C[i].adr=q;
            }
            p2=Suivant(p2);
            p=q;
            cpt++;
        }
        C[i].taille=cpt;
    }
}

/**6- Calculer le produit de deux matrices (représenté en deux tabLLC) ****************************************************************************************/

void prod_mat (struct tabllc A[MAX],struct tabllc B[MAX],struct tabllc C[MAX],int lig)
{
    int i,j,k,inter,som,maxcol=0;
    struct Maillon *p=NULL,*q=NULL,*s=NULL;
    for (i=0;i<lig;i++)
    {
        C[i].taille=0;
        C[i].adr=NULL;
        if (A[i].taille>maxcol)
        {
            maxcol=A[i].taille;
        }
        if (B[i].taille>maxcol)
        {
            maxcol=B[i].taille;
        }
    }
    for (k=0;k<maxcol;k++)
    {
        for (i=0;i<lig;i++)
        {
            p=A[i].adr;
            som=0;
            while (p!=NULL)
            {
                s=B[Colonne(p)].adr;
                inter=0;
                while ((s!=NULL) && (inter==0))
                {
                    if (Colonne(s)==k)
                    {
                        inter=Valeur(s);
                    }
                    s=Suivant(s);
                }
                if (inter!=0)
                {
                    som=Valeur(p)*inter+som;
                }
                p=Suivant(p);
            }
            if (som!=0)
            {
                Allouer(&q);
                Aff_Adr(q,NULL);
                Aff_Val(q,som);
                Aff_Col(q,k);
                C[i].taille++;
                p=C[i].adr;
                if (p==NULL)
                {
                    C[i].adr=q;
                }
                else
                {
                    while (Suivant(p)!=NULL)
                    {
                        p=Suivant(p);
                    }
                    Aff_Adr(p,q);
                }
            }
        }
    }
}

/**7- Calculer le produit d'une matrice (représenté en TabLLC) par un scalaire *******************************************************/

void scal_prod_mat (struct tabllc A[MAX],struct tabllc B[MAX],int lig,typeval v)
{
    int i;
    struct Maillon *p=NULL,*q=NULL,*s=NULL;
    if (v!=0)
    {
        for (i=0;i<lig;i++)
        {
            B[i].taille=A[i].taille;
            s=NULL;
            p=A[i].adr;
            B[i].adr=NULL;
            while (p!=NULL)
            {
               Allouer(&q);
               Aff_Adr(q,NULL);
               Aff_Val(q,Valeur(p)*v);
               Aff_Col(q,Colonne(p));
               if (s!=NULL)
               {
                   Aff_Adr(s,q);
               }
               else
               {
                   B[i].adr=q;
               }
               s=q;
               p=Suivant(p);
            }
        }
    }
}


/** 8- Calculer la matrice transposée de la matrice ******************************************************************************************/

void trans_mat (struct tabllc A[MAX],struct tabllc B[MAX],int lig)
{
    int i;
    struct Maillon *p=NULL,*q=NULL;
    for (i=0;i<lig;i++)
    {
        B[i].taille=0;
        B[i].adr=NULL;
    }
    for (i=lig-1;i>=0;i--)
    {
        p=A[i].adr;
        while (p!=NULL)
        {
            Allouer(&q);
            Aff_Adr(q,B[Colonne(p)].adr);
            Aff_Val(q,Valeur(p));
            Aff_Col(q,i);
            B[Colonne(p)].adr=q;
            B[Colonne(p)].taille++;
            p=Suivant(p);
        }
    }
}


/** 9- Calculer le determinant de la matrice **************************************************************************/

float determinant(struct tabllc t[],int lig)
{
    struct tabllc m[lig+1];
    int ind,cpt,det=0,signe=1;
    Maillon *p=NULL;
    p=t[0].adr;
    if (lig==1)
    {
        if (t[0].adr!=NULL)
        {
            return Valeur(t[0].adr);
        }
        else
        {
            return 0;
        }
    }
    else
    {
        for (ind=0;ind<lig;ind++)
        {
            p=t[ind].adr;
            retire_lig_col(t,lig,ind,0,m);
            if (p!=NULL)
            {
             if (Colonne(p)==0) det=(signe*Valeur(p)*determinant(m,lig-1))+det;
            }
            signe=-signe;
        }
    }
    return(det);
}

/** 10- Calculer la matrice inverse de la matrice **************************************************************************/

void inverse (struct tabllc tl[], int lig,int col, struct tabllc res[])
{
   struct tabllc trans[50],co[50];
   float sauve;
   comat(tl,lig,col,co);
   trans_mat(co,trans,lig);
   sauve=(1/determinant(tl,lig));
   scal_prod_mat(trans,res,lig,sauve);
}

/** 11- Resoudre le système d'equation besee une matrice creuse ***************************************************************/

/** 12- retirer la ligne ligvir et la colonne colvir du tabllc (utiliser pour calculer le determinant) *************************/

void retire_lig_col (struct tabllc tl[],int lig,int ligvir,int colvir,struct tabllc m[])
{
    int i,cpt;
    struct Maillon *p=NULL,*q=NULL,*s=NULL;
    for (i=0;i<lig;i++)
    {
        if (i<ligvir)
        {
            p=tl[i].adr;
            cpt=0;
            s=NULL;
            m[i].adr=NULL;
            while (p!=NULL)
            {
                if (Colonne(p)<colvir)
                {
                    Allouer(&q);
                    Aff_Adr(q,NULL);
                    Aff_Val(q,Valeur(p));
                    Aff_Col(q,Colonne(p));
                    if (s!=NULL)
                    {
                        Aff_Adr(s,q);
                    }
                    else
                    {
                        m[i].adr=q;
                    }
                    cpt++;
                    s=q;
                }
                if (Colonne(p)>colvir)
                {
                    Allouer(&q);
                    Aff_Adr(q,NULL);
                    Aff_Val(q,Valeur(p));
                    Aff_Col(q,Colonne(p)-1);
                    if (s!=NULL)
                    {
                        Aff_Adr(s,q);
                    }
                    else
                    {
                        m[i].adr=q;
                    }
                    cpt++;
                    s=q;
                }
                m[i].taille=cpt;
                p=Suivant(p);
            }
        }
        if (i>ligvir)
        {
            p=tl[i].adr;
            cpt=0;
            s=NULL;
            m[i-1].adr=NULL;
            while (p!=NULL)
            {
                if (Colonne(p)<colvir)
                {
                    Allouer(&q);
                    Aff_Adr(q,NULL);
                    Aff_Val(q,Valeur(p));
                    Aff_Col(q,Colonne(p));
                    if (s!=NULL)
                    {
                        Aff_Adr(s,q);
                    }
                    else
                    {
                        m[i-1].adr=q;
                    }
                    cpt++;
                    s=q;
                }
                if (Colonne(p)>colvir)
                {
                    Allouer(&q);
                    Aff_Adr(q,NULL);
                    Aff_Val(q,Valeur(p));
                    Aff_Col(q,Colonne(p)-1);
                    if (s!=NULL)
                    {
                        Aff_Adr(s,q);
                    }
                    else
                    {
                        m[i-1].adr=q;
                    }
                    cpt++;
                    s=q;
                }
                m[i-1].taille=cpt;
                p=Suivant(p);
            }
        }
    }
}

/** 13- Vider le TabLLC *************************/

void vider_tabllc (struct tabllc tl[],int lig)
{
    int i;
    struct Maillon *p=NULL,*s=NULL;
    for (i=0;i<lig;i++)
    {
        tl[i].taille=0;
        p=tl[i].adr;
        tl[i].adr=NULL;
        while (p!=NULL)
        {
            s=Suivant(p);
            liberer(&p);
            p=s;
        }
    }
}

/** 14- Calculer la comatrice de la matrice (Utiliser pour calculer l'inverse de la matrice) *************************/

void comat(struct tabllc t[],int lig,int col,struct tabllc com[])
{
    int i,j,cpt,signe=1;
    struct tabllc m[50];
    struct Maillon *p=NULL,*q=NULL;
    for (i=0;i<lig;i++)
    {
        cpt=0;
        p=NULL;
        for (j=0;j<col;j++)
        {
            retire_lig_col(t,lig,i,j,m);
            if (determinant(m,lig-1)!=0)
            {
                Allouer(&q);
                Aff_Adr(q,NULL);
                Aff_Val(q,(signe*determinant(m,lig-1)));
                Aff_Col(q,j);
                if (cpt==0)
                {
                    com[i].adr=q;
                }
                else
                {
                    Aff_Adr(p,q);
                }
                p=q;
                cpt++;
            }
            signe=-(signe);
        }
        com[i].taille=cpt;
    }
}

/** 15- MENU *************************************************************************************************************/

void choixMenu()
{
    // t : matrice de debut // tsom, tprod, tprods, ttrans, tinv, tsolution : Matrice pour afficher les résultats
    // lig, col, ligsom, colsom, ligprod, colprod, ligprods, colprods, ligtrans, coltrans, liginv, colinv, ligsol, colsol : dimensions des matrices
    // v : scalaire
    // det : Determinant de la matrice t
    // tl, tlsom, tlprod, tlprods, tltrans, tlinv, tlsolution, tlinter : tabLLC (Utiliser pour effectuer les calculs)

    typeval t[MAX][MAX],tsom[MAX][MAX],tprod[MAX][MAX],tprods[MAX][MAX],ttrans[MAX][MAX],tinv[MAX][MAX],tsolution[MAX][MAX];
    int lig,col,ligsom,colsom,ligprod,colprod,ligprods,colprods,ligtrans,coltrans,liginv,colinv,ligsol,colsol,v;
    float det;
    struct tabllc tl[MAX],tlsom[MAX],tlprod[MAX],tlprods[MAX],tltrans[MAX],tlinv[MAX],tlsolution[MAX],tlinter[MAX];
    int choix , choixAffich ;
    boolean quite = faux , milieu ;
    while ( !quite) // Tanque la variable quite n'ai pas a vrai le programme continue
    {

        choix = menu(); // La variable choix reçoit le choix de l'utilisateur
        textattr(0);
        system("cls");
        switch(choix)
        {
        case 1: // Si choix = 1 , l'utilisateur a choisi de créer une matrice
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,10);
            Lire_Mat (t,&lig,&col);
            Mat_LLC (t,lig,col,tl);
            gotoxy(55,40);
            writeCh("LA MATRICE A ETE CREE AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break ;

        case 2: // Si choix = 2 , on affiche le Menu d'affichage des matrices
                textattr(3);
                cadre_aff(90,40,45,5);
                choixAffich = menu_affichage(); // On affecte le choix de l'affichage dans la variable choixAffich
                textattr(15);
                system("cls");
                switch(choixAffich)
                {
                case 1: // Si choixAffich = 1 on affiche la matrice
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    Ecrit_Mat(t,lig,col);
                    getch();
                break;
                case 2: // Si choixAffich = 2 on affiche la somme de deux matrice
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    Ecrit_Mat(tsom,ligsom,colsom);
                    getch();
                 break;
                case 3: // Si choixAffich = 3 on affiche le produit de deux matrices
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    Ecrit_Mat(tprod,lig,colprod);
                    getch();
                 break;
                case 4: // Si choixAffich = 4 on affiche le produit de la matrice par un scalaire
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    Ecrit_Mat(tprods,lig,col);
                    getch();
                 break;
                case 5: // Si choixAffich = 5 on affiche la matrice transposée de la matrice
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    Ecrit_Mat(ttrans,col,lig);
                    getch();
                 break;
                case 6: // Si choixAffich = 6 on affiche le determinant de la matrice
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    printf("Le determinant de la matrice est : %.2f",det);
                    getch();
                 break;
                case 7: // Si choixAffich = 7 on affiche la matrice inverse de la matrice
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    Ecrit_Mat(tinv,liginv,colinv);
                    getch();
                 break;
                case 8: // Si choixAffich = 8 on affiche les solutions du système d'equations
                    textattr(3);
                    cadre_aff(70,40,50,5);
                    textattr(15);
                    gotoxy(55,10);
                    Ecrit_Mat(tsolution,lig,col);
                    getch();
                 break;
                }

        break;

        case 3: // Si choix = 3 , on Calcule la somme de deux matrices
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,7);
            writeCh("Entrer l'autre matrice !\n\n",10);
            gotoxy(55,10);
            Lire_Mat (tsom,&ligsom,&colsom);
            vider_tabllc(tlinter,MAX);
            Mat_LLC (tsom,ligsom,colsom,tlinter);
            som_mat (tlinter,tl,tlsom,ligsom);
            LLC_Mat(tlsom,tsom,ligsom,colsom);
            gotoxy(55,40);
            writeCh("LA SOMME DES DEUX MATRICES A ETE CALCULER AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;

        case 4: // Si choix= 4 on Calcule le produit de deux matrices
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,7);
            writeCh("Entrer l'autre matrice !\n\n",10);
            gotoxy(55,10);
            Lire_Mat (tprod,&ligprod,&colprod);
            vider_tabllc(tlinter,MAX);
            Mat_LLC (tprod,ligprod,colprod,tlinter);
            prod_mat(tlinter,tl,tlprod,lig);
            LLC_Mat(tlprod,tprod,lig,colprod);
            gotoxy(55,40);
            writeCh("LE PRODUIT DES DEUX MATRICES A ETE CALCULER AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;

        case 5: // si choix= 5 on calcule le produit de la matrice par un scalaire
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,7);
            writeCh("Entrer le scalaire !\n\n",10);
            gotoxy(55,10);
            scanf("%d",&v);
            scal_prod_mat(tl,tlprods,lig,v);
            LLC_Mat(tlprods,tprods,lig,col);
            gotoxy(55,40);
            writeCh("LE PRODUIT DE LA MATRICE PAR LE SCALAIRE A ETE CALCULER AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break ;
        case 6: // Si choix = 6 on calcule la transposée de la matrice
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,30);
            trans_mat(tl,tltrans,lig);
            LLC_Mat(tltrans,ttrans,col,lig);
            writeCh("LA MATRICE TRANSPOSEE A ETE CALCULER AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;
        case 7: // Si choix = 7 on calcule le determinant de la matrice
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,30);
            det=determinant(tl,lig);
            writeCh("LE DETERMINANT DE LA MATRICE A ETE CALCULER AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;
        case 8: // si choix = 8 on calcule la matrice inverse de la matrice
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,30);
            writeCh("LA MATRICE INVERSE DE LA MATRICE A ETE CALCULER AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;
        case 9: // si choix = 9 resoudre le systeme d'equations basee une matrice creuse
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,30);
            writeCh("LES SOLUTIONS DU SYSTEME D'EQUATIONS A ETE CALCULER AVEC SUCCEES !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;
        case 10: // si choix = 10 on affiche la complexité des algorithmes
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,10);
            writeCh("Voici la liste des complexitées des algorithmes : !\n\n",10);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;
        case 11: // si choix = 11 on sauvegarde/restore une matrice
            textattr(3);
            cadre_aff(70,40,50,5);
            textattr(15);
            gotoxy(55,30);
            textattr(14);
            gotoxy(55,42);
            retourMenu(); // Retourner au Menu
         milieu = faux;
        break;
        case 12: // si choix = 12 on affiche le guide du menu
            textattr(3);
            cadre_aff(100,5,50,10);
            textattr(15);
            guide_menu(52,11);
            textattr(14);
            gotoxy(52,13);
            retourMenu();
        break;
        case 0: // si choix = 0 on quite le programme
            quite = vrai ;
            textattr(12);
            cadre_aff(50,5,65,17);
            gotoxy(72,19);
            textattr(14);
            printf("MERCI D'AVOIR UTILISE NOTRE PROGRAMME");
            gotoxy(70,24);
            textattr(15);
            system("pause");
        break;
        }
        textattr(15);
        system("cls");
    }
}
