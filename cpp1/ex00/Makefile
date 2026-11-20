NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Zombie.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re
