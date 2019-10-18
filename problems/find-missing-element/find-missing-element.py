def find_missing(original, shuffled):
  """
  Runtime: O(n * log n), Space: O(1)
  """
  original.sort()
  shuffled.sort()
  for i, x in enumerate(shuffled):
    if original[i] != x:
      return x
  return original[-1]

def find_missing2(original, shuffled):
  """
  Runtime: O(n), Space: O(1)
  """
  missing = 0
  for i in original + shuffled:
    missing ^= i
  return missing


print find_missing2([1,2,3,4,5], [4,2,1,3])
print find_missing2([1,2,6,22,5], [6,2,5,1])
print find_missing2([1], [])
