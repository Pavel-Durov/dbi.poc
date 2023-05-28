source scripts/gdb/gdb-memquery.py

# run this command within gdb before running the app to ensure success:
set disable-randomization off

# gdb breakpoints in the loader can interfere with the dlopen() execution, ignore them via:
handle SIGSEGV nostop pass
handle SIGBUS nostop pass

# symbols
set confirm off
add-symbol-file ./build/libhello_world_client.so
add-symbol-file ~/tools/DrMemory-Linux-2.5.0/dynamorio/lib64/debug/libdynamorio.so
add-symbol-file '/lib/x86_64-linux-gnu/libc.so.6' 0x00007f1528280320
add-symbol-file '/lib64/ld-linux-x86-64.so.2' 0x00007f15285b6090

# source commands
source scripts/gdb/dps_cmd.gdb 
source scripts/gdb/setbt_cmd.gdb
source scripts/gdb/setbt64_cmd.gdb
