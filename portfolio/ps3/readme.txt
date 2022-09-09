/**********************************************************************
 *  N-Body Simulation ps3b-readme.txt template
 **********************************************************************/

Name: Adam Baptista
Hours to complete assignment: ~10

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
Simulate celestial bodies and gravity using the sfml library

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
the physics formulas for gravity was central to the assignment.




/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
To print the state of the universe at the end of the simulation I just outputted the
current x and y positions, and the x and y velocities at the time the window is 
closed.
To make the planets rotate counter clockwise, i just -= for all acceleration and
velocities, because when it was +=, it was going clockwise.
Used shared pointers from before.
To play the song, I had to change the makefile to include -lsfml-audio in the LIBS,
otherwise it didnt work.
To display text i had to download a .ttf file to get text, and i also had to look
online on how to do it.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
Had to go online to search how to play sound and display text.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Took me forever to figure out how to make the planets move reasonably,
i was stuck the majority of the time with the planets just going up, or
just going in one direction, or dissapearing 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
