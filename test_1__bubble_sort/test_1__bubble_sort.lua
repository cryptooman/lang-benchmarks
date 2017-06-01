--[[    
    time lua5.3 test_1__bubble_sort.lua
    ...
    repeats: 100000000
    arr[0(1)]: 0 2 2 3 4 5 6 7 8 9
    arr[1(2)]: 0 2 3 4 5 7 8 8 8 9
    swaps: 2025095867

    real    17m45.346s
    user    17m44.956s
    sys     0m0.092s
--]]

REPEATS_MAX = 100000000 -- 100M
SORT_SIZE = 10

function bubbleSort(arr, size)
    local swaps = 0
    local tmp = nil
    for i = 1, SORT_SIZE do
        for j = 1, SORT_SIZE - 1 do
            if arr[j] > arr[j + 1] then
                tmp = arr[j]                 
                arr[j] = arr[j + 1]                
                arr[j + 1] = tmp
                swaps = swaps + 1
            end            
        end                
    end
    return swaps
end

math.randomseed(os.time())

swaps = 0
unsorted = {}
unsorted[1] = {}
unsorted[2] = {}

for repeats = 1, REPEATS_MAX do    
    -- Make array to sort: {
    --     {x1, ..., x10},
    --     {y1, ..., y10}
    -- }    
    for i = 1, SORT_SIZE do
        unsorted[1][i] = math.random(0, 2147483647) % 10
        unsorted[2][i] = math.random(0, 2147483647) % 10
    end
    
    n = (math.random(0, 2147483647) % 2) + 1            
    swaps = swaps + bubbleSort(unsorted[n], SORT_SIZE)
    
    if repeats % 1000000 == 0 then
        print("repeats: " .. repeats)
    end
end

-- Result sort
bubbleSort(unsorted[1], SORT_SIZE)
bubbleSort(unsorted[2], SORT_SIZE)

io.write("arr[0(1)]:")
for i = 1, SORT_SIZE do
    io.write(" " .. unsorted[1][i])
end

io.write("\narr[1(2)]:")
for i = 1, SORT_SIZE do
    io.write(" " .. unsorted[2][i])
end

print("\nswaps: " .. swaps)
