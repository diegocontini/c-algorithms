#include <stdio.h>

double *max(double vet[], int len)
{
    double *ptr = vet;
    int i;
    for (i = 0; i < len; i++)
    {
        if (vet[i] > *ptr)
        {
            ptr = &vet[i];
        }
    }
    return ptr;
}


int main()
{

    double vet[5] = {1, 2, 3, 4, 5};
    double *value = max(vet, 5);
    printf("%d", *value);

    printf("ta funcionando");
    return 0;
}