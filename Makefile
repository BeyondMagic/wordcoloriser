.POSIX:

ifndef DESTDIR
DESTDIR = ~/.local
endif

#---------------------------------------------

all: build

#-----------------------------------------------

install:
	cp    -f ./bin/wordcoloriser ${DESTDIR}/bin/wordcoloriser

clean:
	rm    -r bin

uninstall:
	rm    -f ${DESTDIR}/bin/wordcoloriser

build:
	mkdir -p ${DESTDIR}/bin
	g++   ./source/main.cpp  -std=c++20 -O3  -o ./bin/wordcoloriser

.PHONY: all build install clean uninstall
