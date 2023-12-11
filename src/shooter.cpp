//
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::ostream;

#include "shooter.h"
#include "roll.h"

std::ostream &operator<<(ostream &os, const Shooter &shooter)
{
    os << " Shooter Overload Rolls : ";
    for (const Roll *roll : shooter.rolls)
    {
        os << "  " << roll->roll_value();
        //        std::cout << " Q3 - :" << roll;
    }
    return os;
}
