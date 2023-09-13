#ifndef __ASSIGNMENT_VECTOR_OPERATIONS_HH__
#define __ASSIGNMENT_VECTOR_OPERATIONS_HH__

#include "params/VectorOperations.hh"
#include "sim/sim_object.hh"
#include <vector>

namespace gem5
{
  
class VectorOperations : public SimObject
{
public:
    VectorOperations(const VectorOperationsParams &params);
    void startup() override;

private:
    // Events for SimObject
    EventFunctionWrapper crossProductEvent;
    EventFunctionWrapper normalizeEvent;
    EventFunctionWrapper subtractionEvent;
    // event handlers
    void execEventCrossProduct();
    void execEventNormalize();
    void execEventSubtraction();
    // Parameters for vector operations
    std::vector<float> vectorA;
    std::vector<float> vectorB;
    // Parameters for tick rates
    Tick crossProductTick;
    Tick normalizeTick;
    Tick subtractionTick;
};
}
#endif // __ASSIGNMENT_VECTOR_OPERATIONS_HH__
