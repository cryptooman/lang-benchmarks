<?php
/*
php5.5 test_2__bubble_sort.php5
Doing unsorted_list_100.txt                                                                                                                                                                                       
sorting time, sec: 0.004532
result slice [1, 10]:   0 0 0 0 0 0 0 1 1 1                                                                                                                                                                       
result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9                                                                                                                                                                       
swaps: 2619                                                                                                                                                                                                       
                                                                                                                                                                                                                  
Doing unsorted_list_1k.txt                                                                                                                                                                                        
sorting time, sec: 0.138487
result slice [1, 10]:   0 0 0 0 0 0 0 0 0 0                                                                                                                                                                       
result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9                                                                                                                                                                       
swaps: 226375                                                                                                                                                                                                     
                                                                                                                                                                                                                  
Doing unsorted_list_10k.txt                                                                                                                                                                                       
sorting time, sec: 13.726343
result slice [1, 10]:   0 0 0 0 0 0 0 0 0 0                                                                                                                                                                       
result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9                                                                                                                                                                       
swaps: 22698501                                                                                                                                                                                                   
                                                                                                                                                                                                                  
Doing unsorted_list_100k.txt                                                                                                                                                                                      
sorting time, sec: 1980.483579
result slice [1, 10]:   0 0 0 0 0 0 0 0 0 0                                                                                                                                                                       
result slice [n-10, n]: 9 9 9 9 9 9 9 9 9 9                                                                                                                                                                       
swaps: 2247498217
*/
define('TESTS_COUNT', 4);
$TESTS = array(
    "unsorted_list_100.txt",
    "unsorted_list_1k.txt",
    "unsorted_list_10k.txt",
    "unsorted_list_100k.txt"
);

function bubbleSort(array &$arr, $size) {
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

function runSortTest($listFilePath) {
    $unsorted = preg_split('//', file_get_contents($listFilePath), -1, PREG_SPLIT_NO_EMPTY);    
    $len = count($unsorted);
    
    $tStart = microtime(true);
    $swaps = bubbleSort($unsorted, $len);
    $tEnd = microtime(true);
    
    printf("sorting time, sec: %.6f\n" , $tEnd - $tStart);
    
    printf("result slice [1, 10]:   %s\n", join(' ' , array_slice($unsorted, 0, 10)));    
    printf("result slice [n-10, n]: %s\n", join(' ' , array_slice($unsorted, $len - 10, 10)));        
    
    printf("swaps: %d\n", $swaps);    
}

for ($i = 0; $i < TESTS_COUNT; $i++) {
    printf("Doing %s\n", $TESTS[$i]);
    runSortTest($TESTS[$i]);        
    printf("\n");
}
