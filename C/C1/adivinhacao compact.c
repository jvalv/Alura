#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


int main (){
	printf("***********************\n");
	printf("**jogo de adivinhacao**\n");
	printf("***********************\n");


	 int seconds = time(0);// time 0 é 1 de janeiro de 1970 
	 srand(seconds);//passa valor para rand()
	 int randow = rand();//gera numeros randomicos
	 int numsecret = randow % 100;
	 int kick;
	 int tentativa = 1;
	 double points = 1000;
	 double lostpoints;
	 int correct = 0;
	 int maior = 0;

	 int level;
	 printf("Escolha uma dificuldade: (1) FACIL, (2) MEDIO e (3) DIFICIL \n");
	 scanf("%d",& level);
	 int NUM_TRY;

	 switch(level){ 
	 	case 1:
	 		NUM_TRY = 12;
	 		system("cls");
	 		printf("Voce possui 12 tentativas\n");
	 		break;
	 	case 2:
	 		NUM_TRY = 9;
	 		system("cls");
	 		printf("Voce possui 9 tentativas\n");
	 		break;
	 	default: //else
	 		NUM_TRY = 6;
	 		system("cls");
	 		printf("Voce possui 6 tentativas\n");
	 		break;
	 	}


	 for (int i = 0; i < NUM_TRY; ++i){
	 		printf("tentativa %d\n\n",tentativa);

		 	printf("Qual seu chute: ");
		 	scanf("%d", &kick);

		 	if (kick < 0){
		 		printf("Nao é permitido numero negativo tente denovo!\n\n");
		 		//i--;
		 		continue; // faz o for executar o resto do bloco mas n encerra sua execuçao
		 	}

		 	correct = (kick == numsecret);
		 	maior = (kick > numsecret);
		 
		 	if(correct){
		 	break;	
			}

		 	else if (maior){
	     	printf("Chute maior que o numero secreto\n\n");
	     	}
	     	else{
	        		printf("Chute menor que o numero secreto\n\n");
	     	}
	     	
	     	tentativa++; 
			lostpoints = abs(kick - numsecret) / (double)2; //casting
			// o uso  do abs serve para converter o resultado em positivo, numero absoluto.
			
			points = points - lostpoints;
		}
		if(correct){
			system("cls");
			printf("***END GAME***\n");
			printf("YOU WIN!\n");
			printf("Voce acertou com %d tentativas\n", tentativa);
			printf("Sua pontuacao foi %0.2f pontos de 1000\n",points );
			}	
			else{
				system("cls");
				printf("***END GAME***\n");
	     		printf("YOU LOSE, TRY AGAIN :D\n");
	     	}
}
