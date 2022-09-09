/**********************************************************************
 *  ps2-readme template                                                   
 *  Recursive Graphics (Pythagoras tree)                       
 **********************************************************************/

Your name: Adam Baptista

Hours to complete assignment: 5 days

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
The assignment was to code the pythagoras tree using sfml and recursion,
and I acomplished it.

 /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
A key algorithm I used to design the tree was to set the origin of the 
left square to the bottom left and the position of the origin to the top
left of the previously drawn square, then rotated +45 deg. The right side 
was similar which was that I set the origin of the right square to the 
bottom right and the positon to the top right of the previously drawn 
square, then rotated -45 deg.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
else if(Keyboard::isKeyPressed(Keyboard::Right)) {
    if (iter < N)
        iter++;
} 

this code excerpts that I added to the assignment was to show each iteration
after the RIGHT arrow key was pressed.

To implement the 30,60,90 triangle pythagoras tree I used the formula, x = hypotnuse,
x/2 is the shorter side, and (x/2)/sqrt(3) is the longer side. I just changed the size of
the right triangle to size/2 and the other side to (side/2)/sqrt(3), and I changed the right 
square rotate angle to -30 deg, and the left square rotation to +60 deg.

 /**********************************************************************
 *  Briefly explain what you learned in the assignment.
 **********************************************************************/
I learned how to code the pythagoras tree in c++ using sfml.


/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
google for sfml.


/**********************************************************************
 *  Describe any serious problems you encountered.  
 *  If you didn't complete any part of any assignment, 
 *  the things that you didn't do, or didn't get working.                  
 **********************************************************************/
 The majority of the time I spent on this assignment was figuring out
the recursuve part of the assignment because I had a hard time setting 
the different origins and positions correctly.

I also didn't include the drawable class because I do not understand 
how to implent it, but I just got the adress of the window, so I could
draw the shape within the function, which worked fine.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 USE THE RIGHT ARROW KEY TO GO THROUGH THE ITERATIONS.