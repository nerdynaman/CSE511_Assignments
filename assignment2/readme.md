# Assignment 2
## Introduction
In this assignment we have created a custom SimObject which performs 3 operations on two vectors:
- cross product
- normalization
- subtraction

Results of these operations are printed on screen. Further we have also implemented DEBUG flags to get desired output for particular operation.
- `VECTOR` - prints vector values
- `RESULTSUB` - prints result of subtraction
- `RESULTCROSS` - prints result of cross product
- `NORMALIZE` - prints normalized vector

Above logic was achieved by creating a custom SimObject and then scheduling events for each operation at their corresponding ticks.

## Installation
		git clone https://github.com/gem5/gem5
		cd gem5
		mkdir src/assignment
		mkdir config/assignment
paste all the files in this folder to `src/assignment` folder in gem5 directory and paste `simulation` file in `config/assignment` folder in gem5 directory.

		scons build/ARM/gem5.opt -j9
## Usage
		build/ARM/gem5.opt config/assignment/simulation.py


## SimObject
Custom SimObject was created in file `VectorOpearations.py` named `VectorOperations`. We defined 5 parameters for this object:
- `vectorA` - first vector
- `vectorB` - second vector
- `crossTick` - tick at which cross product was calculated
- `normalizeTick` - tick at which normalization was calculated
- `subtractionTick` - tick at which subtraction was calculated
## logic files
- `VectorOperations.cpp` - contains logic for VectorOperations object
- `VectorOperations.hh` - contains header for VectorOperations object
In the logic file we defined 3 functions:
- `VectorOperations::execEventCrossProduct` - calculates cross product of two vectors
- `VectorOperations::execEventNormalize` - normalizes vector
- `VectorOperations::execEventSubtraction` - subtracts two vectors

Constructor for VectorOperations initializes all tick and vector values as provided through `params`. Furtheron we have defined events for all of these functions mentioned above and these events are connected to their corresponding functions on constructor call.
We are then scheduling all these events at their corresponding ticks inside of `startup` function.

## SConscript
We have registered our custom made `SimObject` along with registering all the debug flags to be used in logic code and provided location for source code for our SimObject.

## Simulation Script
using ```Root(full_system=False)``` we instantiated root object and then instantiated our SimObject `VectorOperations` along with required parameters. Which we further made child of Root object.