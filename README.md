# Learning C++ — small practice projects

This workspace contains small, self-contained C++ programs used while learning core C++ concepts (I/O, arrays, functions, control flow, simple algorithms).

Why these projects
- banking.cpp: practice functions, passing/returning values, simple state.
- quiz.cpp: practice arrays of strings, nested loops, basic user input and scoring.
- RPS.cpp: practice randomness, input validation, and modular functions.
- sort.cpp: practice algorithms (bubble sort) and array manipulation.

Build and run
- Compile a single file:
  - g++ -std=c++17 banking.cpp -o banking
  - g++ -std=c++17 quiz.cpp -o quiz
  - g++ -std=c++17 RPS.cpp -o RPS
  - g++ -std=c++17 sort.cpp -o sort
- Run:
  - ./banking
  - ./quiz
  - ./RPS
  - ./sort

Tips for extending these exercises
- Add input validation and error handling (check std::cin after reads).
- Move repeated logic into helper functions and headers.
- Replace C-style arrays with std::vector or std::array.
- Add unit tests for pure functions (sorting, win-logic).
- Instrument code with comments explaining each step.

Where to look in this workspace
- [banking.cpp](banking.cpp)
- [quiz.cpp](quiz.cpp)
- [RPS.cpp](RPS.cpp)
- [sort.cpp](sort.cpp)
- [search.cpp](search.cpp)
- Binary/artifact files (may be non-text): [banking](banking), [quiz](quiz), [RPS](RPS), [search](search), [sort](sort)

Keep iterating: pick one file, add a small feature, compile, run, then read and refactor. Good progress comes from many small, focused experiments.