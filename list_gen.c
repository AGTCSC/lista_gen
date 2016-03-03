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
int main()
{
	ListaGen* l = (ListaGen*) malloc(sizeof(ListaGen));
	
	//criando atomo
	l->terminal = 1;
	strcpy(l->no.info, "info");
}
