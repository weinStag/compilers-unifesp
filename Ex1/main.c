// Projete um programa que troque as vogais minusculas por maiusculas e as maiusculas por minusculas usando um buffer.
// Com excecao das funcoes para manipulacao de arquivo, I/O e atoi, nenhuma
// outra funcao de bibliotecas padrao deve ser utilizada.
#include "funcs.h";

int main(){
    //verificar se o numero de parametros passados na linha de comando é o correto
    //os parametros sao 1: nome do arquivo 2: tamanho do buffer
    if(argc != 3){
        return 1;
    }
    //abrir o arquivo e verificar se ele foi aberto corretamente
    FILE *file = fopen(argv[1], "r");
    if(file == NULL){
        return 1;
    }
    allocate_buffer(atoi(argv[2]));
    replace_print(file);
    deallocate_buffer();
    fclose(file);
    return 0;
}