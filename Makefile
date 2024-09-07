NAME = libftprintf.a
SRC = ft_printf.c ft_putnbr.c ft_putstr.c ft_percent.c ft_heximal.c ft_putptr.c

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

CC = cc
CFLAGS = -Wall -Wextra -Werror
MKDIR = mkdir -p
RM = rm -rf
AR = ar -rcs

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

all : $(OBJ_DIR) $(NAME)

$(OBJ_DIR) :
	$(MKDIR) $(OBJ_DIR)

$(NAME) : $(OBJ)
	$(AR) $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: re fclean clean all
