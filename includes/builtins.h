#ifndef BUILDINS_H
# define BUILDINS_H

# include "libft.h"
# include "command.h"

# define VALID_ECHO_OPTIONS 'n'

int	builtin_switch(t_command *command);

// int	echo_builtin(t_word_list *list);
/* 各ビルトインコマンドの実装 */
// int builtin_echo(int argc, char **argv);
// int builtin_exit(int argc, char **argv);
// int builtin_pwd(int argc, char **argv);

#endif