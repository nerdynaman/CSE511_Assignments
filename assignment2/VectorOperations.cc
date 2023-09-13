#include "debug/VECTOR.hh"
#include "debug/RESULTCROSS.hh"
#include "debug/NORMALIZE.hh"
#include "debug/RESULTSUB.hh"
#include "assignment/VectorOperations.hh"

#include "base/trace.hh"
namespace gem5
{
// Constructor for VectorOperations, initializing the parameters recieved from the simulation script
VectorOperations::VectorOperations(const VectorOperationsParams &params)
    : SimObject(params),
      crossProductEvent([this]{ execEventCrossProduct(); }, name()),
      normalizeEvent([this]{ execEventNormalize(); }, name()),
      subtractionEvent([this]{ execEventSubtraction(); }, name()),
        crossProductTick(params.crossTick),
        normalizeTick(params.normalizeTick),
        subtractionTick(params.subtractionTick)

{
    std::istringstream issA(params.vectorA);
    std::istringstream issB(params.vectorB);

    float valueA, valueB;
    while (issA >> valueA && issB >> valueB) {
        VectorOperations::vectorA.push_back(valueA);
        VectorOperations::vectorB.push_back(valueB);
    }
    DPRINTF(VECTOR, "VectorA: (%f, %f, %f)\n", vectorA[0], vectorA[1], vectorA[2]);
    DPRINTF(VECTOR, "VectorB: (%f, %f, %f)\n", vectorB[0], vectorB[1], vectorB[2]);
}
// Cross product of two vectors
void VectorOperations::execEventCrossProduct()
{
    std::vector<float> resultVector(3, 0.0);

    // Assuming vectorA and vectorB are 3x1 vectors
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        int k = (i + 2) % 3;

        resultVector[i] = VectorOperations::vectorA[j] * VectorOperations::vectorB[k] - VectorOperations::vectorA[k] * VectorOperations::vectorB[j];
    }
    printf("Cross Product Result: (%f, %f, %f)\n", resultVector[0], resultVector[1], resultVector[2]);
    DPRINTF(RESULTCROSS, "Cross Product Result: (%f, %f, %f)\n", resultVector[0], resultVector[1], resultVector[2]);
}
// Normalization of two vectors
void VectorOperations::execEventNormalize()
{
    float magnitudeA = 0.0;
    float magnitudeB = 0.0;

    for (int i = 0; i < 3; ++i) {
        magnitudeA += vectorA[i] * vectorA[i];
        magnitudeB += vectorB[i] * vectorB[i];
    }

    magnitudeA = sqrt(magnitudeA);
    magnitudeB = sqrt(magnitudeB);

    std::vector<float> normalizedVectorA(3, 0.0);
    std::vector<float> normalizedVectorB(3, 0.0);

    for (int i = 0; i < 3; ++i) {
        normalizedVectorA[i] = VectorOperations::vectorA[i] / magnitudeA;
        normalizedVectorB[i] = VectorOperations::vectorB[i] / magnitudeB;
    }

    printf("Normalized VectorA: (%f, %f, %f)\n",normalizedVectorA[0], normalizedVectorA[1], normalizedVectorA[2]);
    printf("Normalized VectorB: (%f, %f, %f)\n",normalizedVectorB[0], normalizedVectorB[1], normalizedVectorB[2]);
    DPRINTF(NORMALIZE, "Normalized VectorA: (%f, %f, %f)\n", normalizedVectorA[0], normalizedVectorA[1], normalizedVectorA[2]);
    DPRINTF(NORMALIZE, "Normalized VectorB: (%f, %f, %f)\n", normalizedVectorB[0], normalizedVectorB[1], normalizedVectorB[2]);

}
// Subtraction of two vectors
void VectorOperations::execEventSubtraction()
{
    std::vector<float> resultVector(3, 0.0);

    for (int i = 0; i < 3; i++) {
        resultVector[i] = VectorOperations::vectorA[i] - VectorOperations::vectorB[i];
    }
    printf("Subtraction Result: (%f, %f, %f)\n",resultVector[0], resultVector[1], resultVector[2]);
    DPRINTF(RESULTSUB, "Subtraction Result: (%f, %f, %f)\n", resultVector[0], resultVector[1], resultVector[2]);

}
// Scheduling the events
void VectorOperations::startup()
{
    schedule(subtractionEvent, subtractionTick);
    schedule(crossProductEvent, crossProductTick);
    schedule(normalizeEvent, normalizeTick);
}

} // namespace gem5