NAME	= Fixed
CPP		= c++ -fsanitize=address -fno-omit-frame-pointer
FLAGS	= -Wall -Wextra -I -std=c++98
RM		= rm -rf

SRC		= Fixed.cpp main.cpp
INC		= Fixed.hpp

OBJ		= $(SRC:%.cpp=%.o)

all : $(NAME)

%.o : %.cpp $(INC)
	@echo "\033[0;33mCompiling $<\033[0m"
	@$(CPP) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@echo "\033[0;32mFixed point numbers!\033[0m"
	@$(CPP) $(FLAGS) $^ -o $@

clean:
	@echo "\033[0;31mRemoving objects...\033[0m"
	@$(RM) $(OBJ)

fclean: clean
	@echo "\033[0;31mRemoving executable...\033[0m"
	@$(RM) $(NAME)

re : fclean all