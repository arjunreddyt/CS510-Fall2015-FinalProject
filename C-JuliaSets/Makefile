LDLIBS=-lm

all: julia

julia: complex.o cplane.o

run: all
	./julia

clean:
	rm -f julia cplane.o complex.o
