'''
- Problem: https://leetcode.com/problems/short-encoding-of-words/
- Solution:
  - Using trie data structure to manage next word is included by previous words or not.
  - Preprocessing: sort words descent size of each word.
  - Time and space complexity.
    - TC: O (nlog(n) + n*m) // m is size of word
    - SC: O(m)
'''

class Trie:
    def __init__(self):
        self.is_end = False
        self.next = [None]*27

def isInclude(t : Trie, word: str) -> bool:
    for i in reversed(range(len(word))):
        c = word[i]
        if t.next[ord(c) - ord('a')] == None:
            return False
        t = t.next[ord(c) - ord('a')]
    return True
    
def addWord(t: Trie, word: str):
    for i in reversed(range(len(word))):
        c = word[i]
        if t.next[ord(c) - ord('a')] == None:
            t.next[ord(c) - ord('a')] = Trie()
            
        t = t.next[ord(c) - ord('a')]
    t.is_true = True
    

def minimumLengthEncoding(words: list) -> int:
    words.sort(key = lambda x: -len(x))    
    res = 0
    t = Trie()
    
    for word in words:
        if not isInclude(t, word):
            addWord(t, word)
            res += len(word)+1    
    
    return res

if __name__ == "__main__":
    words = ["time", "me", "bell"]
    print(minimumLengthEncoding(words))
