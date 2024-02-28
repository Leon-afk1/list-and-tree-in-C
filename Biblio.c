#include <stdio.h>
#include "stdbool.h"
#include "stdlib.h"
#include "Biblio.h"
#define COUNT 10

bool est_vide(course c){
    if (c==NULL){
        return true;
    }else{
        return false;
    }
}

bool is_empty(list l){
    if (l==NULL){
        return true;
    }else{
        return false;
    }
}

course ajout_tete(course c, int Num, float Prix,int Quantite){
    course v;
    v=(prod*) malloc(sizeof (prod));
    v->num=Num;
    v->prix=Prix;
    v->quantite=Quantite;
    v->next=c;
    return v;
}

list insert_head(list l, int e){
    list new;
    new=(elem*)malloc(sizeof(elem));
    new->value=e;
    new->next=l;
    return new;
}

course ajout_queue(course c, int Num, float Prix,int Quantite){
    course l=c;
    course n;
    n=(prod*) malloc(sizeof (prod));
    n->num=Num;
    n->prix=Prix;
    n->quantite=Quantite;
    n->next=NULL;
    if (l==NULL){
        l=n;
    }else{
        while (l->next!=NULL){
            l=l->next;
        }
        l->next=n;
    }
    return c;
}

list insert_tail(list l, int e){
    list new;
    list p;
    new=(elem*)malloc(sizeof(elem));
    new->value=e;
    new->next=NULL;
    if (l==NULL){
        l=new;
    }else{
        p=l;
        while (p->next!=NULL){
            p=p->next;
        }
        p->next=new;
    }
    return l;
}

list insert_at_n(list l, int val, int n){
    list new;
    list p;
    n=n-2;
    new=(elem*)malloc(sizeof(elem));
    new->value=val;
    new->next=NULL;
    if (l==NULL){
        l=new;
    }else{
        p=l;
        for (int i = 0; i < n; ++i) {
            p=p->next;
        }
        new->next=p->next;
        p->next=new;
    }
    return l;
}

list new_elem(int v){
    list new;
    new=(elem*)malloc(sizeof(elem));
    new->value=v;
    new->next=NULL;
    return new;
}

list insert_tail_r(list l, int v){
    if (is_empty(l)){
        return new_elem(v);
    }else{
        return insert_head(insert_tail_r(rest(l),v), head_value(l));
    }
}

list remove_tail_r(list l){
    if (is_empty(l)){
        return l;
    }else{
        if (is_empty(rest(l))){
            free(l);
            return NULL;
        }else{
            return insert_head(remove_tail_r(rest(l)), head_value(l));
        }
    }
}
course supp_tete(course c){
    course v;
    if (c==NULL){
        v=NULL;
    }else{
        v=c->next;
        free(c);
    }
    return v;
}

list remove_head(list l){
    list p;
    if (l==NULL){
        p=NULL;
    }else{
        p=l->next;
        free(l);
    }
    return p;
}

course supp_queue(course c){
    if (c!=NULL){
        if (c->next==NULL){
            c=NULL;
        }else{
            course v=c;
            while (v->next->next!=NULL){
                v=v->next;
            }
            free(v->next);
            v->next=NULL;
        }
    }
    return c;
}

list remove_tail(list l){
    if (l!=NULL){
        if (l->next==NULL){
            free(l);
            l=NULL;
        }else{
            list p=l;
            while (p->next->next!=NULL){
                p=p->next;
            }
            free(p->next);
            p->next=NULL;
        }
    }
    return l;
}

void affiche_course(course c){
    if (c==NULL){
        printf("Il n'y a pas de produit\n");
    }else{
        course v=c;
        while (v->next!=NULL){
            printf("[num:%d , prix:%f , quantite:%d\n",v->num,v->prix,v->quantite);
            v=v->next;
        }
        printf("[num:%d , prix:%f , quantite:%d\n",v->num,v->prix,v->quantite);
    }
}

void print_list(list l){
    if (is_empty(l)){
        printf("La liste est vide\n");
    }else{
        list p=l;
        printf("[");
        while (p->next!=NULL){
            printf("%d ",p->value);
            p=p->next;
        }
        printf("%d]\n",p->value);
    }
}

int valeur_tete(course c){
    return c->num;
}

float valeur_prix(course c){
    return c->prix;
}

int valeur_quantite(course c){
    return c->quantite;
}

int head_value(list l){
    return l->value;
}

course suite(course c){
    return c->next;
}

list rest(list l){
    return l->next;
}

int combien(course c){
    int nb=0;
    if (!est_vide(c)){
        course v=c;
        while (v!=NULL){
            nb++;
            v= suite(v);
        }
    }
    return nb;
}

int count_recur(list l){
    if (is_empty(l)){
        return 0;
    }else{
        return count_recur(rest(l))+1;
    }
}

int count(list l){
    int c=0;
    list p;
    if (!is_empty(l)){
        p=l;
        while (p!=NULL){
            c=c+1;
            p= rest(p);
        }
    }
    return c;
}

bool contiens(course c, int Num){
    bool cont= false;
    course v=c;
    while (!est_vide(v) && cont==false){
        if (valeur_tete(v)==Num){
            cont = true;
        }else{
            v= suite(v);
        }
    }
    return cont;
}

bool contains_r(list l,int v){
    if (is_empty(l)){
        return false;
    }else{
        if (head_value(l)==v){
            return true;
        }else{
            return contains_r(rest(l),v);
        }
    }
}

