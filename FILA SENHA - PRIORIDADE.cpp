#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

typedef struct TipoSenha{
	int senha;
	bool prioridade;
}TSenha;

typedef struct TipoFila{
	TSenha fila[300];
	int tamanho;
	int psenha;
	int csenha;
}TFila;

void Inicializar(TFila *p){
	p->tamanho = 0;
	p->psenha = 1;
	p->csenha = 1;
}

int Menu(){																				//Imprimir Menu Principal na Tela
	system("cls");
	int x;
	
	printf("\n\t""1 - SENHA NORMAL");
	printf("\n\t""2 - SENHA PREFERENCIAL");
	printf("\n\t""3 - CHAMAR PROXIMO DA FILA");
	printf("\n\t""4 - MOSTRAR FILA");
	printf("\n\t""0 - SAIR");
	printf("\n\n""OPCAO: ");
	scanf("%d", &x);
	
	return x;
}

void SenhaNormal(TFila *p){
	system("cls");
	
	if(p->tamanho == 0){
		p->fila[0].senha = p->csenha;
		p->fila[0].prioridade = false;
		printf("Senha %d comum gerada. Aguarde ser chamado.", p->csenha);
	} else{
		p->fila[p->tamanho].senha = p->csenha;
		p->fila[p->tamanho].prioridade = false;
		
		printf("Senha %d comum gerada. Aguarde ser chamado.", p->csenha);
	}
	
	p->csenha++;
	p->tamanho++;
	printf("\n\n""Pressione qualquer tecla para voltar ao menu.");
	getch();
}

void SenhaPreferencial(TFila *p){
	system("cls");
	int x;
	
	if(p->tamanho == 0){
		p->fila[0].senha = p->psenha;
		p->fila[0].prioridade = true;
		printf("Senha %d preferencial gerada. Aguarde ser chamado.", p->psenha);
	} else{
		for(x = 0; x < p->tamanho; x++){
			if(!p->fila[x].prioridade){
				for(int y = p->tamanho; y > x; y--){
					p->fila[y] = p->fila[y-1];
				}
				p->fila[x].senha = p->psenha;
				p->fila[x].prioridade = true;
				printf("Senha %d preferencial gerada. Aguarde ser chamado.", p->psenha);
				break;
			}
		}
	}
	
	p->psenha++;
	p->tamanho++;
	printf("\n\n""Pressione qualquer tecla para voltar ao menu.");
	getch();
}

void ChamarProximoFila(TFila *p){
	system("cls");
	
	if(p->tamanho > 0){
		if(p->fila[0].prioridade){
			printf("\t""+---------------------------------------+""\n");
			printf("\t""|                                       |""\n");
			printf("\t""|   Chamando senha PREFERENCIAL -> %d\t|""\n", p->fila[0].senha);
			printf("\t""|                                       |""\n");
			printf("\t""+---------------------------------------+""\n");
		}			
		else{
			printf("\t""+---------------------------------------+""\n");
			printf("\t""|                                       |""\n");
			printf("\t""|      Chamando senha COMUM -> %d\t|""\n", p->fila[0].senha);
			printf("\t""|                                       |""\n");
			printf("\t""+---------------------------------------+""\n");
		}			
		Beep(500,800);
		Beep(400,800);
		printf("\n""Aguarde...");
		Sleep(2000);
			
		
		int y = p->fila[0].senha;
		for(int x = 0; x < p->tamanho-1; x++){
			p->fila[x] = p->fila[x+1];
		}
		p->tamanho--;
		printf("\n\n""Senha ( %d ) em atendimento", y);
		
	}else{
		Beep(1000,500);
		printf("Nao ha clientes na fila.");
	}
	
	printf("\n\nPressione qualquer tecla para voltar ao menu.");
	getch();
}

void Apresentar(TFila *p){
	system("cls");
	
	if(p->tamanho > 0){
		printf("Fila de Senhas:\n");
		if(p->tamanho > 0){
			for(int x = 0; x < p->tamanho; x++){
				printf("\n""%d""\t| ", p->fila[x].senha);
				
				if(p->fila[x].prioridade)
					printf("Preferencial");
				else
					printf("Comum");				
			}
		}
	}else{
		Beep(1000,500);
		printf("Nao ha senhas ativas em espera.");
	}
	
	printf("\n\n""Pressione qualquer tecla para voltar ao menu.");
	getch();
}

int main(){
	TFila fila;
	
	Inicializar(&fila);
	
	int opc;
	do{																					//Verificar vontade do usuário
		switch(Menu()){																	//Chamar função de acordo com a opção escolhida
			case 1: SenhaNormal(&fila); opc = 1; break;
			
			case 2: SenhaPreferencial(&fila); opc = 2; break;
			
			case 3: ChamarProximoFila(&fila); opc = 3; break;
			
			case 4: Apresentar(&fila); opc = 4; break;
			
			case 0: opc = 0; break;
			
			default: opc = 5; break;
		}
	}while(opc != 0);
	
}
