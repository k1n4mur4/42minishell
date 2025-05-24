#include "debug.h"

void	debug_lexer(t_word_list *word_list)
{
	t_word_list	*cur;
	int			index;

	cur = word_list;
	index = 1;
	while (cur)
	{
		printf("-----%i words-----:\n", index);
		printf("word:\"%s\"\n", cur->word->word);
		printf("flags:%i\n", cur->word->flags);
		cur = cur->next;
		index++;
	}
}
