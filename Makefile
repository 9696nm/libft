# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:46:16 by hmori             #+#    #+#              #
#    Updated: 2025/07/13 12:14:56 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET			=	libft.a
PROJECT_NAME	=	Libft

MAKEFLAGS		+=	--no-print-directory 

# -compile rule-
CC				=	gcc
WARNING_FLAG	=	-Wall -Wextra -Werror -Wshadow
OPT_FLAGS		=	-O0
INC_PATHS		=	-Iincludes
DEPEND_FLAGS	=	-MMD -MP

# -target-
SRCS_DIR		=	srcs/
OBJ_DIR			=	objs/

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

EXTRA_SRC_FILES	=	get_next_line.c q_rsqrt.c perrturn.c
# ft_strtol.c

OBJ_FILES		=	$(patsubst %.c, $(OBJ_DIR)%.o, $(TARGET_SRC))
DEPENDENCY		=	$(patsubst %.c, $(OBJ_DIR)%.d, $(TARGET_SRC))

ifeq ($(FLAG), extra)
TARGET_SRC		=	$(SRC_FILES) $(BONUS_SRC_FILES) $(EXTRA_SRC_FILES)
else ifeq ($(FLAG), bonus)
TARGET_SRC		=	$(SRC_FILES) $(BONUS_SRC_FILES)
else
TARGET_SRC		=	$(SRC_FILES)
endif

# -color code-
RED				=	"\033[1;31m"
GREEN			= 	"\033[1;32m"
YELLOW			=	"\033[1;33m"
CYAN			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
RESET			=	"\033[0m"

# --rule--
-include $(DEPENDENCY)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)
	@echo $(GREEN)"---$(PROJECT_NAME) Sccusse $(FLAG)!---"$(RESET)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c | $(OBJ_DIR)
	$(CC) $(WARNING_FLAG) $(OPT_FLAGS) $(INC_PATHS) $(DEPEND_FLAGS) -c $< -o $@

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
	@if [ -f $(TARGET) ]; then \
		rm -f $(TARGET); \
		echo $(RED)"$(TARGET) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re bonus debug
