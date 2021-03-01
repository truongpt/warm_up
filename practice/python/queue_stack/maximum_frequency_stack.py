'''
- Problem: https://leetcode.com/problems/maximum-frequency-stack
- Solution:
  - Frequency of element status is managed by hashtable.
  - Using priority queue to keep the most frequency elem on the top.
  - Time and space complexity.
    - TC: O(log n) for push/pop
    - SC: O(n)

- Solution2:
  - Using 2 hashtable:
    - One map value -> frequency
    - One maping frequency -> stack of values, which same frequency.
  - Time and space complexity.
    - TC: O(1) for push/pop
    - SC: O(n)
'''

import collections

# solution
# implemente later :-(

# solution 2
class FreqStack2:

    def __init__(self):
        self.freq = collections.Counter()
        self.group = collections.defaultdict(list)
        self.max_freq = 0
        

    def push(self, x: int) -> None:
        self.freq[x] += 1
        self.group[self.freq[x]].append(x)
        
        if self.max_freq < self.freq[x]:
            self.max_freq = self.freq[x]
        

    def pop(self) -> int:
        res = self.group[self.max_freq].pop()
        self.freq[res] -= 1
        if not self.group[self.max_freq]:
            self.max_freq -= 1
            
        return res

if __name__ == "__main__":
    obj = FreqStack2()
    obj.push(1)
    obj.push(2)
    obj.push(2)
    obj.push(2)
    obj.push(3)

    for i in range(5):
        print(obj.pop())
    
