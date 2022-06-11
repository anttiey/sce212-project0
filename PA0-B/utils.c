#include "dir_file.h"
#include "utils.h"

int open_file(char* fname, FILE** input) {
    if (access(fname, F_OK) == -1) {
        ERR_PRINT("The '%s' file does not exists\n", fname);
        return -1;
    }

    *input = fopen(fname, "r");
    if (input == NULL) {
        ERR_PRINT("Failed open '%s' file\n", fname);
        return -1;
    }

    return 1;
}

// This parse_str_to_list() split string to the tokens, and put the tokens in token_list.
// The value of return is the number of tokens.
int parse_str_to_list(const char* str, char** token_list) {
    
    int num_token = 0;
    char *ptr;
    ptr = strtok((char*)str, "/\n");
    while (ptr != NULL) {
        // token_list[num_token] = ptr;
        token_list[num_token] = malloc(strlen(ptr)+1);
        strcpy(token_list[num_token], ptr);
        num_token++;
        ptr = strtok(NULL, "/\n");
    }

    return num_token;
}

void free_token_list(char** token_list, int num_token) {
    int index;

    for (index = 0; index < num_token; index++) {
        free(token_list[index]);
    }

    free(token_list);
}
