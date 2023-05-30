# optional args: $arg0=frame count, $arg1=start frame ptr
define setbt
  if $argc < 1
    set var $max=5
  else
    set var $max=$arg0
  end
  if $argc < 2
    set var $myfp=$ebp
  else
    set var $myfp=$arg1
  end
  set var $count=0
  while $count < $max && $myfp != 0
    if $count == 1
      set var $esp = $myfp
    end
    if $count == 2
      set var $ebp = $myfp
    end
    printf "\nframe %d\n", $count
    x/4dx $myfp
    info line * *((long*)($myfp+sizeof(long)))
    x/2i *((long*)($myfp+sizeof(long)))
    set var $myfp=*((long *)$myfp)
    set var $count=$count+1
  end
  bt
end
