# IRC Server Project

## Table of Contents
- [Introduction](#introduction)
- [General Rules](#general-rules)
- [Mandatory Part](#mandatory-part)
  - [Arguments](#arguments)
  - [External functions](#external-functions)
  - [Execution](#execution)
- [Requirements](#requirements)
- [Usage](#usage)
## Introduction
Internet Relay Chat (IRC) is a text-based communication protocol on the Internet. It offers real-time messaging that can be either public or private. Users can exchange direct messages and join group channels. IRC clients connect to IRC servers in order to join channels. IRC servers are connected together to form a network.

## General Rules
- Your program should not crash in any circumstances (even when it runs out of memory), and should not quit unexpectedly.
- You have to turn in a Makefile which will compile your source files. It must not relink.
- Your Makefile must at least contain the rules: `$(NAME)`, `all`, `clean`, `fclean` and `re`.
- Compile your code with `c++` and the flags `-Wall -Wextra -Werror`.
- Your code must comply with the C++ 98 standard.Then, it should still compile
if you add the flag -std=c++98.
- Try to always develop using the most C++ features you can (for example, choose
<cstring> over <string.h>). You are allowed to use C functions, but always prefer
their C++ versions if possible.
- Any external library and Boost libraries are forbidden

## Mandatory Part

### Arguments:
- **port**: The listening port
- **password**: The connection password

### External functions:
Everything in C++ 98 including `socket`, `close`, `setsockopt`, `getsockname`, `getprotobyname`, `gethostbyname`, `getaddrinfo`, `freeaddrinfo`, `bind`, `connect`, `listen`, `accept`, `htons`, `htonl`, `ntohs`, `ntohl`, `inet_addr`, `inet_ntoa`, `send`, `recv`, `signal`, `sigaction`, `lseek`, `fstat`, `fcntl`, `poll` (or equivalent).

### Execution:
Your executable will be run as follows:
./ircserv <port> <password>

- **port**: The port number on which your IRC server will be listening to for incoming IRC connections.
- **password**: The connection password. It will be needed by any IRC client that tries to connect to your server.

## Requirements
- The server must be capable of handling multiple clients at the same time and never hang.
- Forking is not allowed. All I/O operations must be non-blocking.
- Only one `poll()` (or equivalent) can be used for handling all these operations (read, write, but also listen, and so forth).
- Several IRC clients exist. You have to choose one of them as a reference. Your reference client will be used during the evaluation process.
- Your reference client must be able to connect to your server without encountering any error.
- Communication between client and server has to be done via TCP/IP (v4 or v6).
- Using your reference client with your server must be similar to using it with any official IRC server. However, you only have to implement the following features:
  - Authenticate, set a nickname, a username, join a channel, send and receive private messages.
  - All messages sent from one client to a channel have to be forwarded to every other client that joined the channel.
  - You must have operators and regular users.
  - Implement commands that are specific to channel operators:
    - `KICK`: Eject a client from the channel
    - `INVITE`: Invite a client to a channel
    - `TOPIC`: Change or view the channel topic
    - `MODE`: Change the channel’s mode:
      - `i`: Set/remove Invite-only channel
      - `t`: Set/remove the restrictions of the TOPIC command to channel operators
      - `k`: Set/remove the channel key (password)
      - `o`: Give/take channel operator privilege
      - `l`: Set/remove the user limit to channel

## Usage
```bash
./ircserv <port> <password>
