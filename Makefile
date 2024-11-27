.PHONY: all clean fclean re docker-build docker-run docker-clean docker

NAME = ft_printf

CFILES_DIR = cfiles/
OBJS_DIR = objs/

CFILES = printf \
		putchar \
		putstr \
		putptr \
		putnbr \
		putprct

INCLUDE = include
MAKEFILE = Makefile

RM = rm -f
CC = cc
AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror 

DOCKER_IMAGE = ft_printf
DOCKER_TAG = latest

SRC  = $(addprefix $(CFILES_DIR)/, $(addsuffix .c, $(addprefix ft_, $(CFILES))))
OBJS = $(addprefix $(OBJS_DIR)/, $(CFILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
        $(CC) -o $@ $^

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