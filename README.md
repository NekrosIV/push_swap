# push_swap

## Description

`push_swap` is a 42 algorithmic project focused on sorting integers with two stacks (`a` and `b`) and a strict set of allowed operations. The program takes a list of unique integers, validates the input, and prints a sequence of operations (`sa`, `pb`, `ra`, etc.) to sort stack `a` in ascending order.

This repository also includes the bonus `checker` program, which reads instructions from standard input and verifies whether they correctly sort the initial stack.

## Features

- Parses input as either multiple arguments (`./push_swap 3 2 1`) or one quoted string (`./push_swap "3 2 1"`).
- Validates syntax, integer range (`INT_MIN` to `INT_MAX`), and duplicate values.
- Uses a doubly linked list stack model (`t_node`) for stack operations.
- Handles small input (`<= 3`) with a dedicated fast path.
- Uses a cost-based strategy for larger inputs by evaluating multiple rotation combinations between stacks.
- Prints only push_swap instructions on standard output for the mandatory program.
- Provides `checker` bonus target (`make bonus`) to validate an instruction stream.

## How it works

1. **Input and validation**
   - `main` in `src/push_swap.c` initializes stack `a` from arguments.
   - `src/parsing.c` checks numeric syntax and integer limits.
   - `src/stack_init.c` rejects duplicates and builds the linked-list stack.

2. **Sorting strategy by input size**
   - If already sorted, no operations are printed.
   - For 2-3 numbers, `src/ft_sort_three.c` applies a minimal rule-based sort.
   - For larger sets, `src/algo.c`:
     - pushes part of `a` to `b`,
     - computes best move costs with helpers from `src/algo_what_action.c`,
     - applies actions via `src/algo_do_action.c`,
     - reinserts into `a` and rotates `a` to place the minimum value on top.

3. **Primitive operations**
   - `src/swap.c`, `src/push.c`, `src/rotate.c`, `src/rrotate.c` implement and print allowed instructions.

4. **Bonus checker**
   - `bonus/checker_bonus.c` reads instructions with `get_next_line`, applies silent operations, and prints success/failure based on final stack state.

## Installation / Build

```bash
git clone <your-repository-url>
cd push_swap
make HEADERS=./include
```

Optional bonus build:

```bash
make bonus HEADERS=./include
```

Build system details:
- Compiler: `cc`
- Flags: `-Wall -Wextra -Werror`
- Uses local `libft/` via the project Makefile.

## Usage

Mandatory program:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

Count operations:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

Bonus checker:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## Example

```bash
$ ./push_swap 3 2 1
ra
sa

$ ARG="3 2 1"; ./push_swap $ARG | ./checker $ARG
OK
```

Note: in this repository, `checker` prints `OK`/`KO` with ANSI colors and additional ASCII art.

Example invalid input:

```bash
$ ./push_swap 0 one 2
Error
```

## Project Structure

```text
push_swap/
├── Makefile
├── Push_swap.pdf
├── include/
│   └── push_swap.h
├── src/
│   ├── push_swap.c
│   ├── parsing.c
│   ├── stack_init.c
│   ├── algo.c
│   ├── algo_what_action.c
│   ├── algo_do_action.c
│   ├── good_place.c
│   ├── ft_sort_three.c
│   ├── swap.c push.c rotate.c rrotate.c
│   └── free.c lst_utils.c lst_utils2.c stack_init_utils.c
├── bonus/
│   ├── checker_bonus.c
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   └── cheler_utils_bonus.c
└── libft/
```

## What I learned

- Designing a constrained sorting algorithm where operation count matters as much as correctness.
- Building a robust C parser with strict validation and deterministic error handling.
- Using doubly linked lists to implement stack primitives safely.
- Comparing several move strategies and selecting the cheapest one at runtime.
- Structuring a C project with clean module separation (`parsing`, `algorithm`, `operations`, `bonus checker`).
