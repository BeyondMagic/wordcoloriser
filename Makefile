.POSIX:

include config.mk

#---------------------------------------------

all: build

#-----------------------------------------------

install:
	cp    -f ./bin/$(NAME_PROGRAM)-$(VERSION) ${DESTDIR}/bin/$(NAME_PROGRAM)

clean:
	rm    -r bin

uninstall:
	rm    -f ${DESTDIR}/bin/$(NAME_PROGRAM)

build:
	mkdir -p ${DESTDIR}/bin
	g++   ./source/main.cpp $(CPP_VERSION) $(CPP_FLAGS) $(CPP_LIBS) -o ./bin/$(NAME_PROGRAM)-$(VERSION)

.PHONY: all build install clean uninstall
