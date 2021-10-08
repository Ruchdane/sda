#include <sda.h>

struct element * createList(){
	return NULL;
}


struct element *appendElement(struct element *L,struct element* element){
	struct element *tmp;
	if(isListEmpty(L))
		return element;
	forreach(tmp,L);
	tmp->next = element;
	return L;
}

struct element *prependElement(struct element *list,struct element* element){
	if(element){
		element->next = list;
		list = element;
	}
	return list;
	
}

struct element *removeFirst(struct element* L ,struct element** removed){
	struct element* element;
	if(isListEmpty(L)){
		if(removed)
			*removed = NULL;
	}
	else if(removed){
		*removed = L;
		L = L->next;
		(*removed)->next = NULL;
	}
	else{
		element = L;
		L = L->next;
		freeElement(element);
	}
	return L;
}

struct element *removeLast(struct element* L ,struct element** removed){
	struct element* element;
	if(isListEmpty(L) && removed)
		*removed = NULL;

	else if(L->next = NULL){
		if(removed)
			*removed = L;
		else
			freeElement(L);
		L =  NULL;
	}
	
	else forreach(element,L)
		if(element->next->next == NULL){
			if(removed){
				*removed = element->next;
				element->next = NULL;
			}
			else{
				freeElement(element->next);
				element->next = NULL;
			}
		}
	return L;
}

struct element *removeAt(struct element *L,int index,struct element** removed){
	struct element* element,*tmp = NULL;
	int i = 0;
	if(isListEmpty(L) && removed)
		*removed = NULL;
	else if(index == 0)
		L = removeFirst(L,removed);
	else foreach(element,L){
		if(i == index - 1){
			if(element->next != NULL) {
				tmp = element->next->next;
				element->next->next = NULL;
			}
			if(removed)
				*removed = element->next;
			else
				free(freeElement(element->next));
			element->next = tmp;
			break;
		}
		i++;
	}
	return L;
}
struct element *insertElementAt(struct element *L,struct element *elt,int index){
	struct element* element,*tmp = NULL;
	int i = 0;
	if( index == -1 || elt == NULL);
	else if(isListEmpty(L) || index == 0)
		L = elt;
	else foreach(element,L){
		if(i == index - 1){
			elt->next = element->next;
			element->next = elt;
			break;
		}
		i++;
	}
	return L;
}
// struct element *insertAt(struct element *L,void *value,int index,void *suivant){
// 	return insertElementAt(L,createElement(value),index,suivant);
// }