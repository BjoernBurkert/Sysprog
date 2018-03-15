#include <stdio.h>
#include <locale.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int i;
    unsigned int size;
    setlocale(LC_ALL, "de_DE");
    
    for (i = 0; i < argc; ++i)
    {
	struct stat st;
        fp = fopen(argv[i],"r");
        if (fp == NULL)
        {
            perror(argv[i]);
            continue;
        }
        
        if (stat(argv[i], &st) == 0)
	{
	    size = st.st_size;
	}
        printf("Die Datei \"%s\" ist %d Byte groß.\n", argv[i], size);
    }
        return 0;
    }
