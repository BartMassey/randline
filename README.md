# randline — print a random line from stdin
Copyright (c) 2018 Bart Massey

This code is supposed to be a simple but correct C
implementation of the spec "read stdin, which is assumed to
be 8-bit "ASCII" text, and print a random line on stdout."

No real effort has been made to make the code efficient in
either time or space.

The program is expected to tolerate all valid ASCII inputs.

* It is permitted to run out of memory if necessary, in
  which case it will fail and dump core.

* It is permitted to fail and exit with an error message if
  an underlying library routine fails.

* It is permitted to exit with an error message if the file
  contains ASCII NUL characters ('\\0') since there is no
  reasonable way to represent them as a C string.

* It is required to pass all 8-bit characters other than NUL
  through unchanged. This should make it work with UTF-8
  strings.

* It is required to produce a line uniform-randomly from the
  file, upt to limitations of implementations of the ANSI
  `rand()` and `srand()` functions.

The algorithm chosen is the naïve one which stores every
line in a file

The motivation here, other than as a coding exercise, is to
show how *unbelievably hard and error-prone* it is to code
this correctly in C.

The C code contains extensive comments to try to explain
what is going on.

Implementations in C++, Rust, Haskell and Python are
provided for comparison and contrast. These implementations
may fail with errors if the input is not valid UTF-8, which
may or may not be a feature.

This program is licensed under the "MIT License".  Please
see the file LICENSE in the source distribution of this
software for license terms.
