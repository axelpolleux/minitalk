# Minitalk

_This project has been created as part of the 42 curriculum by apolleux_

## Description

Minitalk is a project that explores inter-process communication (IPC) using UNIX signals. The goal is to create a simple communication system between a client and a server using only two signals: `SIGUSR1` and `SIGUSR2`. The client sends a message to the server, which then displays it.

## Instructions

### Compilation

To compile the project, use the provided Makefile:

```bash
make
```

### Usage

1. **Server**: Launch the server in a terminal. It will display its process ID (PID).

```bash
 ./server
```

2. **Client**: Use the client to send a message to the server. Replace `<server_pid>` with the PID displayed by the server and `<message>` with your message.

```bash
 ./client <server_pid> <message>
```

### Example

```bash
# Terminal 1
./server
# Output: Process ID: 12345

# Terminal 2
./client 12345 "Hello, 42!"
```

## Resources

- [UNIX Signals](<https://en.wikipedia.org/wiki/Signal_(IPC)>)
- [kill(2) — Linux manual page](https://man7.org/linux/man-pages/man2/kill.2.html)
- [signal(2) — Linux manual page](https://man7.org/linux/man-pages/man2/signal.2.html)
- [pause(2) — Linux manual page](https://man7.org/linux/man-pages/man2/pause.2.html)
