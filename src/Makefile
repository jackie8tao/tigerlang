PROJ := tiger

CC := gcc
CFLAGS := -c -I $(ROOTDIR)/include
LDFLAGS :=

LEX := lex
LEXFLAGS := 

OBJS := lex.yy.o main.o

tiger: lex $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROJ) $(OBJS)

.PHONY: lex
lex: 
	$(LEX) $(LEXFLAGS) lex.l

.PHONY: clean
clean: 
	rm -rf $(PROJ) $(OBJS) lex.yy.c

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -o $@ $^