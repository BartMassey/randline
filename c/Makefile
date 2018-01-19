# Copyright (c) 2018 Bart Massey
# [This program is licensed under the "MIT License"]
# Please see the file LICENSE in the source
# distribution of this software for license terms.

CC = gcc
CFLAGS = -g -Wall

OBJS = randline.o readline.o

randline: $(OBJS)
	$(CC) $(CFLAGS) -o randline $(OBJS)

$(OBJS): readline.h

clean:
	-rm -f $(OBJS) randline
