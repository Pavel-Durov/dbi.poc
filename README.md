# DynamoRIO

DynamoRIO is a runtime code manipulation system that supports code transformations on any part of a program, while the program is executed. 

DynamoRIO exports an interface for building dynamic tools for a wide variety of uses: program analysis and understanding, profiling, instrumentation, optimization, translation, etc.

## Arch

DynamoRIO operates in user mode on a target process. It acts as a process virtual machine, interposing between the application and the operating system. 
DynamoRIO has a complete view of the application code stream and acts as a runtime control point, allowing custom tools to be embedded inside it.


## Samples

- https://github.com/DynamoRIO/dynamorio/tree/master/api/samples

# Tutorials

[] API Usage Tutorial - https://dynamorio.org/API_tutorial.html

# Resources

- https://dynamorio.org

- https://dynamorio.org/overview.html

