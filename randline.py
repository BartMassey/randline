#!/usr/bin/python3
# Copyright (c) 2018 Bart Massey
# [This program is licensed under the "MIT License"]
# Please see the file LICENSE in the source
# distribution of this software for license terms.

# Print a random line from stdin.

from sys import stdin
from random import randrange

lines = list(stdin)
print(lines[randrange(len(lines))], end="")
