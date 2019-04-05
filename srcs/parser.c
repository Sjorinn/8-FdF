/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 09:24:44 by pchambon          #+#    #+#             */
/*   Updated: 2019/03/26 13:22:22 by pchambon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char		*strjoin_space(const char *s1, const char *s2)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp = ft_strjoin(s2, " ")))
		return (NULL);
	if (!(tmp2 = ft_strjoin(s1, tmp)))
		return (NULL);
	free(tmp);
	tmp = NULL;
	return (tmp2);
}

int			str_to_int(char *str)
{
	int		i;
	int		neg;
	int		conv;

	i = 0;
	neg = 1;
	if (str[0] == '-')
	{
		i++;
		neg = -1;
	}
	conv = ((str[i]) - 48);
	while (str[++i])
		conv = (conv * 10) + (str[i] - 48);
	return ((neg * conv));
}

t_point		*convert(char **tab, int len)
{
	int			j;
	t_point		*head;
	t_point		*elem;

	j = -1;
	if (!(head = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	elem = head;
	while (tab[++j])
	{
		j != 0 ? elem = elem->next : 0;
		if (!(elem->next = (t_point *)malloc(sizeof(t_point))))
			return (NULL);
		elem->x = j % len;
		elem->y = j / len;
		elem->z = ((int)log10(10 * str_to_int(tab[j]))) * 2;
		elem->len = len;
		get_color(elem);
	}
	free(elem->next);
	elem->next = NULL;
	free_tab(tab);
	return (head);
}

int			check_line(char *s)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (s[++i])
	{
		if (ft_isdigit(s[0]) == 0 && s[0] != '-')
			return (0);
		if (s[i] == ' ')
		{
			len++;
			if (ft_isdigit(s[i + 1]) == 0 && s[i + 1] != '-')
				return (0);
		}
		if (s[i] == '-')
			if (ft_isdigit(s[i + 1]) == 0)
				return (0);
		if (ft_isdigit(s[i]) == 1)
			if (ft_isdigit(s[i + 1]) == 0 && s[i + 1] != 32 && s[i + 1])
				return (0);
		if (ft_isdigit(s[i]) == 0 && s[i] != '-' && s[i] != ' ')
			return (0);
	}
	return ((len + 1));
}

t_point		*parser(int argc, char **argv)
{
	t_parser	data;
	char		**tab;

	data.tmp_len = -1;
	data.stock = ft_strnew(1);
	if (argc != 2 || (data.fd = open(argv[1], O_RDONLY)) <= 0)
		return (null_free(data.stock));
	while (get_next_line(data.fd, &data.line) == 1)
	{
		if ((data.len = check_line(data.line)) == 0)
			return (null_free(data.line));
		if (data.tmp_len != -1 && data.tmp_len != data.len)
			return (null_free(data.line));
		data.tmp_len = data.len;
		if (!(data.tmp = strjoin_space(data.stock, data.line)))
			return (null_free(data.line));
		free(data.stock);
		data.stock = data.tmp;
		free(data.line);
	}
	close(data.fd);
	tab = ft_strsplit(data.stock, ' ');
	ft_strdel(&data.stock);
	return (convert(tab, data.len));
}
