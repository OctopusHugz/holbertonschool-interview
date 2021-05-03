#!/usr/bin/python3
"""This module queries the Reddit API"""
import requests


def count_words(subreddit, word_list, count=0, after="", title_dict={},
                word_count=0):
    """Prints a sorted count of given keywords listed for a subreddit"""
    user_agent = {'User-agent': 'OctopusHugs/605.1.15'}
    if not after:
        req = requests.get(
            "https://www.reddit.com/r/{}/hot/.json?limit=100".format(
                subreddit),
            headers=user_agent, allow_redirects=False)
    else:
        req = requests.get(
            "https://www.reddit.com/r/{}/hot/.json?limit=100&after={}".format(
                subreddit, after),
            headers=user_agent, allow_redirects=False)
    try:
        data = req.json().get('data')
    except Exception:
        return None
    after = data.get('after')
    children = data.get('children')
    for child in children:
        title = child.get('data').get('title').lower().split()
        for word in word_list:
            word = word.lower()
            word_count = title_dict.get(word)
            if word_count is None:
                word_count = 0
            word_count += title.count(word)
            if word_count > 0:
                title_dict.update({word: word_count})
    count += len(children)
    if after is not None:
        count_words(subreddit, word_list, count, after, title_dict, word_count)
    else:
        values = title_dict.values()
        values = list(values)
        while len(values) > 0:
            for key, value in title_dict.items():
                key_list = []
                if len(values) > 1:
                    max_value = max(values)
                elif len(values) == 1:
                    max_value = values[0]
                else:
                    return
                if value == max_value:
                    valueCount = values.count(value)
                    if valueCount == 1:
                        print("{}: {:d}".format(key, title_dict.get(key)))
                        index = values.index(max_value)
                        del values[index]
                    else:
                        for k, v in title_dict.items():
                            if value == v:
                                key_list.append(k)
                        key_list.sort()
                        for key in key_list:
                            print("{}: {:d}".format(key, title_dict.get(key)))
                            index = values.index(max_value)
                            del values[index]
