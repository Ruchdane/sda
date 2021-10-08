#include <sda.h>
#include <minunit.h>

int tests_run;
int tests_failed;
int tests_passed;

static char *Test_Creer_Une_Liste_Vide(){
    mu_begin_of_a_test();
	struct element *L = createList();
	mu_assert(isListEmpty(L),"La liste creer n'est pas vide");
    return 0;
}

static char *Test_Ajouter_Un_Element_Au_Debut_D_Une_Liste_Vide(){
    mu_begin_of_a_test();
	struct element *L = createList(),
		*element = createElement((void *)1);
	L = prependElement(L,element);
	mu_assert(L == element,"L'element ajouter n'est pas celle donner");
    return 0;
}

static char *Test_Ajouter_Un_Element_Dans_Une_Liste(){
    mu_begin_of_a_test();
	int i = 0;
	struct element *L = createList(),*tmp,*elements[4] = {createElement((void *)1), createElement((void *)2), createElement((void *)3), createElement((void *)4)};
	L = appendElement(L,elements[0]);
	L = appendElement(L,elements[3]);
	L = insertElementAt(L,elements[1],1);
	L = insertElementAt(L,elements[2],2);
	mu_assert(!isListEmpty(L),"la liste est vide");
	foreach(tmp,L){
		mu_assert(tmp == elements[i],"L'element numéro  n'est pas le bon");
		i++;
	}
    return 0;
}

static char *Test_Ajouter_Un_Element_A_La_Fin__D_Une_Liste_Vide(){
    mu_begin_of_a_test();
	struct element *L = createList(),
		*element = createElement((void *)1);
	L = appendElement(L,(void *)element);
	mu_assert(L == element,"L'element ajouter n'est pas celle donner");
    return 0;
}

static char *Test_Ajouter_Une_Valeur_Au_Debut_D_Une_Liste_Vide(){
    mu_begin_of_a_test();
	struct element *L = createList();
	L = prepend(L,(void*)1);
	mu_assert((int)L->value == 1,"L'element ajouter n'est pas celle donner");
    return 0;
}

static char *Test_Ajouter_Une_Valeur_Dans_Une_Liste(){
    mu_begin_of_a_test();
	int i = 0,valeurs[] = {1,2,3,4};
	struct element *L = createList(),*tmp;
	L = append(L,valeurs[0]);
	L = append(L,valeurs[3]);
	L = insertAt(L,valeurs[1],1);
	L = insertAt(L,valeurs[2],2);
	foreach(tmp,L){
		mu_assert((int)(tmp->value) == valeurs[i],"L'element numéro  n'est pas le bon");
		i++;
	}
    return 0;
}

static char *Test_Ajouter_Une_Valeur_A_La_Fin__D_Une_Liste_Vide(){
    mu_begin_of_a_test();
	struct element *L = createList();
	L = append(L,(void *)1);
	mu_assert((int)(L->value) == 1,"L'element ajouter n'est pas celle donner");
    return 0;
}

static char *Test_Enledver_Une_Valeur_D_Une_Liste_Vide(){
    mu_begin_of_a_test();
	struct element *L = createList(),*tmp;
	L = append(L,(void *)1);
	L = append(L,(void *)2);
	L = append(L,(void *)3);
	removeAt(L,1,&tmp);
	mu_assert((int)(tmp->value) == 2,"L'element retirer n'est pas celle demander");
	mu_assert((int)(L->next->value) == 3,"L'element n'a pas ete bien retirer n'est pas celle demander");
    return 0;
}

int main(void){
        mu_begin();

        mu_run_test(Test_Creer_Une_Liste_Vide);

        mu_run_test(Test_Ajouter_Un_Element_Au_Debut_D_Une_Liste_Vide);

        mu_run_test(Test_Ajouter_Un_Element_Dans_Une_Liste);

        mu_run_test(Test_Ajouter_Un_Element_A_La_Fin__D_Une_Liste_Vide);

        mu_run_test(Test_Ajouter_Une_Valeur_Au_Debut_D_Une_Liste_Vide);

        mu_run_test(Test_Ajouter_Une_Valeur_Dans_Une_Liste);

        mu_run_test(Test_Ajouter_Une_Valeur_A_La_Fin__D_Une_Liste_Vide);

        mu_run_test(Test_Enledver_Une_Valeur_D_Une_Liste_Vide);

        mu_result();
}