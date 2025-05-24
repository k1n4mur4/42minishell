#include "parser.h"

/// リダイレクトを作る 
// int	command_flags(t_word_list *word_list)
// {
// 	if (word_list->word->flags == TOK_PIPE)
// 		return (TOK_PIPE);
// 	return (0);
// }

// t_command	*init_command(t_word_list *word_list)
// {
// 	t_command	*command;

// 	command = (t_command *)ft_calloc(1, sizeof(t_command));
// 	if (!command)
// 		return (NULL);
// 	command->word_list = word_list;
// 	command->flags = command_flags(word_list);
// 	command->type = 0;
// 	command->redirects = NULL;
// 	return (command);
// }

// t_word_list	*read_word_list(t_word_list *word_list)
// {
// 	t_word_list	*current_word_list;
// 	t_word_list	*next_word_list;

// 	if (!word_list || !word_list->next)
// 		return (NULL);
// 	if (word_list->word->flags == TOK_PIPE)
// 	{
// 		next_word_list = disconnect_word_list(word_list);
// 		return (next_word_list);
// 	}
// 	current_word_list = word_list;
// 	next_word_list = current_word_list->next;
// 	while (next_word_list)
// 	{
// 		if (next_word_list->word->flags == TOK_PIPE)
// 			break ;
// 		current_word_list = next_word_list;
// 		next_word_list = next_word_list->next;
// 	}
// 	next_word_list = disconnect_word_list(current_word_list);
// 	return (next_word_list);
// }

// t_command	*make_command(t_word_list *word_list)
// {
// 	t_word_list		*next_word_list;
// 	t_command		*current_command;
// 	t_command		*next_command;
// 	t_command		*command;

// 	if (!word_list)
// 		return (NULL);
// 	next_word_list = read_word_list(word_list);
// 	while (next_word_list)
// 	{
// 		next_word_list = read_word_list(word_list);
// 		word_list = next_word_list;
// 	}
// 	return (command);
// }
