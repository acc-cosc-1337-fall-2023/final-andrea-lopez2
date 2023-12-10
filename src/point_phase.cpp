//


#include "point_phase.h"
#include "roll.h" // Include the Roll class header file

// Constructor implementation
PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll *roll) const
{
    int rolledValue = roll->roll_value();

    if (rolledValue == point)
        return RollOutcome::point;
    else if (rolledValue == 7)
        return RollOutcome::seven_out;
    else
        return RollOutcome::nopoint;
}