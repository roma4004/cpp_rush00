
NAME = ft_retro

CC = clang++ -Wall -Wextra -Werror

LIBKEY = -lncurses


OBJ_PATH	= objectives
SRC_PATH	= sources
INC_PATH	= includes
LIBS_PATH	= libraries

INC = -I includes/

SRC_N = main.cpp NPC.cpp Observer.cpp stage_two.cpp

SRC = $(addprefix ${SRC_PATH}/, $(SRC_N))

OBJ = $(addprefix ./$(OBJ_PATH)/, $(SRC_N:.cpp=.o))

LIBS =


all: $(NAME)

./$(OBJ_PATH)/%.o : ./$(SRC_PATH)/%.cpp
	$(CC) $(INC) -c $< -o $@

$(NAME): objdir $(OBJ)
	$(CC) $(LIBKEY) $(OBJ) $(LIBS) -o $(NAME)

run: all
	./$(NAME)

objdir:
	mkdir -p $(OBJ_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.phony: all clean fclean re