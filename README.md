# So_long

simple 2D game developed with [the minilibx](https://github.com/42Paris/minilibx-linux), the graphical library for 42 Projects.

## The Project

Create the programs `so_long`.

This program takes the path to the map file with the `.ber` extension as input from the command line argument. The map must be formatted as the following rules.

- The map must be composed of only 5 possible characters:

  | Character | Object |
  | - | - |
  | 1 | Wall. |
  | 0 | Empty space. |
  | C | Collectable. |
  | E | Exit. |
  | P | Player starting position. |

- The map must be surrounded by walls.
- The map has at least one exit, collectible, and starting position.
- The map must be rectangular.

If any misconfiguration of any kind is encountered in the file, the program
must exit properly and return "Error\n" followed by an explicit error message.

When the map is properly formatted, this program launches a 2D game.
- The player must be able to move: up, down, left, right by WASD key.
- Pressing ESC close the window and quit the program.

### misc
- I can use `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`,
  `strerror`, `exit`, and all functions of the Minilibx,
  and other normal libc functions are forbidden.
    - [Man page of minilibx](https://github.com/42Paris/minilibx-linux/tree/master/man) and [the document](https://harm-smits.github.io/42docs/libs/minilibx) some 42 students made is very helpful.
- In no way can it quit abruptly.
  (segmentation fault, bus error, double free, etc).
- All heap allocated memory space must be properly freed when necessary.
  No leaks will be tolerated.
- Global variables are forbidden.
- All code must conform to the [42 Norm](https://github.com/42School/norminette).

## Usage

![](./demo.gif)

Clone this repository and run `make`, and make the executable file `so_long`.

This program is used as follows :
```bash
./so_long path_to_map_file
```

Then enjoy the game!!!

## Author

[Twitter](https://twitter.com/t76_1205)

## Licence

[MIT](./LICENSE)