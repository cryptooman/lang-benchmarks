
# time perl test_1__bubble_sort.pl
# ...
# repeats: 100000000
# arr[0]: 0 1 1 2 2 5 5 6 7 8
# arr[1]: 1 1 2 3 6 7 7 9 9 9
# swaps: 2024946155
# 
# real    53m6.818s
# user    53m6.012s
# sys     0m0.024s

use strict;

use constant REPEATS_MAX => 100_000_000;
use constant SORT_SIZE => 10;

sub bubbleSort {
    my $arr = $_[0];
    my $size = $_[1];
    
    my $swaps = 0;
    my $tmp;        
    for (my $i = 0; $i < $size; $i++) {
        for (my $j = 0; $j < $size - 1; $j++) {            
            if ($$arr->[$j] > $$arr->[$j + 1]) {
                $tmp = $$arr->[$j];
                $$arr->[$j] = $$arr->[$j + 1];
                $$arr->[$j + 1] = $tmp;
                $swaps++;
            }            
        }
    }    
    $swaps;
}

my @unsorted;
my $swaps = 0;

for (my $repeats = 0; $repeats < REPEATS_MAX; $repeats++) {
    # Make array to sort: {
    #    {x1, ..., x10},
    #    {y1, ..., y10}
    # }
    for (my $i = 0; $i < SORT_SIZE; $i++) {
        $unsorted[0][$i] = rand(2147483647) % 10;
        $unsorted[1][$i] = rand(2147483647) % 10;
    }
    
    my $n = rand(2147483647) % 2;
    $swaps += bubbleSort(\@unsorted[$n], SORT_SIZE);
    
    if (($repeats + 1) % 1000000 == 0) {
        print 'repeats: ' . ($repeats + 1) . "\n";
    }    
}

# Result sort
bubbleSort(\@unsorted[0], SORT_SIZE);
bubbleSort(\@unsorted[1], SORT_SIZE);

print "arr[0]:";
for (0 .. SORT_SIZE - 1) {
    print ' ' . $unsorted[0][$_];
}

print "\narr[1]:";
for (0 .. SORT_SIZE - 1) {
    print ' ' . $unsorted[1][$_];
}

print "\nswaps: $swaps\n";
