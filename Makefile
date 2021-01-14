CC ?= gcc

INCLUDE_PATH = ./Headers
TARGET   = main

SOURCESDIR   = Sources
OBJECTSDIR   = Obj


SOURCES  := $(wildcard $(SOURCESDIR)/*.c)
INCLUDES := $(wildcard $(INCLUDE_PATH)/*.h)
OBJECTS  := $(SOURCES:$(SOURCESDIR)/%.c=$(OBJECTSDIR)/%.o)


$(SOURCESDIR)/$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS) -lm -g
	@echo "Compilation Reussie"

$(OBJECTS): $(OBJECTSDIR)/%.o : $(SOURCESDIR)/%.c
	mkdir -p $(OBJECTSDIR)
	$(CC) -o $@ -c $< $(CFLAGS) -I$(INCLUDE_PATH)

Define_Nbr:
	./Define_Nbr.sh Define_Nbr

clean:
	rm -f $(OBJECTSDIR)/*.o
	rm -f Saves/*.txt