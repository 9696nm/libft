# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:46:16 by hmori             #+#    #+#              #
#    Updated: 2025/07/14 23:58:27 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FT Library
TARGET			=	libft.a
PROJECT_NAME	=	Libft

MAKEFLAGS		+=	--no-print-directory

.DEFAULT_GOAL	:=	all


# -compile rule-
CC				=	gcc
WARNING_FLAGS	=	-Wall -Wextra -Werror -Wuninitialized
INC_PATHS		=	$(addprefix -I,$(INC_DIR))
OPT_FLAGS		=	-O0
DEPEND_FLAGS	=	-MMD -MP

AR				=	ar
ARFLAGS			=	rcs

# -target dir-
INC_DIR			=	./
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/

# -sources-
SRCS			=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
					ft_islower.c ft_isupper.c \
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
					ft_putbit.c ft_isspace.c ft_isvalue.c ft_split_toi.c
BONUS_SRCS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
EXTRA_SRCS		=	get_next_line.c perrturn.c ret_errmsg.c # ft_strtol.c

TARGET_SRCS		=	$(SRCS)
ifneq ($(filter bonus, $(COMPILE_TYPE)),)
TARGET_SRCS		+=	$(BONUS_SRCS)
endif
ifneq ($(filter extra, $(COMPILE_TYPE)),)
TARGET_SRCS		=	$(EXTRA_SRCS)
endif

# -objects-
OBJS			=	$(patsubst %.c, $(OBJ_DIR)%.o, $(TARGET_SRCS))
DEPS			=	$(patsubst %.c, $(OBJ_DIR)%.d, $(TARGET_SRCS))

# -include-
-include $(DEPS)

-include libarith/libarith.mk

# -color code-
RED				=	"\033[1;31m"
GREEN			= 	"\033[1;32m"
YELLOW			=	"\033[1;33m"
CYAN			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
RESET			=	"\033[0m"


# --rule--
all: $(TARGET)

$(TARGET): $(OBJS)	
	$(AR) $(ARFLAGS) $@ $^
	@echo $(GREEN)"--- $(PROJECT_NAME) compiled successfully $(COMPILE_TYPE) ---"$(RESET)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(WARNING_FLAGS) $(OPT_FLAGS) $(INC_PATHS) $(DEPEND_FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus:
	@$(MAKE) all COMPILE_TYPE=bonus

extra:
	@$(MAKE) all COMPILE_TYPE=extra

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo $(RED)"$(PROJECT_NAME) $(OBJ_DIR) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) object has already been deleted."$(RESET); \
	fi

ifeq ($(SKIP_CLEAN), 1)
fclean: $(CLEAN_TARGETS)
else
fclean: clean $(CLEAN_TARGETS)
endif
	@if [ -f $(TARGET) ]; then \
		rm -f $(TARGET); \
		echo $(RED)"$(PROJECT_NAME) $(TARGET) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

re: fclean all

.PHONY: all bonus extra clean fclean re
