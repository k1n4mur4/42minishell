#ifndef		MAKE_CMD_H
# define	MAKE_CMD_H

# include <stdlib.h>

# include "command.h"
# include "libft.h"

t_word_desc	*alloc_word_desc(void);
t_word_desc	*make_bare_word(const char *string);
t_word_desc	*make_word_flags(t_word_desc *w, const char *string);
t_word_desc	*make_word(const char *string);
t_word_list	*make_word_list(t_word_desc *word, t_word_list *wlink);

#endif