#include <sda.h>//Header containing methods to be tested
#include <minunit.h>

int tests_run;
int tests_failed;
int tests_passed;

static char *Test_La_File_Est_Vide(){
    mu_begin_of_a_test();
    struct file* F = createFile();
	mu_assert(isFileEmpty(F),"La file n'est pas vide");
    freeFile(F);
    return 0;
}

static char *Test_Enfiler_Une_Valeur(){
    mu_begin_of_a_test();
    struct file* F = createFile();
    enfile(F,(void *)1);
	mu_assert(!isFileEmpty(F),"La file n'est pas vide");
    mu_assert(F->head->value == (void*)1,"La valeur inserer n'est pas la bonne");
    enfile(F,(void *)2);
    mu_assert(F->tail->value == (void*)2,"La valeur inserer n'est pas la bonne");
    freeFile(F);
    return 0;
}

static char *Test_Defiler_Une_Valeur(){
    mu_begin_of_a_test();
    struct file* F = createFile();
    enfile(F,(void *)1);
    enfile(F,(void *)2);
    mu_assert(defile(F) == (void *)1,"La va leur defiler n'est pas la bonne");
    mu_assert(F->head->value == (void*)2,"La valeur inserer n'est pas la bonne");
    defile(F);
    mu_assert(isFileEmpty(F),"La liste n'est pas vide");
    freeFile(F);
    return 0;
}

int main(void){
        mu_begin();

        mu_run_test(Test_La_File_Est_Vide);

        mu_run_test(Test_Enfiler_Une_Valeur);

        mu_run_test(Test_Defiler_Une_Valeur);

        mu_result();
}