SRC     := $(wildcard src/*.c)
PKGS    :=
CC      := clang
CFLAGS  := -Iheaders
CFLAGS  += -Wall -O2 -std=c17 $(shell pkg-config --cflags $(PKGS))
LDFLAGS := $(shell pkg-config --libs $(PKGS))

.PHONY: dev clean compile cnr

dev:
	echo $(CFLAGS) | tr " " "\n" > compile_flags.txt
	echo $(LDFLAGS) | tr " " "\n" >> compile_flags.txt

clean:
	$(RM) *.o a.out

compile: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $^

run:
	$(CC) $(CFLAGS) $(LDFLAGS) $^ && ./a.out
