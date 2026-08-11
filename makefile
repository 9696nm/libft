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

# -- Info --
TARGET			:=	libft.a
PROJECT_NAME	:=	Libft

MAKEFLAGS		+=	--no-print-directory
.DEFAULT_GOAL	:=	all

# -- Compile Rule --
CC				:=	cc
CPPFLAGS		=	$(addprefix -I,$(INC_DIRS)) $(addprefix -D,$(CPPDEFS))
CFLAGS			=	-Wall -Wextra -Werror
DEPFLAGS		:=	-MMD -MP

AR				:=	ar
ARFLAGS			:=	rcs

# -- Dir --
INC_DIRS		=	.
SRC_DIR			:=	srcs
OBJ_DIR			:=	objs

# -- Srcs --
SRCS			:=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
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
					ft_atoi.c ft_itoa.c lite_atof.c \
					ft_putbit.c ft_isspace.c ft_isvalue.c ft_split_toi.c
BONUS_SRCS		:=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
EXTRA_SRCS		:=	get_next_line.c perrturn.c ret_errmsg.c # ft_strtol.c

TARGET_SRCS		=	$(SRCS)
ifneq ($(filter bonus, $(COMPILE_TYPE)),)
TARGET_SRCS		+=	$(BONUS_SRCS)
endif
ifneq ($(filter extra, $(COMPILE_TYPE)),)
TARGET_SRCS		+=	$(EXTRA_SRCS)
endif

# -- Objs --
OBJS			:=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(TARGET_SRCS))
DEPS			:=	$(OBJS:.o=.d)

# -- Arg Rule --
CPPDEFS			+=	$(DEF)

ifeq ($(DEBUG),1)
CFLAGS			+=	-g -Og  -Wuninitialized -Wfatal-errors -Wshadow
else
CFLAGS			+=	-O3
endif

# --color code--
RED				:=	"\033[1;31m"
GREEN			:= 	"\033[1;32m"
YELLOW			:=	"\033[1;33m"
CYAN			:=	"\033[1;36m"
WHITE			:=	"\033[1;37m"
RESET			:=	"\033[0m"

# -- Rules --
.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(AR) $(ARFLAGS) $@ $<
	@echo $(GREEN)"--- $(PROJECT_NAME) compiled successfully $(COMPILE_TYPE) ---"$(RESET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

.PHONY: bonus
bonus:
	@$(MAKE) all COMPILE_TYPE=bonus

.PHONY: extra
extra:
	@$(MAKE) all COMPILE_TYPE=extra

.PHONY: clean
clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo $(RED)"$(PROJECT_NAME) $(OBJ_DIR) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) object has already been deleted."$(RESET); \
	fi

.PHONY: fclean
ifeq ($(SKIP_CLEAN), 1)
fclean:
else
fclean: clean
endif
	$(MAKE) $(CLEAN_TARGETS)
	@if [ -f $(TARGET) ]; then \
		rm -f $(TARGET); \
		echo $(RED)"$(PROJECT_NAME) $(TARGET) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

.PHONY: re
re: fclean
	$(MAKE) all

# -- Include --
-include $(DEPS)
-include libarith/libarith.mk
