
Part 1:

To add a new systemcall to the systemcall table: 
goto linux-4.17/arch/x86/entry/syscalls/syscall_64.tbl in your directory

This file has the following format
<number> <abi> <name> <entry point>
333  common    hello_kernel    sys_hello_kernel
Add a new dummy systemcall in this file.

----------------------------------------
----------------------------------------
Now, edit linux-4.17/include/linux/syscalls.h

To this, add:

asmlinkage int sys_hello_kernel(void); //Line 894

-----------------------------------------------
----------------------------------------------
Now add the actual code to linux-4.17/mm/mmap.c

function name: sys_hello_kernel(void)

using a printk to add it to dmesg --Removed it afterwards

---------------------------------------------
---------------------------------------------

linux-4.17/include/linux/syscalls.h   

added asmlinkage int sys_hello_kernel(void); to line 735

--------------------------------------------
All Set, now compile
---------------------------------------------
make menuconfig
make -j
run compile kernel
