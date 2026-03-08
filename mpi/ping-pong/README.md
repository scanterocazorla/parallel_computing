# MPI Ping-Pong Communication

This program measures the communication latency between two MPI processes using a ping-pong message exchange.

Process 0 sends a message to process 1, and process 1 sends the same message back. This exchange is repeated several times to compute the average transmission time.

## Description

- Two processes communicate using MPI.
- A message of size `n` bytes is exchanged between them.
- The exchange is repeated multiple times to measure the average time per message.

The implementation uses `MPI_Sendrecv` for bidirectional communication.
