<?php
/*
    time php7.0 test_1__bubble_sort.php
    ...
    repeats: 100000000
    arr[0]: 1 2 2 2 3 4 5 6 8 8
    arr[1]: 0 3 3 3 3 4 4 6 7 9
    swaps: 2025036284

    real    11m2.026s
    user    11m1.728s
    sys     0m0.084s
*/
define('REPEATS_MAX', 100000000); // 100M
define('SORT_SIZE', 10);

function bubbleSort(array &$arr, int $size): int {
    $swaps = 0;
    $tmp = null;
    for ($i = 0; $i < $size; $i++) {
        for ($j = 0; $j < $size - 1; $j++) {
            if ($arr[$j] > $arr[$j + 1]) {
                $tmp = $arr[$j];
                $arr[$j] = $arr[$j + 1];
                $arr[$j + 1] = $tmp;
                $swaps++;
            }
        }
    }    
    return $swaps;   
}

$unsorted = [];
$swaps = 0;

for ($repeats = 0; $repeats < REPEATS_MAX; $repeats++) {     
    // Make array to sort: {
    //     {x1, ..., x10},
    //     {y1, ..., y10}
    // };
    for ($i = 0; $i < SORT_SIZE; $i++) {
        $unsorted[0][$i] = rand() % 10;
        $unsorted[1][$i] = rand() % 10;
    }
    
    $n = rand() % 2;
    $swaps += bubbleSort($unsorted[$n], SORT_SIZE);
                
    if (($repeats + 1) % 1000000 == 0) {
        echo 'repeats: ' . ($repeats + 1) . "\n";
    }
}

// Result sort
bubbleSort($unsorted[0], SORT_SIZE);
bubbleSort($unsorted[1], SORT_SIZE);
        
echo "arr[0]:";
for ($i = 0; $i < SORT_SIZE; $i++) {
    echo ' ' . $unsorted[0][$i];
}

echo "\narr[1]:";
for ($i = 0; $i < SORT_SIZE; $i++) {
    echo ' ' . $unsorted[1][$i];
}

echo "\nswaps: $swaps\n";
