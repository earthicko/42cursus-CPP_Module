NAME		= harlFilter

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -Wno-implicit-fallthrough -std=c++98

SRCS		= \
			Harl.cpp \
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
