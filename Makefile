SRCS = $(wildcard *.c)

PROGS = $(patsubst %.c,%,$(SRCS))

all: $(PROGS) testcase.sh

	chmod u+x testcase.sh

%: %.c
	$(CC) $(CFLAGS)  -o $@ $<
	
clean:
	rm ./project1_2-1
	rm ./project1_2-5
	