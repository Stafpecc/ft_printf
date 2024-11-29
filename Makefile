.PHONY: all clean fclean re docker-build docker-run docker-clean

NAME = ft_printf

CFILES_DIR = cfiles/
OBJS_DIR = objs/

CFILES = printf       \
	putchar           \
	putstr            \
	putptr            \
	putnbrunsigned    \
	putnbrbase        \
	putprct

INCLUDE = include
MAKEFILE = Makefile

RM = rm -f
CC = cc
AR = ar -rcs

CFLAGS = -Wall -Wextra -Werror 

DOCKER_IMAGE = ft_printf
DOCKER_TAG = latest

SRC  = $(addprefix $(CFILES_DIR), $(addsuffix .c, $(addprefix ft_, $(CFILES))))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(addprefix ft_, $(CFILES))))

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(INCLUDE)
	cp include/libft.a .
	mv libft.a $(NAME)
	$(CC) -o $@ $^

$(OBJS_DIR):
    mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(CFILES_DIR)%.c $(INCLUDE) $(MAKEFILE) | $(OBJS_DIR)
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