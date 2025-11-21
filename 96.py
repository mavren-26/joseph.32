class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0       # number of words that pass through this node
        self.isEnd = False

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        node = self.root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
            node.count += 1  # increment count for prefix
        node.isEnd = True

    def countPrefix(self, prefix):
        node = self.root
        for ch in prefix:
            if ch not in node.children:
                return 0
            node = node.children[ch]
        return node.count


# Example
trie = Trie()
words = ["apple", "app", "apt", "bat", "ball"]
for w in words:
    trie.insert(w)

print(trie.countPrefix("ap"))   # 3
print(trie.countPrefix("ba"))   # 2
print(trie.countPrefix("app"))  # 2
