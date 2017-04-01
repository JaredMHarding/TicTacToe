▪ Name and the last 5 digits of student id for all team members.

    Jared Harding,      09583
    Colin St. Claire,   06003
    
▪ How to build and run your code.

    In the terminal, run the make file by typing "make" on the command line.
    This will create a "Games" file.
    Run the games file on the command line with the game you want to play as the argument.
    
    "./Games TicTacToe" or "./Games TicTacNo"
    
    Each game will prompt the user to input a row number and then a column number to place their mark (0 based).
    
▪ What is the rule of the second game? Explain the win, lose, and draw status.

    The game is called TicTacNo, very similar to TicTacToe.
    This is played on a 5x5 grid.
    The goal of the game is to avoid making 3 in a row, whoever makes 3 in a row first loses, and the other player wins.
    If neither player makes 3 in a row, the game will end in a draw.
    
▪ What is inheritance in object oriented programming and how do you use it in this project?

    Inheritance is when a class inherits from a base class.
    The base class typically has functions and variables that can be used by inheriting class.
    
    In this project, our base class "GridGame" is being inherited by both the "TicTacToe" class and the "NewGame" class.
    This is because they both have an "is a" relationship with GridGame.

▪ What is object composition in object oriented programming and how do you use it in this project?

    Composition is when an object has a "has a" relationship with another class.
    
    In this project, the GridGame class has an instance of the Grid class.

▪ What is running time polymorphism and how do you use it in this project?

    Running time polymorphism is when something can behave differently based on the circumstances at runtime.
    An example of this involves virtual functions.
    We use virtual functions in the GridGame base class that expect to be overwritten by the TicTacToe and NewGame classes.

▪ What algorithms do you use for the “placeMark” method in the two game classes respectively? Is it a perfect algorithm? Explain how it works?

    In the TicTacToe game, we tried to implement a typical minimax algorithm at first.
    But after multiple attempts with no success, we decided to do something different.
    Now our ai algorithm is much simpler, it just looks for spots where it can do the following...
        1. Can it make 3 in a row?
        2. Can it block the human player from making 3 in a row?
        3. If it can't do either of those, it will pick a random spot.
    This is not a perfect algorithm, as it will occationally lose the game.
    But this algorithm still works relatively well, and still at least puts up a fight.
    
    In the TicTacNo game, we went about the ai a slightly different way.
    The ai checks which spots it should try to avoid by adding them to 2 lists.
        - A list where the AI can make 3 in a row.
        - A list where the human can make 3 in a row.
    All remaining spots get put into a safe list.
    The ai will then choose where to place its mark in the following way...
        1. If there are any spots in the safe list, randomly pick one of those.
        2. Otherwise, if there are any spots where it can block the human from making 3 in a row, randomly pick one of those.
        3. Finally, if there is no other choice, then it will pick a spot where it will make 3 in a row, which will then make it lose the game.
    Since the ai makes fairly random moves, it is still possible to beat if you play well.
    However, since it will only pick spots where it makes 3 in a row as a last resort, it is still fairly challenging.