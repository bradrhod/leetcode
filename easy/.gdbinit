set pagination off
set confirm off
set print pretty on
set print array on
set print array-indexes on
set print elements 200

set history save on
set history filename .gdb_history
set history size 1000

layout src
break main

define hook-stop
  info args
  info locals
end
