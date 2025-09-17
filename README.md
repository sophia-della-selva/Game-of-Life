# Game of Life (C++)

This is a C++ implementation of **Conway's Game of Life**, a cellular automaton where cells on a grid live, die, or reproduce based on their neighbors. Alive cells are represented with `*` and dead cells with `.`.

---

## Features

- Handles custom grid sizes
- Simulates a specified number of generations
- Outputs the final state of the grid

---

## How It Works

1. The program reads three integers from standard input:
   - `m` → number of rows
   - `n` → number of columns
   - `g` → number of generations to simulate
2. The next `m` lines contain `n` characters each (`*` for alive, `.` for dead), representing the initial grid.
3. The program updates the grid according to Conway's rules:
   - Any live cell with fewer than 2 or more than 3 live neighbors dies
   - Any live cell with 2 or 3 live neighbors survives
   - Any dead cell with exactly 3 live neighbors becomes alive
4. After simulating `g` generations, the final grid is printed to the console.

---

## Input Example
```bash
5 5 3
. * * * .
. * . * .
. * * * .
. . . . .
. . . . .

```

- First line: `5 5 3` → 5 rows, 5 columns, 3 generations.  
- Following lines: initial grid state.

---

## Output Format Example
```markdown
. . . . .
. * . * .
. * * * .
. . . . .
. . . . .
```


- Displays the final grid state after simulating the generations.

---

## How to Compile and Run
```bash
g++ game_of_life.cpp -o game_of_life
./game_of_life
```
