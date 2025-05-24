#include "parser.h"

t_connection	*init_connection(t_connection *connections)
{
	t_connection	*connection;

	connection = (t_connection *)ft_calloc(1, sizeof(t_connection));
	if (!connection)
		return (NULL);
	connection->first = NULL;
	connection->second = NULL;
	connection->connector = 0;
	connection->ignore = 0;
	return (connection);
}