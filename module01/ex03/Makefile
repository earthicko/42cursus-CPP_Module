NAME		= ex03

CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		= \
			HumanA.cpp \
			HumanB.cpp \
			Weapon.cpp \
			main.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
