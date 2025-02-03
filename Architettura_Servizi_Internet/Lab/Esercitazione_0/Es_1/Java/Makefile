SOURCES := $(wildcard *.java)
OBJECTS := $(notdir $(SOURCES))
TARGETS := $(patsubst %.java, %.class, $(OBJECTS))

TODAY := $(shell date +%Y-%m-%d)
ARCHIVE := Esercitazione_0_$(TODAY).zip

.PHONY: clean dist

all: ${TARGETS}

%.class: %.java
	@javac $<

clean:
	@rm -f *.class *.zip *~

dist:
	@zip $(ARCHIVE) $(SOURCES) Makefile

