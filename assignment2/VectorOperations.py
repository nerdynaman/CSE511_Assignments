from m5.params import *
from m5.SimObject import SimObject

class VectorOperations(SimObject):
	type = "VectorOperations"
	cxx_header = "assignment/VectorOperations.hh"
	cxx_class = "gem5::VectorOperations"
	# Parameters
	# Add parameters for vector values and tick values
	vectorA = Param.String("1.0 2.0 3.0","Initial values for vector A")
	vectorB = Param.String("1.0 2.0 3.0","Initial values for vector B")
	crossTick = Param.Int(150, "Tick for Cross event")
	normalizeTick = Param.Int(1500, "Tick for Normalize event")
	subtractionTick = Param.Int(15000, "Tick for Subtraction event")
