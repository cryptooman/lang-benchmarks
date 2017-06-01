/*
    go build -o test_1__bubble_sort__go test_1__bubble_sort.go
    time ./test_1__bubble_sort__go 
    ...
    repeats:  100000000
    arr[0]: 0 0 1 1 2 3 4 6 9 9
    arr[1]: 0 1 1 2 4 5 5 6 7 9
    swaps: 2024951328

    real    1m27.046s
    user    1m27.056s
    sys     0m0.052s
*/
package main
import "fmt"
import "math/rand"
import "time"

const REPEATS_MAX = 100000000 // 100M
const SORT_SIZE int = 10

func bubbleSort(arr *[SORT_SIZE]int, size int) int {
    var swaps int = 0
    var tmp int
    for i := 0; i < size; i++ {
        for j := 0; j < size - 1; j++ {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = tmp
                swaps++
            }                
        }
    }
    return swaps
}

func main() {        
    rand.Seed(time.Now().UTC().UnixNano())
    
    var unsorted [2][SORT_SIZE]int
    var swaps int = 0
    
    for repeats := 0; repeats < REPEATS_MAX; repeats++ {        
        // Make array to sort: {
        //     {x1, ..., x10}, 
        //     {y1, ..., y10}
        // }
        for i := 0; i < SORT_SIZE; i++ {
            unsorted[0][i] = rand.Int() % 10;
            unsorted[1][i] = rand.Int() % 10;
        }
        
        var n int = rand.Int() % 2
        swaps += bubbleSort(&unsorted[n], SORT_SIZE)
        
        if ((repeats + 1) % 1000000 == 0) {
            fmt.Println("repeats: ", repeats + 1)
        }        
    }

    // Result sort
    bubbleSort(&unsorted[0], SORT_SIZE)
    bubbleSort(&unsorted[1], SORT_SIZE)
    
    fmt.Print("arr[0]:")
    for i := 0; i < SORT_SIZE; i++ {
        fmt.Printf(" %d", unsorted[0][i])
    }
    
    fmt.Print("\narr[1]:")
    for i := 0; i < SORT_SIZE; i++ {
        fmt.Printf(" %d", unsorted[1][i])
    }
        
    fmt.Printf("\nswaps: %d\n", swaps)    
}
