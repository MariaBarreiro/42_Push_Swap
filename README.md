![Score](https://img.shields.io/badge/Score-92.4%25_C-lightgrey) ![Makefile](https://img.shields.io/badge/Makefile-7.6%25-lightgrey)

# Push_swap

> *Stack-based sorting algorithm challenge*
> *Optimize instructions for minimal operations*

---

## Table of Contents

* [About 📌](#about)
* [Setup 🛠️](#setup)
* [Rules 📖](#rules)
* [Benchmark 📊](#benchmark)
* [Program ⚙️](#program)

---

## About 📌

**push_swap** is an algorithmic project where you sort integers using exactly two stacks (`a` and `b`) and a very limited instruction set. The core challenge is to **minimize the number of operations** while guaranteeing a correct sort for all valid inputs. You’ll practice algorithmic complexity, careful parsing, memory management, and rigorous C coding. 

---

## Setup 🛠️

1. **Language**: C (no globals, respect the 42 Norm).
2. **Makefile**: Must include rules `$(NAME)`, `all`, `clean`, `fclean`, `re` (and `bonus` if you implement checker).
3. **Compiler flags**: `-Wall -Wextra -Werror`, compiler `cc`.
4. **Libft**: Allowed — copy sources + Makefile into `libft/` and build from your project’s Makefile. 

---

## Rules 📖

* **Initial state**:
  * Stack **a**: a random amount of **unique** integers (can be negative).
  * Stack **b**: empty.
* **Goal**: sort **a** in ascending order using the fewest operations.

**Allowed operations** (each printed one per line):
- `sa`, `sb`, `ss` — swap top two
- `pa`, `pb` — push top between stacks
- `ra`, `rb`, `rr` — rotate up
- `rra`, `rrb`, `rrr` — reverse rotate down

**Errors** → print `Error\n` to **stderr** (non-integers, overflows, duplicates, bad instruction, etc.). 

---

## Benchmark 📊

To fully validate the project (100%) and qualify for bonus:  
- **100 numbers** → **< 700** operations  
- **500 numbers** → **≤ 5500** operations  

Minimum validation (80%) can be reached with one of these average pairs:  
- **100 ≤ 1100** and **500 ≤ 8500**  
- **100 ≤ 700** and **500 ≤ 11500**  
- **100 ≤ 1300** and **500 ≤ 5500**  

---

## Program ⚙️

### `push_swap`
* **Input**: list of integers forming **stack a** (first arg = top of the stack).
* **Output**: the **shortest** valid instruction sequence to sort `a` (each on its own line).
* **No output** when no parameters.
* **Constraints**: no globals; no unexpected quits (SEGV, double free, …); no memory leaks.
* **Failure**: if the sequence is longer than allowed limits or result isn’t sorted, grade = 0. 

**Example**
```bash
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa

