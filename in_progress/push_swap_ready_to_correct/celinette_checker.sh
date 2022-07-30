# Black        0;30     Dark Gray     1;30
# Red          0;31     Light Red     1;31
# Green        0;32     Light Green   1;32
# Brown/Orange 0;33     Yellow        1;33
# Blue         0;34     Light Blue    1;34
# Purple       0;35     Light Purple  1;35
# Cyan         0;36     Light Cyan    1;36
# Light Gray   0;37     White         1;37

LRED='\033[1;31m'
BLUE='\033[1;34m'
LP='\033[1;35m'
NC='\033[0m' # No Color

# This checker requires that you use the checker provided for this project.
# This checker will run your program NUM_RUNS number of times, count the number of KO's, and return this number.
# This is useful to quickly check that your program is still working for several different combination of numbers.
# The numbers x and y in (x..y) is the range of numbers from which the random combination of numbers is created. You can change the numbers x and y in (x..y).

NUM_RUNS=20;

#PUSH_SWAP MAKEFILE ============================================================
printf "${LP}\n*** Running makefile\n${NC}"
make re -s | wc -l

printf "${LP}Number of runs: ${NC}"
echo $NUM_RUNS

#PUSH_SWAP FOR 200 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for -201 to 200\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (-201..200).to_a.shuffle.join(' ')"`;valgrind --leak-check=full ./push_swap $ARG | ./checker_Mac $ARG >> './celinette_checker'
	i=$[$i+1]
done
printf "${BLUE}\n*** number of KO = \t ${NC}"
grep -o "KO" '/Users/jechekao/Desktop/cursus/in_progress/push_swap/celinette_checker' | wc -l
cat /dev/null > './celinette_checker'

#PUSH_SWAP FOR -100 to 100 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for -1000 to 1000\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (101..564).to_a.shuffle.join(' ')"`;valgrind --leak-check=full ./push_swap $ARG | ./checker_Mac $ARG >> './celinette_checker'
	i=$[$i+1]
done
printf "${BLUE}\n*** number of KO = \t ${NC}"
grep -o "KO" './celinette_checker' | wc -l
cat /dev/null > './celinette_checker'
