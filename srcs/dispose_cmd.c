#include "dispose_cmd.h"

void	dispose_word(t_word_desc *w);
void	dispose_words(t_word_list *list);
void	dispose_command(t_command *command);

void	dispose_word(t_word_desc *w)
{
	if (!w)
		return ;
	free(w->word);
	free(w);
}

void	dispose_words(t_word_list *list)
{
	t_word_list	*t;

	while (list)
	{
		t = list;
		list = list->next;
		dispose_word(t->word);
	}
}

void	dispose_command(t_command *command)
{
	if (command->current_command)
		free(command->current_command);
}
