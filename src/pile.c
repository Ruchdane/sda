#include <sda.h>

struct pile *createPile(){
    struct pile *result = malloc(sizeof(*result));

    #if defined(TABLEAU)
    result->head = -1;
    result->Tab = NULL;

    #else
    result->head = NULL;

    #endif //TABLEAU
    return result;
}

void *depile(struct pile *pile){
    void *result = NULL;

    #if defined(TABLEAU)
    if(pile->head != -1){
        result = pile->Tab[pile->head];
        if(pile->head != 0) 
            pile->Tab = realloc(pile->Tab,pile->head);
        else {
            free(pile->Tab);
            pile->Tab = NULL;
        }
        pile->head--;
    }
    #else
    struct element *tmp;
    if (pile->head){
        result = pile->head->value;
        tmp = pile->head;
        pile->head = pile->head->next;
        free(tmp);
    }
    #endif // TABLEAU
    return result;
}

void enpileElement(struct pile *pile,struct element *new){
    int result;
    void *tmp;
    if(pile){
        #if defined(TABLEAU)
        pile->head++;
        pile->Tab = realloc(pile->Tab,pile->head + 1);
        pile->Tab[pile->head] = value;
        #else
        new->next = pile->head;
        pile->head = new;
        #endif // TABLEAU
    }
}

void freePile(struct pile *P){
    struct element *prev = NULL,*tmp;
    if(P){
        prev = P->head;
    }
    if(prev != NULL)
        foreach(tmp,prev->next){
            freeElement(prev);
            prev = tmp; 
        }
}
// int main(int argc, char const *argv[])
// {
//     struct pile *pile = create();
//     empile(pile,(void *) '+');
//     empile(pile,(void *) 2);
//     empile(pile,(void *) 3);
//     printf("%d",(int)depile(pile));
//     affiche(pile);
//     return 0;
// }
