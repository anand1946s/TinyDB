# TinyDB

TinyDB is a minimal embedded key–value database written in C++ with a terminal-based user interface.  
This project is built to understand **database internals**, not to replace production systems.

No ORM. No magic. Just files, data structures, and control.

---

## Goals

- Learn how databases actually work under the hood
- Implement core DB concepts from scratch:
  - Key–value storage
  - O(1) lookup
  - Binary file persistence
  - Basic crash safety
  - Command parsing

---

## Features

- Key–Value operations: `INSERT`, `FIND`, `DEL`, `LIST`, `UPDATE`,`EXIT`
- Persistent storage using a binary data file
- Periodic flush-to-disk for basic crash safety
- Write operation logging 
- Interactive terminal interface with split-pane layout:
  - Key browser
  - Value inspector
  - Command input bar

---

## Terminal UI

> The UI is intentionally minimal and keyboard-driven.

---

## Project Structure
tinydb/
├── src/
│ ├── main.cpp # Entry point & event loop
│ ├── storage.cpp # Disk persistence logic
│ ├── storage.h
│ ├── commands.cpp # Command parsing
│ ├── commands.cpp 
├── README.md


---

## Status

🚧 **Actively developed**  
Expect breaking changes and rough edges.

---

## License

MIT


