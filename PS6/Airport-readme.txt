/**********************************************************************
 *  Airport-readme template                                                   
 *  Airport Simulation (C++11 Concurrency)                       
 **********************************************************************/

Your name: Adam Baptista

Operating system you're using (Linux, OS X, or Windows): Linux

If Windows, which solution?:

Text editor or IDE you're using: Visual Studio Code

Hours to complete assignment: 10+

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
Simulate landings of multiple airplanes on multiple runways at Logan Airport.
Use thread and mutex to run multiple threads of code at the same time, which
simulated multiple landing lanes landing at the same time.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
OO design was mutex, and using switch statements to lock and unlock different
runways when they were in use.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
implemented switch statement to check if lanes are being used by different
planes.

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
Learned how to use thread and mutex libraries


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Used google to help understand how mutex and thread worked, and how to use
them.

/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
The first time I ran Airport_Sync the planes crashed after a few seconds,
but after that it ran fine, for 15 min. I do not know what caused this, so
if this happens when you test it for the first time, try again and it might 
fix itself. Another problem I had was that my terminal only saves 10000 lines
so my output.txt only has 10000 output lines.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
