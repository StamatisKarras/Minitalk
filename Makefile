SERVER = miniserver
CLIENT = miniclient

CC = cc
FLAGS = -Wall -Wextra -Werror

LIB_DIR = ./Custom_Libft/
HEADERS = -I $(LIB_DIR) -I .
LIBFT_A = $(LIB_DIR)/libft.a

SRC_server = server.c
SRC_client = client.c
OBJ_server = (SRC_server:.c=.o)
OBJ_client = (SRC_client:.c=.o)

.SILENT:

all: $(SERVER) $(CLIENT) $(LIBFT_A)

$(SERVER): $(OBJ_server)
	$(CC) $(FLAGS) $(OBJ_server) $(HEADERS) $(LIBFT_A) -o $(SERVER)

$(CLIENT): $(OBJ_client)
	$(CC) $(FLAGS) $(OBJ_client) $(HEADERS) $(LIBFT_A) -o $(CLIENT)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)

$(LIBFT_A):
	$(MAKE) -C $(LIB_DIR) -j4

re: fclean all

clean:
	rm -rf $(OBJ_client)
	rm -rf $(OBJ_server)
	$(MAKE) clean -C $(LIB_DIR)

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)
	$(MAKE) fclean -C $(LIB_DIR)

.PHONY: all re clean fclean
