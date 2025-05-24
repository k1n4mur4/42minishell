#include "parser.h"

int	redirect_flags(t_word_list *word_list)
{
	if (!word_list || !word_list->word)
		return (0);
	if (word_list->word->flags == TOK_REDIR_HERE)
		return (O_TRUNC | O_WRONLY | O_CREAT | O_EXCL);
	if (word_list->word->flags == TOK_REDIR_APP)
		return (O_APPEND | O_WRONLY | O_CREAT);
	if (word_list->word->flags == TOK_REDIR_IN)
		return (O_RDONLY);
	if (word_list->word->flags == TOK_REDIR_OUT)
		return (O_TRUNC | O_WRONLY | O_CREAT);
	return (0);
}

t_redirect	*init_redirect(t_word_list *word_list)
{
	t_redirect	*redirect;
	t_word_list	*next_word_list;

	if (!word_list || !word_list->next)
		return (NULL);
	next_word_list = word_list->next;
	redirect->next = NULL;
	// redirect->flags = redirect_flags(word_list->word->word);
	if (word_list->word->flags == TOK_REDIR_HERE)
		redirect->here_doc_eof = ft_strdup(next_word_list->word->word);
	else
		redirect->here_doc_eof = NULL;
	return (redirect);
}

void	read_redirect(t_word_list *word_list)
{
	t_word_list	*current_word_list;
	t_word_list	*next_word_list;

	if (!word_list || !word_list->next)
		return ;
	next_word_list = word_list->next;
	current_word_list = NULL;
	while (next_word_list)
	{
		if (is_redirect_chars(next_word_list->word->word))
		{
			if (!next_word_list->next)
				return ;// TODO error line
			if (current_word_list)
				word_list->next = next_word_list->next->next;
			else
				word_list = next_word_list->next->next;
			next_word_list->next->next = NULL;
		}
		word_list = next_word_list;
		next_word_list = next_word_list->next;
	}
}

t_redirect	*make_redirect(t_word_list *word_list)
{
	t_redirect	*redirect;
	t_word_list	*next_word_list;
	t_word_list	*redirect_word_list;

	if (!word_list)
		return (NULL);
	next_word_list = word_list;
	while (next_word_list)
	{
	}
	return (redirect);
}
