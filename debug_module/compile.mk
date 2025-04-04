
NAME			=	libft.a
PROJECT_NAME	=	Libft


CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
IFLAGS			=	-Iincludes

OBJ_DIR			=	./objs
OBJ_FILES		=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(TARGET_SRC))

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

clean:
	@if [ -d $(OBJ_DIR) ]; then \
		rm -rf $(OBJ_DIR); \
		echo $(RED)"$(PROJECT_NAME) $(OBJ_DIR) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) object has already been deleted."$(RESET); \
	fi

fclean: clean
	@if [ -f $(NAME) ]; then \
		rm -f $(NAME); \
		echo $(RED)"$(NAME) has been deleted !"$(RESET); \
	else \
		echo $(CYAN)"$(PROJECT_NAME) archive has already been deleted."$(RESET); \
	fi


.DEFAULT_GOAL := all

.PHONY: all clean fclean
