#include <iostream>

class Cat {
    int lives; // Cats have 9 lives
public:
    // Construct a Cat with the number of lives
    Cat(int startLives) : lives{startLives} {
        // nothing else to do
    }

    // Reports to cout about the Cat's lives
    void reportLives() {
        std::cout << "This Cat has " << lives << " lives." << std::endl;
    }

    // Decrements the life by 1
    void loseLife() {
        lives--;
    }
};

int main() {
    Cat mittens(9);
    mittens.reportLives();
    mittens.loseLife();
    mittens.loseLife();
    mittens.reportLives();
}
