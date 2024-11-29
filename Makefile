.PHONY: all clean fclean re docker-build docker-run docker-clean

NAME 			= libftprintf.a

CFILES_DIR		= cfiles/
OBJS_DIR		= objs/
LIBFT_DIR		= libft/

CFILES = printf			\
	putchar				\
	putstr				\
	putnbrbase			

INCLUDE			= includes
MAKEFILE 		= Makefile
LIBFT			= $(LIBFT_DIR)libft.a

RM 				= rm -f
CC				= cc
AR				= ar -rcs

MAKE			= make

CFLAGS 			= -Wall -Wextra -Werror 

DOCKER_IMAGE 	= ft_printf
DOCKER_TAG		= latest

SRC				= $(addprefix $(CFILES_DIR), $(addsuffix .c, $(addprefix ft_, $(CFILES))))
OBJS 			= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(addprefix ft_, $(CFILES))))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(AR) $@ $^ $(LIBFT)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(CFILES_DIR)%.c $(INCLUDE) $(MAKEFILE) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re : fclean all

docker-build:
	docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) .

docker-run: docker-build
	docker run --rm -it $(DOCKER_IMAGE):$(DOCKER_TAG)

docker-clean:
	docker rmi -f $(DOCKER_IMAGE):$(DOCKER_TAG)