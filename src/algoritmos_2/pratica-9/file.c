#include <stdio.h>
#include <stdlib.h>
char *findAlphabeticFile(FILE *file)
{
    int charDisplay;
    int arrLenght = 0;
    while (1)
    {
        int tempChar;
        tempChar = fgetc(file);
        if (feof(file))
            break;
        if (tempChar >= 65 && tempChar <= 122)
        {
            arrLenght++;
        }
    }
    rewind(file);
    char *arrChar = (char *)malloc(sizeof(char) * arrLenght);
    int i = 0;
    while (1)
    {

        if (feof(file))
            break;

        charDisplay = fgetc(file);
        if (charDisplay >= 65 && charDisplay <= 122)
        {
            arrChar[i] = (char)charDisplay;            
            i++;
        }
    }
    if (arrLenght == 0)
        return NULL;
    else
        return arrChar;
    fclose(file);
}

