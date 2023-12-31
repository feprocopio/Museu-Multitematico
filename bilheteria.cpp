include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    int  num, pagamento, quantidade, introducao;
    float preco_total;
    float museu_inteira = 10.0;
    float museu_meia = 5.0;
    char nome[5];
    int museu1;
    FILE * pont_arq;

    printf("\tInforme apenas seu 1° nome: ");
    scanf("\t\n\n%s", nome);
    system("cls");
    printf("\tOlá %s, é uma prazer recebe-lo(a) em nosso Museu!!!\n", nome);


    printf("\t---------------------------------------\n");
    printf("\t SELECIONE O TIPO DE INGRESSO: \n\n");

			
	do
    {
		printf("\t [1]Inteira: 10,00 R$ \n");
        printf("\t [2]Meia: 5,00 R$ \n");
        scanf("%i",&museu1); //variavel forma de pagamento
        
        
        
        if (museu1 == 0)  //se o usuário digitar nenhum dos numeros espepcificados
        {
            museu1 = 3;
        }
        if (museu1 > 2)
        {
            printf("Opção invalida, tente novamente.\n"); // repetição até ele digitar corretamente
        }

    }while(museu1 > 2 );(museu1 < 1);
    		
    printf("\t---------------------------------------\n");


    printf("Quantos ingressos você deseja comprar? ");
    scanf("%d", &quantidade);


    if ( museu1 ==1 ) //se ele escolher ingresso inteira
    {
        float preco_total = quantidade * museu_inteira;
        printf(" Preço total: R$%.2f\n", preco_total);
        pont_arq = fopen("tipoingresso.csv", "a"); // "a" vai adicionar mais conteudo
        // testando para ver se o arquivo foi realmente criado
        if (pont_arq == NULL)
        {
            printf("Erro ao tentar abrir!");
            exit(1);
        }
        else{
            
            // usando printf para armazenar a string no arquivo
            fprintf(pont_arq, "%s comprou %d ingressos(Inteira) \n", &nome, quantidade);

            // usanfo fclose para fechar o arquivo
            fclose(pont_arq);

            printf("\nDados gravados com sucesso\n");
        }     
        
    }

    if ( museu1 ==2 )  //se ele escolher ingresso meia
    {
        float preco_total = quantidade * museu_meia;
        pont_arq = fopen("tipoingresso.csv", "a"); // "a" vai adicionar mais conteudo
        printf(" Preço total: R$%.2f\n", preco_total);
        if (pont_arq == NULL)
        {
            printf("Erro ao tentar abrir!");
            exit(1);
        }
        else{
            
            // usando printf para armazenar a string no arquivo
            fprintf(pont_arq, "%s comprou %d ingressos(Meia) \n", &nome, quantidade);

            // usanfo fclose para fechar o arquivo
            fclose(pont_arq);

            printf("\nDados gravados com sucesso\n");
        }   
    }
    

    for( ; ;)
    {
        printf("\n\n\tQual será a forma de pagamento?\n\t[1] PIX\n\t[2] Dinheiro\n\t[3] Débito\n\t[4] Crédito\n");
        scanf("%d", &pagamento);
        if (pagamento == 1)
        {
            system("cls");

            printf("\tPagamento sendo processado...\n");
            Sleep(3000);
            system("cls");
            printf("\tPagamento aprovado!\n");
            printf("\tGerando seu Token...\n");
            Sleep(1000);
            break;
        }
        if (pagamento == 2)
        {
            system("cls");

            printf("\tPagamento sendo processado...\n");
            Sleep(3000);
            system("cls");
            printf("\tPagamento aprovado!\n");
            printf("\tGerando seu Token...\n");
            Sleep(1000);
            break;
        }

        if (pagamento == 3)
        {
            system("cls");

            printf("\tPagamento sendo processado...\n");
            Sleep(3000);
            system("cls");
            printf("\tPagamento aprovado!\n");
            printf("\tGerando seu Token...\n");
            Sleep(1000);
            break;
        }

        if (pagamento == 4)
        {
            system("cls");

            printf("\tPagamento sendo processado...\n");
            Sleep(3000);
            system("cls");
            printf("\tPagamento aprovado!\n");
            printf("\tGerando seu Token...\n");
            Sleep(1000);
            break;
        }
        else
        {
            printf("\nOpção invalida, tente novamente.\n");
        }
    }


    /* Função srand vai utilizar a leitura do relogio do sistema*/
    srand(time(NULL));
    num = rand() % 100000; /* Função para escolher um numéro aleatória (token)*/
    printf("\n\tSeu token é o N° %d\n", num);

    int verificar;

    printf("\n\n\n\t\t\t\t\t\t\tCarregando...\n");
    Sleep(2000);
    for( ; ; )
    {
        printf("\t\nInforme o seu token: ");
        scanf("%d", &verificar);
        system("cls");
        printf("Validando...");
        Sleep(1500);

        if(verificar != num)
        {
            system("cls");
            Sleep(4000);
            printf("Acesso negado!");
            printf("\n\n\t\t\t\t\t\t\tToken inválido. Tente novamente:     Pedido: N° %d", num);
        }
        else
        {
            printf("\n\t\t\t\t\t\tAcesso autorizado...  ", verificar);
            Sleep(1500);
            printf("\n\t\t\t\t\tSeja bem vindo(a) ao nosso Museu, %s!!!", nome);
            break;
        }
    }

    printf("\n\n\n------------------------------------------------------------------------------\n");

    
    system("pause");
}
