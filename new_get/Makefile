NAME = getnextline

CC = cc

CFLAGS = -Wall -Wextra -Werror
SRC_DIR = .

OBJ_DIR = objs

SRCS = main.c get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "✅ Compilação concluída com sucesso!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🛠️ Compilando $<"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

all: $(NAME)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🧹 Arquivos objeto removidos!"

fclean: clean
	@rm -f $(NAME)
	@echo "🚮 Executável removido!"

re: fclean all

.PHONY: all clean fclean re
