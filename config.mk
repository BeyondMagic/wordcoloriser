#---------------------------------------------
# -- Program defaults.

NAME_PROGRAM = wordcoloriser

#OBJECTS = main.o

# The program's version
VERSION = 1

#---------------------------------------------
# -- For installations.

ifndef DESTDIR
DESTDIR = ~/.local
endif

#PREFIX = /usr/local
#MANPREFIX = $(PREFIX)/share/man
#EGPREFIX = $(PREFIX)/share/doc/$(NAME_PROGRAM)/examples

#---------------------------------------------
# -- CPP version.

CPP_VERSION = -std=c++20
#CPP_VERSION := -std=c++2b

#---------------------------------------------
# -- Debugging.

#CPP_FLAGS := -ggdb

#---------------------------------------------
# -- Warnings we *need* to see.

CPP_FLAGS := -O3

CPP_FLAGS := $(CPP_FLAGS) -Wall

CPP_FLAGS := $(CPP_FLAGS) -Wextra

CPP_FLAGS := $(CPP_FLAGS) -pedantic

CPP_FLAGS := $(CPP_FLAGS) -Wsign-conversion

#---------------------------------------------
# -- Compile-time limits.

CPP_FLAGS := $(CPP_FLAGS) -fconstexpr-ops-limit=1000000000

CPP_FLAGS := $(CPP_FLAGS) -fconstexpr-loop-limit=100000000

#------------------------------------------------
# -- Sanitisers.

CPP_FLAGS := $(CPP_FLAGS) -fsanitize-undefined-trap-on-error

CPP_FLAGS := $(CPP_FLAGS) -fsanitize-address-use-after-scope

CPP_FLAGS := $(CPP_FLAGS) -fsanitize=address
CPP_FLAGS := $(CPP_FLAGS),undefined
#CPP_FLAGS := $(CPP_FLAGS),nullability
#CPP_FLAGS := $(CPP_FLAGS),implicit-integer-truncation
#CPP_FLAGS := $(CPP_FLAGS),implicit-integer-arithmetic-value-change
#CPP_FLAGS := $(CPP_FLAGS),implicit-conversion
#CPP_FLAGS := $(CPP_FLAGS),integer

#---------------------------------------------
# -- Extra libraries to be compiled.

#CPP_LIBS = 
