//
#include <iostream>
#include <vector>
#include "roll.h"

using std::ostream;

#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
public:
    // Shooter(); // default constructor
    Roll *throw_die(Die &die1, Die &die2)
    {
        Roll *roll = new Roll(die1, die2); // Create a dynamic instance of Roll
        roll->roll_die();                  // Call the roll_die function
        rolls.push_back(roll);             // Add the roll instance to the vector
        return roll;                       // Return the roll instance
    }

    // Overload << operator to output vector of Roll*
    friend std::ostream &operator<<(std::ostream &os, const Shooter &shooter);

    // Destructor to clear memory
    ~Shooter()
    {
        for (Roll *roll : rolls) // Iterate through the rolls vector and delete each roll
        {
            delete roll;
        }
        rolls.clear(); // Clear the vector
    }

private:
    std::vector<Roll *> rolls;
};

#endif
