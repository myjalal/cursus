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

# Save this checker in your push_swap folder.
# This checker will run your program NUM_RUNS number of times.
# The number of moves for each run is recorded in a txt file.
# It then calculates and displays the average number of moves that your program needs to sort the numbers.
# It also displays the minimum and maximum number of moves.
# This is useful when optimizing your program.
# The numbers x and y in (x..y) is the range of numbers from which the random combination of numbers is created. You can change the numbers x and y in (x..y).

NUM_RUNS=40;
COUNT_PATH=./count

#PUSH_SWAP MAKEFILE ============================================================
printf "${LP}\n*** Running makefile\n${NC}"
make re -s | wc -l

#PUSH_SWAP FOR 5 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 5 numbers\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l >> $COUNT_PATH
	i=$[$i+1]
done

count=0;
total=0;
for i in $( awk '{ print $1; }' $COUNT_PATH )
   do
     total=$(echo $total+$i | bc )
     ((count++))
   done
printf "${BLUE}\n*** Avg =\t ${NC}"
echo "scale=0; $total / $count" | bc

printf "${BLUE}\n*** Min =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | head -1
printf "${BLUE}\n*** Max =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | tail -1
cat /dev/null > $COUNT_PATH
rm $COUNT_PATH

#PUSH_SWAP FOR 100 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 100 numbers\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l >> $COUNT_PATH
	i=$[$i+1]
done

count=0;
total=0;
for i in $( awk '{ print $1; }' $COUNT_PATH )
   do
     total=$(echo $total+$i | bc )
     ((count++))
   done
printf "${BLUE}\n*** Avg =\t${NC}"
echo "scale=0; $total / $count" | bc

printf "${BLUE}\n*** Min =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | head -1
printf "${BLUE}\n*** Max =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | tail -1
cat /dev/null > $COUNT_PATH
rm $COUNT_PATH

#PUSH_SWAP FOR 200 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 200 numbers\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (1..200).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l >> $COUNT_PATH
	i=$[$i+1]
done

count=0;
total=0;
for i in $( awk '{ print $1; }' $COUNT_PATH )
   do
     total=$(echo $total+$i | bc )
     ((count++))
   done
printf "${BLUE}\n*** Avg =\t${NC}"
echo "scale=0; $total / $count" | bc

printf "${BLUE}\n*** Min =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | head -1
printf "${BLUE}\n*** Max =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | tail -1
cat /dev/null > $COUNT_PATH
rm $COUNT_PATH

#PUSH_SWAP FOR 300 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 300 numbers\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (1..300).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l >> $COUNT_PATH
	i=$[$i+1]
done

count=0;
total=0;
for i in $( awk '{ print $1; }' $COUNT_PATH )
   do
     total=$(echo $total+$i | bc )
     ((count++))
   done
printf "${BLUE}\n*** Avg =\t${NC}"
echo "scale=0; $total / $count" | bc

printf "${BLUE}\n*** Min =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | head -1
printf "${BLUE}\n*** Max =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | tail -1
cat /dev/null > $COUNT_PATH
rm $COUNT_PATH

#PUSH_SWAP FOR 400 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 400 numbers\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (1..400).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l >> $COUNT_PATH
	i=$[$i+1]
done

count=0;
total=0;
for i in $( awk '{ print $1; }' $COUNT_PATH )
   do
     total=$(echo $total+$i | bc )
     ((count++))
   done
printf "${BLUE}\n*** Avg =\t${NC}"
echo "scale=0; $total / $count" | bc

printf "${BLUE}\n*** Min =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | head -1
printf "${BLUE}\n*** Max =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | tail -1
cat /dev/null > $COUNT_PATH
rm $COUNT_PATH

#PUSH_SWAP FOR 500 NUMBERS ============================================================
printf "${LP}\n*** Running pushswap for 500 numbers\n${NC}"
i="0"
while [ $i -lt $NUM_RUNS ]
	do
	ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l >> $COUNT_PATH
	i=$[$i+1]
done

count=0;
total=0;
for i in $( awk '{ print $1; }' $COUNT_PATH )
   do
     total=$(echo $total+$i | bc )
     ((count++))
   done
printf "${BLUE}\n*** Avg =     ${NC}"
echo "scale=0; $total / $count" | bc

printf "${BLUE}\n*** Min =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | head -1
printf "${BLUE}\n*** Max =  ${NC}"
cat $COUNT_PATH | sort -nk1,1 | tail -1
cat /dev/null > $COUNT_PATH
rm $COUNT_PATH
