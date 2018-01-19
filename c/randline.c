/* Copyright © 2018 Bart Massey */

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
        char *line = readline();
        if (line == 0)
            break;
        lines = realloc(lines, (nlines + 1) * sizeof *lines);
        assert(lines != 0);
        lines[nlines] = line;
        nlines++;
    }

    /* Generate a random index and print that line. */
    srand(getpid());
    while (1) {
        /* Fill up all of a size_t with random bits. Assumes
           sizeof (int) evenly divides sizeof (size_t). */
        size_t base = 0;
        for (int i = 0; i < sizeof base / sizeof (int); i++)
            base |= rand() << (8 * sizeof (int) * i);
        size_t intervals = __SIZE_MAX__ / nlines;
        if (base < nlines * intervals) {
            /* Have selected an index truly uniform-pseudorandomly. */
            size_t index = base % nlines;
            printf("%s\n", lines[index]);
            return 0;
        }
    }
}
