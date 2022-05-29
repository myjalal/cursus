#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include "libft.h"
#include <stdbool.h> // check if you are allower to use false and true and bool

typedef struct node
{
	int	num;
	struct node *next;
	struct node *previous;
} t_node;

typedef struct var
{
	char **temp; // ft_split list temp
	int len; // size of list 
	t_node *a; // list a
	t_node *b; // list b
} t_var;

/*-------check_arg.c--------*/
/*
static int 	digit_check(char *argv);
static int 	is_neg(char *argv, bool *neg, int i);
int check_int(char *argv);
int check_arg(int argc, char **argv);
*/
/*-------check_dup.c--------*/
//check if there is a duplicate number in args
void check_duplic(char **argv);
//compare string
int	ft_strcmp(const char	*s1, const char	*s2);





#endif

/*
- check if there at least 2 argc
- split spaces " "from argv[]
- add argc into temp list
- check if the number are correct valid arg
- check duplicates 
- populate list A
- validate is list A is correctly populated
- if lenth is <= 10 (short sort)
- if lenth is > 10 (long sort)
*/