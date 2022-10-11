NAME	:=	fizzbuzz
SRCS		:=	$(wildcard *.asm)
OBJS		:=	$(SRCS:.asm=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	ld $^ -o $@

%.o: %.asm
	nasm -f elf64 $^ -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all 
