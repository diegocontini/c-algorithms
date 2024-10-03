FILE *file;
    file = fopen("teste.txt", "r");
    char *f = findAlphabeticFile(file);
    printf("%s", f);
    free(file);