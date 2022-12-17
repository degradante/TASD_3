CDIR = ./src
HDIR = ./inc
ODIR = ./out

CC = gcc
CFLAGS = -I$(HDIR) -std=c99 -Wall -Wextra -Wpedantic -Wfloat-equal

build: app.exe
app.exe: $(ODIR)/main.o $(ODIR)/io.o $(ODIR)/menu.o $(ODIR)/my_memory.o $(ODIR)/my_task.o $(ODIR)/profile.o $(ODIR)/stack_array.o $(ODIR)/stack_list.o 
	$(CC) $^ -o $@

$(ODIR)/%.o: $(CDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: build clean

clean:
	rm -f $(ODIR)/*.o *.exe