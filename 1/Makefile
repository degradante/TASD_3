CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra

HDIR = ./inc
ODIR = ./out

build: app.exe

app.exe: $(ODIR)/division.o $(ODIR)/print.o $(ODIR)/view.o $(ODIR)/check.o $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/check.o: check.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/view.o: view.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/division.o: division.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/print.o: print.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm $(ODIR)/*.o *.exe