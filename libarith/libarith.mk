# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libarith.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hana/hmori <hmori@student.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 18:46:16 by hmori             #+#    #+#              #
#    Updated: 2025/07/15 00:06:05 by hana/hmori       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Arithmetic Library Module
ARITH_TARGET		=	libarith.a
ARITH_PROJECT_NAME	=	Libarith

CLEAN_TARGETS		+=	arith_clean


# -target dir-
ARITH_DIR			=	libarith/
ARITH_INC_DIR		=	$(ARITH_DIR)internal/
ARITH_SRC_DIR		=	$(ARITH_DIR)$(SRC_DIR)
ARITH_OBJ_DIR		=	$(OBJ_DIR)$(ARITH_DIR)

# -sources-
ARITH_SRCS			=	q_rsqrt.c \
						quaternion.c \
						vecter3.c \

# -objects-
ARITH_OBJS			=	$(patsubst %.c, $(ARITH_OBJ_DIR)%.o, $(ARITH_SRCS))
ARITH_DEPS			=	$(patsubst %.c, $(ARITH_OBJ_DIR)%.d, $(ARITH_SRCS))

# -add to main targets-
INC_DIR				+=	$(ARITH_INC_DIR)

# -include-
-include $(ARITH_DEPS)


# -rule-
arith: $(ARITH_TARGET)

$(ARITH_TARGET): $(ARITH_OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@echo $(GREEN)"--- $(ARITH_PROJECT_NAME) compiled successfully ---"$(RESET)

$(ARITH_OBJ_DIR)%.o: $(ARITH_SRC_DIR)%.c | $(ARITH_OBJ_DIR)
	$(CC) $(WARNING_FLAG) $(OPT_FLAGS) $(INC_PATHS) $(DEPEND_FLAGS) -c $< -o $@

$(ARITH_OBJ_DIR):
	@mkdir -p $(ARITH_OBJ_DIR)

arith_clean:
	@if [ -f $(ARITH_TARGET) ]; then \
		rm -f $(ARITH_TARGET); \
		echo $(RED)"$(ARITH_PROJECT_NAME) $(ARITH_TARGET) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(ARITH_PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

.PHONY: arith arith_clean
