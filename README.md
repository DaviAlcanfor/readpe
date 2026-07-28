# readpe
Parser de arquivos PE (Portable Executable) escrito em C.
Lê o cabeçalho DOS de um arquivo executável (.exe) e mostra a assinatura
MZ e o offset do cabeçalho PE.

## Uso
```bash
./setup.sh
./run.sh <arquivo.exe>
```

## TODO
- [ ] Coletar `e_lfanew` do DOS header
- [ ] Parsear o PE header (NT Headers)
- [ ] Coletar informações das seções (`.text`, `.data`, etc.)
