/*Loja de automóveis*/
#include "stdio.h"
#include "string.h"
typedef struct
{
    int placa;
    char modelo[20];
    char marca[20];
    char cor[20];
    int quilometragem;
    float valor;
    int ano;
} tcarro;
void exibir_modelo(tcarro carros[], int tamanho, char m[], int a1, int a2, float valor);
void reajustar_valor(tcarro carros[], int tamanho, float p);
void retirar_carro(tcarro carros[], int tamanho, int placa);
void main()
{
    tcarro frota[3] = {
        {.placa = 1234,
         .modelo = "Fusca",
         .marca = "Volkswagen",
         .cor = "Azul",
         .quilometragem = 8500,
         .valor = 1500,
         .ano = 1975},
        {.placa = 5678,
         .modelo = "Onix",
         .marca = "Chevrolet",
         .cor = "Prata",
         .quilometragem = 4200,
         .valor = 5500,
         .ano = 2020},
        {.placa = 9101,
         .modelo = "Corolla",
         .marca = "Toyota",
         .cor = "Preto",
         .quilometragem = 0,
         .valor = 12000,
         .ano = 2023}};

    exibir_modelo(frota, 3, "Corolla", 1000, 2600, 13000);
    reajustar_valor(frota, 3, 10);
    retirar_carro(frota, 3, 9101);
}

void exibir_modelo(tcarro carros[], int tamanho, char m[], int a1, int a2, float valor)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (strcmp(carros[i].modelo, m) == 0 && carros[i].ano > a1 && carros[i].ano < a2 && carros[i].valor < valor)
        {
            printf("placa: %d\n", carros[i].placa);
            pxrintf("modelo: %s\n", carros[i].modelo);
            printf("marca: %s\n", carros[i].marca);
            printf("cor: %s\n", carros[i].cor);
            printf("quilometragem: %d\n", carros[i].quilometragem);
            printf("valor: %f\n", carros[i].valor);
            printf("ano: %d\n", carros[i].ano);
        }
    }
}
void reajustar_valor(tcarro carros[], int tamanho, float p)
{
    int i;
    for (i = 0; i < tamanho; i++)
    {
        if (carros[i].quilometragem == 0)
        {
            printf("%f", carros[i].valor);
            carros[i].valor *= 1 + (p / 100);
            break;
        }
    }
    printf("valores atualizados!");
    printf("%f", carros[i].valor);
}

void retirar_carro(tcarro carros[], int tamanho, int placa)
{
    int i, posicao;
    for (i = 0; i < tamanho; i++)
    {
        if (carros[i].placa == placa)
        {
            posicao = i;
            break;
        }
    }
    for (int j = posicao; j < tamanho - 1; j++)
    {
        carros[j] = carros[j + 1];
    }
    printf("Veiculo retirado!");
}