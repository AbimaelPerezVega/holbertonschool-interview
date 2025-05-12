#!/usr/bin/python3
"""
Recursive function that queries the Reddit API and
returns a sorted count of given keywords in hot articles' titles.
"""
import requests


def count_words(subreddit, word_list, word_count={}, after=None):
    """
    Queries the Reddit API, parses titles of hot articles, and prints
    a sorted count of given keywords (case-insensitive).
    """
    if not word_count:
        for word in word_list:
            word_lower = word.lower()
            word_count[word_lower] = word_count.get(word_lower, 0) + 1
        word_list = list(set([w.lower() for w in word_list]))

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "Python/3.4.3"}
    params = {"limit": 100, "after": after}
    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get("data", {})
    children = data.get("children", [])

    for post in children:
        title = post.get("data", {}).get("title", "").lower().split()
        for word in title:
            clean_word = ''.join(filter(str.isalnum, word))
            if clean_word in word_list:
                word_count[clean_word] += 1

    if data.get("after"):
        return count_words(subreddit, word_list, word_count, data.get("after"))

    sorted_words = sorted(
        [(k, v) for k, v in word_count.items() if v > 0],
        key=lambda x: (-x[1], x[0])
    )
    for word, count in sorted_words:
        print(f"{word}: {count}")
