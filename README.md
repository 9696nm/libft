# libft

A custom C library with fundamental functions for 42 projects.

## Build Instructions

### Standard Build
```bash
make
```

### Build with Bonus Functions
```bash
make bonus
```

### Build with Extra Functions
```bash
make extra
```

### Cleaning
```bash
# Remove object files
make clean

# Remove object files and library
make fclean

# Rebuild the library
make re
```

## Using the Library

### Linking with Your Project

After building the library, link it with your project:

```bash
gcc your_program.c -I/path/to/libft -L/path/to/libft -lft -o your_program
```

Then include the header in your C files:

```c
#include "libft.h"
```

## Library Contents

The library contains various utility functions organized into three categories:

**📖 For detailed function reference, see [function_list.md](function_list.md)**

1. **Standard Functions** (default build)
   - Character checks (`ft_isalnum`, `ft_isalpha`, etc.)
   - Memory operations (`ft_memchr`, `ft_memcmp`, etc.)
   - String operations (`ft_strlen`, `ft_strchr`, etc.)
   - And more...

2. **Bonus Functions** (with `make bonus`)
   - Linked list operations (`ft_lstnew`, `ft_lstadd_front`, etc.)

3. **Extra Functions** (with `make extra`)
   - Additional utilities like `get_next_line`, `perrturn`, etc.

## Additional Libraries

### libarith

The project includes an additional arithmetic library (`libarith`) for extended mathematical operations:

- Located in `libarith/` directory
- Integrated into the build system via `libarith.mk`
- Build simultaneously with the main library

#### Building libarith

The libarith library is automatically built when you run the standard build commands:

```bash
# Build libft and libarith together
make arith
```

#### Using libarith

To use the arithmetic functions in your project:

```c
#include "libarith.h"
```

Make sure to include both libft and libarith when compiling:

```bash
gcc your_program.c -I/path/to/libft -L/path/to/libft -larith -o your_program
```

### Combining Make Targets

Multiple make targets can be combined to build different components simultaneously:

```bash
# Build both standard libft and libarith
make all arith

# Build standard functions, extra functions and libarith
make all extra arith
```
```bash
gcc your_program.c -I/path/to/libft -L/path/to/libft -lft -larith -o your_program
```

---

*Crafted with care by hmori/azusa* 
