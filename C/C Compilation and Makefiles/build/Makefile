# -*- MakeFile -*-

.DEFAULT_GOAL := help

HDRDIR = ../include
SRCDIR = ../src
TSTDIR = ../tests
INIDIR = ../ini
OBJDIR = obj
BINDIR = bin

CC = gcc
FLAGS = -Wall

ifdef P
.DEFAULT_GOAL := all
endif

ifdef RUN
.DEFAULT_GOAL := $(RUN)

.PHONY: $(RUN)
$(RUN):
	$(BINDIR)/$(RUN)

endif

.PHONY: all
all: $(BINDIR)/$(P)

$(BINDIR)/$(P): $(OBJDIR)/Core.o $(OBJDIR)/$(P)Main.o $(OBJDIR)/$(P)Tests.o $(OBJDIR)/$(P).o
	@echo ""
	@echo "+--------------------------+"
	@echo "| Compiling Program        |"
	@echo "+--------------------------+"
	@echo ""
	$(CC) -I $(HDRDIR) $(FLAGS) $^ -o $@

$(OBJDIR)/$(P)Main.o: $(INIDIR)/$(P)Main.c $(HDRDIR)/Core.h
	@echo ""
	@echo "+--------------------------+"
	@echo "| Assembling Init Program  |"
	@echo "+--------------------------+"
	@echo ""
	$(CC) -I $(HDRDIR) $(FLAGS) -c $< -o $@

$(OBJDIR)/$(P)Tests.o: $(TSTDIR)/$(P)Tests.c $(OBJDIR)/$(P).o
	@echo ""
	@echo "+--------------------------+"
	@echo "| Assembling Test File     |"
	@echo "+--------------------------+"
	@echo ""
	$(CC) -I $(HDRDIR) $(FLAGS) -c $(TSTDIR)/$(P)Tests.c -o $@

$(OBJDIR)/$(P).o: $(SRCDIR)/$(P).c $(HDRDIR)/$(P).h
	@echo ""
	@echo "+--------------------------+"
	@echo "| Assembling Source File   |"
	@echo "+--------------------------+"
	@echo ""
	$(CC) -I $(HDRDIR) $(FLAGS) -c $< -o $@

# Core Module

$(OBJDIR)/Core.o: $(SRCDIR)/Core.c $(HDRDIR)/Core.h
	@echo ""
	@echo "+--------------------------+"
	@echo "| Assembling Core Module   |"
	@echo "+--------------------------+"
	@echo ""
	$(CC) -I $(HDRDIR) $(FLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm $(OBJDIR)/*.o
	@echo "All objects removed"

.PHONY: remove
remove:
	rm $(BINDIR)/*.exe
	@echo "All executables removed"

.PHONY: erase
erase: remove clean

.PHONY: help
help:
	@echo "+------------------------------------------------------------+"
	@echo "| Help Menu                                                  |"
	@echo "|                                                            |"
	@echo "| This Makefile can be used to build modules individually    |"
	@echo "|                                                            |"
	@echo "| Option 'P' compiles a single module:                       |"
	@echo "|                                                            |"
	@echo "|    make P=SinglyLinkedList                                 |"
	@echo "|                                                            |"
	@echo "| Option 'RUN' can be used to run the program:               |"
	@echo "|                                                            |"
	@echo "|    make RUN=SinglyLinkedList                               |"
	@echo "|                                                            |"
	@echo "| Option 'av' to print all available structures              |"
	@echo "|                                                            |"
	@echo "| Option 'clean' deletes all .o files                        |"
	@echo "| Option 'remove' removes all .exe files                     |"
	@echo "| Option 'erase' removes all .o and .exe files               |"
	@echo "|                                                            |"
	@echo "+------------------------------------------------------------+"
	@echo "Your version: $(MAKE_VERSION)"
	@echo "Make version required: 3.81"

.PHONY: av
av:
	@echo "Available 'P' parameters:"
	@echo ""
	@echo "SinglyLinkedList"
	@echo "DoublyLinkedList"
	@echo "Stack"