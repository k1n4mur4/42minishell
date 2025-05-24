#include "eval.h"

void	sig_handler(int sig)
{
	if (sig == SIGINT)
		write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	if (sig == SIGINT)
		rl_replace_line("", 1);
	if (sig == SIGINT)
		exit_value(1, SET);
	rl_redisplay();
}

void	set_signal(struct sigaction *sa_sig, struct sigaction *sa_old)
{
	// setup_terminal(0);
	(*sa_sig).sa_handler = sig_handler;
	sigemptyset(&(*sa_sig).sa_mask);
	(*sa_sig).sa_flags = 0;
}

void	reset_signal(struct sigaction *sa_old)
{
	if (sigaction(SIGQUIT, sa_old, NULL) == -1 || sigaction(SIGINT, sa_old, NULL) == -1)
		exit(1);
	// setup_terminal(1);
}

int	reader_loop(void)
{
	t_command			command;
	struct sigaction	sa_sig;
	struct sigaction	sa_old;

	set_signal(&sa_sig, &sa_old);
	while (1)
	{
		command.current_command = readline(ft_strjoin(ENAME, "$ "));
		if (!command.current_command)
		{
			write(2, "exit\n", 5);
			break ;
		}
		if (!*(command.current_command))
			continue ;
		set_deftext(command.current_command);
		parser(&command);
		execute_command(&command);
		dispose_command(&command);
	}
	reset_signal(&sa_old);
	reset_signal(&sa_sig);
	return (exit_value(0, GET));
}
