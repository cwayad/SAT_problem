#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct liste   //définion d'une structure gérant les collisions
{
    int val;
    int clause;
    struct liste* svt;
} liste;

typedef struct  //définion de la structure de la table d'hachage
{
    int var;
    int val;
    int clause;
    liste* p; //pointeur vers la liste chainée
} TypeSAT;

TypeSAT table[50]; //
void initialisation() 	// permet d'initialiser la table
{
    int i = 0;
    while(i<50)
    {
        table[i].var = 0;
        table[i].val = -1;
        table[i].clause= 0;
        table[i].p=NULL;
        i++;
    }
}

void insertion (int var, int val,int clause)   //le fait d'insertion d'un element pour la premiere fois dans la table.
{

    table[var].val = val ;
    table[var].var = var;
    table[var].clause = clause;

}
/*------------fonction inserer dans la Table ----------------------*/

int inserer (int var,int val, int clause)
{

    liste * elt;
    liste * q;


            insertion (var,val,clause);

            if (table[var].p == NULL)//pas de liste chainée=>création d'un element enchainement direct
                {
                    elt =(liste *) malloc(sizeof(liste));
                    elt->val = val;
                    elt->clause = clause;
                    elt->svt = NULL;
                    table[var].p = elt;
                }
                else  //sinon,parcours de la liste chainee (existante) et insertion a la fin
                {   q=table[var].p;
                    while(q->svt!=NULL){
                        q=q->svt;
                    }
                    elt =(liste *) malloc(sizeof(liste));
                    elt->val = val;
                    elt->clause = clause;
                    elt->svt = NULL;
                    q->svt = elt;



                }


}
void afficher()
{
    int i;
    printf("***************  Table  *************\n");
    printf("________________________________________________________________________\n");

    printf("|Variable:        |       VAleur             |       Clause            | \n");
    printf("|_________________|__________________________|_________________________| \n");

    i=0;
    while(i<50)
    {       printf("|%d                        ",table[i].var);
            printf("%d                         ",table[i].val);
            printf("%d\n",table[i].clause);
            printf("|                 |                          |                          |\n");
            printf("|_________________|__________________________|__________________________| \n");

            if(table[i].p!=NULL)
            {   liste *q;
                q=table[i].p;
                while( q!=NULL)
                {   printf("|%d                        ",q->val);
                    printf("%d                       \n",q->clause);
                    printf("|                 |                         |                          | \n");
                    printf("|_________________|_________________________|__________________________| \n");
                    q=q->svt;
                }
            }

    i++;
    }
}

int main()
{   int i=0, j=0, k=0;
    printf("Hello world!\n");

    initialisation();
    while (i<50){
    inserer (i,j,k);
    j++; i++; k++;
    }
    afficher();

    return 0;
}
