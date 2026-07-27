# readpe

Parser de arquivos PE (Portable Executable) escrito em C.

Lê o cabeçalho DOS de um arquivo executável (.exe) e mostra a assinatura
MZ e o offset do cabeçalho PE.


## Uso

```bash
cd lib && make && cd ..
make
LD_LIBRARY_PATH=./lib ./readpe <arquivo.exe>
```
