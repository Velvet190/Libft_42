_This project has been created as part of the 42 curriculum by vlaval-a._

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

## Part 1 - Libc functions

Reimplementation of standard C library functions:

| Function | What it does |
|---|---|
| `ft_isalpha` | Checks whether a character is an uppercase or lowercase letter. |
| `ft_isdigit` | Checks whether a character is a decimal digit (0–9). |
| `ft_isalnum` | Checks whether a character is a letter or a digit. |
| `ft_isascii` | Checks whether a value belongs to the ASCII character set (0–127). |
| `ft_isprint` | Checks whether a character is printable (32–126). |
| `ft_strlen` | Returns the length of a string, excluding the terminating null character. |
| `ft_memset` | Fills a memory area with a specified byte value. |
| `ft_bzero` | Sets the specified number of bytes to zero. |
| `ft_memcpy` | Copies a specified number of bytes from one memory area to another; the areas must not overlap. |
| `ft_memmove` | Copies bytes between memory areas safely, even when they overlap. |
| `ft_strlcpy` | Copies a string into a destination buffer of a specified size and returns the full length of the source string, regardless of truncation. |
| `ft_strlcat` | Appends a string to a destination buffer of a specified size and returns the length of the string it tried to create (or the destination length plus the source length if the destination is not null-terminated within the specified size). |
| `ft_toupper` | Converts a lowercase letter to uppercase; other values remain unchanged. |
| `ft_tolower` | Converts an uppercase letter to lowercase; other values remain unchanged. |
| `ft_strchr` | Returns a pointer to the first occurrence of a character in a string, including the terminating null character if searching for `\0`. |
| `ft_strrchr` | Returns a pointer to the last occurrence of a character in a string, including the terminating null character if searching for `\0`. |
| `ft_strncmp` | Compares two strings up to a specified number of characters, using unsigned character values. |
| `ft_memchr` | Searches for the first occurrence of a byte in a memory area. |
| `ft_memcmp` | Compares two memory areas byte by byte, using unsigned character values. |
| `ft_strnstr` | Searches for a substring within a string, considering at most a specified number of characters. |
| `ft_atoi` | Converts the initial numeric portion of a string into an integer, handling leading whitespace and an optional sign. |
| `ft_calloc` | Allocates memory for an array and initializes all allocated bytes to zero. |
| `ft_strdup` | Allocates memory and creates a duplicate of the given string. |

## Part 2 - Additional functions

Additional utility functions:

| Function | What it does |
|---|---|
| `ft_substr` | Allocates and returns a substring starting at a specified index; returns an allocated empty string if the starting index is beyond the source string. |
| `ft_strjoin` | Allocates and returns a new string containing the concatenation of two strings. |
| `ft_strtrim` | Allocates and returns a copy of a string with specified characters removed from both ends. |
| `ft_split` | Splits a string into an array of strings using a specified delimiter, with a NULL pointer at the end of the array. |
| `ft_itoa` | Converts an integer into a newly allocated string, handling negative numbers and zero. |
| `ft_strmapi` | Applies a function to each character of a string and returns a newly allocated string containing the results. |
| `ft_striteri` | Applies a function to each character of a string, passing its index and a pointer to the character, modifying the original string. |
| `ft_putchar_fd` | Writes a character to the specified file descriptor. |
| `ft_putstr_fd` | Writes a string to the specified file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to the specified file descriptor. |
| `ft_putnbr_fd` | Writes an integer to the specified file descriptor. |

## Linked lists

Linked list manipulation functions:

| Function | What it does |
|---|---|
| `ft_lstnew` | Allocates and returns a new list node containing the given content, with its next pointer set to NULL. |
| `ft_lstadd_front` | Adds a new node at the beginning of a list and updates the head pointer. |
| `ft_lstsize` | Returns the number of nodes in a linked list. |
| `ft_lstlast` | Returns a pointer to the last node of a linked list, or NULL if the list is empty. |
| `ft_lstadd_back` | Adds a new node at the end of a linked list. |
| `ft_lstdelone` | Deletes a single node, freeing its content using the provided deletion function, without freeing the rest of the list. |
| `ft_lstclear` | Deletes and frees every node in a list, then sets the head pointer to NULL. |
| `ft_lstiter` | Applies a function to the content of every node in a linked list. |
| `ft_lstmap` | Creates a new list by applying a function to each node's content, using a deletion function to clean up if allocation fails.

## Resources

- [C Programming Language - cppreference](https://en.cppreference.com/w/c)
- [GNU Compiler Collection (GCC)](https://gcc.gnu.org/)
- [GNU Make Manual](https://www.gnu.org/software/make/manual/)
- 42 subject: Libft

### Use of AI

AI tools were used as a learning and assistance resource to clarify C concepts, understand function behavior, assist with debugging, create and run final tests, and help with documentation. All implementations, test results, and final decisions are reviewed and validated by me.