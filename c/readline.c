/* Copyright © 2018 Bart Massey */
/* [This program is licensed under the "MIT License"]
   Please see the file LICENSE in the source
   distribution of this software for license terms. */

/* Read a line from stdin. */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "readline.h"

/* Read a line of text from stdin and return a pointer to
   malloced storage. Return 0 when file has ended and no
   more lines are avilable. (The last line of the file is
   read properly if it ends with EOF instead of newline.)
   Exit with an error message on errors. */
char *
readline(void) {
    /* Line buffer. */
    char *line_buffer = 0;
    size_t nread = 0;

    /* Ignoring coding guideline: Moving the test inside the
       loop. */
    while (1) {
        /* Check for sufficient buffer space. */
        if (nread >= __SIZE_MAX__ - 1) {
            fprintf(stderr, "readline: line too long\n");
            exit(1);
        }
        
        /* Get a valid character from stdin. */
        errno = 0;
        int ch = getchar();
        if (ch == EOF) {
            if (errno != 0) {
                perror("readline: getchar");
                exit(1);
            }
            if (nread == 0)
                return 0;
            break;
        }
        if (ch == '\0') {
            fprintf(stderr, "readline: null character in line\n");
            exit(1);
        }
        if (ch == '\n')
            break;

        /* Save the character. */
        line_buffer = realloc(line_buffer, nread + 1);
        line_buffer[nread] = ch;
        nread++;
    }

    /* Append the null. */
    line_buffer = realloc(line_buffer, nread + 1);
    line_buffer[nread] = '\0';

    return line_buffer;
}
