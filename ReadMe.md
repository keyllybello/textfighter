# CONSOLE APPLICATION : TextFighter Project Overview
## TextFighter

TextFighter is a simple C++ text-based fighting game that showcases basic object-oriented programming concepts such as classes, constructors, destructors, getters/setters, and random-based combat.

Two fighters, **Ryu** and **Ken**, battle it out over multiple rounds using randomly generated attack values until one of them is knocked out.

---

## Features

- `Fighter` class with:
  - Private health member
  - Constructor & destructor
  - Getter and setter for health
  - `attack()` method that uses `rand()` to generate damage
  - `takeDamage()` method to apply damage
- `playerFight(round)` function to simulate a full round between two fighters
- Three example rounds run from `main()`
- Uses `rand()` with `srand(time(NULL))` to randomize attacks each run

---

## How it works

- Each fighter starts with **100 health**.
- On each turn:
  - Ryu attacks with a random value between **10 and 35**
  - Ken attacks with a random value between **10 and 35**
- Each fighter takes damage equal to the opponent’s attack.
- The round ends when either fighter’s health is `<= 0`.
- The program runs **3 rounds** (`playerFight(1)`, `playerFight(2)`, `playerFight(3)`).

There is also a `TODO` in the code to implement a `superAttack()` method:
- Generates damage between **30 and 50**
- Can only be used when the fighter’s health is **below 15**

---

## Requirements

- C++ compiler (e.g. `g++`, `clang++`, MSVC)
- C++11 or later recommended

---

## How to compile and run

Using `g++`:

```bash
g++ -std=c++11 -o TextFighter TextFighter.cpp
./TextFighter

