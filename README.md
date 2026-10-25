# HTTP Server from Scratch (C++17, Linux)

A static-file HTTP/1.1 server with a custom thread pool, written by hand to learn
sockets, concurrency and OS fundamentals.

## Rules
- I write every line of code. AI explains concepts and reviews; it never writes the code.
- Read the matching section of [Beej's Guide](https://beej.us/guide/bgnet/) after each lesson.
- Commit after every milestone.

## Folder layout
```
exercises/   one standalone practice file per lesson
server/      the real project; grows from Lesson 4 onward
notes/       my notes, one file per lesson (copy notes/_template.md)
build/       compiled binaries (git-ignored)
```

## Naming rules
| What | Pattern | Example |
|---|---|---|
| Exercise | `exercises/LNN-short-name.cpp` | `exercises/L02-echo-server.cpp` |
| Notes | `notes/LNN-short-name.md` (same name as the exercise) | `notes/L02-echo-server.md` |
| Server files | `server/snake_case.cpp` / `.hpp`, one job per file | `server/thread_pool.hpp` |
| Commit | `LNN: what changed` | `L02: echo server accepts one client` |
| Git tag | `lesson-NN` when a lesson is done | `lesson-02` |

`NN` is always two digits (`00`–`10`). Names are lowercase with hyphens.

## Workflow for every lesson
1. **Learn:** get the lesson explanation, then read the Beej's Guide section.
2. **Notes:** `cp notes/_template.md notes/LNN-short-name.md` and fill in "What I learned".
3. **Code:** write `exercises/LNN-short-name.cpp` yourself.
4. **Build and run:** `make run L=NN`.
5. **Review:** paste the code for review; fix the issues yourself.
6. **Finish notes:** bugs hit, interview Q&A, anything still unclear.
7. **Commit and tag:** `git add -A && git commit -m "LNN: ..." && git tag lesson-NN`.
8. **Tick** the lesson in the Progress table below.

From Lesson 4, steps 3–4 also apply to `server/` (`make server`, then `./build/server`).

## Progress
| Lesson | Topic | Done |
|---|---|---|
| 0 | IP, ports, TCP; what a socket is | [ ] |
| 1 | File descriptors | [ ] |
| 2 | Echo server: socket, bind, listen, accept | [ ] |
| 3 | Client: connect; testing with nc and curl | [ ] |
| 4 | HTTP request format and parsing | [ ] |
| 5 | Serving files, headers, 404 | [ ] |
| 6 | Threads | [ ] |
| 7 | Mutex, race conditions, condition variables | [ ] |
| 8 | Thread pool | [ ] |
| 9 | RAII wrappers, graceful shutdown | [ ] |
| 10 | Benchmarking with wrk | [ ] |

## Benchmarks
_Fill in after Lesson 10._

## Notes
My own notes per lesson live in `notes/`.
