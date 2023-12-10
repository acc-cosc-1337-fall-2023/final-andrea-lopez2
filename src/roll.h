//
#include "die.h"

#ifndef ROLL_H
#define ROLL_H

class Roll
{
public:
    Roll(); // default constructor
    // Constructor with initializer list to initialize die1 and die2
    Roll(Die &d1, Die &d2) : die1(d1), die2(d2){};
    void roll_die();
    // Returns the value of the roll
    int roll_value() const { return value; };

private:
    Die &die1; // Reference to the first Die
    Die &die2; // Reference to the second Die
    bool rolled = false;
    int value; // Saves rolled values die1 + die2
};

#endif

