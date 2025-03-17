#!/bin/bash

cc -Iincludes srcs/ft_strtol.c debug.c libft.a
valgrind --leak-check=full -q ./a.out
