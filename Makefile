SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<
	
clean: all test
	chmod u+x mc.sh
	rm ./project1_2-1
	rm ./project1_2-5
	