class TrieNode {
  constructor() {
    this.children = {};
    this.count = 0;
    this.isEnd = false;
  }
}

class Trie {
  constructor() {
    this.root = new TrieNode();
  }

  insert(word) {
    let node = this.root;
    for (let ch of word) {
      if (!node.children[ch]) node.children[ch] = new TrieNode();
      node = node.children[ch];
      node.count++;
    }
    node.isEnd = true;
  }

  countPrefix(prefix) {
    let node = this.root;
    for (let ch of prefix) {
      if (!node.children[ch]) return 0;
      node = node.children[ch];
    }
    return node.count;
  }
}
