NAME		= ex04

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= \
			main.cpp \
			fileUtils.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

tester: tests.o
	$(CXX) $(CXXFLAGS) tests.o -o $@ $(LDFLAGS)

clean:
	$(RM) $(OBJS) tests.o

fclean: clean
	$(RM) $(NAME) tester

re:
	make fclean
	make all

.PHONY: all clean fclean re
