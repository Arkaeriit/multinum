LIBS = -lpthread
CFLAGS = -Wall -g

SRC= main.c         \
     multimulti.c   \

OBJ=$(SRC:.c=.o)

all : multiReduc

multiReduc : $(OBJ)
	gcc $(OBJ) -o multiReduc

objets : $(SRC)
	gcc -c $(SRC) $(CFLAGS) -o $(OBJ)

clean :
	rm -f *.o
	rm -f multiReduc

