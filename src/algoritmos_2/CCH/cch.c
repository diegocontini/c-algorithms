
/////////////////////////////////////   CODIGO FINAL  //////////////////////////////////////////////////////////////////////////////////////////////////////////



#include <stdio.h>
#include <stdlib.h>
/// Exibe o menu de configuracao, para informar qtde de alunos e notas
int configuracao(int *qtdeAluno, int *qtdeNota)
{
	printf("Informe a quantidade de alunos da turma:\n");
	scanf("%d", qtdeAluno);
	printf("Informe a quantidade de notas de cada aluno:\n");
	scanf("%d", qtdeNota);
}

/// Exibe o menu de configuracao, com as opcoes q podem ser selecionadas
int menuConfiguracao(int *qtdeAluno, int *qtdeNota)
{
	int opcSelecionada;
	printf("--- Menu de configuracao ---\n");
	printf("1 - Configuracao\n");
	printf("\nSelecione uma das opcoes listadas anteriormente para continuar: \n");
	scanf("%d", &opcSelecionada);
	if (opcSelecionada == 1)
	{
		configuracao(qtdeAluno, qtdeNota);
	}
	else
	{
		printf("ATENCAO! Opcao nao encontrada. Tente novamente com um valor valido.\n");
		menuConfiguracao(qtdeAluno, qtdeNota);
	}
}

// Popula o array de alunos com seus respectivos RAs. E também popula a matriz de notas.
void incluirAlunoENota(int qtdAluno, int qtdNotasPorAluno, int vetRAAluno[], float **matrizNotasPorAluno)
{
	int i, j;

	for (i = 0; i < qtdAluno; i++)
	{
		matrizNotasPorAluno[i] = (float *)malloc(qtdNotasPorAluno * sizeof(float)); // Alocando memória para as linhas da matriz
	}
	for (i = 0; i < qtdAluno; i++)
	{
		printf("Informe o RA do %d aluno\n", i + 1);
		scanf("%d", &vetRAAluno[i]);
		for (j = 0; j < qtdNotasPorAluno; j++)
		{
			printf("Digite a nota para o aluno %d, nota %d: ", vetRAAluno[i], j + 1);
			scanf("%f", &matrizNotasPorAluno[i][j]);
		}
	}
}

// Lista todos os alunos e suas respectivas notas.
void listarTodos(int vetAlunoRA[], float **matrizNotasPorAluno, int qtdAluno, int qtdNota)
{
	int i, j;
	for (i = 0; i < qtdAluno; i++)
	{
		printf("\nNotas do aluno do RA: %d\n", vetAlunoRA[i]);
		for (j = 0; j < qtdNota; j++)
		{
			printf("%.2f\n", matrizNotasPorAluno[i][j]);
		}
	}
}

//Lista todos os alunos aprovados com media maior ou igual a 6.
void listarAprovados(int vetAlunoRA[], float **matrizNotasPorAluno, int qtdAluno, int qtdNota) {
///Dá pra se basear na funcao listarTodos. Única diferença é que terá que validar antes de exibir se a média final é igual ou superior ao mínimo. O mínimo é 6.
	int i, j;
	
	printf("Alunos aprovados: \n");
	for (i = 0; i < qtdAluno; i++)
	{
		float soma = 0;
		for(j = 0; 	j < qtdNota; j++)
		{
			soma += matrizNotasPorAluno[i][j];
		}
		
		float media = soma / qtdNota;
		if(media >= 6)
		{
			printf("RA: %d\n", vetAlunoRA[i]);
			printf("Media: %.2f\n", media);
		}
	}
}

//Lista todos os alunos reprovados com media menor que 6.
void listarReprovados(int vetAlunoRA[], float **matrizNotasPorAluno, int qtdAluno, int qtdNota) {
	///Dá pra se basear na funcao listarTodos. Única diferença é que terá que validar antes de exibir se a média final é inferior ao mínimo ou não. O mínimo é 6.
	int i, j;
	
	printf("Alunos reprovados: \n");
	for (i = 0; i < qtdAluno; i++)
	{
		float soma = 0;
		for(j = 0; 	j < qtdNota; j++)
		{
			soma += matrizNotasPorAluno[i][j];
		}
		
		float media = soma / qtdNota;
		if(media < 6)
		{
			printf("RA: %d\n", vetAlunoRA[i]);
			printf("Media: %.2f\n", media);
		}
	}
}
// Remove um aluno com base no RA
void removerAluno(int *qtdAluno, int *vetRA, float **matrizNotasPorAluno, int *qtdNota) {
	int i;
    int raRemover;
    
    printf("Informe o RA do aluno que deseja remover: ");
    scanf("%d", &raRemover);

    int indice = -1;
    for (i = 0; i < *qtdAluno; i++) 
	{
        if (vetRA[i] == raRemover)
		{
            indice = i;
            break;
        }
    }

    if (indice != -1) {
        // Desaloca a memória alocada para as notas do aluno a ser removido
        free(matrizNotasPorAluno[indice]);

        // Remover o aluno do vetor de RAs
        for (i = indice; i < *qtdAluno - 1; i++) 
		{
            vetRA[i] = vetRA[i + 1];
            matrizNotasPorAluno[i] = matrizNotasPorAluno[i + 1];
        }

        // Atualizar a quantidade de alunos
        (*qtdAluno)--;

        printf("Aluno removido com sucesso.\n");
    } else 
	{
        printf("RA não encontrado. Nenhum aluno foi removido.\n");
    }
}

int menuPrograma(int qtdeAluno, int qtdeNotasPorAluno, int vetRA[], float **matrizNotas)
{
	int opcSelecionada, qtdeNota;
	do
	{
		printf("\n--- Menu de configuracao ---\n");
		printf("1 - Adicionar alunos e notas\n");
		printf("2 - Listar todos\n");
		printf("3 - Listar aprovados\n");
		printf("4 - Listar reprovados\n");
		printf("5 - Remover\n");
		printf("6 - Sair\n");
		printf("\nSelecione uma das opcoes listadas anteriormente para continuar: \n");
		scanf("%d", &opcSelecionada);
		switch (opcSelecionada)
		{
		case 1:
			matrizNotas = (float **)malloc(qtdeAluno * sizeof(float *)); // Alocando memoria para as colunas da matriz
			incluirAlunoENota(qtdeAluno, qtdeNotasPorAluno, vetRA, matrizNotas);
			break;
		case 2:
			listarTodos(vetRA, matrizNotas, qtdeAluno, qtdeNotasPorAluno);
			break;
		case 3:
			listarAprovados(vetRA, matrizNotas, qtdeAluno, qtdeNotasPorAluno);
			break;
		case 4:
			listarReprovados(vetRA, matrizNotas, qtdeAluno, qtdeNotasPorAluno);
			break;
		case 5:
		    removerAluno(&qtdeAluno, vetRA, matrizNotas, &qtdeNota);
		    break;		
		default:
			break;
		}
	} while (opcSelecionada != 6);
}


int main()//tst
{
	int opcMenu, qtdeAluno, qtdeNota;
	menuConfiguracao(&qtdeAluno, &qtdeNota);

	int vetAlunoRA[qtdeAluno];
	float **matrizNotasPorAluno = NULL;
	menuPrograma(qtdeAluno, qtdeNota, vetAlunoRA, matrizNotasPorAluno);
}







