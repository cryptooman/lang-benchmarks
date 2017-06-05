# lang-benchmarks
Various programming languages benchmarks
<pre>
# test_1__bubble_sort: Repeatable bubble sort + random number

            Time            Rate
--------------------------------
C           0m33.312s       1.0

Go1.6       1m27.046s       2.61

PHP7.0      11m2.026s       19.8

Lua5.3      17m45.346s      31.9

Perl5.2     53m6.818s       95.6

CPU: 4 x Intel(R) Core(TM) i7-3770 CPU @ 3.40GHz
     cpu MHz         : 3392.292
     cache size      : 8192 KB
     flags           : .. lm .. (64-bit)
     
OS: Ubuntu 16.04.1 LTS

# test_2__bubble_sort: Bubble sort

            100 items       1K          10K         100K        Rate (100K)
---------------------------------------------------------------------------
C           0.000034s       0.0020s     0.1678s     15.72s      1.0

Go1.6       0.000064s       0.0055s     0.2896s     29.99s      1.9

Lua5.3      todo

Perl5.2     todo

PHP7.0      0.002378s       0.097389s   9.36s       965.14s     61.3

PHP5.5      0.004532s       0.138487s   13.72s      1980.48s    125.9

CPU: 4 x Intel(R) Core(TM) i7-3770 CPU @ 3.40GHz
     cpu MHz         : 3392.292
     cache size      : 8192 KB
     flags           : .. lm .. (64-bit)
     
OS: Ubuntu 16.04.1 LTS
</pre>