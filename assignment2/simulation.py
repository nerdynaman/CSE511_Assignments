import m5
from m5.objects import *

# Create the VectorOperations SimObject with parameters
vector_ops = VectorOperations(
    vectorA="1.0 2.0 3.0",   # Modify vector values as needed
    vectorB="4.0 5.0 6.0",   # Modify vector values as needed
    crossTick=1500,      # Modify tick rates as needed
    normalizeTick=150,        # Modify tick rates as needed
    subtractionTick=15000      # Modify tick rates as needed
)
# vector_ops = VectorOperations() #for default values
# Set the VectorOperations SimObject as the simulation root
root = Root(full_system=False)
root.vector_ops = vector_ops

# Instantiate the simulation
m5.instantiate()

print("Beginning simulation!")
exit_event = m5.simulate()
print('Exiting @ tick {} because {}'.format(m5.curTick(), exit_event.getCause()))
