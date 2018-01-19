CC = gcc
CFLAGS = -g -Wall

OBJS = randline.o readline.o

randline: $(OBJS)
	$(CC) $(CFLAGS) -o randline $(OBJS)

$(OBJS): readline.h

clean:
	-rm -f $(OBJS) randline
