# C Compilation Process

| Compiler Option | File Extension |    Process   | What it does                                       |
|:---------------:|:--------------:|:------------:|----------------------------------------------------|
|        -E       |       .c       | Preprocessor | Handle #include, #define, strips out comments      |
|        -S       |       .s       |   Compiler   | Translate C do Assembly                            |
|        -c       |       .o       |   Assembler  | Translate Assembly to Object File                  |
|                 |      exec      |    Linker    | Brings together object files to produce executable |

# Makefiles

How to create a makefile:

* Create a File named ```Makefile```
* First line must be ```# -*- MakeFile -*-```

It is devided into block that follow the structure:

```makefile
target: dependencies
	action
```

Note that there must be a tab character before ```action```

## Example

```makefile
# -*- MakeFile -*-

SinglyLinkedList: Main_SLL.o Core.o SinglyLinkedListTests.o SinglyLinkedList.o
	gcc Main_SLL.o Core.o SinglyLinkedListTests.o SinglyLinkedList.o -o SinglyLinkedList -l m

Main_SLL.o: Main_SLL.c Core.h
	gcc -c Main_SLL.c

Core.o: Core.c Core.h
	gcc -c Core.c

SinglyLinkedListTests.o: SinglyLinkedListTests.c SinglyLinkedList.o
	gcc -c SinglyLinkedListTests.c

SinglyLinkedList.o: SinglyLinkedList.c SinglyLinkedList.h
	gcc -c SinglyLinkedList.c

DoublyLinkedList: Main_DLL.o Core.o DoublyLinkedListTests.o DoublyLinkedList.o
	gcc Main_DLL.o Core.o DoublyLinkedListTests.o DoublyLinkedList.o -o DoublyLinkedList -l m

Main_DLL.o: Main_DLL.c Core.h
	gcc -c Main_DLL.c

Core.o: Core.c Core.h
	gcc -c Core.c

DoublyLinkedListTests.o: DoublyLinkedListTests.c DoublyLinkedList.o
	gcc -c DoublyLinkedListTests.c

DoublyLinkedList.o: DoublyLinkedList.c DoublyLinkedList.h
	gcc -c DoublyLinkedList.c

clean:
	rm *.o SinglyLinkedList.exe DoublyLinkedList.exe
```

In this example there are 3 compilations that can be done: ```SinglyLinkedList```, ```DoublyLinkedList``` and ```clean``` where this last one can be used to clean all ```*o``` files (objects) and all executables. The ```make``` command will compile only the first target, ```SinglyLinkedList```. If you want to compile a specific target, you can use ```make {target}``` where ```{target}``` can be the name of anything that is before the colon.

* ```make SinglyLinkedList```
* ```make DoublyLinkedList.o```
* ```make clean```
* ```make Main_SLL.o```

An ```all``` can be added at the beggining of the file so you can compile all units (it can be any name actually as long as in the dependency section you specify all other units that you want to be compiled).

	all: SinglyLinkedList DoublyLinkedList
