#include "syntax.h"

int	is_shell_dquote_char(char c);
int	is_shell_squote_char(char c);
int	is_shell_bquote_char(char c);
int	is_shell_quote_char(char c);

int	is_shell_dquote_char(char c)
{
	if (ft_strncmp(&c, SHELL_DQUOTE_CHAR, ft_strlen(SHELL_DQUOTE_CHAR)) == 0)
		return (TOK_DQUOTE);
	return (0);
}

int	is_shell_squote_char(char c)
{
	if (ft_strncmp(&c, SHELL_SQUOTE_CHAR, ft_strlen(SHELL_SQUOTE_CHAR)) == 0)
		return (TOK_SQUOTE);
	return (0);
}

int	is_shell_bquote_char(char c)
{
	if (ft_strncmp(&c, SHELL_BQUOTE_CHAR, ft_strlen(SHELL_BQUOTE_CHAR)) == 0)
		return (TOK_BQUOTE);
	return (0);
}

int	is_shell_quote_char(char c)
{
	if (is_shell_dquote_char(c))
		return (TOK_DQUOTE);
	if (is_shell_squote_char(c))
		return (TOK_SQUOTE);
	if (is_shell_bquote_char(c))
		return (TOK_BQUOTE);
	return (0);
}
