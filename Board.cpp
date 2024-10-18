
#include "Board.h";


void Board::PaintBoard() {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cout << board[i][j];
            if (j < x - 1) cout << " | ";  
        }
        cout << endl;
        if (i < y - 1) cout << "---------" << endl;  
    }
    cout << endl;
}
void Board::Clear()
{
    system("cls");
}

bool Board::GetInput(int x, int y,int playerOrder)
{
    board[y][x] = (playerOrder==2)?'X':'O';
    return CheckWin(x,y,playerOrder);
   
}
bool Board::ValidateInput(int x, int y)
{
    bool result=board[y][x] == ' '&&x<3&&x>=0&&y<3&&y>=0;
    if (result == false)
        cout << "InvalidPosition" << endl;
    return result;
      
}
bool Board::CheckWin(int lastX, int lastY, int playerOrder) 
{
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            cout << "Player " << (board[i][0] == 'X' ? 1 : 2) << " wins (horizontal)!" << endl;
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            cout << "Player " << (board[0][j] == 'X' ? 1 : 2) << " wins (vertical)!" << endl;
            return true;
        }
    }

  
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        cout << "Player " << (board[0][0] == 'X' ? 1 : 2) << " wins (diagonal)!" << endl;
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        cout << "Player " << (board[0][2] == 'X' ? 1 : 2) << " wins (diagonal)!" << endl;
        return true;
    }

  
    bool draw = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = false;  
                break;
            }
        }
    }

    if (draw) {
        cout << "It's a draw!" << endl;
        return true;
    }
    return false;
}
Board::Board()
{
    x = 3;
    y = 3;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            board[i][j] = ' ';  
        }
    }
}
Board::~Board()
{
    delete(board);
}