#include <stdio.h>
int main()
{
    char frase1[50];
    char frase2[50];

    fgets(frase1, 50, stdin);
    fgets(frase2, 50, stdin);
    int isDiferente = 0;
    int i = 0;
    while (!frase1[i] == '\0')
    {

        if (frase1[i] >= 97 && frase1[i] <= 122)
        {
            frase1[i] = frase1[i] - 32;
        }
        if (frase2[i] >= 97 && frase2[i] <= 122)
        {
            frase2[i] = frase2[i] - 32;
        }

        if (frase1[i] != frase2[i])
        {
            isDiferente = 1;
        }

        i++;
    }
    
    
    
    if (isDiferente == 1)
    {
        printf("As frases sao diferentes");
    }
    else
    {
        printf("As frases sao iguais");
    }
    return 1;
}