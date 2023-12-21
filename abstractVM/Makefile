##
## EPITECH PROJECT, 2023
## B-SYN-400-MPL-4-1-abstractVM-mohamed-amine.rouita
## File description:
## Makefile
##

CC = g++ -std=c++17
CFLAGS = -g3 -Wall -Wextra

SRCS	=	$(wildcard *.cpp) \
			$(wildcard Types/*.cpp)

SRC_T	=	$(wildcard tests/*.c) \
			$(wildcard src/*.c)

OBJS = $(SRCS:.cpp=.o)
TFLAGS  =       -W -Wall -Wextra -Iinclude --coverage -lcriterion

EXECUTABLE = abstractVM
EXECUTABLE_T = unit_test

.PHONY: all clean fclean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(EXECUTABLE)

re: fclean all
