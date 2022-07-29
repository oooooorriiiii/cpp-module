CC			:=	clang++
CFLAGS		:=	-std=c++98 -Wall -Wextra -Werror

NAME		:=	out

SRCS		:=	Account.cpp \
				tests.cpp

INCLUDES	:=	Account.hpp

OBJS		:=	$(SRCS:%.cpp=%.o)

.PHONY:	all
all		:	$(NAME)

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean
	rm -rf $(OBJS)

.PHONY: fclean
fclean:	clean
	rm -rf $(NAME)

.PHONY: re
re:	fclean all
