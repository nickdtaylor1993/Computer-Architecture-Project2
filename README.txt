Author:Nicholas Taylor
/*****************************************************************Testing Documentation****************************************************************\
*****************************
Test1:
*****************************
Using the input file: testInputCapacity.txt 
Using the config files: configTestCapacity.txt and configTestCapacity2.txt 
I test when using two
configuration files when capacity changes what the performance of the cache
results in. 

subTest1: capacity:128, block_size:32, assoc:1
RESULT: ./pdriver configTestCapacity.txt testInputCapacity.txt 
Addr: 256
printContents
******SET 0 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 2 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 384
printContents
******SET 0 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 2 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 576
printContents
******SET 0 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 288
printContents
******SET 0 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 416
printContents
******SET 0 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 480
printContents
******SET 0 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 3 valid 1 lru 0
*****************
Addr: 256
printContents
******SET 0 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 3 valid 1 lru 0
*****************
Addr: 576
printContents
******SET 0 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 3 valid 1 lru 0
*****************
Addr: 288
printContents
******SET 0 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 3 valid 1 lru 0
*****************
Addr: 480
printContents
******SET 0 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 4 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 3 valid 1 lru 0
*****************
printStatistics
ACCESSES 10
HITS 2
MISSES 8
HIT RATE 0.2

***********************
Test1:
***********************

subTest1:capacity:256, block_size:32, assoc:1
RESULT: ./pdriver configTestCapacity2.txt inputTestCapacity.txt 
Addr: 256
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 2 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 5 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 384
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 2 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 576
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 288
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 416
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 480
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 1 valid 1 lru 0
*****************
Addr: 256
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 1 valid 1 lru 0
*****************
Addr: 576
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 1 valid 1 lru 0
*****************
Addr: 288
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 1 valid 1 lru 0
*****************
Addr: 480
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 4 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 5 ******
Index 0: tag 1 valid 1 lru 0
*****************
******SET 6 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 7 ******
Index 0: tag 1 valid 1 lru 0
*****************
printStatistics
ACCESSES 10
HITS 4
MISSES 6
HIT RATE 0.4


Analysis:
Using these two configuration files for testing the changing of capacity while
leaving block_size and assoc constant results in when changing the capacity
from 128 bytes to 256 bytes to increase its hit rate from 20% to 40%. 
The reason why this is correct is because when you increase the capacity the
number of blocks should increase and since this is a direct mapped cache when
the number of blocks is fewer that results in a higher probability of mapping
to the same set which can lead to evicting lines before a hit occurs. Which
will consequently result in the Cache perform worse.  However when increasing
the capacity the number of blocks increase leading to larger amount of sets
which then allows when addresses map to a set to be able to have a higher
chance of hitting before the address is evicted because of the address
collision. Therefore increasing capacity while other things constant reduces
collisions thus improving hit rate.  This is demonstrated by the output.   


*****************
Test2:
*****************
In this second test I test using two configuration files what the result in
performance of the Cache becomes when changing the block_size while leaving
capacity and associativity the same. 

subTest: Capacity:128, block_size:32, assoc:2
RESULT: ./pdriver configTestBlock_Size.txt inputTestBlocksize.txt
Addr: 60
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
Addr: 62
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
Addr: 75
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
Addr: 80
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
Addr: 98
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
Addr: 115
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
printStatistics
ACCESSES 6
HITS 3
MISSES 3
HIT RATE 0.5

***************
Test2:
***************
subTest: Capacity:128, block_size:64, assoc:2
RESULT: ./pdriver configTestBlock_Size2.txt inputTestBlocksize.txt
Addr: 60
printContents
******SET 0 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
Addr: 62
printContents
******SET 0 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
Addr: 75
printContents
******SET 0 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
Addr: 80
printContents
******SET 0 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
Addr: 98
printContents
******SET 0 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
Addr: 115
printContents
******SET 0 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
printStatistics
ACCESSES 6
HITS 4
MISSES 2
HIT RATE 0.666667

Analysis: In this test using two configuration files I change the block_size
from 32bytes to 64 bytes.  What the output suggest with the block_size first
being 32 bytes results in a hit rate of 50% while increasing the block_size in
the second to 64bytes results in a hit rate of 67%.  The reason behind why
this is the result is because the block_size determines how many bytes from
main memory that is accesses can go within a block using spatial locality of
the 0-nbytes n = 32 or 64.  In the 32 byte example the first memory access
will always result in miss then if using a memory access that is within the
block_size range will always result in a hit.  Thus in my input I made sure to
have the case where each byte address and the next byte address results in being within the block_size range.  
I do this in my test until the last byte address which will not be 
within the same block range but very close.  So when you increase the
block_size to 64 bytes it will result in a pattern of miss then hit 3 times
and then the final byte address being close in the 32 byte example since it is
now 64 bytes will still be included within the block_size range. Thus it will
result in a additional hit. This consequently results in the 4 hits compared
to the only 3 hits in the previous test.  Thus by increasing the block_size
enchances the performance of the cache when dealing with memory accesses that
generally have good spatial locality and even better when there a non
consistent spatial locality if the block_size is large compared to a smaller
block_size.  


***************
Test3:
***************
In this test case I use configuration files which I change the associativity
of the cache while leaving the capacity and block_size constant.  


subTest:Capacity:128, block_size:32: assoc:1
RESULT: ./pdriver testConfigAssoc.txt testInputAssoc.txt 
Addr: 60
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 288
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 2 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 62
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 75
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 448
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 3 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 80
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 0 lru -1
*****************
Addr: 98
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 1 lru 0
*****************
Addr: 480
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 3 valid 1 lru 0
*****************
Addr: 115
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 2 ******
Index 0: tag 0 valid 1 lru 0
*****************
******SET 3 ******
Index 0: tag 0 valid 1 lru 0
*****************
printStatistics
ACCESSES 9
HITS 0
MISSES 9
HIT RATE 0


*********************
Test3:
*********************

SubTest:Capacity:128, block_size:32: assoc:2
RESULT: ./pdriver testConfigAssoc2.txt testInputAssoc.txt

Addr: 60
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
Addr: 288
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 4 valid 1 lru 0
*****************
Addr: 62
printContents
******SET 0 ******
Index 0: tag 0 valid 0 lru -1
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 4 valid 1 lru 1
*****************
Addr: 75
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 0 valid 0 lru -1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 4 valid 1 lru 1
*****************
Addr: 448
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 1
Index 1: tag 7 valid 1 lru 0
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 4 valid 1 lru 1
*****************
Addr: 80
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 7 valid 1 lru 1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 0
Index 1: tag 4 valid 1 lru 1
*****************
Addr: 98
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 7 valid 1 lru 1
*****************
******SET 1 ******
Index 0: tag 0 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
Addr: 480
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 7 valid 1 lru 1
*****************
******SET 1 ******
Index 0: tag 7 valid 1 lru 0
Index 1: tag 1 valid 1 lru 1
*****************
Addr: 115
printContents
******SET 0 ******
Index 0: tag 1 valid 1 lru 0
Index 1: tag 7 valid 1 lru 1
*****************
******SET 1 ******
Index 0: tag 7 valid 1 lru 1
Index 1: tag 1 valid 1 lru 0
*****************
printStatistics
ACCESSES 9
HITS 3
MISSES 6
HIT RATE 0.333333


Analysis: In this test I use configuration files to test what the performance
of the Cache will result in when changing the associativity while leaving
capacity and block_size constant.  The performance from the test where the
cache's associativity is 1 (direct-mapped) has really poor performance with a
hit rate of 0% compared to the 2-way set associative example where the hite
rate is 33%.  The reason why the Cache performs better when increasing the
Associativity is because it reduces the risk of collisions which result in
evictions in the set.  In direct-mapped caches since it only has one block
per set, if a byte address maps to a set and the next byte address would
actually hit the previous address before the one that just replaced the block
the result is a miss. However in a set-associative cache since each set has
multiple blocks within when a byte address and the next address map to the
same set the two address will go into different blocks in the case of misses.
Then if the next byte address hits the address the two byte address will still
remain in the set which will lead to a successful hit in the Set.  This is how
I set my input file making the first two memory addresses map to the same set
then having the third memory address which should hit the first memory address
passed into the Cache either make a hit or miss based on the type of mapping
the Cache has.  That being said having a higher assocaitivity reduces the case 
where collisions occur and thus result in higher chance of a successful hit
compared to Direct-Mapping where collisions are VERY high to occur.  



************************************
PIN TOOL TESTS USING TWO PROGRAMS
good.cpp
heavyAddress.cpp
************************************


PROGRAM ONE TEST
*****************

The program good.cpp demonstrates temporal locality in memory access which allows the 
testing of what happens when changing the associativty from 1 (direct mapping) to 2 (set-associative) 
/**** Direct Map *****\
ACCESSES 1500
HITS 1337
MISSES 163
HIT RATE 0.891333
ACCESS FREQ 0.001159
CPI for miss latency = 10 cycles 1.001259


/**** 2-Set Way Assoc map ****\
ACCESSES 1500
HITS 1495
MISSES 5
HIT RATE 0.996667
ACCESS FREQ 0.001159
CPI for miss latency = 10 cycles 1.000039
The difference is direct map hit rate is 89% and set-assoc is 99% 

NOTE: This program demonstrates my analysis from the test3 section. 

/******************************************************************\

PROGRAM TWO TEST
****************

The program heavyAccess which has many memory accesses test the
difference when changing the line size of a cache and its performance while
maintaining the capacity and associativity. 

first test: config.txt = capacity: 256bytes
	    		 line_size: 64bytes
	    		 associativity: 2

ACCESSES 3750
HITS 3446
MISSES 304
HIT RATE 0.918933
ACCESS FREQ 0.002944
CPI for miss latency = 10 cycles 1.002386


second test: config.txt =  capacity: 256bytes
	     		   line_size: 128bytes
             		   associativity: 2
ACCESSES 3750
HITS 3574
MISSES 176
HIT RATE 0.953067
ACCESS FREQ 0.002944
CPI for miss latency = 10 cycles 1.001382

NOTE: This program demonstrates my analysis from the test2 section. 

The hit rate for test when line_size 64 is: 92% and the hit rate for test when line_size 128 is:95%.
This demonstrates increase in performance when changing the line_size with a program that requires alot of spatial locality accesses usage. 
So when memory addresses are accessed close to each other where occassionally
there is an access where the byte address of the first and the next byte
address the same block in memory size. If you increase the block_size in the
cache then the performance enchances because then  you can have higher amount
of byte addresses that when accessed spatially result in correct hits rather
than misses because there not in the same block range. 



*************
Further notes
*************
From each of these test with configuration files and inputs my Cache correctly
demonstrates from the output the use of multiple cache sets for both
Direct-Mapped and set-associativie caches. 

My test files also demonstrate that when Cache conflicts occur the correct
lines or blocks are evicted.  Again this is demonstrated through the output in
the test cases section.   
