//Data: 26/11/18
//All functions used in work stay here
#include <aluno.h>
#include <bibliotecas.h>

/* Functions Prototyping */
ls_alunos* cria_lista_alunos();
void cadastra_aluno(ls_alunos*);
void busca_aluno(ls_alunos*);
void cadastra_com_arquivo(ls_alunos*);
void aprovados(ls_alunos*);
void reprovados(ls_alunos*);
float media_aluno(float, float, float, float);

/* Strucuture of functions */
ls_alunos* cria_lista_alunos()
{
	ls_alunos* lista = (ls_alunos*) malloc(sizeof(ls_alunos));
	lista->cabeca = (no*) malloc(sizeof(no));
	lista->cabeca->ant = NULL;
	lista->cabeça->prox = NULL;
	return lista;
}

void cadastra_aluno(ls_alunos* lista)
{
	aluno* novo_aluno;
	no *novo_no, *p, *q;
	
	/* Create new space in list for student and fills the data field */
	novo_aluno = (aluno*) malloc(sizeof(aluno));
	printf("Insira os dados do aluno(Nome, RA, Nota da P1, da P2, do Trabalho e da PO):\n");
	scanf("%s %u %f %f %f %f", novo_aluno->Nome, &(novo_aluno->RA), &(novo_aluno->P1), &(novo_aluno->P2),
		&(novo_aluno->Trab), &(novo_aluno->PO));
	/* Calculate average of test */
		novo_aluno->media = media_aluno(novo_aluno->P1, novo_aluno->P2, novo_aluno->PO, novo_aluno->Trab);
	/* Create a new nó for new student */
	novo_no = (no*) malloc(sizeof(no));
	novo_no->al = novo_aluno;
     /* Founding end of list */
	p = lista->cabeca;
	q = lista->cabeca->prox;
	while(q != NULL && strcmp(q->al->Nome, novo_aluno->Nome) < 0)
	{
		p = q;
		q = q->prox;
	}
    /* Point novo_no's ant and prox to p and q, and make them point back */
	novo_no->ant = p;
	novo_no->prox = q;
	p->prox = novo_no;
	if(q != NULL)
		q->ant = novo_no;
}

void busca_aluno(ls_alunos* lista)
{
	char nome[SIZE];
	no* p;
	int a = 0;

	printf("Insira o nome do aluno a ser buscado:\n");
	scanf("%s", nome);

	for(p = lista->cabeca->prox; p != NULL; p = p->prox)
	{
		if(strstr(p->al->Nome, nome) != NULL)
		{
			a++;
			if(p->al->situacao == true)
				printf("%s %u %f Aprovado!\n", p->al->Nome, p->al->RA, p->al->media);
			else
				printf("%s %u %f Reprovado!\n", p->al->Nome, p->al->RA, p->al->media);
		}
	}

	printf("%d", a);
}

float media_aluno(float P1, float P2, float PO, float T) 
{
	float media;
	if(PO > P1)
		media = (PO + P2)*0.35 + T*0.3;
	else if(PO > P2)
		media = (P1 + PO)*0.35 + T*0.3;
	else
		media = (P1 + P2)*0.35 + T*0.3;
	
	return media;
}
