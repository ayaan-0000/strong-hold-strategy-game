<h1 align="center">🏰 Stronghold — Console Kingdom Management Game</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" />
  <img src="https://img.shields.io/badge/OOP-Templates%20%7C%20Inheritance%20%7C%20Polymorphism-blueviolet?style=for-the-badge" />
</p>

<p align="center"><b>A console strategy game built to demonstrate object-oriented programming principles in a real, interactive system.</b></p>

---

## 📖 Project Explanation

Players manage a kingdom turn by turn — collecting taxes, training an army, saving progress, and responding to random in-game events.

```
=== STRONGHOLD ===
1. Collect Taxes
2. Train Army
3. Save Game
4. Quit
```

A generic `Resource<T>` template class manages quantities such as gold and population with safe addition and subtraction operations. An abstract `Leader` base class defines tax collection and economy handling as pure virtual methods, allowing different leadership behaviors to be implemented through inheritance. A custom `GameException` class, derived from `std::runtime_error`, is thrown on invalid actions such as overspending and is caught centrally in the main game loop. Game state can be saved to and loaded from disk between sessions.

## 🛠️ Tech Stack

<p>
  <img src="https://img.shields.io/badge/Language-C%2B%2B17-00599C?style=flat-square&logo=c%2B%2B" />
  <img src="https://img.shields.io/badge/Design-Templates%20%7C%20Abstract%20Classes-informational?style=flat-square" />
</p>

## 🧩 Things Used

- **C++ Templates** — `Resource<T>` generalizes over `int`/`float` resource quantities
- **Abstract base classes & pure virtual functions** — `Leader` hierarchy for polymorphic leadership behavior
- **Custom exception hierarchy** — `GameException` derived from `std::runtime_error`
- **File I/O** — save/load game state to disk

## 📂 Project Structure

```
.
├── main.cpp            # Game loop and menu handling
├── resource.h           # Resource template and Leader class hierarchy
├── Bank.h                # Banking subsystem
├── army.h                 # Army management subsystem
├── economy.h               # Economic simulation subsystem
├── politics.h                # Political event subsystem
├── population.h               # Population management subsystem
├── SocialStructure.h            # Social hierarchy subsystem
└── taxPolicy.h                    # Tax policy subsystem
```

## 🚀 Build & Run

```bash
g++ -std=c++17 main.cpp -o stronghold
./stronghold
```

## ⭐ Honest Review

**Strengths:** The `Resource<T>` template and the `Leader` abstract class hierarchy are well-designed pieces of OOP — using templates for resource quantities rather than separate int/float classes is a genuinely good instinct, and the custom exception type shows an understanding of proper error handling rather than just returning error codes.

**Areas for improvement:** Several of the subsystem headers (banking, army, economy, politics, population, and social structure) are scaffolded but not yet fully fleshed out with their own logic — bringing each of those up to the same depth as the `resource.h` design would turn this from a promising foundation into a genuinely complete strategy game. Once those subsystems are filled in, this has real potential to be one of the standout C++ projects on the profile, since the architectural bones are already solid.

## 👤 Author

Ayaan Amir — Object-Oriented Programming coursework project.

## 📄 License

MIT
