#include "lexical_analysis.h"
#include "parser.h"

/*
#include <string.h>

int main(int argc, char const *argv[])
{
    char* str = "-6 + 3 * (70/5 - 6)\n";
    struct token_list_node* head = lexical_analysis(str, strlen(str));
    struct token_list_node* pos = head;

    int result = expr(&pos);

    printf("result: %d\n", result);

    del_list(head);
    return 0;
}
*/

int expr(struct token_list_node** pos){
    int t, ret;

    t = term(pos);
    ret = next_expr(pos, t);
    
    return ret;
}

int next_expr(struct token_list_node** pos, int pre){
    int ret, mid_ret;

    if((*pos)->tt == OP_PLUS){
        next_pos(pos);
        mid_ret = pre + term(pos);
        ret = next_expr(pos, mid_ret);
    }
    else if((*pos)->tt == OP_MINUS){
        next_pos(pos);
        mid_ret = pre - term(pos);
        ret = next_expr(pos, mid_ret);
    } else {
        ret = pre;
    }

    return ret;
}

int term(struct token_list_node** pos){
    int f, ret;

    f = factor(pos);
    ret = next_term(pos, f);
    
    return ret;
}

int next_term(struct token_list_node** pos, int pre){
    int ret, mid_ret;

    if((*pos)->tt == OP_MUL){
        next_pos(pos);
        mid_ret = pre * factor(pos);
        ret = next_term(pos, mid_ret);
    }
    else if((*pos)->tt == OP_DIV){
        next_pos(pos);
        mid_ret = pre / factor(pos);
        ret = next_term(pos, mid_ret);
    } else {
        //<end>
        ret = pre;
    }

    return ret;
}

int factor(struct token_list_node** pos){
    int ret;

    if((*pos)->tt == L_BRACKET){
        next_pos(pos);
        ret = expr(pos);
        if((*pos)->tt == R_BRACKET){
            next_pos(pos);
        }
    } else {
        ret = number(pos);
    }

    return ret;
}

int number(struct token_list_node** pos){
    int ret = 0;
    int tmp = -1;
    while((tmp = digit(pos)) != -1){
        ret *= 10;
        ret += tmp;
    }

    return ret;
}

int digit(struct token_list_node** pos){
    enum token_type token = (*pos)->tt;
    int ret = -1;

    switch(token){
        case NUM_0: ret = 0; break;
        case NUM_1: ret = 1; break;
        case NUM_2: ret = 2; break;
        case NUM_3: ret = 3; break;
        case NUM_4: ret = 4; break;
        case NUM_5: ret = 5; break;
        case NUM_6: ret = 6; break;
        case NUM_7: ret = 7; break;
        case NUM_8: ret = 8; break;
        case NUM_9: ret = 9; break;
        default: return ret;
    }

    next_pos(pos);
    
    return ret;
}
