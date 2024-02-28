#ifndef BIBLIO_FONCTION_LIST_BIBLIO_H
#define BIBLIO_FONCTION_LIST_BIBLIO_H


typedef struct elem{
    int value;
    struct elem* next;
}elem;

typedef  elem* list;

typedef struct prod{
    int num;
    float prix;
    int quantite;
    struct prod* next;
}prod;

typedef prod* course;

typedef struct Arbre
{
    int value;
    struct Arbre *Agauche;
    struct Arbre *Adroit;
    struct Arbre *parent;
}Arbre;

typedef Arbre* tree;

bool est_vide(course c);
bool is_empty(list l);
course ajout_tete(course c, int Num, float Prix,int Quantite);
list insert_head(list l, int e);
course ajout_queue(course c, int Num, float Prix,int Quantite);
list insert_tail(list l, int e);
list insert_tail_r(list l,int v);
list insert_at_n(list l, int val, int n);
course supp_tete(course c);
list remove_head(list l);
course supp_queue(course c);
list remove_tail(list l);
list remove_tail_r(list l);
void affiche_course(course c);
void print_list(list l);
int valeur_tete(course c);
float valeur_prix(course c);
int valeur_quantite(course c);
int head_value(list l);
course suite(course c);
list rest(list l);
int combien(course c);
int count_recur(list l);
int count(list l);
bool contiens(course c, int Num);
bool contains_r(list l,int v);
bool contains(list l, int v);
course tri_prix(course c);
list sort(list l);
list reverse(list l);
void est_trie(list l);
int nombre_de_noeuds (tree ar);
tree cree_arbre(int x);
void affiche_arbre_prefixe(tree ar);
tree join_arbre(tree gauche,tree droit,int n);
int nombre_de_feuille(tree c);
list inter(list l,list p);
void valeur_arbre(tree a, int v);
void arbre_egal(tree a, tree b);
void vider_arbre(tree ar);
void print2DUtil(tree root, int space);
void print2D(tree root);
void supp(tree ar);

#endif //BIBLIO_FONCTION_LIST_BIBLIO_H
