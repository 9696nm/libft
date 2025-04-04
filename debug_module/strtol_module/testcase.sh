#!/bin/bash


strtol_assert()
{
	NPTR="$1"
	ENDPTR="$1"
}

valgrind --leak-check=full -q ./debug_module/org.out '  xz' 'NULL' '0'
