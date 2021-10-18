#include <sda.h>

struct file *createFile(){
    struct file *result = malloc(sizeof(*result));

    #if defined(TABLEAU)
    result->tail = -1;
    result->Tab = NULL;

    #else
    result->head = NULL;

    #endif //TABLEAU
    
    return result;
}

void *defile(struct file *file){
    void *result = NULL;
    #if defined(TABLEAU)
    int i;
    if(file->tail != -1){
        result = file->Tab[0];
        for (i = 0; i < file->tail; i++)
            file->Tab[i] = file->Tab[i + 1];
        file->Tab = realloc(file->Tab,file->tail);
        file->tail--;
    }
    #else
    struct element *tmp;
    if (file->head){
        result = file->head->value;
        tmp = file->head;
        file->head = file->head->next;
        free(tmp);
    }
    #endif // TABLEAU
    return result;
}

void enfileElement(struct file *file,void *value){
    int result;
    void *tmp;
    if(file){
        #if defined(TABLEAU)
        file->tail++;
        file->Tab = realloc(file->Tab,file->tail + 1);
        file->Tab[file->tail] = value;
        #else
        struct element *new = malloc(sizeof(struct element));
        new->value = value;
        new->next = NULL;
        if(!file->head){
            file->head = new;
            file->tail = new;
        }

        else{
            file->tail->next = new;
            file->tail = new;
        }
        #endif // TABLEAU
    }
}

void freeFile(struct file * F){
    struct element *prev = F->head,*tmp;
    foreach(tmp,prev->next){
        freeElement(prev);
    }
}

// int main(int argc, char const *argv[])
// {
//     struct file *file = create();
//     enfile(file,(void *) 3);
//     enfile(file,(void *) 3);
//     enfile(file,(void *) 4);
//     // printf("Here");
//     defile(file);
//     // printf("%s",(char)54);
//     printf("%d\n",(int)defile(file));
//     // printf("%d\n",(int)defile(file));
//     return 0;
// }
