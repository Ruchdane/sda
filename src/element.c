#include <sda.h>
struct element *createElement(void *value){
	struct element *element = malloc(sizeof(*element));
	if(element == NULL)
		fprintf(stderr,"Could not allocate memory for creating a new element");
	
	else{
		/*
		* Note on utilise les pointers des valeurs pas les valeur elle meme.
		* Si les valeurs elle meme sont utiliser dans le cas des type de base, il peut y avoir des erreur
		* au cour de la conversion (void *) => type.
		* Si ce n'est pas un type de base il vaut mieu utiliser le pointer sur ce dernier?
		* Que doit il se passer si on enpile NULL ?	
		*/
		element->value = value;
		element->next = NULL;
	}
	return element;
}

void * freeElement(struct element *element){
	void * value = NULL;
	if(element){
		value = element->value;
		free(element);
	}
	return value;
}
