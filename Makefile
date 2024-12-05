.SILENT:

.PHONY: all clean fclean re #main test docker-build docker-run docker-clean

NAME 			= libftprintf.a
EXEC			= libftprintf.out
NAME_EXEC		= libftprintf

CFILES_DIR		= cfiles/
OBJS_DIR		= .objs/
LIBFT_DIR		= libft/
TESTER_DIR		= .ft_printfTester/

CFILES = printf			\
	putchar				\
	putstr				\
	putnbrbase			

INCLUDE			= includes
LIBFT			= libft.a
MAIN			= main.c

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

PURPLE          = \033[1;35m
GREEN           = \033[1;32m
RED             = \033[1;31m
RESET           = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	echo "$(PURPLE)Compilation of libft in progress...$(RESET)"

		$(MAKE) -C $(LIBFT_DIR)
		mv $(LIBFT_DIR)$(LIBFT) .

	echo "$(PURPLE)Move $(LIBFT) to the current directory$(RESET)"

		mv $(LIBFT) $(NAME)

	echo "$(PURPLE)Rename $(LIBFT) to $(NAME)$(RESET)"
	echo "$(GREEN)Compilation of $(LIBFT) completed successfully$(RESET)"
	echo "$(PURPLE)Compilation of $(NAME) in progress...$(RESET)"

		$(AR) $@ $^

	echo "$(GREEN)Compilation of $(NAME) completed successfully$(RESET)"

	echo "$(GREEN)"
	echo "┌───────────────────────────────────────────────────────────┐"
	echo "│      Compilation finished successfully! ᕕ(⌐■_■)ᕗ ♪♬       │"
	echo "└───────────────────────────────────────────────────────────┘"

	echo "                      ☆  *    .      ☆"
	echo "                        ∧＿∧   ∩    * ☆"
	echo "                 *  ☆ ( ・∀・)/ ."
	echo "                  .  ⊂      ノ* ☆"
	echo "                ☆ * (つ   ノ  .☆"
	echo "                      (ノ"

	echo "$(RESET)"


$(OBJS_DIR):
	echo "$(PURPLE)Creating directory $(OBJS_DIR)...$(RESET)"

		mkdir -p $(OBJS_DIR)

	echo "$(GREEN)Directory $(OBJS_DIR) created successfully!$(RESET)"


$(OBJS_DIR)%.o: $(CFILES_DIR)%.c $(INCLUDE) | $(OBJS_DIR)
	echo "$(PURPLE)Compiling $<...$(RESET)"

		$(CC) $(CFLAGS) -c $< -o $@

	echo "$(GREEN)$< completed successfully!$(RESET)"


#test:
# 	echo "$(PURPLE)Running tests...$(RESET)"

# 		$(MAKE) -C $(TESTER_DIR)

# 	echo "$(PURPLE)"
# 	echo "┌───────────────────────────────────────────────────┐"
# 	echo "│      Tests completed successfully! ᕙ(⇀‸↼‶)ᕗ       │"
# 	echo "└───────────────────────────────────────────────────┘"

# 	echo "                      |\\__/,|   ( \\"
# 	echo "                    _.|o o   |_   ) )"
# 	echo "                  -(((---(((---------"

# 	echo "$(RESET)"

# 		$(MAKE) fclean

# $(EXEC): 
# 	echo "$(PURPLE)Compiling main program...$(RESET)"

# 		$(CC) $(CFLAGS) -o $(EXEC) $(MAIN) -L. -lftprintf

# 	echo "$(GREEN)$(EXEC) completed successfully!$(RESET)"
# 	echo "$(PURPLE)Execute $(EXEC)...$(RESET)"


# main: all $(MAIN) $(INCLUDE) $(EXEC)
# 	echo "$(PURPLE)"
# 	echo "─────────────────────────────────────────────────"

# 		./$(EXEC)

# 	echo "─────────────────────────────────────────────────"	
# 	echo "$(RESET)"
# 	echo "$(GREEN)Exec of $(EXEC) completed successfully!$(RESET)"
# 	echo "$(RED)Deleting $(EXEC)...$(RESET)"

# 		$(RM) $(EXEC)

# 	echo "$(GREEN)Deleting $(EXEC) completed successfully!$(RESET)"	


clean:
	echo "$(RED)Deleting object files...$(RESET)"

		$(RM_DIR) $(OBJS_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean

	echo "$(GREEN)Deleting object files completed successfully!$(RESET)"


fclean: clean
	echo "$(RED)Deleting $(NAME)...$(RESET)"

		$(RM) $(NAME)

	echo "$(GREEN)Deleting $(NAME) completed successfully!$(RESET)"
	
	echo "$(RED)"
	echo "┌──────────────────────────────────────────────────────────┐"
	echo "│      Deletion finished successfully! ( ◔ ω◔) ノシ        │"
	echo "└──────────────────────────────────────────────────────────┘"
	
	echo "                          ╱|、"
	echo "                        (˚ˎ 。7"
	echo "                         |、˜〵"
	echo "                        じしˍ,)ノ"
	
	echo "$(RESET)"


re : fclean all


#docker-build:
#	docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) .

#docker-run: docker-build
#	docker run --rm -it $(DOCKER_IMAGE):$(DOCKER_TAG)

#docker-clean:
#	docker rmi -f $(DOCKER_IMAGE):$(DOCKER_TAG)