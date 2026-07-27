#include <stdio.h>
#include <stdlib.h>
#include "lib/petest.h"

void fatal(char *msg){
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void usage(void){
    printf("Uso: \n readpe <arquivo.exe>\n");
    exit(1);
}

bool ispe(const unsigned char *b){
    return (b[0] == 'M' && b[1] == 'Z');
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage();
    }
    
    PEFILE pe;
    /* typedef struct {
     *   char *filepath;
     *   IMAGE_DOS_HEADER *hdr_dos;
     * } PEFILE; */


    pe.filepath = argv[1];
    puts(pe.filepath);
    
    petest_init(&pe);
    if (petest_ispe(&pe))
        printf("Eh um PE! Continuando...\n");
    else
        fatal("Nao eh um PE! Saindo...\n");

    printf("File: %s\n", pe.filepath);
    printf("MZ header: %x\n", pe.hdr_dos->e_magic);
    printf("COFF header offset: %x\n", pe.hdr_dos->e_lfanew);

    petest_deinit(&pe);

    return 0;
}
