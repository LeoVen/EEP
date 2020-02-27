import discord
import nltk

client = discord.Client()

help_message = '''
Available Commands

Example:
$command_name (param1, param2, ...) [opt_param=..., opt_param2=...]

$syntax (sentences) [] - Analyzes the syntax of a sentences
$hello ( ) [] - prints a simple Hello! message
'''

abbvr = {
    "CC"   : "coordinating conjunction",
    "CD"   : "cardinal digit",
    "DT"   : "determiner",
    "EX"   : "existential there",
    "FW"   : "foreign word",
    "IN"   : "preposition/subordinating conjunction",
    "JJ"   : "adjective (large)",
    "JJR"  : "adjective, comparative (larger)",
    "JJS"  : "adjective, superlative (largest)",
    "LS"   : "list market",
    "MD"   : "modal (could, will)",
    "NN"   : "noun, singular (cat, tree)",
    "NNS"  : "noun plural (desks)",
    "NNP"  : "proper noun, singular (sarah)",
    "NNPS" : "proper noun, plural (indians or americans)",
    "PDT"  : "predeterminer (all, both, half)",
    "POS"  : "possessive ending (parents)",
    "PRP"  : "personal pronoun (hers, herself, him, himself)",
    "PRP$" : "possessive pronoun (her, his, mine, my, our)",
    "RB"   : "adverb (occasionally, swiftly)",
    "RBR"  : "adverb, comparative (greater)",
    "RBS"  : "adverb, superlative (biggest)",
    "RP"   : "particle (about)",
    "TO"   : "infinite marker (to)",
    "UH"   : "interjection (goodbye)",
    "VB"   : "verb (ask)",
    "VBG"  : "verb gerund (judging)",
    "VBD"  : "verb past tense (pleaded)",
    "VBN"  : "verb past participle (reunified)",
    "VBP"  : "verb, present tense not 3rd person singular (wrap)",
    "VBZ"  : "verb, present tense with 3rd person singular (bases)",
    "WDT"  : "wh-determiner (that, what)",
    "WP"   : "wh-pronoun (who)",
    "WRB"  : "wh-adverb (how)"
}

@client.event
async def on_ready():
    print('We have logged in as {0.user}'.format(client))

@client.event
async def on_message(message):
    if message.author == client.user or not message.content.startswith('$'):
        return

    if message.content.startswith('$help'):
        await message.channel.send(help_message)

    elif message.content.startswith('$hello'):
        await message.channel.send('Hello!')

    elif message.content.startswith('$syntax'):
        param = message.content[7:].strip()

        sentences = nltk.sent_tokenize(param)

        from nltk.tokenize import RegexpTokenizer
        tokenizer = RegexpTokenizer(r'\w+')

        # tokenize each sentence
        tokens = [tokenizer.tokenize(sent) for sent in sentences]

        # pos_tag each sentence
        tagged = [nltk.pos_tag(sent) for sent in tokens]

        # flatten
        tagged = [tup for sublist in tagged for tup in sublist]

        wd = {}
        sep = ' - '

        for tup in tagged:
            if tup[1] not in wd:
                wd[tup[1]] = tup[0] + sep
            else:
                wd[tup[1]] += tup[0] + sep

        result = ''

        for key in wd.keys():
            result += '{} : \n\t{}\n'.format(abbvr[key].title(), wd[key][:-2])

        await message.channel.send(result)

    else:
        await message.channel.send('Sorry, I don\'t understand that...')

with open('secret.txt', encoding="utf8") as file:
        token = file.read()

client.run(token)
