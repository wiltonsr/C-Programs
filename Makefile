OBJECTS		= month_name.o echo.o
LIBRARIES	=
PROGRAMS	= month_name echo
CC = gcc

.PHONY:         all clean

# Default target: build everything.
all: $(OBJECTS) $(LIBRARIES) $(PROGRAMS) cleano

# Clean up build products.
clean:
	rm -f $(PROGRAMS) $(OBJECTS)

cleano:
	rm -f $(OBJECTS)
