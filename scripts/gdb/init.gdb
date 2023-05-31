# Run this command within gdb before running the app to ensure success:
set disable-randomization off
# Gdb breakpoints in the loader can interfere with the dlopen() execution, ignore them via:
handle SIGSEGV nostop pass
handle SIGBUS nostop pass
handle SIGILL nostop pass

# Source files
set confirm off
# add-symbol-file '/home/user/dr/suite/tests/bin/libclient.events.dll.so' 0x00007f14e46143e0
# add-symbol-file '/home/user/dr/lib64/debug/libdynamorio.so' 0x00007f152865c000
add-symbol-file /home/kimchi/tools/DrMemory-Linux-2.5.0/dynamorio/lib64/debug/libdynamorio.so
add-symbol-file '/lib/x86_64-linux-gnu/libc.so.6' 0x00007f1528280320
add-symbol-file '/lib64/ld-linux-x86-64.so.2' 0x00007f15285b6090
