#include "syntax.h"

int	is_shell_break_chars(char c);
int	is_shell_pipe_char(char c);
int	is_redirect_chars(char *s);

int	is_shell_break_chars(char c)
{
	if (is_redirect_chars(&c))
		return (is_redirect_chars(&c));
	if (is_shell_pipe_char(c))
		return (is_shell_pipe_char(c));
	return (ft_isspace(c));
}

int	is_shell_pipe_char(char c)
{
	if (ft_strncmp(&c, SHELL_PIPE_CHAR, ft_strlen(SHELL_PIPE_CHAR)) == 0)
		return (TOK_PIPE);
	return (0);
}

int	is_redirect_chars(char *s)
{
	if (ft_strncmp(s, SHELL_IN_CHAR, ft_strlen(SHELL_IN_CHAR)) == 0)
	{
		if (ft_strncmp(s, SHELL_HERE_CHARS, ft_strlen(SHELL_HERE_CHARS)) == 0)
			return (TOK_REDIR_HERE);
		return (TOK_REDIR_IN);
	}
	else if (ft_strncmp(s, SHELL_OUT_CHAR, ft_strlen(SHELL_OUT_CHAR)) == 0)
	{
		if (ft_strncmp(s, SHELL_APPEND_CHARS, ft_strlen(SHELL_APPEND_CHARS)) == 0)
			return (TOK_REDIR_APP);
		return (TOK_REDIR_OUT);
	}
	return (0);
}
