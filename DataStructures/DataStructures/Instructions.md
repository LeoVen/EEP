# Instructions

>Project compiled in Visual Studio 2017

# Config

## \*.c

Right-Click file -> Properties -> C/C++ -> All Options -> Precompiled Headers

	Not Using Precompiled Headers

## Include .h in cpp file

	extern "C" {
		#include "C\Headers\SinglyLinkedList.h" // C header file
	}

## Header .h

	#ifdef __cplusplus
	extern "C" {
	#endif

		// Functions
		// Structs

	#ifdef __cplusplus
	}
	#endif

<hr>

Thanks StackOverflow for providing all informations so I could have a single project for both C and C++ structures :smile: