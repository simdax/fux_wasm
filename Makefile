LIBFT_MOD= $(addprefix libft/, . array mem list)
INCLUDE= $(addprefix -I, $(LIBFT_MOD))
CC=gcc -g
NO_LINK=-c
LINK= 
SRCS= ft_lstadd.c ft_lstnew.c main.c ft_memcpy.c
OBJS= $(SRCS:.c=.o)
vpath %.c libft/list:libft/mem
vpath %.o objs

NAME= fux

all: $(OBJS) 
				$(CC) $(addprefix objs/, $(OBJS)) $(LINK) -o $(NAME)

%.o: %.c
				@echo $<
				@mkdir -p objs
				$(CC) $(INCLUDE) $(NO_LINK) $< -o objs/$@

debug: all
				lldb $(NAME)

clean: $(OBJS)
				rm -rf $^

fclean: clean
				rm -rf $(NAME)

re: fclean
				make all

wasm: 
				make CC=emcc NAME=io.js	
