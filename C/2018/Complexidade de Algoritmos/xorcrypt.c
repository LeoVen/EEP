/**
 * @file xorcrypt.c
 *
 * @author Leonardo Vencovsky
 * 
 * @date 01/11/2018
 *
 * @brief XOR Cipher
 *
 */

#include <stdio.h>
#include <stdlib.h>

// Types of ciphers
//
// Electronic CodeBook (ECB)
// Cipher Block Chaining (CBC)
// Cipher FeedBack Block (CFB)
// Output FeedBack Block (OFB)

// Types of operations
//
// Substitution
// Transposition

// cipher = message xor key 
char *cipher(const char *message, int msize, const char key)
{
	char *content = malloc(sizeof(char) * (msize + 1));

	if (!content)
		return NULL;

	for (int i = 0; i < msize; i++)
	{
		content[i] = message[i] ^ key;
	}

	content[msize] = '\n';

	return content;
}

// message = cipher xor key
char *decipher(const char *message, int msize, const char key)
{
	char *content = malloc(sizeof(char) * (msize + 1));

	if (!content)
		return NULL;

	for (int i = 0; i < msize; i++)
	{
		content[i] = message[i] ^ key;
	}

	content[msize] = '\n';

	return content;
}

char *make_message(const char *message, int msize)
{
	char *content = malloc(sizeof(char) * (msize + 1));

	for (int i = 0; i < msize; i++)
		content[i] = message[i];

	content[msize] = '\n';

	return content;
}

int main(int argc, char const *argv[])
{
	int msize = 27;
	const char m[27] = "Lorem ipsum dolor sit amet.";

	char *message = make_message(m, msize);

	unsigned char key = 'G';

	char *ciphered_message = cipher(message, msize, key);

	printf("\nCiphered message: %s", ciphered_message);

	char *wrong_key = decipher(ciphered_message, msize, 'v');

	printf("\nDeciphered message with wrong key: %s", wrong_key);

	char *deciphered_message = decipher(ciphered_message, msize, key);
	
	printf("\nDeciphered message: %s", deciphered_message);

	free(message);
	free(ciphered_message);
	free(wrong_key);
	free(deciphered_message);

	return 0;
}
