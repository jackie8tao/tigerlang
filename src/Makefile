ifndef ROOTDIR
$(error variable ROOTDIR is not defined)
endif

ifndef PROJ
$(error variable PROJ is not defined)
endif

INCLUDEDIR := $(ROOTDIR)/include

CC := gcc
CFLAGS := -c -I $(INCLUDEDIR)
LDFLAGS := 

LEX := flex
LEXFLAGS := --header-file="$(INCLUDEDIR)/yylex.h"

OBJS := lex.yy.o main.o

tiger: lex $(OBJS)
	$(CC) $(LDFLAGS) -o $(ROOTDIR)/$(PROJ) $(OBJS)

.PHONY: lex
lex: 
	$(LEX) $(LEXFLAGS) lex.l

.PHONY: clean
clean: 
	rm -rf $(PROJ) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ $^