#include <stdio.h>
#include <string.h>
#include "lexical_analysis.h"
#include "parser.h"

#define MAX_BUFFER_SIZE 256

int main(int argc, char const *argv[])
{
    printf("### Calculator ###\n");
    char buf[MAX_BUFFER_SIZE] = {0};
    
    while(1){
        printf("> ");
        fflush(stdout);
        fgets(buf, MAX_BUFFER_SIZE, stdin);

        struct token_list_node* head = lexical_analysis(buf, strlen(buf));
        int result = expr(&head);
        printf("%d\n", result);
    }

    return 0;
}
