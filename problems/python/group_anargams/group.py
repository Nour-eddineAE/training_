from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)

        for string in strs:
            anagrams["".join(sorted(string))].append(string)

        return list(anagrams.values())


strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
# [["bat"],["nat","tan"],["ate","eat","tea"]]
print(Solution().groupAnagrams(strs))
