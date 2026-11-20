NAME = harl
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Harl.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Harl.hpp

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
