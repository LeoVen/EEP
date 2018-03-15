# Shame!

Here I'll compile all my stupidity and funny mistakes while coding. Enjoy :smile:

## factorial(10M)

So one day I decided to calculate a millionth factorial and then save that huge number in a ```.txt```

Ok... First things first: make a ```factorial.txt``` at ```C:\Users\myUser\Documents``` then simply open the python shell...

```python
>>> from math import factorial
>>> file = open(r"C:\Users\myUser\Documents\factorial.txt", 'a')
>>> file.write(str(factorial(1000000)))
 .
 . 4 hours later...
 .
>>> file.close()
>>> len(str(factorial(1000000)))
 .
 . 30 minutes later...
 .
5565709
```

And after 4 hours and 30 minutes of calculating I finally have a whopping 5565709 digits in a ```.txt``` file representing one million factorial!

But one day I thought...

>The sky is the limit. - Somebody

__So... let's calculate 10 million factorial!__

Yeah... actually the limit was my computer hardware :sweat_smile: 

Next time I should just use Stirling's Approximation :grin:

## Blame it on NULL !

```c
CSinglyLinkedNode *scanner = SinglyLinkedList->head;
while (scanner != NULL) // Can NULL just not be 0....... error in this line, loop is infinite
{
	printf("%d -> ", scanner->data);
}
```

Of course its a NULL problem :stuck_out_tongue_closed_eyes:. The comment says so!

But for a single line...

```c
scanner = scanner->next;
```

...I could've probably saved an hour of debugging and not committed this ridiculous comment :sweat_smile:.

>Code never lies, comments sometimes do – Ron Jeffries