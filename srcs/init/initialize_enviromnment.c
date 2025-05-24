#include "env.h"

void	initialize_environment(char **env);
void	free_env(t_env *env);
void	free_env_list(t_env *env);
t_env	*init_env(char *key, char *value);

t_env	*init_env(char *key, char *value)
{
	t_env	*new;

	if (!key || !value)
		return (NULL);
	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	new->value = ft_strdup(value);
	if (!new->key || !new->value)
	{
		free(new->key);
		free(new->value);
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}

t_env	*make_env(char *env)
{
	int		i;
	t_env	*new;
	char	*key;
	char	*value;

	i = 0;
	while (env[i] != '=' && env[i] != '\0')
		i++;
	if (env[i] == '\0')
		return (NULL);
	key = ft_strndup(env, i);
	if (!key)
		return (NULL);
	value = ft_strdup(env + i + 1);
	if (!value)
	{
		free(key);
		return (NULL);
	}
	new = init_env(key, value);
	free(key);
	free(value);
	return (new);
}


void	initialize_environment(char **env)
{
	t_env	*env_list;
	t_env	*cur;

	env_list = make_env(*env);
	cur = env_list;
	if (!env)
	{
		ft_env(&env_list, SET);
		return ;
	}
	env++;
	while (env)
	{
		cur->next = make_env(*env);
		if (cur->next)
		{
			free_env_list(env_list->next);
			break ;
		}
		cur = cur->next;
		env++;
	}
	ft_env(&env_list, SET);
}
