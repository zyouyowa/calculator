#include <string.h>
#include <stdlib.h>
#include "lexical_analysis.h"

/*
int main(int argc, char const *argv[])
{
    const char* str = "-6 + 3 * (70/5 - 6)\n";
    struct token_list_node* head = lexical_analysis(str);
    struct token_list_node* node;

    for(node = head; node != NULL; node = node->next){
        printf("%c", token2char(node->tt));
    }
    printf("\n");

    del_list(head);

    return 0;
}
*/

enum token_type char2token(char c)
{
    enum token_type ret;
    switch(c){
        case '0': ret = NUM_0; break;
        case '1': ret = NUM_1; break;
        case '2': ret = NUM_2; break;
        case '3': ret = NUM_3; break;
        case '4': ret = NUM_4; break;
        case '5': ret = NUM_5; break;
        case '6': ret = NUM_6; break;
        case '7': ret = NUM_7; break;
        case '8': ret = NUM_8; break;
        case '9': ret = NUM_9; break;
        case '+': ret = OP_PLUS; break;
        case '-': ret = OP_MINUS; break;
        case '*': ret = OP_MUL; break;
        case '/': ret = OP_DIV; break;
        case '\n': ret = NEW_LINE; break;
        case ' ':
        case '\t': 
            ret = WHITE_SPACE; break;
        default: ret = UNDEFINED;
    }
    return ret;
}

char token2char(enum token_type token){
    char ret;
    switch(token){
        case NUM_0: ret = '0'; break;
        case NUM_1: ret = '1'; break;
        case NUM_2: ret = '2'; break;
        case NUM_3: ret = '3'; break;
        case NUM_4: ret = '4'; break;
        case NUM_5: ret = '5'; break;
        case NUM_6: ret = '6'; break;
        case NUM_7: ret = '7'; break;
        case NUM_8: ret = '8'; break;
        case NUM_9: ret = '9'; break;
        case OP_PLUS: ret = '+'; break;
        case OP_MINUS: ret = '-'; break;
        case OP_MUL: ret = '*'; break;
        case OP_DIV: ret = '/'; break;
        case NEW_LINE: ret = '\n'; break;
        case WHITE_SPACE: ret = ' '; break;
        default: ret = UNDEFINED;
    }
    return ret;
}

struct token_list_node* lexical_analysis(const char* str)
{
    size_t i;
    size_t length = strlen(str);

    struct token_list_node* head;
    head = malloc(sizeof(*head));

    //init head
    for(i = 0; i < length; i++)
    {   
        enum token_type t = char2token(str[i]);
        //TODO: エラー処理
        //if(t == UNDEFINED) {/*error?*/}
        if(t != WHITE_SPACE){
            head->tt = t;
            head->next = NULL;
            i++;
            break;
        }
    }

    struct token_list_node* tail = head;

    for(;i < length; i++){
        enum token_type t = char2token(str[i]);
        if(t == WHITE_SPACE) continue;
        //TODO: エラー処理
        //if(t == UNDEFINED) {/*error?*/}
        tail = add_node(t, tail);
    }

    return head;
}

struct token_list_node* add_node(enum token_type token, struct token_list_node* tail)
{
    struct token_list_node* node;
    
    node = malloc(sizeof(*node));
    node->tt = token;
    node->next = NULL;

    tail->next = node;
    return node;
}

void del_list(struct token_list_node* head){
    struct token_list_node* node = head;
    struct token_list_node* tmp;
    while(node != NULL){
        tmp = node;
        node = node->next;
        free(tmp);
    }
}
