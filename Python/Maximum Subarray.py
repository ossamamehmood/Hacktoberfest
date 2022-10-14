def kadanesAlgorithm(array):
  maxAtThisPoint = array[0]
  finalMax = array[0]

  for num in array[1:]:
    maxAtThisPoint = max(num, maxAtThisPoint + num)
    finalMax = max(finalMax, maxAtThisPoint)

  return finalMax