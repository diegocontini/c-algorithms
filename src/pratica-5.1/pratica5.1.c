#include <stdio.h>
#include <string.h>

char *acharVogal(char v, char *vetor)
{
    int i;
    for (i = 0; i < strlen(vetor); i++)
    {
        if (v == vetor[i])
            return &vetor[i];
    }
    return NULL;
}

int main()
{
    char frase[50];
    char vogal;

    scanf("%[^\n]s", frase);
    scanf(" %c", &vogal);

    // adicione sua resposta abaixo deste comentário.
    char *vogalEncontrada = acharVogal(vogal, frase);
    if (vogalEncontrada != NULL)
    {
        printf("Encontrou a vogal: %c", *vogalEncontrada);
    }
    else
    {
        printf("Vogal nao encontrada.");
    }
    return 0;
}





