#ifndef	COMMAND_H
#define	COMMAND_H

/* A structure which represents a word. */
typedef struct s_word_desc
{
	char		*word;		/* Zero terminated string. */
	int			flags;		/* Flags associated with this word. */
}				t_word_desc;

/* A linked list of words. */
typedef struct s_word_list
{
	struct s_word_list	*next;
	t_word_desc			*word;
}				t_word_list;

/* Command Types: */
enum e_command_type
{
	cm_for,
	cm_case,
	cm_while,
	cm_if,
	cm_simple,
	cm_select,
	cm_connection,
	cm_function_def,
	cm_until,
	cm_group,
	cm_arith,
	cm_cond,
	cm_arith_for,
	cm_subshell,
	cm_coproc
};

/* Possible values for the `flags' field of a WORD_DESC. */
# define W_HASDOLLAR	(1 << 0)
# define W_QUOTED	(1 << 1)
# define W_ASSIGNMENT	(1 << 2)
# define W_SPLITSPACE	(1 << 3)
# define W_NOSPLIT	(1 << 4)
# define W_NOGLOB	(1 << 5)
# define W_NOSPLIT2	(1 << 6)
# define W_TILDEEXP	(1 << 7)
# define W_DOLLARAT	(1 << 8)
# define W_ARRAYREF	(1 << 9)
# define W_NOCOMSUB	(1 << 10)
# define W_ASSIGNRHS	(1 << 11)
# define W_NOTILDE	(1 << 12)
# define W_NOASSNTILDE	(1 << 13)
# define W_EXPANDRHS	(1 << 14)
# define W_COMPASSIGN	(1 << 15)
# define W_ASSNBLTIN	(1 << 16)
# define W_ASSIGNARG	(1 << 17)
# define W_HASQUOTEDNULL	(1 << 18)
# define W_DQUOTE	(1 << 19)
# define W_NOPROCSUB	(1 << 20)
# define W_SAWQUOTEDNULL	(1 << 21)
# define W_ASSIGNASSOC	(1 << 22)
# define W_ASSIGNARRAY	(1 << 23)
# define W_ARRAYIND	(1 << 24)
# define W_ASSNGLOBAL	(1 << 25)
# define W_NOBRACE	(1 << 26)
# define W_COMPLETE	(1 << 27)
# define W_CHKLOCAL	(1 << 28)
# define W_FORCELOCAL	(1 << 29)
# define W_PIPE	(1 << 30)

typedef struct s_redirectee
{
	int			dest;			/* Place to redirect REDIRECTOR to, or ... */
	// t_word_desc	*filename;		/* filename to redirect to. */
	char		*filename;		/* name of variable to redirect to. */
}				t_redirectee;

typedef struct s_redirect
{
	struct s_redirect	*next;
	t_redirectee		redirector; // 入力
	int					flags;			/* Flag value for `open'. */
	t_redirectee		redirectee;	/* File descriptor or filename */// 出力
	char				*here_doc_eof;
}					t_redirect;

typedef struct s_command
{
	// t_command_type	type; /* コマンドの種類 */
	char			*current_command;
	enum e_command_type	type;
	int				flags; /* コマンドのフラグ redirect有無*/
	t_redirect		*redirects;
	t_word_list		*word_list;/* 単純コマンドの場合の単語列 */
}				t_command;

typedef struct s_connection
{
	struct s_connection	*first;
	struct s_connection	*second;
	t_command			*command;
	int					ignore;
	int					connector;
}						t_connection;

#endif