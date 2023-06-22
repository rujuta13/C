CC = cc
CFLAGS = -Wall -Wextra
SRCS = mainList.c graphList.c stack.c queue.c
OBJS = $(SRCS:.c=.o)
EXEC = a.out
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)

