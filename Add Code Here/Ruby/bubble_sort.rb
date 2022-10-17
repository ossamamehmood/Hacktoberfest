def bubble(arr)
    loop until arr.each_cons(2).each_with_index.none? do |(x,y),index|
        arr[index], arr[index+1] = y,x if x > y
    end

    arr
end

data = [9, 2, 4, 44, 99, 10, 0]
p bubble(data) # output: [0, 2, 4, 9, 10, 44, 99]
