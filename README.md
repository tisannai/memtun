# Memtun - Memory Tunnel

Memory Tunnel provides an interface to Custom Memory Managers,
CMM. The idea is to make the type of memory manager transparent to the
user. It can also be used to collect statistics of memory access
pattern and various other memory access instrumentations.

Memtun provides an interface for memory allocation and de-allocation
features. It does not define nor restrict how CMM is setup and
destroyed.


See Doxygen docs and `memtun.h` for details about Memtun API. Also
consult the test directory for usage examples.


## Memtun API documentation

See Doxygen documentation. Documentation can be created with:

    shell> doxygen .doxygen


## Examples

All functions and their use is visible in tests. Please refer `test`
directory for testcases.


## Building

Ceedling based flow is in use:

    shell> ceedling

Testing:

    shell> ceedling test:all

User defines can be placed into `project.yml`. Please refer to
Ceedling documentation for details.


## Ceedling

Memtun uses Ceedling for building and testing. Standard Ceedling files
are not in GIT. These can be added by executing:

    shell> ceedling new memtun

in the directory above Memtun. Ceedling prompts for file
overwrites. You should answer NO in order to use the customized files.
