#include "minishell.h"

void shell_initialize(void)
{
	rl_clear_history();
	exit_value(0, SET);
}

// void	sigint_handler(int sig)
// {
// 	(void)sig;
// 	write(STDOUT_FILENO, "\n", 1);// Ctrl+C の入力に対する改行
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// 	rl_redisplay();
// }

