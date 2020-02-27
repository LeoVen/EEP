import time
import re
from selenium import webdriver
from webdriver_manager.chrome import ChromeDriverManager

page_script = '''
    window.scrollTo(0, document.body.scrollHeight);
'''

def post_keys(hashtag, scrolls=4, url="https://www.instagram.com/explore/tags/"):

    if scrolls < 1:
        return None

    browser = webdriver.Chrome(ChromeDriverManager().install())
    browser.get(url + hashtag)

    source = []

    for _ in range(scrolls):
        time.sleep(1)
        browser.execute_script(page_script)
        source.append(browser.page_source)

    browser.quit()

    keys = set()

    for page in source:
        for match in re.finditer(r'"shortcode":"(.+?)"', page):
            for k in match.groups():
                keys.add(k)

    print(f'Hashtag {hashtag} found {len(keys)} keys with {scrolls} scrolls.')

    return keys


def post_url(key, base_url="https://www.instagram.com/p/"):
    return base_url + key
