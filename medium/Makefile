CC = gcc
CFLAGS = -Wall -Wextra -g

TARGETS = 80_remove_duplicates_sorted 55_jump_game 134_gas_station 6_zigzag_conversion 289_gameoflife 54_spiralmatrix \
		  217_containsduplicate 242_valid_anagram 1_twosum 49_group_anagram 49_group_anagram_a 347_top_k_frequent_elements \
		  271_Encode_Decode_Strings 238_Product_Array_Except_Self 
 
all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)

.PHONY: all clean
