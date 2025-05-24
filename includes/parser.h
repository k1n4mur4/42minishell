#ifndef PARSER_H
#define PARSER_H

#include "eval.h"
#include "command.h"
#include "error.h"
#include "syntax.h"
#include "dispose_cmd.h"
#include "make_cmd.h"

#define MAXWORD 1024  /* 1つの単語の最大長 */

typedef struct s_ast_type
{
	int	flag;
	int	input;
	int	output;
	int	error;
	int	pre;
}	t_ast_type;

// parser.c
void		parser(t_command *command);

// lexer.c
t_word_list	*lexer(t_command *command);

#endif
