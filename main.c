#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct node
{
    bool hand;
    struct nodo *next;
};

typedef struct node *lista_C;

int main()
{
    srand(time(NULL));
    int menu;
    int tempo_aleatorio = (rand() % 6) + 5;

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
    } while (menu < 1 || menu > 2);

    switch (menu)
    {
    case 1:
        // cria lista circular com duas posições
        break;
    case 2:
        // cria lista circular com três posições
        break;
    }

    while (true)
    {
        do
        {
            tempo_atual = time(NULL);

        } while (difftime(tempo_atual, tempo_inicio) < tempo_aleatorio);
    }
}
