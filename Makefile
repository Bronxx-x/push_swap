LIBFT_DIR = ft_printf/
LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a

SRCS = swap.c lstdelitem.c push.c reverse.c rotate.c sort_algo.c sort_util1.c \
	sort_util_ab.c sort_util_ba.c rotate_type.c lst_util.c big_sort.c apply_algo.c

MAIN_SRC = main.c

BONUS_SRC = checker.c checker_utils.c

OBJS =${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

BONUS = checker

INCLUDE = -L $(LIBFT_DIR) -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT_LIB) $(NAME) $(BONUS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
$(NAME): $(OBJS) ${MAIN_SRC:.c=.o}
	$(CC) $(CFLAGS) $^ -o $(NAME) $(INCLUDE)
	
$(BONUS): $(OBJS) ${BONUS_SRC:.c=.o}
	$(CC) $(CFLAGS) $^ -o $(BONUS) $(INCLUDE)

bonus: ${BONUS}

clean:
	$(RM) $(OBJS) $(BONUS_OBJ) $(BONUS) ${BONUS_SRC:.c=.o} ${MAIN_SRC:.c=.o}
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) libftprintf.a
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
