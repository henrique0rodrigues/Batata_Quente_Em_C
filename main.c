#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>

typedef struct elem
{
    int id;
    bool hand;
    struct elem *link;
}celula;


int main()
{
    celula j1,j2, j3;
    celula *atual = NULL;
    
    int menu, sorteado;

    srand(time(NULL));
    int tempo_aleatorio = (rand() % 6) + 6;
    time_t tempo_inicio = time(NULL);
    time_t tempo_atual;

    do
    {
        printf("--- SEJA BEM VINDO AO BATATA QUENTE ---\n");
        printf("\n--- Menu ---\n");
        printf("Digite 1 para partida com dois jogadores\n");
        printf("Digite 2 para partida com tres jogadores\n");
        printf("Escolha: ");
        scanf("%d", &menu);
        system("cls");
    } while (menu < 1 || menu > 2);

    j1.id = 1; j2.id = 2; j3.id = 3;
    j1.hand = false; j2.hand = false; j3.hand = false;

    switch (menu){
        case 1:
            j1.link = &j2;
            j2.link = &j1;
            
            sorteado = rand() % 2;
            if(sorteado == 0){
                j1.hand = true;
                atual = &j1;
            } else{
                j2.hand = true;
                atual = &j2;
            }   
            break;
        case 2:

            j1.link = &j2;
            j2.link = &j3;
            j3.link = &j1;

            sorteado = rand() % 3;
            if(sorteado == 0){
                j1.hand = true;
                atual = &j1;
            } else if (sorteado == 1){
                j2.hand = true;
                atual = &j2;
            } else{
                j3.hand = true;
                atual = &j3;
            }
            break;
    }
    printf("\n--- O JOGO COMECOU!! ---\n");
    printf("A batata esta como jogador %d!\n", atual->id);
    printf("Para passar a batata pressione ESPACO  o quanto antes!!!\n");

        do
        {
            tempo_atual = time(NULL);

            if (_kbhit()) {
            // Lê a tecla pressionada sem precisar apertar Enter
            char tecla = _getch(); 

            // Verifica se a tecla pressionada foi o espaço
            if (tecla == ' ') {
                atual->hand = false;
                atual = atual->link;
                atual->hand = true;
                
                printf("A batata foi passada!! Agora esta com o jogador %d\n", atual->id);
            }
        }
        } while (difftime(tempo_atual, tempo_inicio) < tempo_aleatorio);
    
    printf("\n FIM DE JOGO! O tempo acabou!!\n");
    printf("O jogador %d estava com a batata na mao e perdeu!!\n", atual->id);

    return 0;
}