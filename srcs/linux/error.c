#include "error.h"

void	programming_error(const char *format, ...)
{
	va_list	args;

	ft_dprintf(STDERR_FILENO, "%s: ", ENAME);
	va_start(args, format);
	ft_vdprintf(STDERR_FILENO, format, args);
	va_end(args);
	exit(1);
}

// void	parser_error(t_minishell *minishell, char *iname, const char *format, ...)
// {
// 	va_list	args;

// 	if (!iname)
// 		ft_dprintf(STDERR_FILENO, "%s: ", ENAME);
// 	else
// 		ft_dprintf(STDERR_FILENO, "%s: %s: ", ENAME, iname);
// 	va_start(args, format);
// 	ft_vdprintf(STDERR_FILENO, format, args);
// 	va_end(args);
// 	minishell->exit_value = 2;
// }
