
    #include <stdio.h>
    int main()
    {
        int matriz[3][3];
        int matriz2[3][3];
        int i;
        int j;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                scanf("%d", &matriz[i][j]);
            }
        }
        i = 0;
        j = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {

                matriz2[i][j] = matriz[j][i];
            }
        }

        i = 0;
        j = 0;

        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("%d ", matriz2[i][j]);
            }

            printf("\n");
        }
    }