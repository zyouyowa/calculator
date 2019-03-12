#ifdef LEXICAL_ANALYSIS_H
#define LEXICAL_ANALYSIS_H

enum token_type{
    NUM_0 = 0,      //"0"
    NUM_1,          //"1"
    NUM_2,          //"2"
    NUM_3,          //"3"
    NUM_4,          //"4"
    NUM_5,          //"5"
    NUM_6,          //"6"
    NUM_7,          //"7"
    NUM_8,          //"8"
    NUM_9,          //"9"
    OP_PLUS,        //"+"
    OP_MINUS,       //"-"
    OP_MUL,         //"*"
    OP_DIV,         //"/"
    NEW_LINE,       //"\n"
    WHITE_SPACE,    //" ", "\t"
    UNDEFINED
};

struct token_list_node{
    enum token_type tt;
    struct token_list_node* next;
};

enum token_type char2token(char c);
char token2char(enum token_type token);

struct token_list_node* lexical_analysis(const char* str);
struct token_list_node* add_node(enum token_type token, struct token_list_node* tail);
void del_list(struct token_list_node* head);

#endif /* LEXICAL_ANALYSIS_H */