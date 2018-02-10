#include <checker.h>

void	get_instructions(t_check *e)
{
	char	*line;
	int		len;

	while (get_next_line(0, &line) > 0)
	{
		len = ft_strlen(line);
		if ((len != 2 && len != 3) || ((len == 2 && !ft_strequ(line, "sa") &&
!ft_strequ(line, "sb") && !ft_strequ(line, "ss") && !ft_strequ(line, "pa") &&
!ft_strequ(line, "pb") && !ft_strequ(line, "ra") && !ft_strequ(line, "rb") &&
!ft_strequ(line, "rr")) || (len == 3 && !ft_strequ(line, "rra") &&
!ft_strequ(line, "rrb") && !ft_strequ(line, "rrr"))))
		{
			ft_strdel(&line);
			c_exit(e, -1);
		}
		e->instructions = ft_strmer(e->instructions,
											ft_strmer(ft_strdup(" "), line));
	}
}
