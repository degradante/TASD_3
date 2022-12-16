CDIR = ./src
HDIR = ./inc
ODIR = ./out

CC = gcc
CFLAGS = -I$(HDIR) -std=c99 -Wall -Werror -Wextra -Wpedantic -Wfloat-equal

build: app.exe
app.exe: $(ODIR)/main.o $(ODIR)/io.o $(ODIR)/menu.o $(ODIR)/queue_array.o $(ODIR)/queue_list.o #$(ODIR)/profile.o  $(ODIR)/my_task.o
	$(CC) $^ -o $@

$(ODIR)/%.o: $(CDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: build clean

clean:
	rm -f $(ODIR)/*.o *.exe