ifndef ROOTDIR
$(error variable ROOTDIR is not defined)
endif

ifndef PROJ
$(error variable PROJ is not defined)
endif

INCLUDEDIR := $(ROOTDIR)/include

CC := gcc
CFLAGS := -c -I $(INCLUDEDIR) -g
LDFLAGS := -g

LEX := flex
LEXFLAGS := --header-file=$(INCLUDEDIR)/lex.h 

YACC := bison
YACCFLAGS := --header=$(INCLUDEDIR)/parser.h

OBJS := lex.yy.o parser.tab.o stuff.o stxtree.o symtable.o main.o

tiger: lex yacc $(OBJS)
	$(CC) $(LDFLAGS) -o $(ROOTDIR)/$(PROJ) $(OBJS)

.PHONY: lex
lex: 
	$(LEX) $(LEXFLAGS) lex.l

.PHONY: yacc
yacc: 
	$(YACC) $(YACCFLAGS) parser.y

.PHONY: clean
clean: 
	rm -rf $(PROJ) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ $^