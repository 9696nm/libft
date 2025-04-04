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

NAME			=	libft.a
PROJECT_NAME	=	Libft


CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-Iincludes
MAKEFLAGS		+=	--no-print-directory

SRC_DIR			=	./srcs
SRC_FILES		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
					ft_memchr.c ft_memcmp.c \
					ft_strlen.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
					ft_memset.c ft_memcpy.c ft_memmove.c \
					ft_bzero.c ft_strlcpy.c ft_strlcat.c \
					ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_strtrim.c \
					ft_striteri.c ft_strmapi.c \
					ft_tolower.c ft_toupper.c \
					ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
					ft_calloc.c \
					ft_atoi.c ft_itoa.c \
					ft_putbit.c ft_isspace.c ft_isvalue.c ft_split_toi.c \

BONUS_SRC_FILES	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

EXTRA_SRC_FILES	=	get_next_line.c q_rsqrt.c \

ifeq ($(FLAG), extra)
TARGET_SRC		=	$(SRC_FILES) $(BONUS_SRC_FILES) $(EXTRA_SRC_FILES)
else ifeq ($(FLAG), bonus)
TARGET_SRC		=	$(SRC_FILES) $(BONUS_SRC_FILES)
else
TARGET_SRC		=	$(SRC_FILES)
endif

OBJ_DIR			=	./objs
OBJ_FILES		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(TARGET_SRC))
DEPENDENCY		=	$(patsubst %.c, $(OBJ_DIR)/%.d, $(TARGET_SRC))

RED				=	"\033[1;31m"
GREEN			= 	"\033[1;32m"
YELLOW			=	"\033[1;33m"
CYAN			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
RESET			=	"\033[0m"


all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)
	@echo $(GREEN)"---$(PROJECT_NAME) Sccusse $(FLAG)!---"$(RESET)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(IFLAGS) -MMD -MP -c $< -o $@

-include $(DEPENDENCY)

bonus:
	@$(MAKE) all FLAG=bonus

extra:
	@$(MAKE) all FLAG=extra

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo $(RED)"$(PROJECT_NAME) $(OBJ_DIR) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) object has already been deleted."$(RESET); \
	fi

ifeq ($(SKIP_CLEAN), 1)
fclean:
else
fclean: clean
endif
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo $(RED)"$(NAME) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

re: fclean all

debug: $(NAME)
	$(MAKE) -f debug_module/compile.mk $(MAKECMDGOALS)
#	cc -Iincludes debug_module/strtol_module/org_main.c libft.a -o debug_module/org.out
#	cc -Iincludes srcs/ft_strtol.c debug_module/strtol_module/ft_main.c libft.a -o debug_module/ft.out
#	./debug_module/compile.sh

.DEFAULT_GOAL := all

.PHONY: all clean fclean re bonus debug
