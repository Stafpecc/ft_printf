.PHONY: all clean fclean re docker-build docker-run docker-clean docker

NAME = ft_printf

CFILES = ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putptr.c

INCLUDE = ft_printf.h
MAKEFILE = Makefile

RM = rm -f
CC = cc
AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror 

OBJS = $(CFILES:.c=.o)
DOCKER_IMAGE = ft_printf
DOCKER_TAG = latest

all: $(NAME)

$(NAME): $(OBJS)
        $(CC) -o $@ $^ -lncurses -lm

%.o: %.c $(INCLUDE) $(MAKEFILE)
        $(CC) $(CFLAGS) -c $< -o $@ 

clean:
        $(RM) $(OBJS)

fclean: clean
        $(RM) $(NAME)

re : fclean all

docker-build:
        docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) .

docker-run: docker-build
        docker run --rm -it $(DOCKER_IMAGE):$(DOCKER_TAG)

docker-clean:
        docker rmi -f $(DOCKER_IMAGE):$(DOCKER_TAG)