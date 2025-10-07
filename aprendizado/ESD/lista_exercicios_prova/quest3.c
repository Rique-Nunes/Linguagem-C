/*Construa o programa a seguir.
Faça  a  função horario que receba um parâmetro (inteiro por valor) com o total de minutos de um evento e receba também dois parâmetros
(inteiros por referência) no qual deve preencher a quantidade de hora e de minutos equivalente.
Por exemplo: 145 minutos equivale a 2 h e 25 min. Esta função deverá OBRIGATORIAMENTE  chamar a função  DivisaoInteira
Faça um programa que leia  o tempo de treino (em minutos)  de 10 atletas, mostrando a cada um,  o tempo de treino no formato hh:mm.
(utilize a função do item a).No final deve ser exibido o maior tempo de treino e quantos atletas o fizeram
*/

#include <stdio.h>
int DivisaoInteira(int dividendo, int divisor, int *consiente, int *resto);
int horario(int tempo, int *hora, int *minuto);

typedef struct
{
    char nome[30];
    int hora;
    int minutos;
} tatleta;

int main()
{
    tatleta vetor[30];
    int escolha = 1, i = 0, tempo, maior_tempo = -1, posicao_maior;
    while (escolha != 0)
    {
        printf("digite 1 para cadastrar, 2 para o maior tempo de treino, 0 para sair");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case 1:
            printf("digite o nome do atleta: ");
            scanf("%s", vetor[i].nome);
            printf("digite o tempo do atleta: ");
            scanf("%d", &tempo);
            horario(tempo, &vetor[i].hora, &vetor[i].minutos);
            if (tempo > maior_tempo)
            {
                posicao_maior = i;
                maior_tempo = tempo;
            }
            i++;

            break;
        case 2:
            // CORREÇÃO: Lógica para encontrar e exibir o maior tempo e os atletas
            int maior_h, maior_m;
            int contador_maior = 0;
            horario(maior_tempo, &maior_h, &maior_m); // Converte o maior tempo para hh:mm

            printf("\nO maior tempo de treino foi: %02dh:%02dm\n", maior_h, maior_m);
            printf("Atletas que atingiram este tempo:\n");

            // Loop corrigido para encontrar todos os atletas com o maior tempo
            for (int j = 0; j < i; j++)
            {
                // Calcula o tempo total em minutos para cada atleta para comparar
                int tempo_atleta_atual = (vetor[j].hora * 60) + vetor[j].minutos;
                if (tempo_atleta_atual == maior_tempo)
                {
                    printf(" - %s\n", vetor[j].nome);
                    contador_maior++;
                }
            }
            printf("Total de atletas com o maior tempo: %d\n", contador_maior);
            break;
        }
    }
    return 1;
}

int DivisaoInteira(int dividendo, int divisor, int *consiente, int *resto)
{
    if (dividendo == 0 || divisor == 0)
    {
        return -1;
    }
    else if (divisor == 0)
    {
        return 0;
    }

    *consiente = dividendo / divisor;
    *resto = dividendo % divisor;
    return 1;
}

int horario(int tempo, int *hora, int *minuto)
{
    int hora_total, minutos_totais, teste;
    teste = DivisaoInteira(tempo, 60, &hora_total, &minutos_totais);
    *hora = hora_total;
    *minuto = minutos_totais;
    return teste;
}