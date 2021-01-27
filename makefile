# specify the compiler
CC=g++

# specify options for the compiler
CFLAGS=-Wall 

FILE1=main
FILE2=components
FILE3=canvas

all: a


a: $(FILE1).o $(FILE2).o $(FILE3).o
	$(CC) $(FILE1).o $(FILE2).o $(FILE3).o -o a

$(FILE1).o: $(FILE1).cpp
	$(CC) -c $(CFLAGS) $(FILE1).cpp -o $(FILE1).o

$(FILE2).o: $(FILE2).cpp $(FILE2).h
	$(CC) -c $(CFLAGS) $(FILE2).cpp -o $(FILE2).o

$(FILE3).o: $(FILE3).cpp $(FILE3).h
	$(CC) -c $(CFLAGS) $(FILE3).cpp -o $(FILE3).o

clean:
	rm -rf *o a
