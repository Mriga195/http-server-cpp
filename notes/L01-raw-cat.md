# L01: File descriptors

Date: 2026-11-04

## What I learned
- **fd (file descriptor)**: a plain integer Linux gives you when you open something. You use it in every call after that. Sockets are fds too.
- Every program starts with 3 fds already open:
  | fd | What |
  |---|---|
  | `0` | keyboard (input) |
  | `1` | screen (output) |
  | `2` | screen, for errors |
- Linux always gives the **lowest free number**, so the first file you open gets `3`.
- Reading a file:
  ```
  1. open   → get fd   (-1 = failed, e.g. file not found)
  2. read   → get n    (n = bytes read)
  3. n is 0 → end of file, stop
  4. n is -1 → error, stop
  5. write n bytes (not the array size!) to fd 1
  6. repeat from 2
  7. close
  ```
- Loop with `while (n > 0)`. That stops for **both** `0` (end) and `-1` (error). `n != 0` loops forever on an error.
- Return `0` = success, `1` = failure (Linux reads this).

## Key calls
| Call | What it does | Gives back | Header |
|---|---|---|---|
| `open("f", O_RDONLY)` | open a file for reading | fd, or `-1` | `<fcntl.h>` |
| `read(fd, buf, size)` | copy up to `size` bytes into `buf` | bytes read, `0` = end, `-1` = error | `<unistd.h>` |
| `write(fd, buf, n)` | send `n` bytes from `buf` | bytes written | `<unistd.h>` |
| `close(fd)` | free the fd | `0`, or `-1` | `<unistd.h>` |

## Exercises
- `L01-raw-cat.cpp`: my own `cat`, using only open/read/write/close.
- `L01b-fd-numbers.cpp`: opened 3 times and got `3 4 5`. Closed 4, opened again and got `4` back.
- `L01c-fd-limit.cpp`: opened without closing until it failed.

## What broke when I broke it on purpose
- **Wrong file name + `while (n != 0)`**: `open` gave `-1`, `read` gave `-1` forever, and the loop never ended.
- **Old fd after close**: `fd2` still held `4` after `close(fd2)`, and the next `open` got `4` again. Reading `fd2` would quietly read the **new** file. **Rule: never use an fd after `close`.**
- **Never closing**: `open` failed after ~524k files. That matches `ulimit -n` = 524288, minus 0/1/2, minus 2 fds my shell left open (38, 103), plus 1 because my counter also counted the failed open.
  → Programs **inherit open fds** from whatever started them (`ls -l /proc/self/fd` shows them).

## Interview questions I can now answer
- **Q:** What is a file descriptor?
  **A:** An integer the OS gives a process to refer to an open file or socket.
- **Q:** What are fds 0, 1, 2?
  **A:** stdin, stdout, stderr.
- **Q:** What does `read` returning 0 mean?
  **A:** End of file (for a socket: the other side closed the connection).
- **Q:** What happens if you never close fds?
  **A:** You hit the per-process limit (`ulimit -n`) and `open` starts failing. This is called an fd leak.

## Still unclear
-
