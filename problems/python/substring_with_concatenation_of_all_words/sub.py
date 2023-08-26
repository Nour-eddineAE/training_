from typing import List


from collections import Counter, defaultdict


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if not words or not s:
            return []

        word_len = len(words[0])
        total_words = len(words)
        window_len = word_len * total_words
        words_freq = Counter(words)
        all_words_concatenation_indexes = []

        # * we loop through each index in the range of a word's length, so we can process cases like:
        # * s = "aaaaaaaaaaaaaaaaaaaa" and words = ["aa", "aa"]
        # * if we start at 0 or at 1, we'll have different results, however, they are all considered
        # ! However, words should be of same length which is the case here
        for i in range(word_len):
            left, right = i, i
            current_window_words_freq = defaultdict(int)

            while right + word_len <= len(s):
                word = s[right:right + word_len]
                right += word_len

                if word in words_freq:
                    current_window_words_freq[word] += 1

                    # * Optimize the window by shrinking it from the left, as long as the frequency of
                    # * the word inside the window is great than the necessary(the number of occurences
                    # * of a certain word in "words")
                    while current_window_words_freq[word] > words_freq[word]:
                        current_window_words_freq[s[left:left + word_len]] -= 1
                        left += word_len

                    # * if we meet a window, it must be a valid one
                    if right - left == window_len:
                        all_words_concatenation_indexes.append(left)

                # * if the current word is not in "words", no need to continue => we clear the frequencies at the current window
                # * and move the left pointer forward to where we have found an invalid word
                else:
                    current_window_words_freq.clear()
                    left = right

        return all_words_concatenation_indexes


s = "barfoofoobarthefoobarman"
words = ["bar", "foo", "the"]

print(Solution().findSubstring(s, words))
