
#include <iostream>
#include <string>
using namespace std;

// prototyping the functions
int input_exception_handler(string player, string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *input);
void draw(string A, string B, string C, string D, string E, string F, string G, string H, string I);
bool logic(string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *winner);



int main() {
    // declaring the variables needed
    // different fields the player can choose 
    string A = ("1");
    string B = ("2");
    string C = ("3");
    string D = ("4");
    string E = ("5");
    string F = ("6");
    string G = ("7");
    string H = ("8");
    string I = ("9");
    string player = ("X");          // sign of player 1
    string not_player = ("O");      // sign of player 2
    int field = {0};                // variable that receives the field chosen by a player (initialized to 0)
    bool input = true;              // check used in the do-while loop of the input_exception_handler function (pointer to that is passed to the function so it can be set within the loop and used outside)
    bool winner = true;             // passed as a pointer to the logic function - only gets used and set to false if all fields are chosen and there´s no winner
    
    // do-while loop to keep the game on until logic is set to false (either one player wins or all fields are taken)
    do {
        // calling the draw function to visualize the playing field
        draw(A, B, C, D, E, F, G, H, I);
        field = input_exception_handler(player, A, B, C, D, E, F, G, H, I, &input); // getting the input of the player
        //changing the underlying variable of the field the player chose
        if (field == 1)
            A = player;
        else if (field == 2)
            B = player;
        else if (field == 3)
            C = player;
        else if (field == 4)
            D = player;
        else if (field == 5)
            E = player;
        else if (field == 6)
            F = player;
        else if (field == 7)
            G = player;
        else if (field == 8)
            H = player;
        else if (field == 9)
            I = player;
        
        // changing the player 
        string saver = player;
        player = not_player;
        not_player = saver;

    } while(logic(A, B, C, D, E, F, G, H, I, &winner));
    // we´re repeating the loop as long as the logic returns true (no game ending criteria met)
    
    // drawing the playing filed a last time (to visualize the last choice that ended the game)
    draw(A, B, C, D, E, F, G, H, I);
    
    // Declaring the winner or that the game ended in a draw (got decided in the logic function - if winner got set to false or not)
    if (winner == true){
        if (player == "X")
            cout << "Player 2 has won ... good game!\n\n" << endl;
        else
            cout << "Player 1 has won ... good game!\n\n" << endl;
    } else
        cout << "The game ended in a draw!\n\n" << endl;

    return 0;
}

// draw function (only responsible for "drawing" the field - what is printed on the field comes through the string inputs)
void draw(string A, string B, string C, string D, string E, string F, string G, string H, string I){
    
    system("clear");           // the console is cleared before printing the grid again to make it appear only the input changed
    
    cout << "\n\n Tick Tack Toe \n\n " << endl;
    cout << "  " << A << "  |  " << B <<  "  |  " << C << endl;
    cout << "---------------" << endl;
    cout << "  " << D << "  |  " << E <<  "  |  " << F << endl;
    cout << "---------------" << endl;
    cout << "  " << G << "  |  " << H <<  "  |  " << I << "\n\n" << endl;
}

// logic function (returns a true result until either one player wins or all fields are taken
bool logic(string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *winner){
    
    // the result is initialized as true
    bool result = true;
    
    // if statements to change the result to false (game is over) if the conditions that one player has won are fulfilled
    if (A == B && B == C)
        result = false;
    else if (A == D && D == G)
        result = false;
    else if (B == E && E == H)
        result = false;
    else if (C == F && F == I)
        result = false;
    else if (G == H && H == I)
        result = false;
    else if (D == E && E == F)
        result = false;
    else if (A == E && E == I)
        result = false;
    else if (C == E && E == G)
        result = false;
    // if statement to change the result to false (game is over) if the choices are exhausted
    else if (A != "1" && B != "2" && C != "3" && D != "4" && E != "5" && F != "6" && G != "7" && H != "8" && I != "9"){
        result = false;
        *winner = false;        // in this case we set the variable winner the pointer *winner is pointing to to false 
    }        
    return result;
}

// exception handling for number inputs
int input_exception_handler(string player, string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *input) {
    int result = {0};
    do {    
            // the loop gets executed because we had a "wrong" input (non integer input)
            if (cin.fail()){
                cin.clear();                                            // clears the error flag
                cin.ignore(numeric_limits<int>::max(), '\n');           // let´s the program ignore any input that is not a double
            } 
            
            // initial prompt to let the player choose the field he want´s to mark
            if (player == "X")
                cout << "Player 1 please select a field: ";
            else
                cout << "Player 2 please select a field: ";
            cin >> result;
            
            // we´re setting the pointer to true (standard)
            *input = true;
            
            // we´re controlling for possible errors (here: the field was already chosen before)
            if (result == 1 && A != "1")
                *input = false;
            else if (result == 2 && B != "2")
                *input = false;
            else if (result == 3 && C != "3")
                *input = false;
            else if (result == 4 && D != "4")
                *input = false; 
            else if (result == 5 && E != "5")
                *input = false;
            else if (result == 6 && F != "6")
                *input = false;
            else if (result == 7 && G != "7")
                *input = false;
            else if (result == 8 && H != "8")
                *input = false;
            else if (result == 9 && I != "9")
                *input = false;
            else if (result > 9 || result < 1)  //(here: the chosen number is "out of bounds")
                *input = false;
            
            // based on why we got an input problem we print one of the two messages (clarifying what went wrong)
            if (*input == false && 0 < result && result < 10)
                cout << "This field is already taken... please select a possible option" << endl;
            else if ((*input == false && 0 < result) || (*input == false && result < 10))
                cout << "The entry has to be an integer between 1 and 9, please try again" << endl;
                
        } while(cin.fail() || *input == false); 
         // we repeat the loop of asking for input as long as we get input that is "calssified" as false or  
         // that simply doesn´t meet the data type of the underlying variable (here: field "int")
        
    return result;
}
