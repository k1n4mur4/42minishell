#include "minishell.h"

int	exit_value(int status, enum e_type type)
{
	static int	exit_value = 0;

	if (type == SET)
		exit_value = status;
	else if (type == GET)
		return (exit_value);
	return (exit_value);
}

void	set_bash_input(void)
{
	struct termios	term;

	rl_outstream = stderr;
	if (isatty(STDIN_FILENO) == 0)
		return ;
	if (tcgetattr(STDIN_FILENO, &term) == -1)
		exit(-1);
	term.c_lflag &= ~ECHOCTL;
	if (tcsetattr(STDIN_FILENO, TCSANOW, &term) == -1)
		exit(-1);
}

int	minishell(int argc, char **argv, char **envp)
{
	if (argc > 1)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s: No such file or directory\n",\
		ENAME, argv[1]);
		exit(127);
	}
	// parse_options(argc, argv);
	initialize_environment(envp);
	shell_initialize();
	set_bash_input();
	reader_loop();
	exit_shell();
	return (exit_value(EXIT_SUCCESS, GET));
}


// int	minishell(int argc, char **argv, char **envp)
// {
// 	t_minishell minishell;

// 	if (argc > 1)
// 	{
// 		ft_dprintf(STDERR_FILENO, "%s: %s: No such file or directory\n" ,ENAME, argv[1]);
// 		exit(127);
// 	}
// 	// parse_options(argc, argv);
// 	// initialize_environmentironment(env);
// 	minishell.env = initialize_environment(envp);
// 	shell_initialize(&minishell);
// 	// set_bash_input();
// 	reader_loop(&minishell);
// 	exit_shell(&minishell);
// 	return (minishell.exit_value);
// }
