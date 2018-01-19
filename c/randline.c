/* Copyright © 2018 Bart Massey */
/* [This program is licensed under the "MIT License"]
   Please see the file LICENSE in the source
   distribution of this software for license terms. */

/* Print a random line from a file. */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "readline.h"

int
main() {
    /* Line list. */
    char **lines = 0;
    /* Number of lines read. */
    size_t nlines = 0;

    /* Read all lines into the buffer. */
    while (1) {
        /* Make sure there's room for the line in the buffer. */
        assert(nlines < __SIZE_MAX__);
        /* Read the next line. */
        char *line = readline();
        if (line == 0)
            /* Was last line.*/
            break;
        /* Make room for the new line. */
        lines = realloc(lines, (nlines + 1) * sizeof *lines);
        /* Make sure that worked. */
        assert(lines != 0);
        /* Append the line to the buffer. */
        lines[nlines] = line;
        /* Increment the count. */
        nlines++;
    }

    /* Generate a random index and print that line. */
    srand(getpid());
    while (1) {
        /* Fill up all of a size_t with random bits. Assumes
           sizeof (int) evenly divides sizeof (size_t). */
        size_t base = 0;   /* The underlying random integer. */
        /* Fill up base with calls to rand(). This should be
           just 1 or 2 calls. */
        for (int i = 0; i < sizeof base / sizeof (int); i++)
            base |= rand() << (8 * sizeof (int) * i);
        /* Figure out what the slop at the end of the range
           looks like, and reject if base is in there. */
        size_t intervals = ~(size_t)0 / nlines;
        if (base < nlines * intervals) {
            /* Have selected an index truly uniform-pseudorandomly. */
            size_t index = base % nlines;
            printf("%s\n", lines[index]);
            return 0;
        }
    }
}
