/**********************************************************************
 *  readme.txt template                                                   
 *  Kronos PS7a startup
 **********************************************************************/

Name: Adam Baptista


Hours to complete assignment: 5


/**********************************************************************
 *  Did you complete the whole assignment?
 *  Successfully or not? 
 *  Indicate which parts you think are working, and describe
 *    how you know that they're working.
 **********************************************************************/
I have successfully completed the assignment

/**********************************************************************
 *  Copy here all regex's you created for parsing the file, 
 *  and explain individually what each ones does.
 **********************************************************************/
str_boot = "(.*log.c.166.*)";
this just finds any line with the string "log.c.166" in it

str_done = "(.*oejs.AbstractConnector:Started SelectChannelConnector.*)";
this finds any line that has the string "oejs.AbstractConnector:Started 
SelectChannelConnector" in it

str_time = "([[:digit:]]{2}):([[:digit:]]{2}):([[:digit:]]{2})";
this finds any 2 digits between ":" and is put into 3 different groupings

str_date = "([[:digit:]]{4})-([[:digit:]]{1,2})-([[:digit:]]{1,2}) ";
this does the same thing time does, except find 4 digits, and 1-2 digits
seperated by "-" and puts them into 3 different groupings

/**********************************************************************
 *  Describe your overall approach for solving the problem.
 *  100-200 words.
 **********************************************************************/
I started by looking at the output files for device 5 and tried to make
my output look similar to that format. I then used regex101.com to try 
different regex sequences to find which one worked best at matching
the characters that I wanted it to match to.

/**********************************************************************
 *  List whatever help (if any) you received from lab TAs,
 *  classmates, or anyone else.
 **********************************************************************/
regex101.com

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
figuring out how to format because the pdf didnt have a lot of information

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
none