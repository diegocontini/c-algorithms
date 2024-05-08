#include <stdio.h>
#include <string.h>

typedef struct endereco
{
    char rua[50];
    char cidade[50];
    char estado[50];
    int numero;
} endereco;

typedef struct cliente
{
    int id;
    char nome[50];
    char telefone[20];
    endereco ender;
} cliente;

void ler_cliente(cliente vetCliente[], int len)
{
    int i = 0;

    for (i = 0; i < len; i++)
    {
        cliente tempCli;
        endereco tempEnd;

        scanf(" %d", &tempCli.id);

        scanf(" %[^\n]", tempCli.nome);

        scanf(" %[^\n]", tempEnd.rua);
        scanf(" %[^\n]", tempEnd.estado);
        scanf(" %[^\n]", tempEnd.cidade);

        scanf(" %d", &tempEnd.numero);

        scanf(" %[^\n]", tempCli.telefone);

        tempCli.ender = tempEnd;

        vetCliente[i] = tempCli;
    }
}

void buscar_cliente(cliente vetCliente[], int len)
{
    int i = 0;
    for (i = 0; i < len; i++)
    {
        int idFilter;

        scanf("%d", &idFilter);
        for (i = 0; i < len; i++)
        {
            if (vetCliente[i].id == idFilter)
            {

                printf("%d - %s\n", vetCliente[i].id, vetCliente[i].nome);
                printf("%s, %d\n", vetCliente[i].ender.rua, vetCliente[i].ender.numero);
                printf("%s - %s\n", vetCliente[i].ender.cidade, vetCliente[i].ender.estado);
                printf("Tel: %s",  vetCliente[i].telefone);
            }
        }
    }
}

int main()
{
    cliente vet[2];
    ler_cliente(vet, 2);
    buscar_cliente(vet, 2);
}
