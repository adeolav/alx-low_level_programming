#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar -rc libamy.a *.o
ranlib libmy.a
