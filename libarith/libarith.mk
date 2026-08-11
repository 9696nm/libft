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

# -- Info --
ARITH_TARGET		:=	libarith.a
ARITH_PROJECT_NAME	=	Libarith

CLEAN_TARGETS		+=	arith_clean

# -- Dir --
INC_DIRS			+=	$(ARITH_INC_DIR)

ARITH_DIR			=	libarith
ARITH_INC_DIR		=	$(ARITH_DIR)/internal
ARITH_SRC_DIR		=	$(ARITH_DIR)/$(SRC_DIR)
ARITH_OBJ_DIR		=	$(OBJ_DIR)/$(ARITH_DIR)

# -- Srcs --
ARITH_SRCS			=	q_rsqrt.c \
						coord_add.c \
						coord_sub.c \
						coord_to_vec3.c \
						quat_axis_angle.c \
						quat_conjugate.c \
						quat_from_to.c \
						quat_multiply.c \
						quat_normalize.c \
						quat_rotate.c \
						vec3_add.c \
						vec3_cross.c \
						vec3_dot.c \
						vec3_length.c \
						vec3_normalize.c \
						vec3_scale.c \
						vec3_sub.c \
						vec3_to_coord.c \

# -- Objs --
ARITH_OBJS			=	$(patsubst %.c, $(ARITH_OBJ_DIR)/%.o, $(ARITH_SRCS))
ARITH_DEPS			=	$(OBJS:.o=.d)

# -- Rules --
.PHONY: arith
arith: $(ARITH_TARGET)

$(ARITH_TARGET): $(ARITH_OBJS)
	$(AR) $(ARFLAGS) $@ $^
	@echo $(GREEN)"--- $(ARITH_PROJECT_NAME) compiled successfully ---"$(RESET)

$(ARITH_OBJ_DIR)%.o: $(ARITH_SRC_DIR)%.c | $(ARITH_OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

$(ARITH_OBJ_DIR):
	@mkdir -p $(ARITH_OBJ_DIR)

.PHONY: arith_clean
arith_clean:
	@if [ -f $(ARITH_TARGET) ]; then \
		rm -f $(ARITH_TARGET); \
		echo $(RED)"$(ARITH_PROJECT_NAME) $(ARITH_TARGET) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(ARITH_PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi

# -- Include --
-include $(ARITH_DEPS)
