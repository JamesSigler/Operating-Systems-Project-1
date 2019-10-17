SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

chmod u+x testcase.sh
%: %.c
	$(CC) $(CFLAGS)  -o $@ $<
	
clean: all test
	
	rm ./project1_2-1
	rm ./project1_2-5
	