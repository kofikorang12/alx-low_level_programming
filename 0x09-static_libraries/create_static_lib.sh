#!/bin/bash
gcc -Wall -pedandtic -Werror -Wextra -c *.c
ar -rc liball.a *.o
ranlib liball.a
