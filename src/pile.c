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

void empile(struct pile *pile,void *value){
    int result;
    void *tmp;
    if(pile){
        #if defined(TABLEAU)
        pile->head++;
        pile->Tab = realloc(pile->Tab,pile->head + 1);
        pile->Tab[pile->head] = value;
        #else
        struct element *new = malloc(sizeof(struct element));
        new->value = value;
        new->next = pile->head;
        pile->head = new;
        #endif // TABLEAU
    }
}

void affiche(struct pile *pile, int type){
    void *value;
    #if defined(TABLEAU)
    for (int i = pile->head; i >= 0; i--){
        value = pile->Tab[i];
    #else
    for(struct element *element = pile->head;element;element = element->next){
        value = element->value;
    #endif // TABLEAU
    if(type) printf("%d ->",(int)value);
    else  printf("%c ->",(char)value);
    }
    printf("\n");
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
