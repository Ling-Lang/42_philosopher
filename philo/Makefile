NAME = philo
RM = rm -f
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -g

SRC = 	main.c \
		validate.c \
		utils.c \
		init.c		\
		philo_routine.c	\
		watcher_routine.c
OBJ = $(SRC:.c=.o)

GREEN = \033[0;32m
YELLOW = \033[1;33m
RESET = \033[0m

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling $@$(RESET)"
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation completed: $@$(RESET)"

%.o : %.c
	@echo "$(YELLOW)Compiling $<$(RESET)"
	@$(CC) -c $< -o $@
	@echo "$(YELLOW)$< compiled successfully$(RESET)"

debug: $(OBJ)
	@echo "$(GREEN)Compiling $@ with debugging symbols$(RESET)"
	@$(CC) $(DEBUG) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Debug compilation completed: $@$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files$(RESET)"
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(YELLOW)Cleaning executable $(NAME)$(RESET)"
	@$(RM) $(NAME)

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re
