/* Erik Martin
 * u0915261
 * A1: C++ Starter
 * This program simulates the classic predator-and-prey population interaction.
 */

#include <iostream>

using namespace std;

void updatePopulation(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes);
void chartValues(double numRabbits, double numFoxes, double scale);
void incrementCounter(int *counter);
void plotCharacter(int num, char character);

// Initializes variables and receives starting values from the user.
int main() {
  // Initialize variables
  double rabbitGrowth = 0.2;
  double predationRate = .002;
  double foxPreyConversion = .65;
  double foxMortalityRate = .2;
  double carryCapacity = 1000.0;

  // Get starting values for rabbits and foxes
  cout << "Please enter the starting number of rabbits and foxes." << endl;
  double numRabbits, numFoxes;
  if(cin >> numRabbits >> numFoxes) {
    // If the inputs are both doubles, do the simulation
    for (int counter = 1; counter <= 500; ) {
      chartValues(numRabbits, numFoxes, 0.1);
      updatePopulation(rabbitGrowth, carryCapacity, predationRate, foxMortalityRate, foxPreyConversion, numRabbits, numFoxes);
      incrementCounter(&counter);
    }
  }
  else {
    // If either input is not a double, terminate program
    cout << "Invalid input." << endl;
    return 0;
  }
}

// Performs the calculations required to update the rabbit and fox populations each step of the simulation
void updatePopulation(double g, double K, double p, double m, double c, double &numRabbits, double &numFoxes) {
  double deltaRabbit = (g * numRabbits * (1 - (numRabbits / K))) - (p * numRabbits * numFoxes);
  double deltaFoxes = (c * p * numRabbits * numFoxes) - (m * numFoxes);
  numRabbits += deltaRabbit;
  numFoxes += deltaFoxes;
}

// Charts the values as 'r' and 'F', given a certain scale, to make the data fit the window
void chartValues(double numRabbits, double numFoxes, double scale) {
  int rabbitPos = (int)(numRabbits * scale);
  int foxPos = (int)(numFoxes * scale);
  if(rabbitPos == foxPos) {
    // If the 'F' and 'r' would overlap, just draw a '*'.
    plotCharacter(rabbitPos, '*');
  }
  else if(rabbitPos > foxPos) {
    // If the 'F' comes before the 'r'
    plotCharacter(foxPos, 'F');
    plotCharacter(rabbitPos-foxPos, 'r');
  }
  else {
    // If the 'r' comes before the 'F'
    plotCharacter(rabbitPos, 'r');
    plotCharacter(foxPos-rabbitPos, 'F');
  }
  // Add an endline so the graph actually makes sense
  cout << endl;
}

// Increments the step counter for the simulation
void incrementCounter(int *counter) {
  *counter += 1;
}

// Plots a given character by sending num-1 spaces then the character to std::cout
void plotCharacter(int num, char character) {
  char space = ' ';
  for(int j = 1; j < num; j++) {
    cout << space;
  }
  cout << character;
}
