```
==31==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6020000000c8 
This line states that the error detected is a heap-buffer-overflow, and the address of the error is 0x6020000000c8.


address 0x6020000000c8 
    at pc 0x00000034836f 
    bp 0x7ffc9bb2a1a0 
    sp 0x7ffc9bb2a198
This line states the program counter (PC) address, the base pointer (BP) address and the stack pointer (SP) address where the error occurred.


READ of size 4 at 0x6020000000c8 thread T0
This line states that the error occurred during a read operation of size 4 bytes at the address 0x6020000000c8, and the thread where the error occurred is T0


#9 0x7f5f8a8200b2 (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
This line indicates the call stack of the error. This line states that the error occurred in the 9th call in the call stack and the function is located at 0x7f5f8a8200b2 in the library libc.so.6 and the offset is 0x270b2


0x6020000000c8 is located 8 bytes to the left of 8-byte region [0x6020000000d0,0x6020000000d8)
This line states that the error occurred 8 bytes before the start of an 8-byte memory region.


allocated by thread T0 here:
    #8 0x7f5f8a8200b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
This line states that the memory region where the error occurred was allocated by thread T0
This line indicates the call stack of the allocation. This line states that the allocation occurred in the 8th call in the call stack and the function is located at 0x7f5f8a8200b2 in the library libc.so.6 and the offset is 0x270b2

Shadow bytes around the buggy address:
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff8000: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
=>0x0c047fff8010: fa fa fd fd fa fa fd fa fa[fa]00 fa fa fa 00 fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa

Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==31==ABORTING

Shadow bytes around the buggy address: - This line is showing the memory layout around the error address. The memory layout is represented by the shadow bytes, where each byte represents 8 application bytes. The buggy address is marked with the => sign.

The next few lines show the memory layout around the error address, where each line represents a 16-byte region. The memory layout is represented using the following legend:

Addressable: 00 : the memory is accessible
Partially addressable: 01 02 03 04 05 06 07 : the memory is partially accessible
Heap left redzone: fa : the memory is a left redzone of heap
Freed heap region: fd : the memory is a freed heap region
Stack left redzone: f1 : the memory is a left redzone of stack
Stack mid redzone: f2

```





=================================================================
==31==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x6020000000c8 at pc 0x00000034836f bp 0x7ffc9bb2a1a0 sp 0x7ffc9bb2a198
READ of size 4 at 0x6020000000c8 thread T0
    #9 0x7f5f8a8200b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
0x6020000000c8 is located 8 bytes to the left of 8-byte region [0x6020000000d0,0x6020000000d8)
allocated by thread T0 here:
    #8 0x7f5f8a8200b2  (/lib/x86_64-linux-gnu/libc.so.6+0x270b2)
Shadow bytes around the buggy address:
  0x0c047fff7fc0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fd0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7fe0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff7ff0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x0c047fff8000: fa fa fd fa fa fa fd fa fa fa fd fa fa fa fd fa
=>0x0c047fff8010: fa fa fd fd fa fa fd fa fa[fa]00 fa fa fa 00 fa
  0x0c047fff8020: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8030: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8040: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8050: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x0c047fff8060: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==31==ABORTING