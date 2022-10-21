qs :: [Int] -> [Int]
qs [] = []
qs (x:xs) = [v | v <- qs xs, v <= x] ++ [x] ++ [v | v <- qs xs, v > x]
