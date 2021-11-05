#include<string.h>
#include<string.h>
#include<locale.h>
#include <iostream>

void init ();

class Bank {
	public:
		float saldo;
		
		Bank (float saldo) {
			this->saldo = saldo;
		}
		
		void depositar (float valor) {
			this->saldo = this->saldo + valor;
		}
		
		void sacar (float valor) {
			this->saldo = this->saldo - valor;
		}
		
};

main (void) {
	
	setlocale(LC_ALL, "Portuguese");
	
	init();
	
}

void init () {
	
	float saldoDisponivel = 2500;
	Bank *bank = new Bank(saldoDisponivel);
	
	int operacao = -1;
	
	do{
		
		printf("====================================\n");
		printf("Escolha a operação bancária\n");
		printf("0 - saldo\n");
		printf("1 - depositar\n");
		printf("2 - sacar\n");
		printf("3 - sair\n");
		printf("====================================\n");
		scanf("%d", &operacao);
		
		float dep = 0;
		float saq = 0;
		
		switch(operacao){
			case 0:
				printf("Seu saldo é: R$ %f\n", bank->saldo);
				break;
			case 1:
				printf("Quanto você quer depositar?\n");
				scanf("%f", &dep);
				bank->depositar(dep);
				printf("Valor depositado com sucesso!\n");
				break;
			case 2:
				printf("Quanto você quer sacar?\n");
				scanf("%f", &saq);
				if(saq <= bank->saldo){
					bank->sacar(saq);
					printf("Valor sacado com sucesso!\n");	
				}else{
					printf("Saldo insuficiente!\n");	
				}
				break;
			case 3:
				printf("====================================\n");
				printf("Até logo!\n");
				printf("====================================\n");
				system("cls");
				break;
		}
		
	}while(operacao != 3);
	
}
