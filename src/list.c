#include <sda.h>

struct element * createList(){
	return NULL;
}

bool isListEmpty(struct element *L){
	return toBool(L == NULL);
}

struct element *append(struct element *L,void *value){
	struct element *tmp;
	if(isListEmpty(L))
		return createElement(value);
	forreach(tmp,L);
	tmp->next = createElement(value);
	return L;
}

struct element *prepend(struct element *list,void *value){
	struct element *tmp = createElement(value);
	tmp->next = list;
	return tmp;
}

struct element *removeFirst(struct element* L ,struct element** removed){
	struct element* element;
	if(isListEmpty(L)){
		*removed = NULL;
	}
	else if(removed){
		*removed = L;
		L = L->next;
		(*removed)->next = NULL;
		return L;
	}
	else{
		element = L;
		L = L->next;
		free(freeElement(element));
	}
	return L;
}

struct element *removeLast(struct element* L ,struct element** removed){
	struct element* element;
	if(isListEmpty(L))
		*removed = NULL;

	else if(L->next = NULL){
		if(removed){
			*removed = L;
			return NULL;
		}
		free(freeElement(L));
		L =  NULL;
	}
	
	else forreach(element,L)
		if(element->next->next == NULL){
			if(removed){
				removed = element->next;
				element->next = NULL;
			}
			else{
				free(freeElement(element->next));
				element->next = NULL;
			}
		}

	return L;
}

struct element *removeAt(struct element *L,int index,struct element** removed){
	struct element* element;
	if(isListEmpty(L))
		*removed = NULL;
	else if(index == 0)
		L = removeFirst(L,removed);
	else if(L->next = NULL){
		if(removed){
			*removed = L;
			return NULL;
		}
		free(freeElement(L));
		L =  NULL;
	}
	
	else forreach(element,L)
		if(element->next->next == NULL){
			if(removed){
				removed = element->next;
				element->next = NULL;
			}
			else{
				free(freeElement(element->next));
				element->next = NULL;
			}
		}

	return L;
}