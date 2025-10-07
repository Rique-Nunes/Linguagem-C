/*
A divisão no conjunto de inteiros, produz 2 valores: o quociente e o resto.
No entanto, quando o divisor é zero há duas situações: impossível –
quando apenas o divisor é zero e indeterminada quando o dividendo e o divisor são zeros.
Faça a função divisaoInteira(...) , que recebe  dois valores (o dividendo e  o divisor)
e dois endereços de variáveis, um para armazenar o quociente e outro para o  resto.
Esta função realiza a operação de divisão, se for possível, preenchendo adequadamente o quociente e o resto,
e retorna o valor 1 (sucesso). Caso a operação não possa ser realizada, a função deve retornar 0 ,
quando a divisão é impossível  e -1 quando  é indeterminada.
Utilize sua função adequadamente na main abaixo:
*/
#include <stdio.h>
int DivisaoInteira(int dividendo, int divisor, int *consiente, int *resto);

int main()
{
    int a, b, q, r, st;
    printf("Digite dois valores: ");
    scanf("%d%d", &a, &b);
    if (DivisaoInteira(a, b, &q, &r) == 1)
    {
        printf("%d /%d = %d com resto %d\n", a, b, q, r);
    }
    else
    {
        printf("%d", DivisaoInteira(a, b, &q, &r));
        printf("Erro- divisor eh  0 \n");
    }
    return 0;
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