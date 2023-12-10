//

#ifndef POINT_PHASE_H
#define POINT_PHASE_H

#include "phase.h"

class PointPhase : public Phase
{
public:
    // Constructor
    PointPhase(int p);

    // Implementation of get_outcome for PointPhase
    RollOutcome get_outcome(Roll *roll) const override;

private:
    int point;
};

#endif // POINT_PHASE_H