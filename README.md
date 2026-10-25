# HTTP Server from Scratch (C++17, Linux)

A static-file HTTP/1.1 server with a custom thread pool, written by hand to learn
sockets, concurrency and OS fundamentals.

## Rules
- I write every line of code. AI explains concepts and reviews; it never writes the code.
- Read the matching section of [Beej's Guide](https://beej.us/guide/bgnet/) after each lesson.
- Commit after every milestone.

## Build
```
make NAME=echo_server      # compiles src/echo_server.cpp -> build/echo_server
```

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
