#include <stdio.h>

void inverter(int vet[], int len)
{
    int auxVet[len];
    int i, j;
    for (i = 0; i < len; i++)
    {
        auxVet[i] = vet[i];
    }

    j = len-1;
    for (i = 0; i < len; i++)
    {
        vet[i] = auxVet[j];
        j--;
    }
}

void printVetor(int vet[], int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        printf("%d ", vet[i]);
    }
}

int main()
{
    int vet[4] = {1, 2, 3, 4};
    inverter(vet, 4);
    printVetor(vet, 4);

    return 1;
}