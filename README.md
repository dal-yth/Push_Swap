# Push_Swap
42 school algorithm project.

##### Score 114/100

This project involves sorting data on a stack, with limited number of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

### Features
- Insertion sort
- Homebrew quick/mergesort
- Visualizer

### Running the programs
The project consist of two programs. Push_swap and checker. Push_swap takes a list of numbers as argument, verifies is, uses limited instructions to sort it and prints out the instructions on standard output. Checker takes the same list of numbers as argument and reads the output from push_swap, it then executes these instructions on the list of numbers to make sure they actually get sorted.
##### Usage: push_swap num1 num2 num3... | checker num1 num2 num3...
##### For example: push_swap 3 1 2 | checker 3 1 2

As a bonus, because typing long lists of numbers is tedious, both programs can read from a file with -f: push_swap -f file | checker -f file.
Full options for checker program are: -fdbvco
- **-f** --file, reads input from a file.
- **-d** --debug mode, prints out both stacks after every instruction.
- **-b** --basic visualization, prints out simple visuals for stacks that only include numbers.
- **-v** --visualizer, in addition to showing the actual numbers, shows bars relative to the size of number.
- **-c** --color, colors the last executed instruction.
- **-o** --operatioms, counts the operations and prints them out once they are executed.

### Instructions
These are the allowed instructions push_swap program is allowed to use when it sorts the stack. Push_swap may only use 2 stacks, stack A where all the numbers are at the beginning and stack B which is empty at the beginning.
- **sa:** swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
- **sb:** swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
- **ss:**  sa and sb at the same time.
- **pa:** push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty
- **pb:** push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- **ra:** rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
- **rb:** rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
- **rr:** ra and rb at the same time.
- **rra:** reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
- **rrb:** reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one
- **rrr:** rra and rrb at the same time.

### Insertion sort
First we push every number from stack A to stack B, except for the smallest and biggest number. Like this we never have to consider any special cases if the number we are about to push happens to be smallest or largest and only fits in specific position. Every number is just something between largest and smallest value and we only need to figure out a position in stack A, where number below is larger and number above is smaller. 

The above check is done to every number in stack B and we calculate how many instructions does it take to move the number from stack B to stack A, then we move the number that took the least amount of instructions. We keep repeating this until all the numbers have been moved to stack A and then we rotate stack A until the smallest value is at the top.

It should be noted that insertion sort is is best with small sets of numbers. In my testing I found out that after roughly 350 numbers in a set, my homebrew sort started to perform much better as the amount of instructions required with insertion sort increase massively after 350 numbers and when the amount of numbers reached thousands, the insertion sort performed very poorly, requiring many times the moves of my homebrew sort.

### Homebrew sort
The idea to this algorithm came from quicksort, but someone later pointed out that it sounds like mergesort. The idea is that we check stack A to find out the median value of all the numbers and we push everything larger than that to stack B. So first we push half of the numbers to stack B and we know that these are the largest values in the set. Then we repeat the same until all but 3 values have been moved to stack B. So we take the median value again and push the larger ones to B, and repeat. 3 values can be sorted optimally with very few instructions so this is our baseline.

As the first pushing to B has been done, we now have the numbers in chunks, where the topmost chunks in stack B have the fewest numbers and the numbers are also smallest. Then we move onto the stack B and keep repeating the same operation we did to the whole stack A, except this time we consider each chunk to be its own little stack. So we take the median value of the chunk and push smallest values to stack A. If it happens that we pushed 3 or less numbers, we sort the values in stack A because as I noted earlier, sorting 3 numbers takes very few instructions. IF there were more than 3 numbers, we move onto stack A and split around the median again, creating another chunk in stack B.

So we keep finding medians of the pushed chunks until the size of the current chunk is 3 or less and we can optimally sort it. We do this to every chunk, splitting them to more and more smaller chunks and sorting the smallest chunks in stack A.

This kind of sorting has one advantage over insertion sort and that is linear growth in amount of moves required in relation to the amount of numbers provided. The insertion sort performs much better when there are few numbers, up to around 350, but afterwards it can't compete with homebrew sort.
