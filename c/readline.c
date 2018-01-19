/* Copyright © 2018 Bart Massey */
/* [This program is licensed under the "MIT License"]
   Please see the file LICENSE in the source
   distribution of this software for license terms. */

/* Read a line from stdin. */

#include <assert.h>
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

    while (1) {
        /* Check for sufficient buffer space. */
        if (nread >= __SIZE_MAX__ - 1) {
            fprintf(stderr, "readline: line too long\n");
            exit(1);
        }
        
        /* Get a valid character from stdin. */
        errno = 0;   /* Clear errno for later check. */
        int ch = getchar();
        /* EOF is returned on end-of-file or error. */
        if (ch == EOF) {
            if (errno != 0) {
                /* Was not actually end-of-file. */
                perror("readline: getchar");
                exit(1);
            }
            /* End-of-file at beginning of line does not
               create a line. */
            if (nread == 0)
                return 0;
            /* End-of-file after beginning of line creates a
               line. */
            break;
        }
        /* C cannot reasonably handle NUL characters in
           strings. */
        if (ch == '\0') {
            fprintf(stderr, "readline: null character in line\n");
            exit(1);
        }
        /* Newline creates a line. */
        if (ch == '\n')
            break;

        /* Make room for the character. */
        line_buffer = realloc(line_buffer, nread + 1);
        /* Make sure that worked. */
        assert(line_buffer != 0);
        /* Save the character. */
        line_buffer[nread] = ch;
        /* Increment the count. */
        nread++;
    }

    /* Append the null character. */
    line_buffer = realloc(line_buffer, nread + 1);
    assert(line_buffer);
    line_buffer[nread] = '\0';

    return line_buffer;
}
