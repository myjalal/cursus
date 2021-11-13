
#include <string.h>
#include <stdio.h>
#include "libft.h"

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
			len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

void	ft_del(void *content)
{
	free(content);
}

t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
			return (NULL);
	if (!content)
			elem->content = NULL;
	else
			elem->content = content;
	elem->next = NULL;
	return (elem);
}

int	main(void)
{
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;

	ft_lstdelone(elem3, &ft_del);
	if (elem)
		ft_print_result(elem);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem2)
		ft_print_result(elem2);
	else
		write(1, "NULL", 4);
	write(1, "\n", 1);
	if (elem4)
		ft_print_result(elem4);
	else
		write(1, "NULL", 4);

	return (0);
}