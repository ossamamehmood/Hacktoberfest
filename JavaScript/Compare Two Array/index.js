const compareEqualsArray = (a, b) => {
  if (a.length !== b.length) return false
  const uniqueValues = new Set([...a, ...b])
  for (const v of uniqueValues) {
    const aCount = a.filter((e) => e === v).length
    const bCount = b.filter((e) => e === v).length
    if (aCount !== bCount) return false
  }
  return true
}

console.log(compareEqualsArray(['a', 'b', 'c', 'b'], ['b', 'b', 'c', 'a'])) // Expected true
console.log(compareEqualsArray(['a', 'b', 'c', 'b'], ['d', 'c', 'c', 'a'])) // Expected false
console.log(compareEqualsArray(['a', 'b', 'c', 'b'], ['b', 'c', 'a'])) // Expected false
