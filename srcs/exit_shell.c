#include "minishell.h"

void exit_shell(void)
{
	int	last_command_exit_value;

	rl_clear_history();
	ft_env(NULL, FREE);
	last_command_exit_value = exit_value(0, GET);
	exit(last_command_exit_value);
}
