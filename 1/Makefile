HDIR = ./inc
CDIR = ./src
ODIR = ./out

CC = gcc
CFLAGS = -I$(HDIR) -std=c99 -Wall -Werror -Wpedantic -Wextra

build: app.exe
app.exe: $(ODIR)/division.o $(ODIR)/print.o $(ODIR)/view.o $(ODIR)/check.o $(ODIR)/main.o
	$(CC) $^ -o $@

$(ODIR)/%.o: $(CDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: build clean

clean:
	rm -f $(ODIR)/*.o *.exe