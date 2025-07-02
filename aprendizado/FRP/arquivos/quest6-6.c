#include <stdio.h>
int uniao(char arquivo_a[], char arquivo_b[], char arquivo_c[]);

void main()
{
    printf("%d", uniao("teste.txt", "ordenado.txt", "final.txt"));
}

int uniao(char arquivo_a[], char arquivo_b[], char arquivo_c[])
{
    FILE *arqa, *arqb, *arqc;
    int fimA = 0, fimB = 0, valora, valorb;

    arqa = fopen(arquivo_a, "r");
    arqb = fopen(arquivo_b, "r");
    arqc = fopen(arquivo_c, "w");

    if (!arqa || !arqb || !arqc)
    {
        fclose(arqa);
        fclose(arqb);
        fclose(arqc);
        return 0;
    }

    if (fscanf(arqa, "%d", &valora) == EOF)
    {
        fimA = 1;
    }
    if (fscanf(arqb, "%d", &valorb) == EOF)
    {
        fimB = 1;
    }

    while (!fimA && !fimB)
    {
        if (valora < valorb)
        {
            fprintf(arqc, "%d\n", valora);
            if (fscanf(arqa, "%d", &valora) == EOF)
            {
                fimA = 1;
            }
        }
        else
        {
            if (valorb < valora)
            {
                fprintf(arqc, "%d\n", valorb);
                if (fscanf(arqb, "%d", &valorb) == EOF)
                {
                    fimB = 1;
                }
            }
            else
            {
                fprintf(arqc, "%d\n", valora);
                if (fscanf(arqa, "%d", &valora) == EOF)
                {
                    fimA = 1;
                }
                if (fscanf(arqb, "%d", &valorb) == EOF)
                {
                    fimB = 1;
                }
            }
        }
    }
    if (fimA)
    {
        fprintf(arqc, "%d\n", valorb);

        while (fscanf(arqb, "%d", &valorb) != EOF)
        {
            fprintf(arqc, "%d\n", valorb);
        }
    }
    if (fimB)
    {
        fprintf(arqc, "%d\n", valora);

        while (fscanf(arqb, "%d", &valora) != EOF)
        {
            fprintf(arqc, "%d\n", valora);
        }
    }

    fclose(arqa);
    fclose(arqb);
    fclose(arqc);

    return 1;
}