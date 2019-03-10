#ifndef MODELELLC_H_INCLUDED
#define MODELELLC_H_INCLUDED

/*---------------------------------------------------------------------------------------------------*/
/*        Procédures d'implémentation du modèle du TP 1 sur les matrices creuses                     */
/*---------------------------------------------------------------------------------------------------*/


/*1*/ void Allouer (Maillon**nouveau);

/*2*/ void liberer (Maillon**ancien);

/*3*/ void Aff_Val(Maillon*P, typeval v);

/*4*/ void Aff_Adr(Maillon*P,Maillon *Q);

/*5*/ void Aff_Col(Maillon*P, int c);

/*6*/ Maillon *Suivant(Maillon*P);

/*7*/ typeval Valeur(struct Maillon*P);

/*8*/ int Colonne(struct Maillon*P)

#endif // MODELELLC_H_INCLUDED
