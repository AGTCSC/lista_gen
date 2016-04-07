#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct regLista
{
	struct listagen* cabeca;
	struct listagen* cauda;
}regLista;

typedef union info_lista
{
	char info[20];
	regLista lista;
}List;

typedef struct listagen
{
	char terminal;
	List no;	
}ListGen, ListaGen;

char isAtomo(ListaGen* l);					//retorna se o elemento em esquesta é atomo(1) ou não(0)
char isEmpty(ListaGen* l);					//retorna se a lista está vazia(1) ou não(0)
ListaGen* CriaT(char* info);				//constroi um atomo
ListaGen* Cons(ListaGen* H, ListaGen* T);	//controi uma lista
ListaGen* getHead(ListaGen* l);				//retorna a cabeça da lista caso exista
ListaGen* getTail(ListaGen* l);				//retorna a cabeça da lista caso exista

char isEmpty(ListaGen* l)
{
	return l == NULL;
}

char isAtomo(ListaGen* l)
{
	return !isEmpty(l) && l->terminal;
}

//cria atomo
ListaGen* CriaAtomo(char info[])
{
	ListaGen* L; //declaro a variavel
	L = (ListaGen*) malloc (sizeof(ListaGen)); //estancio a mesma
	L-> terminal = 1;							//sinalizo que a mesma é um atomo.
	strcpy(L->no.info, info);					//insiro a informação trazida por parametro no mesmo.
	return L;									//retorno-a
}

//cria lista
ListaGen* Cons(ListaGen* H, ListaGen* T)
{
	ListGen* l;
	if(!isAtomo(T))
	{
		l = (ListGen*) malloc (sizeof(ListGen));
		l->no.lista.cabeca = H;
		l->no.lista.cauda = T;
		l->terminal = 0;
	}
	else
	{
		printf("Erro Cons: O segundo argumento nao pode ser Atomo!");
		return NULL;
	}
}

ListaGen *getHead(ListaGen* l)			//retorna a cabeça da lista caso exista
{
	if(!isEmpty(l) && !isAtomo(l))
		return l->no.lista.cabeca;
	else
	{
		printf("Erro getHead: o item não existe ou é atomo!\n");
		return NULL;
	}
}

ListaGen *getTail(ListaGen* l)
{
	if(!isEmpty(l) && !isAtomo(l))
		return l->no.lista.cauda;
	else
	{
		printf("Erro getTail: o item não existe ou é atomo!\n");
		return NULL;
	}		
}

void exibirR(ListaGen* l)
{
	if(!isEmpty(l))
	{
		if(isAtomo(l))
			printf("%s", l->no.info);
		else
		{
			printf("[");
			
			exibirR(getHead(l));
			l = getTail(l);
			if(!isEmpty(l))
				printf(",");
			else
				printf("]");
			exibirR(l);
		}
	}
		else
			printf(",");
}

void Exibe(ListaGen *L)
{
	if(!isEmpty(L))
	{
		if(isAtomo(L))
		printf("%s",L->no.info);
		else
		{
			printf("[");
			while(!isEmpty(L))
			{
				Exibe(getHead(L));
				L = getTail(L);
				if(!isEmpty(L))
					printf(",");
			}
			printf("]");
		}
	}
}
void ExibeAtomos(ListaGen* l)
{
	if(!isEmpty(l))
	{
		if(!isAtomo(l))
		{
			ExibeAtomos(getHead(l));
			ExibeAtomos(getTail(l));
		}
		else
			printf("%s",l->no.info);
	}
}
void Kill(ListaGen** l)
{
	if(isAtomo(*l))
		free(*l);
	else
	{
		Kill(&(*l)->no.lista.cabeca);
		Kill(&(*l)->no.lista.cauda);
		free(*l);
		*l = NULL;
	}
}
listagen* Dup(ListaGen* l)
{
	if(isEmpty(l))
		return NULL;
	if(isAtomo(l))
		return CriaAtomo(l->no.info);
	return Cons(Dup(getHead(l)), Dup(getTail(l)));
}
char isEqual(ListaGen* l1, ListaGen* l2)
{
	if(isEmpty(l1) && isEmpty(l2))
		return 0;
	if(isEmpty(l1) || isEmpty(l2))
		return 0;
	if(isAtomo(l1) && isAtomo(l2))
		return 0;
	if(isAtomo(l1) || isAtomo(l2))
		return 0;

	return isEqual(getHead(l1), getHead(l2)) && isEqual(getTail(l1), getTail(l2));
}

int Len(ListaGen* l)
{
	ListaGen *aux;
	int count = 0, max = 0;
	while(!isEmpty(l))
	{
		aux = l;
		count = 0;
		while(!isEmpty(aux))
		{
			if(!isAtomo(l))
				aux = getTail(aux);
			else
				aux = NULL;
			count++;
		}
		if(count > max)
			max = count;
		if(!isAtomo(l))
			l = getHead(l);
		else
			l = NULL;
	}

	return count;
}

int Deph(ListaGen* l)
{
	ListaGen *aux;
	int count = 0, max = 0;

	while(!isEmpty(l))
	{
		aux = l;
		count = 0;
		while(!isEmpty(aux))
		{
			if(!isAtomo(aux))
				aux = getHead(aux);
			else
				aux = NULL;

			count++;
		}
		if(count > max)
			max = count;

		if(!isAtomo(l))
			l = getTail(l);
		else
			l = NULL;
	}

	return count;
}

void append(ListaGen** l, ListaGen* a)
{
	ListaGen* aux = *l;
	while(!isEmpty(aux->no.lista.cauda))	
		aux = aux->no.lista.cauda;
	aux->no.lista.cauda = a;
}

void replace(ListaGen** l, char a[], char b[])
{
	if(!isEmpty(*l))
	{
		if(isAtomo(*l))
		{
			if(strcmp((*l)->no.info, b) == 0)
				strcpy((*l)->no.info, a);
		}
		else
		{
			replace(&(*l)->no.lista.cabeca, a, b);
			replace(&(*l)->no.lista.cauda, a, b);
		}
	}
}

ListaGen* topLevel(ListaGen* l)
{	
	if(!isEmpty(l))
	{	
		if(isAtomo(l->no.lista.cabeca))
			return Cons(CriaAtomo(l->no.lista.cabeca->no.info), topLevel(getTail(l)));
		return NULL;
	}

}
int main()
{
	ListaGen* l, *ai;
	char a[8] = "A";
	l = Cons(CriaAtomo("X"), Cons(CriaAtomo("Y"), Cons(Cons(CriaAtomo("Z"), NULL), NULL)));
	ai = Cons(Cons(CriaAtomo("L"), NULL), Cons(CriaAtomo("X"), NULL));
	//append(&l, ai);
	//replace(&l, "A", "X");
	Exibe(topLevel(l));
	//Exibe((l));	
	printf("\n");

	getchar();
}
