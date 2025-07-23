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

TARGET			=	libft.a
PROJECT_NAME	=	Libft

MAKEFLAGS		+=	--no-print-directory 

# -compile rule-
CC				=	gcc
WARNING_FLAG	=	-Wall -Wextra -Werror -Wshadow
OPT_FLAGS		=	-O0
INC_PATHS		=	-I$(INCLUDES_DIR)
DEPEND_FLAGS	=	-MMD -MP

# -library-
LIBARITH_DIR	=	libarith/
FTLIBM			=	$(LIBARITH_DIR)ftlibm.a

# -target-
INCLUDES_DIR	=	includes/
SRCS_DIR		=	srcs/
OBJS_DIR		=	objs/

SRCS			=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
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

EXTRA_SRCS		=	get_next_line.c perrturn.c
# ft_strtol.c

OBJ_FILES		=	$(patsubst %.c, $(OBJS_DIR)%.o, $(TARGET_SRC))
DEP_FILES		=	$(patsubst %.c, $(OBJS_DIR)%.d, $(TARGET_SRC))

TARGET_SRC		=	$(SRCS)
ifneq ($(filter bonus, $(COMPILE_TYPE)),)
TARGET_SRC		=	$(BONUS_SRCS)
endif
ifneq ($(filter extra, $(COMPILE_TYPE)),)
TARGET_SRC		=	$(EXTRA_SRCS)
endif

# -color code-
RED				=	"\033[1;31m"
GREEN			= 	"\033[1;32m"
YELLOW			=	"\033[1;33m"
CYAN			=	"\033[1;36m"
WHITE			=	"\033[1;37m"
RESET			=	"\033[0m"


# --rule--
-include $(DEP_FILES)

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	ar rcs $@ $^
	@echo $(GREEN)"--- $(PROJECT_NAME) Compiling Sccusse $(COMPILE_TYPE)! ---"$(RESET)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(WARNING_FLAG) $(OPT_FLAGS) $(INC_PATHS) $(DEPEND_FLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

bonus:
	@$(MAKE) all COMPILE_TYPE=bonus

extra:
	@$(MAKE) all COMPILE_TYPE=extra

math:
	@git submodule update --init --remote --recursive
	@make -C $(LIBARITH_DIR)
	@cp $(FTLIBM) ./

clean:
	@if [ -d $(LIBARITH_DIR) ] && [ -f $(LIBARITH_DIR)Makefile ]; then \
		$(MAKE) -C $(LIBARITH_DIR) clean; \
	fi
	@if [ -d $(OBJS_DIR) ]; then \
		rm -rf $(OBJS_DIR); \
		echo $(RED)"$(PROJECT_NAME) $(OBJS_DIR) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) object has already been deleted."$(RESET); \
	fi

ifeq ($(SKIP_CLEAN), 1)
fclean:
else
fclean: clean
endif
	@if [ -d $(LIBARITH_DIR) ] && [ -f $(LIBARITH_DIR)Makefile ]; then \
		$(MAKE) -C $(LIBARITH_DIR) fclean SKIP_CLEAN=1; \
		rm -f ftlibm.a; \
	fi
	@if [ -f $(TARGET) ]; then \
		rm -f $(TARGET); \
		echo $(RED)"$(TARGET) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

re: fclean all

.DEFAULT_GOAL := all

.PHONY: all clean fclean re bonus $(LIBARITH_DIR)
