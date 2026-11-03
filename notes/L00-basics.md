# L00: Networking basics

Date: 2026-11-04

## What I learned
- **IP address**: which computer. `127.0.0.1` means "this computer" (localhost).
- **Port**: which program on that computer. A program claims a port and receives the data sent to it.
  - IP + port together give one exact place: `127.0.0.1:9000` = "the program using port 9000 on my laptop".
- **TCP** works like a phone call: **connect → send/receive → close**. Nothing gets lost, and data arrives in the order it was sent.
- **Handshake**: 3 quick messages that set up the connection *before* any data moves. The OS does it for you when you call `connect`.
  ```
  client: "can I connect?"   [S]
  server: "yes"              [S.]
  client: "ok, starting"     [.]
  ```
- **Client** = the side that calls (browser, `nc 127.0.0.1 9000`).
  **Server** = the side that waits for calls on a port (`nc -l 9000`, a website).
- **Socket** = your program's "phone". The OS hands it to you as a plain number (like `3`), and you pass that number to every call: `send(3, ...)`, `close(3)`.

## Key concepts
| Name | What it does |
|---|---|
| `socket()` | Ask the OS for a socket (get a number back) |
| `bind()` | Server: claim a port ("give me whatever arrives at port 9000") |
| `listen()` | Server: start waiting for clients |
| `accept()` | Server: take the next client who connected |
| `connect()` | Client: call a server (the handshake happens here) |
| `send()` / `recv()` | Send / receive data |
| `close()` | Hang up |

## What I tried
- Terminal 1: `nc -l 9000` (server). Terminal 2: `nc 127.0.0.1 9000` (client).
- What I typed in either terminal appeared in the other, so data goes **both ways**.

## What broke when I broke it on purpose
- **Client with no server running**: `nc -v 127.0.0.1 9000` → **"Connection refused"**.
  No one owns port 9000, so the OS refuses and the handshake never happens.
- **Two servers on the same port**: normally this fails with **"Address already in use"**.
  My `nc` (openbsd-netcat) turns on a setting that allows port sharing, so both worked. My own server won't have that setting.

## Useful commands
- `ss -tlnp`: list every program waiting for connections and the port it uses.
- `nc -l PORT`: be a server. `nc -v IP PORT`: be a client (`-v` shows errors).

## Interview questions I can now answer
- **Q:** What's the difference between an IP address and a port?
  **A:** The IP picks the computer, the port picks the program on it.
- **Q:** What does "Connection refused" mean?
  **A:** Nothing is listening on that port, so the handshake was rejected.
- **Q:** What is the TCP handshake?
  **A:** 3 messages (SYN, SYN-ACK, ACK) that set up a connection before any data is sent.

## Still unclear
-
