#include "lst_includes.h"

enum	cons_types {PFT, IPT, DIS};
int		g_consonnances[7] = {PFT, DIS, IPT, DIS, PFT, IPT, DIS};

int		type_cons(int cf, int ctr);
int		go(t_list *mel, int cf, int ctr, int index, int mvt);
