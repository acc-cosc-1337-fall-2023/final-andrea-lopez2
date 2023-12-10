//
#include "roll.h"

#ifndef PHASE_H
#define PHASE_H

enum class RollOutcome
{
    natural,
    craps,
    point,
    seven_out,
    nopoint
};

class Roll; // Forward declaration

class Phase
{
public:
    // Abstract method to get the outcome based on the roll
    virtual RollOutcome get_outcome(Roll *roll) const = 0;

    // Virtual destructor for the abstract class
    virtual ~Phase() = default;
};

#endif // PHASE_H