#ifndef  DATASTRUCTUREHEADER
#define DATASTRUCTUREHEADER
//#define TABLEAU

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define toBool(condition) (condition ? true: false)

/*#if defined(TABLEAU)
struct file {
    void **Tab;
    int tail;
};
struct pile {
    void **Tab;
    int head;
};
#else
*/
/**/
struct element
{
    void *value;
    struct element *next;
};

#define foreach(element,list) for(element = list;element != NULL;element = element->next)
#define forreach(element,list) for(element = list;element->next != NULL;element = element->next)
struct element *createElement(void *);
void * freeElement(struct element *);

struct element * createList();
bool isListEmpty(struct element *);
struct element *prepend(struct element *,void *);
struct element *append(struct element *,void *);
struct element *removeFirst(struct element *,struct element**);
struct element *removeLast(struct element *,struct element**);
struct element *removeAt(struct element *,int ,struct element**);
//struct element *remove(struct element *,void * ,struct element**);


struct file { 
    struct element *head; 
    struct element *tail; 
};

struct pile { struct element *head; };
//#endif // MACRO

struct noeud{
  int value;
  struct noeud *fils;
  struct noeud *frere;
};


struct file *createFile();
void *defile(struct file *);
void enfile(struct file *,void *);
void afficheFile(struct file *,int);

struct pile *createPile();
void *depile(struct pile *);
void empile(struct pile *,void *);
void affiche(struct pile *,int);


struct noeud *creerNoeud(int val);
struct noeud * ajouterFils(struct noeud *noeud,int val);
struct noeud * srcArbre(struct noeud *noeud,int val);
#endif // DATASTRUCTUREHEADER