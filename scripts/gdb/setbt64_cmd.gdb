# optional args: $arg0=frame count, $arg1=start frame ptr
define setbt64
  if $argc < 1
    set var $max=5
  else
    set var $max=$arg0
  end
  if $argc < 2
    set var $myfp=$rbp
  else
    set var $myfp=$arg1
  end
  set var $count=0
  while $count < $max && $myfp != 0
    if $count == 1
      set var $rsp = $myfp
    end
    if $count == 2
      set var $rbp = $myfp
    end
    printf "\nframe %d\n", $count
    x/4gx $myfp
    info line * *((long*)($myfp+sizeof(long)))
    x/2i *((long*)($myfp+sizeof(long)))
    set var $myfp=*((long *)$myfp)
    set var $count=$count+1
  end
  bt
end
