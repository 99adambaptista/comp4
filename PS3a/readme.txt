/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Adam Baptista
Hours to complete assignment: 15

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
get input from the user from a text file, and place planets in a simulted 
enviroment
  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
shared_ptr were needed to be able to plot multiple bodies in the 
simulation



/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
I implemented the drawable class within the Body class with " : public Drawable"
i used stdin by just cin the file's data into the specific variables, then 
put them into the body class.
used smart pointers by creating a vector of small pointers with vector<shared_ptr<Body>>;
makefile does all the make file needs to do

didnt add the scale, didnt have time to figure it out, didnt work well for me
when reading the files, the spaces before the input messes up my program, which
i plan to fix for ps3b

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Used google to find out how to scale the background to the size of the window

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
had probelms reading the file, always cin "" and the program would crash.
also I used unique_ptr in the beginning, which made my life harder because it
would delete the pointer and I kept trying to figure out how to not let it 
get deleted.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
