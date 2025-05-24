#include "env.h"

void	ft_show_env(t_env *env)
{
	if (!env)
		return ;
	while (env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}

void	free_env(t_env *env)
{
	if (env->key)
		free(env->key);
	if (env->value)
		free(env->value);
	free(env);
}

void	free_env_list(t_env *env)
{
	t_env	*cur;

	cur = env;
	while (cur)
	{
		env = cur->next;
		free_env(cur);
		cur = env;
	}
}

t_env	*ft_env(t_env **env_list, t_type type)
{
	static t_env	*env = NULL;

	if (type == GET)
		return (env);
	if (type == SET)
		env = *env_list;
	if (type == SHOW) // TODO type == DECLEARE
		ft_show_env(env);
	if (type == FREE)
		free_env_list(env);
	else
		return (NULL);
	return (env);
}
