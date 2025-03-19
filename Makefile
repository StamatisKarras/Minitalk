SERVER = miniserver
CLIENT = miniclient

CC = cc
FLAGS = -Wall -Wextra -Werror -g

LIB_DIR = ./Custom_Libft/
HEADERS = -I $(LIB_DIR) -I .
LIBFT_A = $(LIB_DIR)/libft.a

SRC_SERVER = server.c \
			 helper.c
SRC_CLIENT = client.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

.SILENT:

all: $(LIBFT_A) $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(FLAGS) $(OBJ_SERVER) $(HEADERS) $(LIBFT_A) -o $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(FLAGS) $(OBJ_CLIENT) $(HEADERS) $(LIBFT_A) -o $(CLIENT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(LIBFT_A):
	$(MAKE) -C $(LIB_DIR) -j4

re: fclean all

clean:
	rm -rf $(OBJ_CLIENT)
	rm -rf $(OBJ_SERVER)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	$(MAKE) fclean -C $(LIB_DIR)

.PHONY: all re clean fclean
