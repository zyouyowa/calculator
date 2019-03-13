#ifndef PARSER_H
#define PARSER_H

int expr(struct token_list_node** pos);
int next_expr(struct token_list_node** pos, int pre);
int term(struct token_list_node** pos);
int next_term(struct token_list_node** pos, int pre);
int factor(struct token_list_node** pos);
int number(struct token_list_node** pos);
int digit(struct token_list_node** pos);

#endif /* PARSER_H */
