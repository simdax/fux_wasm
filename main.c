#include "array.h"
#include "mem.h"
#include "type.h"
#include <stdio.h>
#include <unistd.h>

int						type_cons(int cf, int ctr)
{
				int	diff;

				diff = cf - ctr;
				while(diff > 6)
								diff -= 7;
				return (g_consonnances[diff]);
}

static int		p(int val)
{
				printf("b%d, \n", val);
				return (1);
}

static void		*ret_cons(int prev_cons)
{
				static int	all_cons[5] = {0, 2, 4, 5, -1};
				static int	iperf_cons[3] = {2, 5, -1};

				if (prev_cons == 4 || prev_cons == 0)
								return (&iperf_cons);
				else
								return (&all_cons);
}

int						go(t_list *mel, int cf, int ctrp, int index, int prev_mvt)
{
				int	curr_cons;
				int	prev;
				int prev_ctrp;
				int	mvt_ctrp;
				int	*cons;

//				curr_cons = dtype_cons(cf, ctr);
	//			if (curr_cons == DIS)
		//						return (0);
				if (mel && mel->content)
								prev = cf - *(int*)mel->content;
				else
								return (p(ctrp));
				cons = ret_cons(prev_mvt);
				while (*cons != -1)
				{
								prev_ctrp = prev + *cons;
								mvt_ctrp = ctrp - prev_ctrp;
								if (go(mel->next, prev, prev_ctrp, index + 1, mvt_ctrp))
										//printf("a%d%s", mvt_ctrp, !index ? "\n" : ", ");
								++cons;
				}
				return (1);
}

static t_list	*populate_list(void *data, size_t type_size, unsigned len)
{
				int i;
				t_list *list;
				
				i = 0;
				list = 0;
				while(i < len)
				{
								ft_lstadd(&list, ft_lstnew(data, type_size));
								data += type_size;
								++i;
				}
				return (list);
}

int		main()
{
				int last_ctr;
				int size = 1;
				int mel[8] = {1, 4, 2, 3, 5, -1, -1, -1};
				int first;

				first = 0;
				last_ctr = 0;
				t_list *io = populate_list(mel, sizeof(int), 8);
				printf("%d\n", *(int*)io->content);				
				go(io, 0, 0, 0, 0);
				return (0);
}
