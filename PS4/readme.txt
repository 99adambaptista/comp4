/**********************************************************************
 *  readme template                                                   
 *  DNA Sequence Alignment
 **********************************************************************/

Name:Adam Baptista
implementation: Needleman-Wunsch
os: linux
array method: c-array
cpu: i7

Hours to complete assignment: 10



/**********************************************************************
 *  Explain what you did to find the alignment itself.
 **********************************************************************/
I used the Needleman-Wunsch method to find the alignment


/**********************************************************************
 * Does your code work correctly with the endgaps7.txt test file? 
 * 
 * This example should require you to insert a gap at the beginning
 * of the Y string and the end of the X string.
 **********************************************************************/
Input: ./ED < sequence/endgaps7.txt

Expected output:

a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

What happened:

Edit distance: 4
a - 2
t t 0
a a 0
t t 0
t t 0
a a 0
t t 0
- a 2

Execution time is 1e-06 seconds
Edit distance (for longer sequences): 4



/**********************************************************************
 *  How much main memory does your computer have? Typical answers
 *  are 2 GB to 16 GB.
 **********************************************************************/
16GB


/**********************************************************************
 *  For this question assume M=N. Look at your code and determine
 *  approximately how much memory it uses in bytes, as a function of 
 *  N. Give an answer of the form a * N^b for some constants a 
 *  and b, where b is an integer. Note chars are 2 bytes long, and 
 *  ints are 4 bytes long.
 *
 *  Provide a brief explanation.
 *
 *  What is the largest N that your program can handle if it is
 *  limited to 8GB (billion bytes) of memory?
 **********************************************************************/
a = 
b = 
largest N =
i dont understand

/**********************************************************************
 *  Were you able to run Valgrind's massif tool to verify that your
 *  implementation uses the expected amount of memory?
 *
 *  Answer yes, no, I didn't try, I tried and failed, or I used a 
 *  different tool.
 *
 *  If yes, paste in the ms_print top chart of memory use over time,
 *  and also indicate which file your code was solving.
 * 
 *  Explain if necessary.
/**********************************************************************
yes, from the startygap.txt
--------------------------------------------------------------------------------


    KB
76.31^                                                                       #
     |                                                                      @#
     |                                                                  ::::@#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
     |                                                                  :   @#
   0 +----------------------------------------------------------------------->Mi
     0                                                                   2.550

Number of snapshots: 41
 Detailed snapshots: [9, 13, 23, 28 (peak), 38]



/**********************************************************************
 *  For each data file, fill in the edit distance computed by your
 *  program and the amount of time it takes to compute it.
 *
 *  If you get segmentation fault when allocating memory for the last
 *  two test cases (N=20000 and N=28284), note this, and skip filling
 *  out the last rows of the table.
 **********************************************************************/

data file           distance       time (seconds)     memory (MB)
------------------------------------------------------------------
ecoli2500.txt       118             1.269s              25MB
ecoli5000.txt       160             4.88s               100MB
ecoli7000.txt       194             9.47s               196MB
ecoli10000.txt      223             19.91s              400MB
ecoli20000.txt      3135            79.18               1601MB
ecoli28284.txt      terminal crashes

/*************************************************************************
 *  Here are sample outputs from a run on a different machine for 
 *  comparison.
 ************************************************************************/

data file           distance       time (seconds)
-------------------------------------------------
ecoli2500.txt          118             0.171
ecoli5000.txt          160             0.529
ecoli7000.txt          194             0.990
ecoli10000.txt         223             1.972
ecoli20000.txt         3135            7.730



/**********************************************************************
 *  For this question assume M=N (which is true for the sample files 
 *  above). By applying the doubling method to the data points that you
 *  obtained, estimate the running time of your program in seconds as a 
 *  polynomial function a * N^b of N, where b is an integer.
 *  (If your data seems not to work, describe what went wrong and use 
 *  the sample data instead.)
 *
 *  Provide a brief justification/explanation of how you applied the
 *  doubling method.
 * 
 *  What is the largest N your program can handle if it is limited to 1
 *  day of computation? Assume you have as much main memory as you need.
 **********************************************************************/
a = 
b = 
largest N = 
i dont understand

**********************************************************************
 *  Did you use the lambda expression in your assignment? If yes, where (describe a method or provide a lines numbers)
 **********************************************************************/
no


**********************************************************************
 *  List whatever help (if any) you received from the course TAs,
 *  instructor, classmates, or anyone else.
 **********************************************************************/
only google for how to delete 2d array


/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
kept trying to use for loops to trace back the matrix, so i was stuck
on that part for a while.


/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
