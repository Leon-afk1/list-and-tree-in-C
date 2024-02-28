#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"
#include "Biblio.h"
#include "Biblio.c"

int main(){
    course c=NULL;
    list l=NULL;
    int option, val,choix;
    do{
        printf("Choisissez entre liste(1) ou course(2) ou arbre (3)\n");
        scanf("%d",&choix);
        fflush(stdin);
    } while(choix!=1 && choix!=2 && choix!=3);
    if (choix==1){
        list p=NULL;
        p= insert_head(p,2);
        p= insert_tail_r(p,5);
        p= insert_head(p,4);
        p= insert_head(p,3);
        p= insert_tail_r(p,6);
        p= insert_head(p,9);

        do{
            printf("Select an option :\n1)add to head\n2)add to tail\n3)remove from head\n4)remove from tail\n5)combien de valeur\n6)contiens une valeur?\n"
                   "7)trier\n8)inverser\n9)Est triee?\n10)Somme de deux liste\n11)Add at place ...\n0)Quit\n");
            scanf("%d",&option);
            switch (option) {
                case 1:
                    printf("enter value to add\n");
                    scanf("%d",&val);
                    l= insert_head(l,val);
                    break;
                case 2:
                    printf("enter value to add\n");
                    scanf("%d",&val);
                    l=insert_tail_r(l,val);
                    break;
                case 3:
                    l= remove_head(l);
                    break;
                case 4:
                    l= remove_tail_r(l);
                    break;
                case 5:
                    val=count_recur(l);
                    printf("La liste contient %d valeurs\n", val);
                    break;
                case 6:
                    printf("enter value to add\n");
                    scanf("%d",&val);
                    if (!contains_r(l,val)){
                        printf("La valeur n'est pas dans la liste\n");
                    }else{
                        printf("La valeur est dans la liste\n");
                    }
                    break;
                case 7:
                    l= sort(l);
                    p= sort(p);
                    break;
                case 8:
                    l=reverse(l);
                    break;
                case 9:
                    est_trie(l);
                    break;
                case 10:
                    print_list(inter(l,p));
                    break;
                case 11:
                    printf("enter value to add\n");
                    scanf("%d",&val);
                    do {
                        printf("enter place to add\n");
                        scanf("%d",&option);
                    } while (option<0 || option>count_recur(l));
                    l=insert_at_n(l,val,option);
                    break;
                default:
                    break;
            }
            print_list(l);
            print_list(p);
        } while (option!=0);
    }else{
        if (choix==2){
            do{
                int num, quantite;
                float prix;
                printf("Select an option :\n1)add to head\n2)add to tail\n3)remove from head\n4)remove from tail\n5)combien de valeur\n6)contiens une valeur?\n"
                       "7)trier\n0)Quit\n");
                scanf("%d",&option);
                switch (option) {
                    case 1:
                        printf("enter values to add(num prix quantite)\n");
                        scanf("%d %f %d",&num,&prix,&quantite);
                        fflush(stdin);
                        c= ajout_tete(c,num,prix,quantite);
                        break;
                    case 2:
                        printf("enter values to add(num prix quantite)\n");
                        scanf("%d %f %d",&num,&prix,&quantite);
                        fflush(stdin);
                        c= ajout_queue(c,num,prix,quantite);
                        break;
                    case 3:
                        c= supp_tete(c);
                        break;
                    case 4:
                        c= supp_queue(c);
                        break;
                    case 5:
                        val=combien(c);
                        printf("La liste contient %d valeurs\n", val);
                        break;
                    case 6:
                        printf("enter number to check\n");
                        scanf("%d",&val);
                        fflush(stdin);
                        if (!contiens(c,val)){
                            printf("La valeur n'est pas dans la course\n");
                        }else{
                            printf("La valeur est dans la course\n");
                        }
                        break;
                    case 7:
                        c= tri_prix(c);
                        break;
                    default:
                        break;
                }
                affiche_course(c);
            } while (option!=0);
        }else{
            tree a=NULL;
            tree b=NULL;
            tree c=NULL;
            tree d=NULL;
            tree e=NULL;
            tree f=NULL;
            do {
                int valeur=0;
                printf("Select an option :\n1)Creer un arbre 1\n2)Creer un arbre 2\n3)Join arbre 1 et 2\n4)Nombre de noeuds\n5)Nombre de feuille\n"
                       "6)Valeur dans arbre\n7)Vider arbres\n8)Equiv 3 avec 1\n9)Equiv 3 avec 2\n10)Creer un arbre 4\n11)Creer un arbre 5\n12)Join arbre 4 et 5\n"
                       "13)Equiv 6 avec 1\n14)Equiv 6 avec 2\n0)Quit\n");
                scanf("%d",&option);
                int choix1=0, choix2=0;
                switch (option) {
                    case 1:
                        printf("Choisissez un valeur de racine\n");
                        scanf("%d",&valeur);
                        a=cree_arbre(valeur);
                        print2D(a);
                        break;
                    case 2:
                        printf("Choisissez un valeur de racine\n");
                        scanf("%d",&valeur);
                        b=cree_arbre(valeur);
                        print2D(b);
                        break;
                    case 3:
                        printf("Choisissez un valeur de racine\n");
                        scanf("%d",&valeur);
                        c=join_arbre(a,b,valeur);
                        print2D(c);
                        break;
                    case 4:
                        valeur =nombre_de_noeuds(c);
                        printf("Il y a %d noeud(s)\n",valeur);
                        break;
                    case 5:
                        valeur=nombre_de_feuille(c);
                        printf("Il y a %d feuilles\n",valeur);
                        break;
                    case 6:
                        printf("Choisissez un valeur a chercher\n");
                        scanf("%d",&valeur);
                        valeur_arbre(c,valeur);
                        break;
                    case 7:
                        supp(a);
                        supp(b);
                        break;
                    case 8:
                        a=c;
                        break;
                    case 9:
                        b=c;
                        break;
                    case 10:
                        printf("Choisissez un valeur de racine\n");
                        scanf("%d",&valeur);
                        d=cree_arbre(valeur);
                        print2D(d);
                        break;
                    case 11:
                        printf("Choisissez un valeur de racine\n");
                        scanf("%d",&valeur);
                        e=cree_arbre(valeur);
                        print2D(e);
                        break;
                    case 12:
                        printf("Choisissez un valeur de racine\n");
                        scanf("%d",&valeur);
                        f=join_arbre(d,e,valeur);
                        print2D(f);
                        break;
                    case 13:
                        a=f;
                        break;
                    case 14:
                        b=f;
                        break;
                    default:
                        break;
                }
            }while (option!=0);
        }
    }
    return 0;
}