LIBS = -lpthread
CFLAGS = -Wall -g

SRC= main.c           \
     multimulti.c     \
	 multithreading.c \

OBJ=$(SRC:.c=.o)

all : multiReduc

multiReduc : $(OBJ)
	gcc $(OBJ) $(LIBS) -o multiReduc

objets : $(SRC)
	gcc -c $(SRC) $(CFLAGS) -o $(OBJ)

clean :
	rm -f *.o
	rm -f multiReduc

