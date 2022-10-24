CC = gcc

CFLAGS = -std=c99 -Wall -Werror -Wextra

SDIR = ./src
HDIR = ./inc
ODIR = ./out

build: app.exe
app.exe: $(ODIR)/main.o  $(ODIR)/print.o  $(ODIR)/init.o
	$(CC) $^ -o $@

$(ODIR)/%.o: $(CDIR)/%.c
	$(CC) $(CFLAGS) -I$(HDIR) -c $< -o $@

.PHONY: build clean

clean:
	rm -f $(ODIR)/*.o *.exe