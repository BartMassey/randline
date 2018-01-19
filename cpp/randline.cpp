/*
 * Copyright (c) 2018 Bart Massey
 * [This program is licensed under the "MIT License"]
 * Please see the file LICENSE in the source
 * distribution of this software for license terms.
 */

/* Print a random line from stdin. */

#include <iostream>
#include <random>
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
    auto rng = mt19937_64(getpid());
    auto nlines = lines.size();
    auto distribution =
        uniform_int_distribution<vector<string>::size_type>(0, nlines - 1);
    auto index = distribution(rng);
    cout << lines[index] << endl;
}
