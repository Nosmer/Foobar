#include "fprintf.h"
#include <stdio.h>

typedef struct			s_lista
{
	int					content;
	struct s_lista		*next;
}						t_lista;

static void	prnt(t_lista *head)
{
	while(head)
	{
		ft_putnbr((int)head->content);
		head = head->next;
	}
}

static void	add(t_lista **head, int content)
{
	t_lista	*new;
	t_lista	*last;
	
	new = (t_lista *)malloc(sizeof(t_lista));
	last = *head;
	new->content = content;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

int			main()
{
	t_lista	*head;
	int		left;
	double	right;
	int		prec;

	right = 546.879;
	prec = 6;
	head = NULL;
	left = (int)right;
	right = right - (double)left;
	add(&head, left);
	while (prec)
	{
		right *= 10;
		left = (int)right;
		right = right - (double)left;
		add(&head, left);
		prec--;
	}
	prnt(head);
	return (0);
}
