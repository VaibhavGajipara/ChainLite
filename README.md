#  ChainLite – Blockchain Simulation Using Linked Lists (C++)

ChainLite is a **console-based blockchain simulation project** developed using **C++** as part of my **Data Structures coursework**.  
The project demonstrates the core working principles of a blockchain, including **block hashing, proof-of-work mining, chain validation, and linked list traversal**.

---

##  Project Objective

The objective of ChainLite is to understand and implement the **fundamental data structures and algorithms** behind blockchain technology by:
- Using **linked lists** to store blocks
- Implementing **hash-based block integrity**
- Simulating **proof-of-work mining**
- Validating blockchain consistency

---

##  Features

-  Blockchain implemented using **singly linked list**
-  Hash generation using SHA-like hashing logic
-  Proof-of-Work mining with adjustable difficulty
-  Genesis block creation
-  Blockchain integrity validation
-  Detailed block inspection and traversal

---

##  Technologies & Concepts Used

- **Language:** C++  
- **Data Structures:** Linked List  
- **Core Concepts:**  
  - Hashing  
  - Proof-of-Work  
  - Blockchain fundamentals  
  - Dynamic memory management  
- **Libraries Used:**  
  - `<functional>` for hashing  
  - `<ctime>` for timestamps  
  - `<sstream>` for hash construction  

---

##  System Design Overview

- **Block Class**
  - Stores block data, timestamp, nonce, hashes
  - Handles hash calculation and mining process

- **Blockchain Class**
  - Manages the linked list of blocks
  - Handles block insertion, validation, and traversal
  - Maintains chain integrity using previous hash references

---

##  Learning Outcomes

- Gained a strong understanding of **blockchain architecture and fundamentals**
- Implemented **linked lists** to store and traverse blockchain data
- Learned how **hashing ensures data integrity** in a blockchain
- Implemented **proof-of-work mining** using a nonce-based approach
- Understood **block validation and chain consistency checks**
- Improved skills in **dynamic memory management** in C++
- Strengthened problem-solving skills through real-world system simulation

---

##  Future Enhancements

- Replace the basic hashing logic with a **real SHA-256 implementation**
- Add **Merkle Tree** support for efficient transaction verification
- Implement **transaction pools (mempool)** and block rewards
- Introduce **blockchain forks and consensus simulation**
- Add **file-based persistence** to store blockchain data
- Optimize mining performance and difficulty adjustment
- Develop a **graphical user interface (GUI)** for better visualization

---

##  How to Run the Project

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/ChainLite.git
