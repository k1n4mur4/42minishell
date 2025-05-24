#include "parser.h"
#include "debug.h"

void	parser(t_command *command)
{
	t_word_list	*word_list;

	if (!command->current_command)
		return ;
	word_list = lexer(command);
	debug_lexer(word_list);
	if (!word_list)
		return ;
	dispose_words(word_list);
}
