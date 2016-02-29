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
int main()
{
	ListaGen* l = (ListaGen*) malloc(sizeof(ListaGen));
	
	//criando atomo
	l->terminal = 1;
	strcpy(l->no.info, "info");
}
