/*------------------------------------------------------------------------------------------------*/
/*            Procédures d'implémentation du modèle du TP 1 sur les matrices creuses              */
/*------------------------------------ -----------------------------------------------------------*/

typedef float typeval;

typedef struct Maillon
{
    typeval val ;
    int col;
    struct Maillon *suiv ;
}Maillon;

/*1*/ void Allouer (Maillon**nouveau)
{
    *nouveau = (Maillon*) malloc(sizeof(Maillon));
}

/*2*/ void liberer (Maillon**ancien)
{
    free(*ancien) ; *ancien=0;
};


/*3*/ void Aff_Val(Maillon*P, typeval v)
{
    P->val =v;
}


/*4*/ void Aff_Adr(Maillon*P,Maillon *Q)
{
    P->suiv = Q;
}

/*5*/ void Aff_Col(Maillon*P, typeval c)
{
    P->col = c;
}


/*6*/ Maillon *Suivant(Maillon*P)
{
    return( P->suiv );
}


/*7*/ typeval Valeur(struct Maillon*P)
{
    return( P->val) ;
}

/*8*/ int Colonne(struct Maillon*P)
{
    return( P->col) ;
}
