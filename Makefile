NAME = push_swap
NAME_BONUS = checker
LIBFTNAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFTDIR = ./libft

SRCS = ./src/swap.c ./src/push.c ./src/rotate.c ./src/rrotate.c ./src/ft_itoa_nosigne.c ./src/lst_utils.c ./src/lst_utils2.c \
		./src/algo.c ./src/free.c ./src/parsing.c ./src/stack_init.c 

SRC_main = ./src/push_swap.c 
	
OBJS = $(SRCS:.c=.o)

OBJ_main = $(SRC_main:.c=.o)

BONUS_SRCS = ./bonus/checker_bonus.c ./bonus/get_next_line_utils.c ./bonus/get_next_line.c ./bonus/cheler_utils_bonus.c

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

HEADERS = ./include/push_swap.h

# COLOR #
GREEN	= \033[38;5;76m
RED		= \033[38;5;160m
YELLOW	= \033[38;5;226m
ORANGE	= \033[38;5;202m
PURPLE	= \033[38;5;213m
LBLUE	= \033[38;5;51m
BLUE	= \033[38;5;117m
INDI	= \033[38;5;99m
RESET	= \033[00m

all: $(NAME)
	@printf "$(BLUE)\n\n\n"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢟⣛⣭⣵⣶⣶⣬⣭⣭⣭⣝⡛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⣫⣵⣾⣿⣿⣿⣿⣿⣿⣿⡿⣏⢻⣟⢿⣷⣬⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⡿⢫⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣜⡜⣿⣆⢿⡜⣿⣎⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⠟⣴⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⡎⣿⢸⡟⣾⢿⡎⢻⣧⡹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⠏⣼⣿⣿⢡⣹⡟⣿⣿⣿⡿⠟⠛⠋⠉⠁⠀⠀⠉⠈⠁⠙⠘⠇⢠⣿⣧⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⠇⣼⣿⣿⣿⣾⢿⣷⠙⠋⠁⠀⠀⠀⠀⠀⢀⣀⣠⣤⣤⣴⣶⣶⣶⡶⢲⣶⣶⣬⣭⣟⣛⣿⢛⣭⣛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡿⢸⣿⡟⣿⡆⠿⠂⠀⠀⠀⣀⣀⣤⣴⣶⣿⣿⣿⣿⣿⣿⣿⠿⠋⠁⣴⣿⣟⣖⣉⠻⠿⣿⡇⣾⣿⣿⣷⡝⢿⣿⣿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡇⣾⣿⣧⢻⠏⠀⢀⣠⣴⣿⣏⣥⡾⠾⢉⣛⠛⠛⠉⠉⠁⠀⠀⠐⠛⠉⠙⠋⠋⠩⣝⣳⣾⡇⣿⣿⣿⣿⣿⢠⣝⢿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⡇⣿⣿⣿⠇⣠⡶⢋⣡⣤⠏⠉⢁⣴⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣷⣦⣿⣿⠧⢻⣿⣿⣿⣿⡄⣿⣆⢻⣿⣿⣿⣿"
	@echo "⣿⣿⣿⡘⢋⣵⣾⣿⡿⠛⠉⠀⠀⠀⣼⣿⣿⣿⣿⣿⣷⡀⠀⣦⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⡛⢉⢷⡄⢻⣿⣿⡿⠇⡿⡇⠀⣿⣿⣿⣿"
	@echo "⣿⡿⢋⣴⣿⠿⠋⠉⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣷⡀⢸⣷⡀⠀⠀⠀⠀⠀⠀⠀⢀⡈⠈⢣⢿⠠⣤⠩⣶⡆⣇⣠⠀⣿⣿⣿⣿"
	@echo "⢋⡴⣫⢉⠄⠀⠀⠀⠀⠀⠀⣼⠀⣾⣿⣿⣿⣿⣿⣿⣿⣿⣧⢸⠿⢛⣀⠘⣄⠀⠀⠀⠀⠈⠻⡟⢺⡼⡇⣿⡀⢙⣇⢿⡟⣼⣿⣿⣿⣿"
	@echo "⣫⡾⠛⠁⠀⣴⠀⠀⠀⠀⠀⣟⡂⡻⠿⣿⣿⣿⣿⣿⣿⣿⣋⣴⣾⠿⢿⠆⢿⡄⠀⠀⠀⠐⣦⣄⡸⢱⡇⣿⠀⠀⠹⠈⢼⣿⣿⣿⣿⣿"
	@echo "⣿⢃⢂⢊⣾⡇⠀⠀⠀⡄⢰⣿⣧⣿⣿⣶⣶⣿⣟⢻⣿⣿⣿⠋⢁⢤⡤⠂⣸⠿⠀⡆⠀⠌⠈⡿⠡⠟⣃⣭⣶⣾⣿⣷⣶⣍⡻⢿⣿⣿"
	@echo "⢁⣶⠟⢺⡏⠀⠀⠀⠀⣷⢸⡟⢋⣩⣄⣉⢹⣿⣿⣾⣿⣿⣿⣷⣯⣄⡲⠖⠩⢂⢲⡇⠉⠘⡧⢀⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⢙⣿"
	@echo "⢸⣩⢘⢸⡇⢠⢇⣤⠀⢿⣿⢷⣿⣿⣿⣿⣿⣿⣿⣦⣉⡿⠿⠟⣛⣭⣦⣾⣷⣿⢸⡇⠸⣣⢀⠀⣦⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢸⣿"
	@echo "⣦⢻⣸⣼⡱⣿⡄⣤⠀⢸⣿⠰⠆⣍⢉⣭⣭⣭⣭⣴⣶⣶⣿⣿⣿⣿⣿⣿⢟⡁⣸⡇⠞⠁⠘⣤⡿⠿⠟⣛⣭⣭⣶⣾⣿⣿⣿⣅⣿⣿"
	@echo "⣾⣀⠿⣅⣉⢾⣧⢻⡁⠀⢿⡇⢦⣿⣿⣿⣿⣿⡿⠿⢟⣛⣻⣭⣭⣭⣭⣁⣌⢠⡿⢠⣖⡄⣄⠀⠁⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⠻"
	@echo "⠰⢭⣓⠦⣭⣥⠙⣧⣙⠦⡌⢿⡄⠙⠗⢙⣭⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⣣⡞⢁⠸⠟⣽⡏⢸⢀⢰⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀"
	@echo "⣿⣶⣬⣭⣙⣛⣛⣛⣛⣓⡲⣌⠻⣦⡘⢾⣿⣿⣿⣿⣿⣿⣿⡿⠛⠛⣩⠞⠉⣠⣿⣿⣳⢷⣷⠈⠻⠾⠈⢟⣛⣛⣋⣿⣿⣿⣿⣿⣿⣦"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠈⠙⠲⠬⣭⣉⣙⣋⣠⣭⠴⠶⠋⠁⢠⣾⡿⣿⣿⣏⣿⠃⠀⠸⡇⢠⢹⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⠀⠀⣾⣷⣶⣶⠤⠀⠀⠶⡀⢀⠄⢠⢿⣟⣴⣿⡿⣼⠃⠀⠀⠀⠈⡉⢘⠛⣛⣫⣤⣶⣿⣿⣿⡟⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠻⣟⣛⠿⣦⣤⣠⡄⠀⠌⠠⢱⡟⣼⠿⠛⣡⠁⠀⠀⠀⠀⠀⠃⢨⣇⣿⣿⣿⣿⣿⡿⢋⣾⣯"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣆⠀⠀⢀⣄⠈⢻⣿⣷⣾⣭⣛⣻⣧⣀⣛⣨⣴⣾⣿⣷⣆⠀⠀⠀⠀⠀⠀⠀⠀⠩⡙⠛⠋⠁⠈⠙⠛⠉"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⢾⣿⠇⠈⣿⣿⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⡟⢻⡆⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⠀⠀⠀⠀"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠁⠀⠀⠈⠻⢿⣿⣿⣿⡇⣿⣿⣿⣿⡿⢋⢠⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣤⣄"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠀⣀⡀⢸⣦⡒⠨⠛⠿⣷⡹⣿⣟⣫⣬⣭⣼⣿⣿⣷⣄⣀⣀⣀⣀⣀⣀⣀⣈⣭⣥⣿⣿⣿⣿"
	@echo "⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢘⣿⣧⣀⣻⣿⣦⣽⣿⣿⡷⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿"

makelibft:
	@cd $(LIBFTDIR) && make

$(NAME): makelibft  $(OBJ_main) $(OBJS)
	@$(CC) $(CFLAGS) -I$(HEADERS) -o $@ $(OBJ_main) $(OBJS) -L ${LIBFTDIR} -lft  
	
%.o: %.c
	@printf "$(LBLUE)[Compilation]$(RESET) In progress... $(GREEN)$<" && \
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@ && \
	printf "\r$(LBLUE)[Compilation]$(RESET) Completed   ... $(GREEN)$<" && \
	printf " $(LBLUE)[$(RESET)$(CC)$(LBLUE)/]$(RESET)\n"

bonus : $(NAME_BONUS)

$(NAME_BONUS) : ${BONUS_OBJS} ${OBJS} makelibft
	@$(CC) $(CFLAGS) -I$(HEADERS) -o $@ $(BONUS_OBJS) $(OBJS) -L ${LIBFTDIR} -lft

clean:
	@cd $(LIBFTDIR) && make clean
	@for obj in $(OBJS); do \
		printf "$(RED)Cleaning Libft...  Removing $$obj... " && \
		sleep 0.01 && \
		rm -f $$obj && \
		printf "\r"; \
	done
	@for obj in $(BONUS_OBJS); do \
		printf "$(RED)Cleaning Libft...  Removing $$obj... " && \
		sleep 0.01 && \
		rm -f $$obj && \
		printf "\r"; \
	done
	@printf "                                                      \r$(GREEN)push_swap is Clean\n$(RESET)"

	
fclean: clean
	@cd $(LIBFTDIR) && make fclean
	@rm -f $(NAME)
	
re: fclean all

.PHONY : all clean fclean re
