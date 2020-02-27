import discord
import re
from insta import post_keys, post_url

client = discord.Client()

help_message = '''
    Welcome to InstaBot

    Example. Return the top 3 images from instagram with the hashtag 'sunset':
        $insta n=3 hashtag=sunset
'''

@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))

@client.event
async def on_message(message):
    if message.author == client.user or not message.content.startswith('$'):
        return

    elif message.content.startswith('$help'):
        await message.channel.send(help_message)

    elif message.content.startswith('$insta'):
        param_list = message.content[6:].strip()

        n_param = re.search(r'n=(\d+)', param_list)

        if n_param is not None:
            count = int(n_param.group(1))
        else:
            await message.channel.send('Missing or incorrect required argument "n"')
            return

        hashtag_param = re.search(r'hashtag=(\w+)', param_list)

        if hashtag_param is not None:
            hashtag = hashtag_param.group(1)
        else:
            await message.channel.send('Missing or incorrect required argument "hashtag"')
            return

        if count > 10:
            count = 10
            await message.channel.send('Sorry but I\'m only bringing you up to 10 posts')

        print(f'Searching for {count} of hashtag {hashtag}')

        keys = list(post_keys(hashtag, scrolls=1))

        if len(keys) > count:
            keys = keys[:count]

        for key in keys:
            await message.channel.send(post_url(key))

    else:
        await message.channel.send('Sorry, I don\'t understand that...')

with open('secret.txt', encoding="utf8") as file:
        token = file.read()

client.run(token)
