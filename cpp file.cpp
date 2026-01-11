#include "header.h"

// Template Specialization
template class Resource<int>;
template class Resource<float>;

// Additional Game Functions
void loadGame(const std::string& filename, Kingdom& kingdom) {
    std::ifstream file(filename);
    if (!file) throw GameException("Failed to load game");
    int pop, gold;
    file >> pop >> gold;
    // Implement full loading logic
    file.close();
}