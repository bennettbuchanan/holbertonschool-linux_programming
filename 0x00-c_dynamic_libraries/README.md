`1-create_dynamic_lib.sh`: Find all files with the suffix .c in the current
working directory and use them to create a shared object file, `liball.so`, 
in the current working directory. `liball.so` can be linked with additional 
objects to create an executable program.

Note: The shared object is compiled using the `-fpic` option.
