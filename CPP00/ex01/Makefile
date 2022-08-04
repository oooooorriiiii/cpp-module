CC		=	clang++ -std=c++98
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	phonebook
SRCS	=	main.cpp \
			Phonebook.cpp \
			Contact.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
