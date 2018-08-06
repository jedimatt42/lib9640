GAS=tms9900-as
LD=tms9900-ld
CC=tms9900-gcc
AR=tms9900-ar
EA5SPLIT=ea5split
ELF2EA5=elf2ea5

FNAME=lib9640

SRCS=$(wildcard *.c)

OBJECT_LIST=$(SRCS:.c=.o)

all: $(FNAME).a

$(FNAME).a: $(OBJECT_LIST)
	$(AR) rcs $(FNAME).a $(OBJECT_LIST)

.phony clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.i *.ii *.iii
	rm -f *.s
	rm -f mapfile
	rm -f *.a

%.o: %.asm
	$(GAS) $< -o $@

%.o: %.c
	$(CC) -c $< -std=c99 -O2 --no-inline --save-temp -o $@

