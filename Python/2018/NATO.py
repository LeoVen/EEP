import unicodedata

def NATO(w):

    words = {
            "a":"alfa",
            "b":"bravo",
            "c":"charlie",
            "d":"delta",
            "e":"echo",
            "f":"foxtrot",
            "g":"golf",
            "h":"hotel",
            "i":"india",
            "j":"juliett",
            "k":"kilo",
            "l":"lima",
            "m":"mike",
            "n":"november",
            "o":"oscar",
            "p":"papa",
            "q":"quebec",
            "r":"romeo",
            "s":"sierra",
            "t":"tango",
            "u":"uniform",
            "v":"victor",
            "w":"whiskey",
            "x":"x-ray",
            "y":"yankee",
            "z":"zulu",
            " ":"\n"
        }



    for i in range(len(w)):
        if(w[i].isalpha() or w[i] == ' '):
            normal_w = normalize_str(w[i])   
            normal_w = normal_w.lower()    
            if(w[i].istitle()):
                print(words[normal_w].title() + " ")

            elif(w[i] == ' '):
                continue
            else:
                print(words[normal_w] + " ")

        else:
            continue

def normalize_str(w):
    nfkd_form = unicodedata.normalize('NFKD', w)
    return u"".join([c for c in nfkd_form if not unicodedata.combining(c)])
