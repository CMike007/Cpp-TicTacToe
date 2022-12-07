# Tic Tac Toe

This project is part of the course "Programming with Advanced Computer Languages" at the University of St. Gallen (HSG) held in the autumn semester of 2022. The purpose is to program the well known game Tic Tac Toe.

### Commenting

Since this project is part of a University project the code is provided twice once as a plain code and once with all-encompassing comments that describe the functionaly of the different parts of the code.

### Structure

In the follwing you can find an explanation and the general structure of the program.

Section 1 
- Including header files
- Prototyping the used functions

Section 2
- Main
    Do-while loop that repeatedly calls the input and draw functions as long as the logic function is true. As soon as the logic function determines the game to be over, the draw function is called one last time and the result of the game is printed out.

Section 3
Actual Definition of the used functions
  
- draw function
    Responsible for drawing the grid. Whenever the displayed variables are updated, through a viable input of one of the players, it is called again to visualize those updates.

- logic function
    Checks if a game ending condition is met. The game can either end because all the fields are chosen, therefore resulting in a draw, or because one player achieves the goal of connecting a "line" of 3 of his inputs.
    
- input_exception_handler function
    Responsible for prompting the player to input a number and then checking the Input for validity. An Input can be invalid for multiple reasons: 
    - Inputting an Integer Value that is out of bounds (smaller 1 or bigger 9)
    - Inputting a Value that responds to an already chosen field
    - Inputting anything else then an Integer Value in general
    As long as the input is valid the function returns that input.
    

