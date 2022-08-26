CXX			:=	clang++
CXXFLAGS	:=	-std=c++98 -Wall -Wextra -Werror

NAME		:=	ex02.out

SRCS		:=	Account.cpp \
				tests.cpp

OBJS		:=	$(SRCS:.cpp=.o)

.o: .cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:	all
all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -rf $(OBJS)

.PHONY: fclean
fclean:	clean
	rm -rf $(NAME)

.PHONY: re
re:	fclean all
