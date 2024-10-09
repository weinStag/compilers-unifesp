//declare the data structures for the buffer, the structure has to have a pointer to the buffer and an int for the size
typedef buffer {
    int size;
    struct buffer *buffer;
} buffer;

void allocate_buffer();
void deallocate_buffer();
void replace_print(FILE*);