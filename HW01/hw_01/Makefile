CC=gcc -g
EXEC=main
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)
OBJS_DIR=sources/objects
vpath %.c sources
vpath %.h headers
OBJS=$(OBJS_DIR)/puzzle.o $(OBJS_DIR)/picture.o $(OBJS_DIR)/menu.o $(OBJS_DIR)/matrix.o $(OBJS_DIR)/main.o

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/puzzle.o: puzzle.c puzzle.h matrix.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJS_DIR)/picture.o: picture.c picture.h matrix.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJS_DIR)/menu.o: menu.c menu.h matrix.h picture.h puzzle.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJS_DIR)/matrix.o: matrix.c matrix.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJS_DIR)/main.o: main.c menu.h picture.h
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(EXEC)
	rm -f $(OBJS)