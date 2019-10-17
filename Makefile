SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<
	
testcase: testcase.sh
	chmod u+x testcase.sh
	
clean: all test
	
	rm ./project1_2-1
	rm ./project1_2-5
	