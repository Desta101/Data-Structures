CC=gcc -g
EXEC=main
DEBUG = -g
CFLAGS = -std=c99  -Wall -Werror $(DEBUG)
OBJS_DIR=sources/objects
vpath %.c sources
vpath %.h headers
OBJS=$(OBJS_DIR)/arrays.o $(OBJS_DIR)/functions.o $(OBJS_DIR)/handler.o $(OBJS_DIR)/main.o

$(EXEC) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/arrays.o: arrays.c arrays.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJS_DIR)/functions.o: functions.c functions.h arrays.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJS_DIR)/handler.o: handler.c handler.h functions.h arrays.h
	$(CC) -c $(CFLAGS) $< -o $@
$(OBJS_DIR)/main.o: main.c handler.h
	$(CC) -c $(CFLAGS) $< -o $@

clean: 
	rm -f $(EXEC)
	rm -f $(OBJS)