CC		=	clang++
CFLAGS	=	-Wall -Wextra -Werror

NAME	=	megaphone
SRCS	=	main.cpp
OBJS	=	$(SRCS:%.cpp=%.o)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
