/*
 * Copyright (c) 2018 Bart Massey
 * [This program is licensed under the "MIT License"]
 * Please see the file LICENSE in the source
 * distribution of this software for license terms.
 */

/* Print a random line from stdin. */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

int
main() {
    auto lines = vector<string>();
    string line;
    while (getline(cin, line)) {
        lines.push_back(line);
    }
    srand(getpid());
    while (1) {
        /* Fill up all of a size_type with random bits. Assumes
           sizeof (int) evenly divides sizeof (size_type). */
        vector<string>::size_type base = 0;
        for (unsigned i = 0; i < sizeof base / sizeof (int); i++)
            base |= rand() << (8 * sizeof (int) * i);
        auto nlines = lines.size();
        auto intervals = ~(size_t)0 / nlines;
        if (base < nlines * intervals) {
            /* Have selected an index truly uniform-pseudorandomly. */
            auto index = base % nlines;
            cout << lines[index] << endl;
            return 0;
        }
    }
}
