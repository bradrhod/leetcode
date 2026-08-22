# LeetCode Practice (C)

Personal LeetCode solutions written in C, organized by difficulty.

## Structure

- `easy/` — easy-difficulty problems
- `medium/` — medium-difficulty problems

Each problem has a `<id>_<name>.c` source file. Running `make` in a subdirectory
builds a same-named executable for every entry in that subdirectory's `Makefile`.

## Building

```sh
cd easy && make      # build all easy solutions
cd medium && make    # build all medium solutions
make clean            # remove built binaries (run inside either directory)
```

Built with `gcc -Wall -Wextra -g`.

## Easy

| # | Problem | File |
|---|---------|------|
| 27 | Remove Element | `27_remove_element.c` |
| 88 | Merge Sorted Array | `88_merge_sorted.c` |
| 121 | Best Time to Buy and Sell Stock | `121_best_time_to_buy.c` |

## Medium

| # | Problem | File |
|---|---------|------|
| 1 | Two Sum | `1_twosum.c` |
| 6 | Zigzag Conversion | `6_zigzag_conversion.c` |
| 36 | Valid Sudoku | `36_Valid_Sodoku.c` |
| 49 | Group Anagrams | `49_group_anagram.c`, `49_group_anagram_a.c` |
| 54 | Spiral Matrix | `54_spiralmatrix.c` |
| 55 | Jump Game | `55_jump_game.c` |
| 80 | Remove Duplicates from Sorted Array II | `80_remove_duplicates_sorted.c` |
| 134 | Gas Station | `134_gas_station.c` |
| 217 | Contains Duplicate | `217_containsduplicate.c` |
| 238 | Product of Array Except Self | `238_Product_Array_Except_Self.c` |
| 242 | Valid Anagram | `242_valid_anagram.c` |
| 271 | Encode and Decode Strings | `271_Encode_Decode_Strings.c` |
| 289 | Game of Life | `289_gameoflife.c` |
| 347 | Top K Frequent Elements | `347_top_k_frequent_elements.c` |

Notes:
- `49_group_anagram.c` and `49_group_anagram_a.c` are two different solution
  approaches to the same problem.
- `36_Valid_Sodoku.c` is a work in progress — `isValidSudoku` is not yet
  implemented and is not currently included in the `medium` `Makefile`.
