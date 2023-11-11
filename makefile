CC = gcc
CFLAGS = 

SRCS = main.c monster.c player.c userInterface.c inventory.c fights.c save.c game.c map.c
OBJS = $(SRCS:.c=.o)

TARGET = Doom

all: $(TARGET)
	@echo "Compilation successful!"

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	@make clean

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)

.PHONY: clean
