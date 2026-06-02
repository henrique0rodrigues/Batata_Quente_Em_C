#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>

typedef struct elem
{
    int id;
    bool hand;
    struct elem *link;
}celula;

void exibir_tela(int batata_pos, int modo_jogo) {
    system("cls");
    printf("\n   ====================================================\n");
    printf("                   BATATA QUENTE EM C  !!                \n");
    printf("   ====================================================\n\n");

    // Linha da Batata
    printf("    ");
    for (int i = 0; i <= 50; i++) {
        if (i == batata_pos) {
            printf("O"); // Caractere que representa a Batata
        } else {
            printf(" ");
        }
    }
    printf("\n");

    // Linha dos Jogadores
    printf("    ");
    for (int i = 0; i <= 50; i++) {
        if (i == 5) { 
            printf("(J1)"); 
            i += 3; 
        } else if (i == 25) { 
            printf("(J2)"); 
            i += 3; 
        } else if (i == 45 && modo_jogo == 2) { 
            printf("(J3)"); 
            i += 3; 
        } else {
            printf(" ");
        }
    }
    
    printf("\n\n   ====================================================\n");
    printf("   Pressione ESPACO para passar a batata!\n");
    printf("   ====================================================\n");
}

int main()
{
    celula j1,j2, j3;
    celula *atual = NULL;
    
    int menu, sorteado;

    srand(time(NULL));
    int tempo_aleatorio = (rand() % 4) + 7;
    time_t tempo_inicio;
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
    // Define a posição inicial da batata
    int pos_batata = (atual->id == 1) ? 6 : (atual->id == 2 ? 26 : 46);
    
    exibir_tela(pos_batata, menu);
    printf("\nA batata comecou com o jogador %d! Preparem-se...\n", atual->id);
    system("pause");

    // O tempo começa a contar aqui
    tempo_inicio = time(NULL);

    do
    {
        tempo_atual = time(NULL);

        if (_kbhit()) {
            char tecla = _getch(); 

            if (tecla == ' ') {
                // 1. Passa a batata na lista circular imediatamente
                atual->hand = false;
                atual = atual->link;
                atual->hand = true;

                // 2. Calcula a nova posição da batata com base no novo jogador atual
                pos_batata = (atual->id == 1) ? 6 : (atual->id == 2 ? 26 : 46);
                
                // 3. Atualiza a tela instantaneamente
                exibir_tela(pos_batata, menu);
            }
        }
    } while (difftime(tempo_atual, tempo_inicio) < tempo_aleatorio);
    
    // Garante que a tela final mostre a batata exatamente com quem perdeu
    pos_batata = (atual->id == 1) ? 6 : (atual->id == 2 ? 26 : 46);
    exibir_tela(pos_batata, menu);

    printf("\n FIM DE JOGO!!!!\n");
    printf(" O jogador %d ficou com a batata na mao e PERDEU!!\n\n", atual->id);

    return 0;
}