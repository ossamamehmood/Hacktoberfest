calc_primes :: [Int] -> [Int]
calc_primes (a:as) = a : (calc_primes [x | x <- as, mod x a /= 0])

primes :: [Int]
primes = calc_primes [2..]
