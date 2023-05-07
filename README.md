# DynamoRIO

DynamoRIO is a runtime code manipulation system that supports code transformations on any part of a program, while the program is executed. 

DynamoRIO exports an interface for building dynamic tools for a wide variety of uses: program analysis and understanding, profiling, instrumentation, optimization, translation, etc.

## Arch

DynamoRIO operates in user mode on a target process. It acts as a process virtual machine, interposing between the application and the operating system. 
DynamoRIO has a complete view of the application code stream and acts as a runtime control point, allowing custom tools to be embedded inside it.

## Build

```
$ cmake -DCMAKE_BUILD_TYPE=Debug -S  . -B ./build
$ cd build && make && cd ../
# OR
$ cmake -DCMAKE_BUILD_TYPE=Debug -S  ./ -B ./build && pushd build && make && popd
```

## Run It
```shell
$ source .envrc && ${DR_HOME}/bin64/drrun -c ./bin/client -- ls
```
## Samples

- https://github.com/DynamoRIO/dynamorio/tree/master/api/samples

# Tutorials

[] API Usage Tutorial - https://dynamorio.org/API_tutorial.html

# Resources

- https://dynamorio.org

- https://dynamorio.org/overview.html

- https://css.csail.mit.edu/6.858/2010/labs/dr-docs/using.html#sec_build

- https://css.csail.mit.edu/6.858/2010/labs/dr-docs/API_samples.html

- (LOCAL) file:///home/kimchi/git-repos/Pavel-Durov/dynamorio.exp/docs/css.csail.mit.edu/6.858/2010/labs/dr-docs/index.html
 