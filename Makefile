# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:46:16 by hmori             #+#    #+#              #
#    Updated: 2025/02/20 21:38:26 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
FLAGS			=	-Iinclude
MAKEFLAGS		+=	--no-print-directory

NAME			=	libft.a


SRC_DIR			=	src
SRC_FILES		=	ft_isdigit.c ft_memset.c ft_strdup.c ft_strncmp.c ft_atoi.c	ft_isprint.c\
					ft_putchar_fd.c ft_striteri.c ft_strnstr.c ft_bzero.c ft_itoa.c ft_putendl_fd.c\
					ft_strjoin.c ft_strrchr.c ft_calloc.c ft_memchr.c ft_putnbr_fd.c ft_strlcat.c\
					ft_strtrim.c ft_isalnum.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c ft_substr.c\
					ft_isalpha.c ft_memcpy.c ft_split.c ft_strlen.c ft_tolower.c\
					ft_isascii.c ft_memmove.c ft_strchr.c ft_strmapi.c ft_toupper.c\
					ft_putbit.c ft_isspace.c ft_isvalue.c ft_split_toi.c

BONUS_SRC_FILES	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

EXTRA_SRC_FILES	=	get_next_line.c q_rsqrt.c

ifeq ($(FLAG), extra)
TARGET_SRC		=	$(SRC_FILES) $(BONUS_SRC_FILES) $(EXTRA_SRC_FILES)
else ifeq ($(FLAG), bonus)
TARGET_SRC		=	$(SRC_FILES) $(BONUS_SRC_FILES)
else
TARGET_SRC		=	$(SRC_FILES)
endif

OBJ_DIR			=	obj
OBJ_FILES		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(TARGET_SRC))

DEPENDENCY		=	$(patsubst %.c, $(OBJ_DIR)/%.d, $(TARGET_SRC))


all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(FLAGS) -MMD -MP -c $< -o $@

-include $(DEPENDENCY)

bonus:
	@$(MAKE) all FLAG=bonus

extra:
	@$(MAKE) all FLAG=extra

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re bonus
