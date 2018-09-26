#include <stdio.h>
#include <locale.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    const mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    int size;
    int status;
    int source;
    int destination;
    char *buffer;
    struct stat st;
    setlocale(LC_MESSAGES, "de_de.UTF-8");


    if (argc != 3)
    {
        printf("Bitte genau zwei Dateiennamen angeben.\n");
        return -1;
    }
    
    source = open(argv[1], O_RDONLY);
    if (source == -1)
    {
        printf("Quelle %s kann nicht geöffnet werden.\n", argv[1]);
        return 1;
    }
    
    destination = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode);
    if (destination == -1)
    {
        printf("Ziel %s konnte nicht erzeugt werden.\n", argv[2]);
        return 1;
    }
    
    status = fstat(source, &st);
    if (status == -1) 
    {
        printf("error");
        return -1;
    }
    size = st.st_size;
    buffer = (char*) malloc(size);
    read(source, buffer, size);
    write(destination, buffer, size);
    free(buffer);

    return 0;



}

