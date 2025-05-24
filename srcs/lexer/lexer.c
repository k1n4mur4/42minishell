#include "parser.h"

static char	*read_current_line(char *p)
{
	char	quote_char;
	char	*redirect_char;
	char	pre;

	if (!p)
		return (NULL);
	while (*p)
	{
		pre = *p;
		if (*p == '\'' || *p == '"')
		{
			quote_char = *p;
			p++;
			while (*p && *p != quote_char)
				p++;
			if (*p != quote_char)
			{
				parser_error("syntax error", ERROR_SYNTAX, quote_char);
				return (NULL);
			}
		}
		if (is_redirect_chars(p))
		{
			redirect_char = p;
			redirect_char++;
			if (*redirect_char == *p || *redirect_char == *p)
				p = redirect_char;
		}
		p++;
		if (is_shell_break_chars(*p) || is_shell_break_chars(pre))
			return (p);
	}
	return (p);
}

t_word_list	*lexer(t_command *command)
{
	char		*p;
	char		*start;
	t_word_desc	*word_desc;
	t_word_list	*word_list;
	t_word_list	*last_word_list;

	if (!*(command->current_command))
		return (NULL);
	word_list = NULL;
	p = command->current_command;
	while (*p)
	{
		while (ft_isspace(*p))
			p++;
		if (!*p)
			break ;
		start = p;
		p = read_current_line(p);
		word_desc = make_word(ft_strndup(start, p - start));
		if (!word_desc)
		{
			dispose_words(word_list);
			return (NULL);
		}
		last_word_list = make_word_list(word_desc, word_list);
		if (!last_word_list)
		{
			dispose_word(word_desc);
			dispose_words(word_list);
			return (NULL);
		}
		word_list = last_word_list;
	}
	return (word_list);
}
