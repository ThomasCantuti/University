# Variabili per i sorgenti Java e C
JAVA_SOURCES := $(wildcard *.java)
JAVA_TARGETS := $(patsubst %.java,%.class,$(JAVA_SOURCES))
C_SOURCES := $(wildcard *.[ch])
C_TARGETS := leggi_dati_sensori server-concurrent-td-connreuse

TODAY := $(shell date +%Y%m%d)
ARCHIVE := soluzione_compito_20230110_v$(TODAY).zip

CFLAGS := -std=c17 -O2 -g3 -Wall -Werror -pedantic -fsanitize=address,undefined -Wformat -Werror=format-security -Werror=array-bounds
LDFLAGS := -fsanitize=address,undefined -fpie -Wl,-pie

ifeq ($(USE_LIBUNISTRING),yes)
CFLAGS += -DUSE_LIBUNISTRING=1
LDFLAGS += -lunistring
endif

.PHONY: all clean dist

all: $(C_TARGETS) $(JAVA_TARGETS)

# Regole di compilazione per i programmi C
leggi_dati_sensori: leggi_dati_sensori.o rxb.o utils.o
	$(CC) $(CFLAGS) -o $@ leggi_dati_sensori.o rxb.o utils.o $(LDFLAGS)

server-concurrent-td-connreuse: server-concurrent-td-connreuse.o rxb.o utils.o
	$(CC) $(CFLAGS) -o $@ server-concurrent-td-connreuse.o rxb.o utils.o $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regola per compilare i file Java
%.class: %.java
	javac $<

clean:
	@rm -rf $(C_TARGETS) $(JAVA_TARGETS) *.o *.zip

dist:
	@zip $(ARCHIVE) $(C_SOURCES) $(JAVA_SOURCES) Makefile