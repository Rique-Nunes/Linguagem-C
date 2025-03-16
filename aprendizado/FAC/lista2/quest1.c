#include "stdio.h"
#include "stdlib.h"
#include "math.h" /*essa parte são bibliotecas, conjunto de códigos para utilizar*/

void main() /*inicializador do código, tudo dentro das {} será executado*/
{
    float peso, altura, imc; /*inicialização das variáveis, float indica números do conjunto dos Reais*/

    printf("Fazendo o calculo do IMC, \nDigite o peso:"); /*tudo dentro dos parenteses será
                                                        imprimido na tela, textos imprimidos tem que ser entre aspas simples ou duplas,
                                                        uma ou outra, nunca as duas (esse \n é quebra de linha)*/

    scanf("%f", &peso); /*comando para scanear o número digitado,
                        "%f" representa o tipo da variável é (float), por exemplo %d é (inteiro),
                       "&" atribui o valor digitado a variavel já criada */

    printf("Digite a altura: "); /*só lembrando que os comandos de palavras chave como printf e scanf tem que terminar com ;*/
    scanf("%f", &altura);

    imc = peso / (altura * altura); /*atribui á variavel imc, o valor da formula*/

    if (imc < 18.5) /*if é o condicional (se), a condição fica entre () e a execução entre {}*/
    {
        printf("Sua condicao e abaixo do esperado"); /*aqui imprime na tela*/
    }
    else if (imc < 25.0) /*else if é o condicional (senão se)*/
    {
        printf("Seu peso e ideal");
    }
    else if (imc < 30.0) /*sim pode ser feito infinitas vezes, porém pode não ser prático*/
    {
        printf("Sua condicao e sobrepeso");
    }
    else if (imc < 35.0)
    {
        printf("Sua condicao e Obesidade grau 1");
    }
    else if (imc < 40.0)
    {
        printf("Sua condicao e Obesidade grau 2");
    }
    else /*esse é o selecionado caso nenhum dos outros seja verdade, em portugues seria algo como (então)*/
    {
        printf("Sua condicao e Obesidade grau 3");
    }
}
