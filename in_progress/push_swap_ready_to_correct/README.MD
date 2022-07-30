03 JULY 2022


was able to fill the list, verify if it already sorted, then created function 
top and bottom to be able to add a node to the top or bottom of the list
(FILE POPULATE.C)

created a function called ft_free, to be able to free a full liked list
(FILE UTILS.C)

created all the move functions SA SB (swap) PA PB (one_top_two) RA RB (revers)
RRA RRB (r_revers) (FILE MOVE.C)

now need to work on algo 

# run python

python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

# run valgrind

valgrind --leak-check=full --show-leak-kinds=all ./push_swap "1 2 3 5 6"  

### or regulare check

valgrind --leak-check=ok ./push_swap "1 2 3 6 4 9 8"

# run test

ARG=`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l

| wc -l     is to count how may moves outputted 
