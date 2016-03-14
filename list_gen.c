struct reg_lista
{
	struct listagen* cabeca;
	struct listagen* cauda;	
};

union info_lista
{
	char info[8];
	struct reg_lista lista;	
};

typedef struct listagen
{
	char terminal;
	union info_lista no;	
}ListaGen;

/*
	O campo etiqueta, chamado terminal, é uma variável que pode assumir
	o valor de verdadeiro ou falso. Se falso, o registro é do tipo não
	terminal, possuindo os campos cabeça e cauda. Caso contrário, o regristro
	é do tipo terminal e possui apenas o campo info. Em termos de alocação de
	memória, quantidade de bytes, o compilador se baseia sempre no maior campo
	(maior quantidade de bytes).
*/
ListaGen * Head(ListaGen * l)
{
	if(Nula(l)) || Atomo(l))
	{
		printf("Head: Nao pode ser NUla ou Atomo!");
		return NULL;
	}
	else
		return l->no.lista.cobeca;
}

ListaGen * Head(ListaGen * l)
{
	if(Nula(l)) || Atomo(l))
	{
		printf("Head: Nao pode ser NUla ou Atomo!");
		return NULL;
	}
	else
		return l->no.lista.cabeca;
}

ListaGen * Tail(ListaGen * l)
{
	if(Nula(l)) || Atomo(l))
	{
		printf("Tail: Nao pode ser Nula ou Atomo!");
		return NULL;
	}
	else
		return l->no.lista.cauda;
}
/*
--> Algoritmo para destruir uma lista generalizada (libera todos os nodos de uma lista).
	Três casos a considerar:
	>>> L tem um vaor nulo, representando uma lista vazia.
	>>> L aponta um nodo terminal representando um átomo
	>>> L aponta um nodo não-terminal, representando uma lista generalizada.
*/
void Kill(ListaGen** l)
{
	if(!Nula(*l))					
	{						
		if(Atomo(l))				
			free((*l));
		else					
		{
			Kill(&(*l)->no.lista.cabeca);
			Kill(&(*l)->no.lista.cauda);
			free(*l);
			*l = NULL;		
		}
	}

}

ListaGen* duplica(ListaGen** l)
{
	if(Nula(l)) //é nula?
		return NULL;
	if(Atomo(l))//é atomo?
		return CriaT(l->no.info) //se for crie um
	return Cons(Dup(Head(l)), Dup(Tail(l))); //se não foi nenhuma das outras é lista
						//com a chamada das fonções nessa ordem andamos da forma em q descemos verticalmente
						//retornamos e andamos horizontalmente.
}
char compara(ListaGen* l1, ListaGen* l2)
{
	if(Nula(l1) && Nula(l2))
		return 1;
	if(Nula(l1) || Nula(l2))
	if(Atomo(l1) && Atomo(l2))
		return !strcmp(l1->no.info, l2->no.info);
	if(Atomo(l1) || Atomo(l2))
		return 0;
	return compara(Head(l1), head(l2)) && compara(Tail(l1), Tail(l2));
	
	
}
void exibeR (ListaGen* l)				//Nesse algoritmo encarregamos a parte recursiva da função para descer na lista
{							//já a parte interativa faz o papel de andar horizontalmente na mesma.
	if(!Nula(L))					
	{						
		if(Atomo(l))				
			printf("%s", l->no.info);	
		else					
		{					
			printf("[");			
			while(!Nula(l))			
			{				
				exibe(Head(l));		
				l = tail(l);		
				if(!Nula(l))		
					printf(",");	
			}				
			printf("]");			
		}					
	}						
}							
void exibeAtomo(ListaGen *l)
{
	if(!Nula(l))
	{
		if(Atomo(l))
			printf("%s", l->no.info);
		else
		{
			exibeAtomo(Head(l));
			exibeAtomo(Tail(l));
		}
	}
}
void percorreI (ListaGen *l)
{
	Pilha *P;
	init(&p);
	push(&p, l);
	
	while(!isEmpity(p))
	{
		if(!Nula(l))
		{
			push(&p, l);
			l = Head(l);
			while(!Nula(l) && !Atomo(l))
			{
				push(&p, l);
				l = Head(l);
			}
			if(Atomo(l))
				printf("%s", l->no.info);
		}
		pop(&p, &l);
		l = Tail(l);
		if(!Nula(l))
			push(&p, l);
	}
	
}
int main()
{
	ListaGen* l = (ListaGen*) malloc(sizeof(ListaGen));
	
	//criando atomo
	l->terminal = 1;
	strcpy(l->no.info, "info");
}
