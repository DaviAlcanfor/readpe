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
    // DOS header signature
    // 2 primeiros bytes = MZ
    return (b[0] == 'M' && b[1] == 'Z');
        
    // obs: 'M' =  0x4d, 'Z' = 0x5a
}

int main(int argc, char *argv[]) {
    FILE *fh;
    unsigned char buffer[32]; // buffer p leitura do arquivo


    // file eh o argumento, so pode ter ele
    // ou seja, tem q ser 2 apenas
    if (argc != 2) {
        usage();
    }

    fh = fopen(argv[1], "rb"); // path (arg), mode

    if (fh == NULL){ 
        fatal("Arquivo nao encontrado!");
    }

    if (fread(buffer, 32, 1, fh) != 1) // ptr, len, elem, file
        fatal("Nao consegui ler os 32 bytes do arquivo!");
    
    fclose(fh);

    if (!petest_ispe(buffer))
        fatal("Arquivo nao parece ser um executavel PE!");
        

    // TODO terminar o resto

    return 0;
}
