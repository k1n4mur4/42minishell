#ifndef DISPOSE_CMD_H
#define DISPOSE_CMD_H

# include <stdlib.h>
# include "command.h"

void	dispose_word(t_word_desc *w);
void	dispose_words(t_word_list *list);
void	dispose_command(t_command *command);

#endif