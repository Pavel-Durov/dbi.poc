#!/usr/bin/env python

# Stolen from https://raw.githubusercontent.com/DynamoRIO/dynamorio/master/tools/gdb-scripts/gdb-memquery.py
# Searches /proc/self/maps for the line containing a given address.
# Usage:
# 1) Place this line into your ~/.gdbinit:
#    source <path-to>/gdb-memquery.py
# 2) Execute the command in gdb:
#    (gdb) memquery $rsp
#    7ffffffde000-7ffffffff000 rw-p 00000000 00:00 0                          [stack]

try:
    import gdb
except ImportError as e:
    raise ImportError("This script must be run in GDB: ", str(e))
import re
from subprocess import check_output

class MemQueryCommand (gdb.Command):
    """Prints memory address properties"""
    def __init__ (self):
        super (MemQueryCommand, self).__init__ ("memquery",
                                                gdb.COMMAND_DATA,
                                                gdb.COMPLETE_FILENAME)
    def invoke(self, arg, unused_from_tty):
        addr = gdb.parse_and_eval(arg)
        pid = int(gdb.selected_inferior().pid)
        map_name = "/proc/%d/maps" % pid
        with open(map_name,'r') as map:
            for line in map:
                line = line.rstrip()
                if not line: continue
                match = re.match(r'^(\w+)-(\w+)', line)
                if match:
                    start = int(match.group(1), 16)
                    end = int(match.group(2), 16)
                    if addr >= start and addr < end:
                        print(line)
MemQueryCommand()
