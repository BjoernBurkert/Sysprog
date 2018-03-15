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
    
    localecheck = setlocale(LC_MESSAGES, "de_de.UTF-8");
    if (localecheck == NULL)
    {
        printf("Die Plattform unterstützt die deutschen Systemmeldungen nicht."\n);
    }
    if (argc != 3)
    {
        printf("Bitte genau zwei Dateiennamen angeben.\n");
        return -1;
    }
    
    errno = 0;
    
    source = open(argv[1], O_RDONLY);
    if (source == -1)
    {   
        fprintf(stderr,
            "Quelle %s kann nicht geöffnet werden (errn %d: %s)\n",
            argv[1], errno. strerror(errno));
        return 1;
    }
    
    destination = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, mode);
    if (destination == -1)
    {   
        fprintf(stderr,
            "Ziel %s konnte nicht erzeugt werden (errno %d: %s)\n,
            argv[2], errno. strerror(errno));
        return 1;
    }
    
    status = fstat(source, &st);
    if (status == -1) 
    {   
        fprintf(stderr,
            "Der fstat-Aufruf ist fehlgeschlagen (errno %d: %s)\n",
                errno, strerror(errno));
        return -1;
    }
    size = st.st_size;
    buffer = (char*) malloc(size);
    read(source, buffer, size);
    write(destination, buffer, size);
    free(buffer);

    return 0;



}

