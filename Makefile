NAME = vector

SRC =	main.cpp


### Sources ###
PATHSRCS = ./srcs
SRCS = $(addprefix $(PATHSRCS)/,$(SRC))

### Objets ###

OBJS = $(SRC:.cpp=.o)

### Flags ###
FLAGS = -Wall -Wextra -Werror -std=c++11

.cpp.o:
	  c++ ${FLAGS} -c -I. $< -o ${<:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJS)
		c++ ${FLAGS} -o ${NAME} ${OBJS}


clean:
	rm $(OBJS)

fclean:	clean	
		rm $(NAME)


re:	fclean all

.PHONY:	all clean fclean re
