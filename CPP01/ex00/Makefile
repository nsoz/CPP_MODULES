NAME = Zombies

CC = c++

CPPFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address

SRCS = main.cpp Zombie.cpp randomChump.cpp newZombie.cpp

OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
