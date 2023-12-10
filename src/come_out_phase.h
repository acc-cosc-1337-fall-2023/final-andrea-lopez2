//

#ifndef COME_OUT_PHASE_H
#define COME_OUT_PHASE_H

#include "phase.h"

class ComeOutPhase : public Phase
{
public:
    // No constructor

    // Implementation of get_outcome for ComeOutPhase
    RollOutcome get_outcome(Roll *roll) const override;
};

#endif // COME_OUT_PHASE_H