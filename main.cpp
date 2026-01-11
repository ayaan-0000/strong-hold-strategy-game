#include "header.h"

int main() {
    srand(time(0));
    Kingdom* kingdom = nullptr;

    try {
        kingdom = new Kingdom();
        int choice;

        while (!kingdom->isGameOver()) {
            std::cout << "\n=== STRONGHOLD ==="
                << "\n1. Collect Taxes\n2. Train Army\n3. Save Game\n4. Quit\nChoice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                kingdom->handleTaxes();
                break;
            case 2: {
                int recruits;
                std::cout << "Enter recruits: ";
                std::cin >> recruits;
                kingdom->trainArmy(recruits);
                break;
            }
            case 3:
                kingdom->saveGame("save.txt");
                break;
            case 4:
                kingdom->saveGame("autosave.txt");
                delete kingdom;
                return 0;
            default:
                std::cout << "Invalid choice!\n";
            }

            // Random event chance
            if (rand() % 4 == 0) kingdom->randomEvent();
        }
    }
    catch (const GameException& e) {
        std::cerr << "Fatal error: " << e.what() << "\n";
        delete kingdom;
        return 1;
    }

    delete kingdom;
    return 0;
}