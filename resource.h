#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

// Exception Classes
class GameException : public std::runtime_error {
public:
    using std::runtime_error::runtime_error;
};

// Template Resource Class
template <typename T>
class Resource {
    T quantity;
public:
    Resource(T initial = 0) : quantity(initial) {}
    void add(T amount) { quantity += amount; }
    void subtract(T amount) {
        if (amount > quantity) throw GameException("Insufficient resources");
        quantity -= amount;
    }
    T get() const { return quantity; }
};

// Leader Hierarchy
class Leader {
protected:
    std::string name;
    float taxRate;
public:
    Leader(const std::string& n) : name(n), taxRate(0.2f) {}
    virtual ~Leader() = default;
    virtual void collectTaxes(Resource<int>& gold) = 0;
    virtual void handleEconomy() = 0;
};

class King : public Leader {
public:
    King(const std::string& n) : Leader(n) {}
    void collectTaxes(Resource<int>& gold) override {
        gold.add(static_cast<int>(1000 * taxRate));
    }
    void handleEconomy() override { taxRate += 0.05f; }
};

// Army Class
class Army {
    int soldiers;
    bool isTraining;
public:
    Army() : soldiers(0), isTraining(false) {}

    void train(int recruits) {
        if (isTraining) throw GameException("Training already in progress");
        isTraining = true;
        std::cout << "Training " << recruits << " soldiers...\n";
        std::this_thread::sleep_for(std::chrono::seconds(recruits));
        soldiers += recruits;
        isTraining = false;
    }

    int getCount() const { return soldiers; }
};

// Kingdom Class
class Kingdom {
    Resource<int> food;
    Resource<int> gold;
    Resource<int> weapons;
    Army army;
    Leader* leader;
    int population;
    bool gameOver;

public:
    Kingdom() : population(1000), gameOver(false) {
        leader = new King("Arthur");
        food.add(500);
        gold.add(1000);
        weapons.add(200);
    }

    ~Kingdom() { delete leader; }

    void handleTaxes() {
        try {
            leader->collectTaxes(gold);
        }
        catch (const GameException& e) {
            std::cerr << "Tax error: " << e.what() << "\n";
        }
    }

    void trainArmy(int recruits) {
        try {
            if (recruits > population / 10) throw GameException("Not enough population");
            army.train(recruits);
            population -= recruits;
        }
        catch (const GameException& e) {
            std::cerr << "Army error: " << e.what() << "\n";
        }
    }

    void saveGame(const std::string& filename) {
        std::ofstream file(filename);
        if (!file) throw GameException("Failed to save game");
        file << population << " " << gold.get();
        file.close();
    }

    void randomEvent() {
        int event = rand() % 3;
        switch (event) {
        case 0:
            population -= 100;
            std::cout << "Plague outbreak!\n";
            break;
        case 1:
            gold.add(500);
            std::cout << "Found treasure!\n";
            break;
        case 2:
            army.train(10);
            std::cout << "Mercenaries join!\n";
            break;
        }
    }

    bool isGameOver() const { return gameOver; }
};