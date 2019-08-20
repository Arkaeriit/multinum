LIBS = -lpthread
CFLAGS = -Wall -g

SRC= main.c           \
     multimulti.c     \
	 multithreading.c \

OBJ=$(SRC:.c=.o)

all : multinum

multinum : $(OBJ)
	gcc $(OBJ) $(LIBS) -o multinum

objets : $(SRC)
	gcc -c $(SRC) $(CFLAGS) -o $(OBJ)

clean :
	rm -f *.o
	rm -f multiReduc
	rm -f multinum