bool contains(list l, int v){
    bool cont = false;
    list p=l;
    while (!is_empty(p) && cont==false){
        if (head_value(p)==v){
            cont = true;
        }else{
            p=rest(p);
        }
    }
    return cont;
}

course tri_prix(course c){
    bool inv=false;
    course v=c;
    float temp;
    int num_temp,num_quantite;
    course f=NULL;
    if ( !est_vide(v) && !est_vide(suite(v))){
        do{
            inv = false;
            v=c;
            while (suite(v)!=f){
                if (valeur_prix(v)> valeur_prix(suite(v))){
                    temp= valeur_prix(v);
                    v->prix= valeur_prix(v->next);
                    v->next->prix=temp;
                    num_temp= valeur_tete(v);
                    v->num= valeur_tete(v->next);
                    v->next->num=num_temp;
                    num_quantite= valeur_quantite(v);
                    v->quantite= valeur_quantite(v->next);
                    v->next->quantite=num_quantite;
                    inv = true;
                }
                v=v->next;
            }
            f=v;
        } while (inv);
    }
    return c;
}

list sort(list l){
    bool inv=false;
    list p=l;
    int temp;
    list f=NULL;
    if ( !is_empty(p) && !is_empty(rest(p))){
        do{
            inv = false;
            p=l;
            while (rest(p)!=f){
                if (head_value(p)> head_value(rest(p))){
                    temp= head_value(p);
                    p->value= head_value(p->next);
                    p->next->value=temp;
                    inv = true;
                }
                p=p->next;
            }
            f=p;
        } while (inv);
    }
    return l;
}

list reverse(list l) {
    if(is_empty(l)){
        return l;
    }else{
        return insert_tail_r(reverse(rest(l)), head_value(l));
    }
}

void est_trie(list l){
    if (is_empty(l)){
        printf("La liste est vide\n");
    }else{
        if (is_empty(l->next)){
            printf("La liste est triee");
        }else{
            if( l->value<=l->next->value){
                est_trie(rest(l));
            }else{
                printf("La liste n'est pas triee\n");
            }

        }
    }
}

int nombre_de_noeuds (tree ar){
    if (ar==NULL){
        return (0);
    }else{
        if(ar->Adroit==NULL && ar->Agauche==NULL){
            return 1;
        }else{
            return (nombre_de_noeuds(ar->Adroit)+ nombre_de_noeuds(ar->Agauche)+1);
        }
    }
}

tree cree_arbre(int x){
    tree tmp=(Arbre*)malloc(sizeof(Arbre));
    tmp->Agauche=NULL;
    tmp->Adroit=NULL;
    tmp->parent=NULL;
    tmp->value=x;
    return tmp;
}

void affiche_arbre_prefixe(tree ar){
    if (ar!=NULL){
        printf("%d\n",ar->value);
        affiche_arbre_prefixe(ar->Agauche);
        affiche_arbre_prefixe(ar->Adroit);
    }else{
        printf("Feuille vide\n");
    }
}

tree join_arbre(tree gauche,tree droit,int n){
    tree temp ;
    temp = (Arbre *) malloc ( sizeof ( Arbre )) ;
    temp -> value = n ;
    temp -> Adroit = droit ;
    temp -> Agauche = gauche ;
    temp -> parent = NULL ;
    return temp ;
}

int nombre_de_feuille(tree c){
    if (c==NULL){
        return (0);
    }else{
        if(c->Adroit==NULL && c->Agauche==NULL){
            return 1;
        }else{
            return (nombre_de_feuille(c->Adroit)+ nombre_de_feuille(c->Agauche));
        }
    }
}

list inter(list l,list p){
    if (is_empty(l) && is_empty(p)){
        return l;
    }else{
        if (is_empty(l)){
            return p;
        }else{
            if (is_empty(p)){
                return l;
            }else{
                if (l->value <= p->value){
                    return insert_head(inter(l->next,p),l->value);
                }else{
                    return insert_head(inter(p->next,l),p->value);
                }
            }
        }
    }
}

void valeur_arbre(tree a, int v){
    if (a==NULL){
        printf("L'arbre ne contient pas la valeur\n");
    }else{
        if (a->Agauche==NULL && a->Adroit==NULL){
            if (a->value==v){
                printf("La valeur est dans l'arbre\n");
            }else{
                printf("L'arbre ne contient pas la valeur\n");
            }
        }else{
            if (a->value==v){
                printf("La valeur est dans l'arbre\n");
            }else{
                valeur_arbre(a->Agauche,v);
                valeur_arbre(a->Adroit,v);
            }
        }

    }
}

void arbre_egal(tree a, tree b){
    if (a == NULL && b==NULL){
        printf("Les arbres sont egaux\n");
    }
    if ((a==NULL && b!=NULL) || (b==NULL && a!=NULL)){
        printf("les arbres ne sont pas egaux\n");
    }
    if (a->value == b->value){

    }
}

void vider_arbre(tree ar){
    if (ar == NULL) return;
    vider_arbre(ar->Agauche);
    vider_arbre(ar->Adroit);
    free(ar);
}

void supp(tree ar){
    vider_arbre(ar);
}

void print2DUtil(tree root, int space){
    if (root == NULL) return;
    space += COUNT;
    print2DUtil(root->Adroit, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->value);
    print2DUtil(root->Agauche, space);
}

void print2D(tree root)
{
    print2DUtil(root, 0);
}
