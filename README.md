# Movie Diary (Linked List in C++)

## Overview
A menu-driven C++ application that allows users to track movies they have watched,
store ratings, and organize entries using a manually implemented linked list.

This project demonstrates core data structure concepts, pointer manipulation,
file persistence, and algorithmic sorting.

---

## Features
- Singly linked list implemented using pointers
- Add, remove, and update movie entries
- Sort movies by:
  - Title
  - Year viewed
  - Rating
- Persistent storage using file I/O
- Dynamic memory allocation and cleanup
- Console-based user interface

---

## Data Structures & Concepts
- **Data Structure:** Singly Linked List
- **Concepts:**
  - Pointer manipulation
  - Dynamic memory management
  - List traversal
  - Insertion and deletion
  - Selection-style sorting on linked lists
  - File I/O

---

## Technologies
- Language: C++
- Libraries: `<iostream>`, `<fstream>`, `<string>`, `<cstdlib>`

---

## How to Run
1. Clone the repository
2. Compile the program:

g++ src/main.cpp -o movieDiary

3. Run:

./movieDiary


---

## What This Project Demonstrates
- Manual implementation of linked lists without STL containers
- Safe handling of dynamic memory
- Sorting and searching operations on linked data structures
- Practical application of data structures in a real-world scenario

---

## Future Improvements
- Replace raw pointers with smart pointers
- Use STL containers for comparison
- Improve input validation
- Modularize sorting logic
