CC = gcc

CFLAGS = -std=c99 -Wall -Werror -Wextra

SDIR = ./src
HDIR = ./inc
ODIR = ./out

build: app.exe
app.exe: $(ODIR)/main.o  $(ODIR)/print.o  $(ODIR)/init.o
	$(CC) $^ -o $@
	
$(ODIR)/main.o: $(SDIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/print.o: $(SDIR)/print.c
	$(CC) $(CFLAGS) -c $< -o $@

$(ODIR)/init.o: $(SDIR)/init.c
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	rm $(ODIR)/*.o *.exe