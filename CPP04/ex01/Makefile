NAME = animal

CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
