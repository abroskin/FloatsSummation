# FloatsSummation
Simple algorithm for summing floats.

# Details
Effectively works only with not negative values.
Modifies an input vector.

# Algorithm
Creates a heap on an input vector.
On each iteration pops two lowest numbers, sums them and push result back to the heap.

# Complexity
Runtime complexity - O(log n)
Memory complexity - O(1)
