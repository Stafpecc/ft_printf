.PHONY: all clean fclean re #docker-build docker-run docker-clean

NAME 			= libftprintf.a

CFILES_DIR		= cfiles/
OBJS_DIR		= .objs/
LIBFT_DIR		= libft/

CFILES = printf			\
	putchar				\
	putstr				\
	putnbrbase			

INCLUDE			= includes
MAKEFILE 		= Makefile
LIBFT			= libft.a

RM 				= rm -f
RM_DIR			= rm -rf
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
	mv $(LIBFT_DIR)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	$(AR) $@ $^

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)%.o: $(CFILES_DIR)%.c $(INCLUDE) $(MAKEFILE) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

test: all
    $(CC) $(CFLAGS) -o test/test_my_library test/test_my_library.c $(LIB)
    ./test/test_my_library

clean:
	$(RM_DIR) $(OBJS_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)

re : fclean all

#docker-build:
#	docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) .

#docker-run: docker-build
#	docker run --rm -it $(DOCKER_IMAGE):$(DOCKER_TAG)

#docker-clean:
#	docker rmi -f $(DOCKER_IMAGE):$(DOCKER_TAG)