# Shame!

Here I'll compile all my stupidity and funny mistakes while coding. Enjoy :smile:

### Blame it on NULL !

	CSinglyLinkedNode *scanner = SinglyLinkedList->head;
	while (scanner != NULL) // Can NULL just not be 0....... error in this line, loop is infinite
	{
		printf("%d -> ", scanner->data);
	}

Of course its a NULL problem :stuck_out_tongue_closed_eyes:. The comment says so!

But for a single line...

	scanner = scanner->next;

...I could've probably saved an hour of debugging and not committed this ridiculous comment :sweat_smile:.