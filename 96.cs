using System.Collections.Generic;

public class TrieNode
{
    public Dictionary<char, TrieNode> Children = new Dictionary<char, TrieNode>();
    public int Count = 0;     // number of words that pass through
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
                node.Children[ch] = new TrieNode();

            node = node.Children[ch];
            node.Count++;         // increment prefix count
        }
        node.IsEnd = true;
    }

    public int CountPrefix(string prefix)
    {
        TrieNode node = root;
        foreach (char ch in prefix)
        {
            if (!node.Children.ContainsKey(ch))
                return 0;
            node = node.Children[ch];
        }
        return node.Count;
    }
}

// Example:
/*
Trie trie = new Trie();
string[] words = { "apple", "app", "apt", "bat", "ball" };
foreach (var w in words) trie.Insert(w);

Console.WriteLine(trie.CountPrefix("ap"));   // 3
Console.WriteLine(trie.CountPrefix("ba"));   // 2
Console.WriteLine(trie.CountPrefix("app"));  // 2
*/
