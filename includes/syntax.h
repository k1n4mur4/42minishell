#ifndef SYNTAX_H
#define SYNTAX_H

#include "libft.h"

/* Defines for use by mksyntax.c */
#define SLASHIFY_IN_QUOTES "\\`$\"\n"
#define SLASHIFY_IN_HERE_DOCUMENT "\\`$"

#define SHELL_META_CHARS	"()<>;&|"
#define SHELL_BREAK_CHARS	"()<>;&| \t\n"

#define SHELL_PIPE_CHAR		"|"

#define SHELL_QUOTE_CHARS	"\"`'"
#define SHELL_DQUOTE_CHAR	"\""
#define SHELL_SQUOTE_CHAR	"'"
#define SHELL_BQUOTE_CHAR	"`"

#define SHELL_EXP_CHARS		"$"

#define SHELL_REDIRECT_CHARS	"<>"
#define SHELL_IN_CHAR			"<"
#define SHELL_OUT_CHAR			">"
#define SHELL_APPEND_CHARS		">>"
#define SHELL_HERE_CHARS		"<<"

/* ----------------- 3. yacc/bison 用トークン番号 ----------------- */
/* 0–255 は 1byte 文字が使うので 256 以降を予約 */
#define TOK_WORD		256
#define TOK_PIPE		257
#define TOK_AND_IF		258
#define TOK_OR_IF		259
#define TOK_SEMI		260
#define TOK_DSEMI		261
#define TOK_LPAREN		262
#define TOK_RPAREN		263
#define TOK_REDIR_IN	270
#define TOK_REDIR_OUT	271
#define TOK_REDIR_APP	272
#define TOK_REDIR_HERE	273
#define TOK_DQUOTE		274
#define TOK_SQUOTE		275
#define TOK_BQUOTE		276
#define TOK_DOLLAR		277
// #define TOK_PIPE_ERR	278
// #define TOK_NEWLINE		280

// syntax.c
int	is_shell_break_chars(char c);
int	is_shell_pipe_char(char c);
int	is_redirect_chars(char *s);

// is_quote.c
int	is_shell_dquote_char(char c);
int	is_shell_squote_char(char c);
int	is_shell_bquote_char(char c);
int	is_shell_quote_char(char c);




#endif /* _SYNTAX_H_ */
