GAS=tms9900-as
LD=tms9900-ld
CC=tms9900-gcc
EA5SPLIT=ea5split

ELF2EA5=elf2ea5

FNAME=gentest
UCFNAME=$(shell echo -n $(FNAME) | tr 'a-z' 'A-Z')

LDFLAGS=\
  ../lib9640.a \
  --script=linkfile \

OBJECT_LIST=\
  gencrt0.o\
  main.o

all: $(FNAME)

$(FNAME): $(FNAME).bin
	$(EA5SPLIT) $(FNAME).bin
	./fixup.py $(UCFNAME)

$(FNAME).bin: $(FNAME).elf
	$(ELF2EA5) $(FNAME).elf $(FNAME).bin

$(FNAME).elf: $(OBJECT_LIST)
	$(LD) $(OBJECT_LIST) $(LDFLAGS) -o $(FNAME).elf -Map=mapfile

.phony clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.i *.ii *.iii
	rm -f *.s
	rm -f mapfile
	rm -f $(UCFNAME)

%.o: %.asm
	$(GAS) $< -o $@

%.o: %.c
	$(CC) -c $< -std=c99 -O2 --no-inline --save-temp -o $@

