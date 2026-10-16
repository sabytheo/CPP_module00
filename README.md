*This project has been created as part of the 42 curriculum by tsaby.*

# C++ Module 00

> Namespaces, classes, member functions, stdio streams, initialization lists, static, const

## Description

First contact with C++: moving from C-style code to classes, member functions and the iostream library.

Part of the C++ piscine of the 42 curriculum: every exercise is written in **C++98** and compiled with `-Wall -Wextra -Werror -std=c++98`.

## Exercises

| Exercise | Name | What it does |
|---|---|---|
| [`ex00`](ex00/) | Megaphone | Prints its arguments in upper case, or a default feedback noise when run without arguments. |
| [`ex01`](ex01/) | My Awesome PhoneBook | An interactive phone book holding up to 8 contacts (the oldest is replaced when full), with `ADD`, `SEARCH` and `EXIT` commands and a formatted, column-aligned listing. |

## Instructions

Each exercise is an independent program with its own `Makefile`:

```bash
cd ex00
make
```

| Exercise | Binary | Usage |
|---|---|---|
| `ex00` | `megaphone` | `./megaphone "shhhhh... I think the students are asleep..."` |
| `ex01` | `Awesome-PhoneBook` | `./Awesome-PhoneBook` |

`make clean` removes the object files, `make fclean` also removes the binary and `make re` rebuilds from scratch.

## Resources

- [cppreference.com](https://en.cppreference.com/w/cpp) — language and standard library reference
- [cplusplus.com](https://cplusplus.com/reference/) — C++98 standard library reference
