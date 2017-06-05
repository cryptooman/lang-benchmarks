/*
go build -o test_2__bubble_sort__go.bin test_2__bubble_sort.go
./test_2__bubble_sort__go.bin
Doing unsorted_list_100.txt
sorting time, sec: 64.085µs
result slice [1, 10]: [0 0 0 0 0 0 0 1 1 1]
result slice [n-10, n]: [9 9 9 9 9 9 9 9 9 9]
swaps: 2619

Doing unsorted_list_1k.txt
sorting time, sec: 5.504724ms
result slice [1, 10]: [0 0 0 0 0 0 0 0 0 0]
result slice [n-10, n]: [9 9 9 9 9 9 9 9 9 9]
swaps: 226375

Doing unsorted_list_10k.txt
sorting time, sec: 289.610582ms
result slice [1, 10]: [0 0 0 0 0 0 0 0 0 0]
result slice [n-10, n]: [9 9 9 9 9 9 9 9 9 9]
swaps: 22698501

Doing unsorted_list_100k.txt
sorting time, sec: 29.995606008s
result slice [1, 10]: [0 0 0 0 0 0 0 0 0 0]
result slice [n-10, n]: [9 9 9 9 9 9 9 9 9 9]
swaps: 2247498217
*/
package main

import (
    "fmt"
    "os"
    "io/ioutil"
    "time"
)

var TESTS = []string{
    "unsorted_list_100.txt",
    "unsorted_list_1k.txt",
    "unsorted_list_10k.txt",
    "unsorted_list_100k.txt" }

func err(e error) {
    if (e != nil) {
        fmt.Printf("Error: %v\n", e)        
        os.Exit(1)
    }
}
    
func bubbleSort(arr *[]int, size int) int {
    var swaps int = 0
    var tmp int
    var i, j int
    for i = 0; i < size; i++ {
        for j = 0; j < size - 1; j++ {
            if ((*arr)[j] > (*arr)[j + 1]) {
                tmp = (*arr)[j]
                (*arr)[j] = (*arr)[j + 1]
                (*arr)[j + 1] = tmp                
                // OR: Tuple swap goes ~ %1 faster
                // (*arr)[j], (*arr)[j + 1] = (*arr)[j + 1], (*arr)[j]                
                swaps++
            }
        }
    }
    return swaps
}

func runSortTest(unsortedListFile string) {        
    res, e := ioutil.ReadFile(unsortedListFile)
    err(e)        
    
    unsortedStr := string(res)
          
    var size = len(unsortedStr)
    var unsorted = make([]int, size)
    for i := 0; i < size; i++ {
        unsorted[i] = int(unsortedStr[i] - '0')
    }
    
    tStart := time.Now()
    swaps := bubbleSort(&unsorted, size)
    tEnd := time.Now()
    
    fmt.Printf("sorting time, sec: %v\n", tEnd.Sub(tStart))
    
    fmt.Printf("result slice [1, 10]: %v\n", unsorted[0:10])
    fmt.Printf("result slice [n-10, n]: %v\n", unsorted[len(unsorted)-10:])
    
    fmt.Printf("swaps: %v\n", swaps)
}

func main() {
    for i := 0; i < len(TESTS); i++ {
        fmt.Printf("Doing %v\n", TESTS[i])
        runSortTest(TESTS[i])
        fmt.Println("")
    }
}
