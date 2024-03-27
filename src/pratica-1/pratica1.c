// Faça um programa que leia um valor inteiro N que representa o tamanho do vetor.
// Em seguida, defina um vetor X tipo float de tamanho N.
//  O programa deve fazer a leitura de N valores float e salvá-los no vetor X.
//  Em seguida,  o programa deve receber da entrada padrão um valor float qualquer.
// Após isso,  o programa deve verificar se o valor informado está no vetor X.
// Caso o valor for encontrado, apresentar na saída padrão "Encontrado na posicao z", onde z é o valor da posição.
//  Caso contrário, apresentar " Valor nao esta armazenado no vetor ".

// 6
// 1.5 3.8 7.4 5.0 1.0 9.9
// 7.4
// encontrado na posicao 2

#include <stdio.h>

int main()
{
    int len;
    scanf("%d", &len);

    float vet[len];
    int i = 0;
    for (i = 0; i < len; i++)
    {
        scanf("%f", &vet[i]);
    }

    float searchValue;
    int indexFinded = -1;
    scanf("%f", &searchValue);
    for (i = 0; i < len; i++)
    {
        if (vet[i] == searchValue && indexFinded == -1)
        {
            indexFinded = i;
        }
    }
    if (indexFinded == -1)
    {
        printf("Valor nao esta armazenado no vetor");
    }
    else
    {
        printf("Encontrado na posicao %d", indexFinded);
    }
    return 1;
}