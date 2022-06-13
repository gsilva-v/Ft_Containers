NAME = ContainerTest
CC = c++

CFLAGS = -std=c++98 -g -Wall -Werror -Wextra

SRC = ./tests/map/mainMap.cpp ./tests/vector/mainVector.cpp ./tests/stack/mainStack.cpp 

OBJS =  $(SRC:%.cpp=%.o)

all:	${NAME} 

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

${NAME}:	${OBJS}

vector: all
	${CC} ${CFLAGS} -o vector ./tests/vector/mainVector.o
	./vector

map: all
	${CC} ${CFLAGS} -o map ./tests/map/mainMap.o
	./map

stack: all
	${CC} ${CFLAGS} -o stack ./tests/stack/mainStack.o
	./stack


clean:		
	@rm -rf ${OBJS}

fclean:		clean
	@rm -rf ${NAME}

re:			fclean all