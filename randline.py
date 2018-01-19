#!/usr/bin/python3

# Print a random line from stdin.

from sys import stdin
from random import randrange

lines = list(stdin)
print(lines[randrange(len(lines))], end="")
