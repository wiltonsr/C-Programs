OBJECTS		= month_name.o echo.o linked-list.o palindrome.o fgets_and_sscanf.o
LIBRARIES	=
PROGRAMS	= month_name echo linked-list palindrome fgets_and_sscanf
CC = gcc

.PHONY:         all clean

# Default target: build everything.
all: $(OBJECTS) $(LIBRARIES) $(PROGRAMS) cleano

# Clean up build products.
clean:
	rm -f $(PROGRAMS) $(OBJECTS)

cleano:
	rm -f $(OBJECTS)
