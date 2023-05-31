# Equivalent to windbg's dps command.
# Pass it the stack pointer range: [start, end)
define dps
  set var $start = (char *) $arg0
  set var $end = (char *) $arg1
  set var $ptr = $start
  while $ptr < $end
    set var $retaddr = *((unsigned long *)$ptr)
    # I don't like how %p prints "(nil)" so:
    if sizeof(void*) == 8
      printf "0x%016lx  0x%016lx  ", $ptr, $retaddr
    else
      printf "0x%08x  0x%08x  ", $ptr, $retaddr
    end
    # We have to cast to void* to avoid gdb failing to properly evaluate
    # $retaddr (ends up using value from 1st iter on each iter).
    #
    # XXX: can we get the result of this into a var and not print it
    # if it says "No symbol matches..."?
    info symbol (void *)$retaddr
    set var $ptr = $ptr + sizeof(void*)
  end
end
