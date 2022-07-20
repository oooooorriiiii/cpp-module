CC		=	clang++ -std=c++98
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	phonebook
SRCS	=	main.cpp \
			phonebook.cpp
INCLUDES	=	phonebook.hpp
OBJS	=	$(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
