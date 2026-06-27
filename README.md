# 🏰 Stronghold — Console Kingdom Management Game (C++ / OOP)

A console-based strategy game inspired by *Stronghold*, built to demonstrate core Object-Oriented Programming concepts: inheritance, polymorphism, templates, custom exception handling, and save/load via file I/O.

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Inheritance%20%7C%20Polymorphism%20%7C%20Templates-blueviolet)

## What it does
Run a kingdom turn-by-turn: collect taxes, train your army, save your progress, and respond to random events — all while managing resources that throw custom exceptions if you overspend.

```
=== STRONGHOLD ===
1. Collect Taxes
2. Train Army
3. Save Game
4. Quit
```

## OOP concepts demonstrated
- **Templates** — a generic `Resource<T>` class manages quantities of gold, population, etc. with safe add/subtract operations.
- **Inheritance & polymorphism** — an abstract `Leader` base class defines `collectTaxes()` / `handleEconomy()` as pure virtual methods for subclasses to implement.
- **Custom exceptions** — `GameException` (derived from `std::runtime_error`) is thrown on invalid actions like overspending resources, and caught at the top level in `main()`.
- **File I/O** — game state can be saved to / loaded from disk (`save.txt`, `autosave.txt`).

## Project structure
```
.
├── main.cpp            # Game loop: menu, turn handling, random events
├── resource.h           # Resource<T> template + abstract Leader hierarchy + GameException
├── Bank.h / army.h / economy.h / politics.h / population.h / SocialStructure.h / taxPolicy.h
│                        # Subsystem headers (currently stubs — see TODO below)
└── cpp file.cpp          # Template instantiations + save/load helper functions
```

## How to run
> ⚠️ **Before building:** `main.cpp` and `cpp file.cpp` both `#include "header.h"`, which isn't present in the repo yet — you'll need to add a `header.h` that pulls together the `Kingdom` class and the other subsystem headers before this compiles. See TODO below.

```bash
g++ -std=c++17 main.cpp -o stronghold
./stronghold
```

## Known issues / TODO (honest status)
This project is mid-build rather than finished — worth completing before showcasing it:
- `header.h`, referenced by both `.cpp` files, is missing from the repo — the project won't compile as-is until it's added.
- `Bank.h`, `SocialStructure.h`, `army.h`, `economy.h`, `politics.h`, `population.h`, and `taxPolicy.h` currently only contain `#pragma once` — they're placeholders, not implemented subsystems yet, despite the project description suggesting a full strategy game.
- `cpp file.cpp` has a space in its filename — rename to something like `extras.cpp`.

**Recommendation:** either finish wiring up `header.h` + the subsystem classes (this could be a genuinely strong OOP showcase once complete — the `Resource<T>` template and exception design are already solid), or keep this repo private until it's in a demoable state.

## License
Add a license (MIT recommended) if you'd like others to reuse this.
