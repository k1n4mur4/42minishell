#ifndef		ENV_H
# define	ENV_H

# include "libft.h"
#include "minishell.h"

typedef struct	s_env
{
	char			*key;
	char				*value;
	struct s_env	*next;
}				t_env;

// initialize_environment.c
void	initialize_environment(char **env);
void	free_env_list(t_env *env);
t_env	*init_env(char *key, char *value);

// env.c
t_env	*ft_env(t_env **env_list, t_type type);

#endif