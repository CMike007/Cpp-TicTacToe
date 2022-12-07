
#include <iostream>
#include <string>
using namespace std;

int input_exception_handler(string player, string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *input);
void draw(string A, string B, string C, string D, string E, string F, string G, string H, string I);
bool logic(string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *winner);


int main() {
    string A = ("1");
    string B = ("2");
    string C = ("3");
    string D = ("4");
    string E = ("5");
    string F = ("6");
    string G = ("7");
    string H = ("8");
    string I = ("9");
    string player = ("X");        
    string not_player = ("O");      
    int field = {0};               
    bool input = true;               
    bool winner = true;             
    
    do {
        draw(A, B, C, D, E, F, G, H, I);
        field = input_exception_handler(player, A, B, C, D, E, F, G, H, I, &input);
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
        
        string saver = player;
        player = not_player;
        not_player = saver;

    } while(logic(A, B, C, D, E, F, G, H, I, &winner));

    draw(A, B, C, D, E, F, G, H, I);
    
    if (winner == true){
        if (player == "X")
            cout << "Player 2 has won ... good game!\n\n" << endl;
        else
            cout << "Player 1 has won ... good game!\n\n" << endl;
    } else
        cout << "The game ended in a draw!\n\n" << endl;

    return 0;
}

void draw(string A, string B, string C, string D, string E, string F, string G, string H, string I){
    
    system("clear");
    
    cout << "\n\n Tick Tack Toe \n\n " << endl;
    cout << "  " << A << "  |  " << B <<  "  |  " << C << endl;
    cout << "---------------" << endl;
    cout << "  " << D << "  |  " << E <<  "  |  " << F << endl;
    cout << "---------------" << endl;
    cout << "  " << G << "  |  " << H <<  "  |  " << I << "\n\n" << endl;
}

bool logic(string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *winner){
    
    bool result = true;
   
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

    else if (A != "1" && B != "2" && C != "3" && D != "4" && E != "5" && F != "6" && G != "7" && H != "8" && I != "9"){
        result = false;
        *winner = false;  
    }        
    return result;
}

int input_exception_handler(string player, string A, string B, string C, string D, string E, string F, string G, string H, string I, bool *input) {
    int result = {0};
    do {    
            if (cin.fail()){
                cin.clear();                                         
                cin.ignore(numeric_limits<int>::max(), '\n');       
            } 
            
            if (player == "X")
                cout << "Player 1 please select a field: ";
            else
                cout << "Player 2 please select a field: ";
            cin >> result;
            
            *input = true;
            
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
            else if (result > 9 || result < 1) 
                *input = false;

            if (*input == false && 0 < result && result < 10)
                cout << "This field is already taken... please select a possible option" << endl;
            else if ((*input == false && 0 < result) || (*input == false && result < 10))
                cout << "The entry has to be an integer between 1 and 9, please try again" << endl;
                
        } while(cin.fail() || *input == false); 
        
    return result;
}
