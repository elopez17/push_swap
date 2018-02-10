#include <checker.h>

void	sort_stack(t_check *e)
{
	char	**instructs;
	int		i;

	i = -1;
	instructs = ft_strsplit(e->instructions, ' ');
	while (instructs[++i])
	{
	}
	free_2d(&instructs);
}
