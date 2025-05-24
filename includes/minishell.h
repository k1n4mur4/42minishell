# ifndef MINISHELL_H
# define MINISHELL_H

typedef enum e_type
{
	SET,
	GET,
	SHOW,
	ADD,
	FREE,
	RESET
}			t_type;

#include "libft.h"
#include "ft_printf.h"
#include "eval.h"
#include "env.h"
#include "execute_cmd.h"

#include <unistd.h> // STDERR_FILENO
# include <readline/readline.h>
# include <readline/history.h>
#include <termios.h>

# define ENAME "minishell"

// main.c
int		main(int argc, char **argv, char **envp);

// minishell.c
int		minishell(int argc, char **argv, char **envp);

// shell_initialize.c
void	shell_initialize(void);
int		exit_value(int status, enum e_type type);

// eval.c
int		reader_loop(void);

// exit_shell.c
void exit_shell(void);

#endif





















// # ifndef MINISHELL_H
// # define MINISHELL_H

// #include <unistd.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <stdio.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include "libft.h"
// #include "ft_printf.h"
// // minishell
// #include "reader_loop.h"
// #include "env.h"
// #include "struct.h"
// #include "parser.h"
// #include "debug.h"

// # define ENAME "minishell"


// // main.c
// int		main(int argc, char **argv, char **env);

// // shell.c
// int		minishell(int argc, char **argv, char **envp);

// // initialize_environmentironment.c
// t_list	*initialize_environment(char **env);

// // shell_initialize.c
// void	shell_initialize(t_minishell *minishell);

// // exit_shell.c
// void	exit_shell(t_minishell *minishell);

// #endif