CC = gcc
CFLAGS = -std=c99 -Wall -Werror -Wpedantic -Wextra

HDIR = ./inc
CDIR = ./src
ODIR = ./out
HEADERS = $(HDIR)/check.h $(HDIR)/division.h $(HDIR)/print.h $(HDIR)/view.h

build: app.exe
app.exe: $(ODIR)/division.o $(ODIR)/print.o $(ODIR)/view.o $(ODIR)/check.o $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/%.o: $(CDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HDIR) -c $< -o $@

.PHONY: build clean

clean:
	rm -f $(ODIR)/*.o *.exe