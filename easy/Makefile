CC = gcc
CFLAGS = -Wall -Wextra -g

TARGETS = 88_merge_sorted 27_remove_element 121_best_time_to_buy

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean
