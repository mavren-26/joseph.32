using System.Collections.Generic;

public class TrieNode
{
    public Dictionary<char, TrieNode> Children = new Dictionary<char, TrieNode>();
    public bool IsEnd = false;
}

public class Trie
{
    private TrieNode root = new TrieNode();

    public void Insert(string word)
    {
        TrieNode node = root;
        foreach (char ch in word)
        {
            if (!node.Children.ContainsKey(ch))
            {
                node.Children[ch] = new TrieNode();
            }
            node = node.Children[ch];
        }
        node.IsEnd = true;
    }

    public bool Search(string word)
    {
        TrieNode node = root;
        foreach (char ch in word)
        {
            if (!node.Children.ContainsKey(ch))
                return false;
            node = node.Children[ch];
        }
        return node.IsEnd;
    }
}

// Usage
/*
Trie trie = new Trie();
trie.Insert("apple");
trie.Insert("app");
trie.Insert("apt");

Console.WriteLine(trie.Search("app"));  // True
Console.WriteLine(trie.Search("ap"));   // False
*/
