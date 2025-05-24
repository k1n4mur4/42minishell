#include "builtins.h"

// int	echo_builtin(t_word_list *list)
// {
// 	int	display_newline;

// 	if (ft_strncmp(list->word->word, "echo", ft_strlen("echo")) != 0)
// 		return (1);
// 	display_newline = 1;
// 	list = list->next;
// 	if (list && list->word && list->word->word && ft_strlen(list->word->word) == 2)
// 	{
// 		if (list->word->word[0] == '-' && list->word->word[1] == VALID_ECHO_OPTIONS)
// 		{
// 			display_newline = 0;
// 			list = list->next;
// 		}
// 	}
// 	while (list)
// 	{
// 		ft_fputs(list->word->word, STDOUT_FILENO);
// 		list = list->next;
// 		if (list)
// 			ft_fputs(" ", STDOUT_FILENO);
// 	}
// 	if (display_newline)
// 		write(STDOUT_FILENO, "\n", 1);
// 	return 0;
// }
