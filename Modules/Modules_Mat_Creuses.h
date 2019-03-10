#ifndef MODULES_FIBONACCI_H_INCLUDED
#define MODULES_FIBONACCI_H_INCLUDED
#define faux 0
#define vrai 1
#define MAX 100
/* DECLARATION DES TYPES : */
typedef int boolean ;

typedef float typeval;

typedef struct Maillon
{
    typeval val ;
    int col;
    struct Maillon *suiv ;
}Maillon;

typedef struct tabllc
{
    int taille ;
    struct Maillon *adr ;
}tabllc;

/* PROTOTYPES DES MODULES : */
/** 1- Lire la matrice **************************************************************************************/
void Lire_Mat (typeval t[MAX][MAX],int *lig,int *col);

/** 2- Ecrire la matrice ****************************************************************************************/
void Ecrit_Mat (typeval t[MAX][MAX],int lig,int col);

/** 3 - Convertir La matrice en tabLLC ***************************************************************************************/
void Mat_LLC (typeval t[MAX][MAX],int lig,int col,struct tabllc tl[MAX]);

/** 4- Convertir Le tabLLC en matrice ******************************************************************************************************/
void LLC_Mat (struct tabllc tl[MAX],typeval t[MAX][MAX],int lig,int col);

/** 5- Calculer la somme de deux matrices (représenté en deux tabLLC) ********************************************************/
void som_mat (struct tabllc A[MAX],struct tabllc B[MAX],struct tabllc C[MAX],int lig);

/** 6- Calculer le produit de deux matrices (représenté en deux tabLLC) ******************************************************/
void prod_mat (struct tabllc A[MAX],struct tabllc B[MAX],struct tabllc C[MAX],int lig);

/** 7- Calculer le produit d'une matrice (représenté en TabLLC) par un scalaire **********************************************/
void scal_prod_mat (struct tabllc A[MAX],struct tabllc B[MAX],int lig,typeval v);

/** 8- Calculer la matrice transposée de la matrice **************************************************************************/
void trans_mat (struct tabllc A[MAX],struct tabllc B[MAX],int lig);

/** 9- Calculer le determinant de la matrice **************************************************************************/
float determinant(struct tabllc t[],int lig);

/** 10- Calculer la matrice inverse de la matrice **************************************************************************/
void inverse (struct tabllc tl[], int lig,int col, struct tabllc res[]);

/** 11- Resoudre le système d'equation besee une matrice creuse ***************************************************************/

/** 12- retirer la ligne ligvir et la colonne colvir du tabllc (utiliser pour calculer le determinant *************************/
void retire_lig_col (struct tabllc tl[],int lig,int ligvir,int colvir,struct tabllc m[]);

/** 13- Vider le TabLLC *************************/
void vider_tabllc (struct tabllc tl[],int lig);

/** 14- Calculer la comatrice de la matrice (Utiliser pour calculer l'inverse de la matrice) *************************/
void comat(struct tabllc t[],int lig,int col,struct tabllc com[]);

/** 15- MENU ******************************************************************************************************************/
void choixMenu();

#endif // MODULES_FIBONACCI_H_INCLUDED
