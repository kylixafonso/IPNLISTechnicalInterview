NAME=main

CC=gcc

OBJECT_NAMES=\
	main \
	read_data \
	calc_vsf \
	display_info \

OUT_DIR=./dist
SRC_DIR=./src

OBJECTS=$(patsubst %, $(OUT_DIR)/%.o, $(OBJECT_NAMES))
SOURCES=$(patsubst %, $(SRC_DIR)/%.c, $(OBJECT_NAMES))

CFLAGS=-Wall -Wextra -Werror
LFLAGS=-I$(SRC_DIR)

all: $(NAME)
$(NAME): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(LFLAGS)

$(OUT_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p dist
	$(CC) -c -o $@ $^ $(CFLAGS)

clean:
	@rm -rf $(OUT_DIR)

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE)
