# Libft

*This project has been created as part of the 42 curriculum by **v-laval-a**.*

## Description

**Libft** is a custom C library that recreates several standard C library functions, along with additional utility functions.

The goal of this project is to understand how standard C functions work internally, improve memory management skills, and develop a deeper understanding of pointers, strings, and linked lists.

The library includes:
- Character checking and conversion functions.
- Memory manipulation functions.
- String manipulation functions.
- Conversion and allocation functions.
- File descriptor output functions.
- Linked list manipulation functions.

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This generates the static library `libft.a`.

### Available commands

| Command | Description |
|---|---|
| `make` or `make all` | Compiles the library |
| `make clean` | Removes object files (`.o`) |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Rebuilds the library from scratch |

### Usage

To use Libft in a C project, include the header file:

```c
#include "libft.h"
```

Compile your program with the library:

```bash
cc main.c -L. -lft -o program
```

Then execute it:

```bash
./program
```

## Library Contents

### Part 1 - Libc functions

Reimplementation of standard C library functions:

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`
- `ft_isascii`, `ft_isprint`
- `ft_strlen`
- `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- `ft_strlcpy`, `ft_strlcat`
- `ft_toupper`, `ft_tolower`
- `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_memchr`, `ft_memcmp`, `ft_strnstr`
- `ft_atoi`
- `ft_calloc`, `ft_strdup`

### Part 2 - Additional functions

Additional utility functions:

- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Linked lists

Linked list manipulation functions:

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Resources

- [C Programming Language - cppreference](https://en.cppreference.com/w/c)
- [GNU Compiler Collection (GCC)](https://gcc.gnu.org/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- 42 subject: Libft

### Use of AI

AI tools were used as a learning and assistance resource to clarify C concepts, understand function behavior, and help with debugging and documentation. All implementations and final decisions are reviewed and tested by me.