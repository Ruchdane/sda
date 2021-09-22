#include <sda.h>
struct noeud *creerNoeud(int val)
{
	struct noeud *result  = malloc(sizeof(*result));
	result->value = val;
	result->fils = NULL;
	result->frere = NULL;
	return result;
}
void printChild(struct noeud *noeud)
{
	struct noeud *tmp;
	if(noeud != NULL && noeud->fils != NULL)
		for(tmp = noeud->fils;tmp;tmp = tmp->frere)
			printf(" %d ",tmp->value);
}

void printArbre(struct noeud *noeud)
{
	struct noeud *tmp;
	if(noeud == NULL)
		return;
	if(noeud->fils != NULL)
	{
		printf("%d ",noeud->value);
		printChild(noeud);
		printf("\n");
		for(tmp = noeud->fils;tmp->frere;tmp = tmp->frere)
			printArbre(tmp);
	}

}

struct noeud * ajouterFils(struct noeud *noeud,int val)
{
	struct noeud *tmp;
	if(noeud == NULL)
		return NULL;
	if(noeud->fils == NULL)
	{
		noeud->fils = creerNoeud(val);
		return noeud->fils;
	}
	else
	{
		for(tmp = noeud->fils;tmp->frere;tmp = tmp->frere);
		tmp->frere = creerNoeud(val);
		return tmp->frere;
	}
}
struct noeud * srcArbre(struct noeud *noeud,int val)
{
	struct noeud *tmp,*result = NULL;
	if(noeud == NULL)
		return NULL;
	if(noeud->value == val)
		result = noeud;
	else if(noeud->fils == NULL)
		return NULL;
	else
		for(tmp = noeud->fils;tmp && result == NULL;tmp = tmp->frere)
		{
			result = src(tmp,val);
		}
//	printf("val %d a %x",val,result);
	return result;
			
}
struct noeud *Lire(char *path)
{
	struct noeud *result = NULL,* cur;
	int i,val;
	char *line = NULL;
	size_t len = 0;
	FILE * in = fopen(path,"r+");

	while (getline(&line, &len, in) != -1) 
	{
		val = line[0] - '0';//Le pere
		if(result == NULL)
		{
			result = creerNoeud(val);
			cur = result;
			printf("Creation de %d\n",val);
		}
		else
			cur = src(result,val);
		
        for(i = 1;line[i] != '\n' && line[i] != '\0';i++)
			if(line[i] != ',')
			{
				val = line[i] - '0';
				ajouterFils(cur,val);
				printf("Ajout de %d a %d\n",val,cur->value);
			}
    }
	fclose(in);
	return result;
}

int main(void)
{
	struct noeud *a = Lire("tree");
	printArbre(a);
	return 0;
}