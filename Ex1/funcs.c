#include "funcs.h";

void allocate_buffer(int size){
    //allocate memory for the buffer
    buffer *b = (buffer*)malloc(sizeof(buffer));
    b->size = size;
    b->buffer = (char*)malloc(size*sizeof(char));
}

void deallocate_buffer(){
    free(b->buffer);
    free(b);
}

void replace_print(FILE *file){
    //load the buffer with the file content in chunks of the buffer size
    while(fread(b->buffer, b->size, 1, file)){
        //chage the characters case in the buffer
        for(int i = 0; i < b->size; i++){
            if(b->buffer[i] >= 'a' && b->buffer[i] <= 'z'){
                b->buffer[i] -= 32;
            } else if(b->buffer[i] >= 'A' && b->buffer[i] <= 'Z'){
                b->buffer[i] += 32;
            }
        }
        printf("%s", b->buffer);
    }
}