class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False


class WordDictionary:
    def __init__(self):
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        def helper(node: TrieNode, word: str) -> bool:
            if not word:
                # ? if end of a word, check if it's a valid word in the trie
                return node.is_end_of_word

            char = word[0]
            if char == '.':
                # ? check all the children of the current node(all possible combinations)
                for child in node.children.values():
                    # ? return True when we meet the first valid word
                    if helper(child, word[1:]):
                        return True
                # ? if no valid word can be formed, return False
                return False
            else:
                if char not in node.children:
                    return False
                return helper(node.children[char], word[1:])

        return helper(self.root, word)


# ? a dot means any char
# ? input [[], ["a"], ["a"], ["."], ["a"], ["aa"], ["a"], [".a"], ["a."]]

obj = WordDictionary()
obj.addWord("a")
obj.addWord("a")
obj.addWord(".")
print(obj.search("."))  # True
print(obj.search("a"))  # True
print(obj.search("aa"))  # False
print(obj.search("a"))  # True
print(obj.search(".a"))  # False
print(obj.search("a."))  # False
