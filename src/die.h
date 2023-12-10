#include <iostream>
#include <ctime> // for time
#include <cstdlib> // for rand() and srand()
#ifndef DIE_H
#define DIE_H

//

class Die
{
    
    public:  Die()
    {
        // Seed the random number generator with the current time
        srand(static_cast<unsigned int>(time(nullptr)));
    };
    void roll();
    int rolled_value() const{return roll_value;}

    private:
    int roll_value = 0;
    int sides{6};

};

#endif