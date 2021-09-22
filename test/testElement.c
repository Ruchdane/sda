#include <sda.h>
#include <minunit.h>

int tests_run;
int tests_failed;
int tests_passed;
static char *Test_Creer_Un_Element_Pour_Un_Entier(){
    mu_begin_of_a_test();
    struct element *element;
    int value = 2;
    element = createElement((void *)value);
    //struct { float real ;float img }  complex = {1.2,2.3};
    mu_assert(element!= NULL,"L'element creer est un pointeur null\n");
    mu_assert((int)(element->value) == value, "L'element creer n'as pas la meme valeur que celle fourni\n");
    mu_assert(element->next == NULL, "Le suivant de l'element creer n'est pas null\n");
    // freeElement(element);
}

static char *Test_Creer_Un_Element_Pour_Un_Pointer_Sur_Entier(){
    mu_begin_of_a_test()
    struct element *element;
    int value = 1;
    element = createElement((void *)(&value));
    //struct { float real ;float img }  complex = {1.2,2.3};
    mu_assert(element!= NULL,"L'element creer est un pointeur null\n");
    mu_assert((int *)(element->value) == &value, "L'element creer n'as pas la meme pointer que celle fourni\n");
    mu_assert(*((int *)(element->value)) == value, "L'element creer ne pointe pas sur la meme variable que celle fourni\n");
    mu_assert(element->next == NULL, "Le suivant de l'element creer n'est pas null\n");
}
struct complex { float real ,img ;};
static char *Test_Creer_Un_Element_Pour_Un_Pointer_Sur_Une_Structure_Quelconque(){
    mu_begin_of_a_test()
    struct element *element;
    struct complex value = {1.2,2.3};
    
    element = createElement((void *)(&value));
    mu_assert(element!= NULL,"L'element creer est un pointeur null\n");
    mu_assert((struct complex *)(element->value) == &value, "L'element creer n'as pas la meme pointer que celle fourni\n");
    mu_assert(((struct complex *)(element->value))->real == value.real,
        "La valeur du premier champ de l'element pointer n'est pas la  meme variable que celle fourni\n");
    mu_assert(((struct complex *)(element->value))->img == value.img,
        "La valeur du deuxieme champ de l'element pointer n'est pas la  meme variable que celle fourni\n");

    mu_assert(element->next == NULL, "Le suivant de l'element creer n'est pas null\n");
}

static char *Test_Liberer_Un_Element_Creer_Pour_Un_Entier(){
    mu_begin_of_a_test();
    struct element *element;
    int value = 2,result = 0;
    element = createElement((void *)value);
    result = (int)freeElement(element);
    // mu_assert(result == value,"La valeur renvoye apres liberation est differente de celle fournie lors de la creation");
}

int main(void){
    mu_begin();
    mu_run_test(Test_Creer_Un_Element_Pour_Un_Entier);
    mu_run_test(Test_Creer_Un_Element_Pour_Un_Pointer_Sur_Entier);
    mu_run_test(Test_Creer_Un_Element_Pour_Un_Pointer_Sur_Une_Structure_Quelconque);
    // mu_run_test(Test_Liberer_Un_Element_Creer_Pour_Un_Entier);
    mu_result();
}