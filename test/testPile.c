#include <sda.h>//Header containing methods to be tested
#include <minunit.h>

int tests_run;
int tests_failed;
int tests_passed;

static char *Test_La_Pile_Est_Vide(){
    mu_begin_of_a_test();
    struct pile* P = createPile();
	mu_assert(isPileEmpty(P),"La file n'est pas vide");
    freePile(P);
    return 0;
}

static char *Test_Enpiler_Une_Valeur_Dans_Une_Pile_Vide(){
    mu_begin_of_a_test();
    struct pile* P = createPile();
    enpile(P,(void *)1);
	mu_assert(!isPileEmpty(P),"La file est  vide");
    mu_assert(P->head->value == (void*)1,"La valeur inserer n'est pas la bonne");
    freePile(P);
    return 0;
}

static char *Test_Enpiler_Une_Valeur_Dans_Une_Pile(){
    mu_begin_of_a_test();
    struct pile* P = createPile();
    enpile(P,(void *)1);
	mu_assert(!isPileEmpty(P),"La file est pas vide");
    enpile(P,(void *)2);
    mu_assert(P->head->value == (void*)2,"La valeur inserer n'est pas la bonne");
    mu_assert(P->head->next->value == (void*)1,"La valeur suivante de la tete n'est pas la bonne");
    freePile(P);
    return 0;
}

static char *Test_Depiler_Une_Valeur_Dans_Une_Pile_Contenant_Un_Seul_Element(){
    mu_begin_of_a_test();
    struct pile* P = createPile();
    enpile(P,(void *)1);
    mu_assert(depile(P) == (void *)1,"La valeur depiler n'est pas la bonne");
    mu_assert(isPileEmpty(P),"La liste n'est pas vide");
    freePile(P);
    return 0;
}
static char *Test_Depiler_Une_Valeur_Dans_Une_Pile_Contenant_Deux_Element(){
    mu_begin_of_a_test();
    struct pile* P = createPile();
    enpile(P,(void *)2);
    enpile(P,(void *)1);
    mu_assert(depile(P) == (void *)1,"La valeur depiler n'est pas la bonne");
    mu_assert(P->head->value == (void *)2,"La valeur suivant celle depiler n'est pas la bonne");
    freePile(P);
    return 0;
}

int main(void){
        mu_begin();

        mu_run_test(Test_La_Pile_Est_Vide);

        mu_run_test(Test_Enpiler_Une_Valeur_Dans_Une_Pile_Vide);

        mu_run_test(Test_Enpiler_Une_Valeur_Dans_Une_Pile);

        mu_run_test(Test_Depiler_Une_Valeur_Dans_Une_Pile_Contenant_Un_Seul_Element);

        mu_run_test(Test_Depiler_Une_Valeur_Dans_Une_Pile_Contenant_Deux_Element);

        mu_result();
}