#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

const int MAX = 20;
void pattern();
void gotoxy(int x, int y);
void erase(int x, int y);
char getCharAtxy(short int x, short int y);
void PrintPacman(int x, int y);
void clear(int x, int y, char previous);
string pattern(string record, int field);
void readpattern();
void printenemy();
void eraseenemy();
void moveenemy();
void moveVerticalEnemy();
void showMenu();
void playGame();
void instructions();
void Header();
void keys();

int enemyX = 40;
int enemyY = 10;
int enemyX2 = 22;
int enemyY2 = 5;

char enemy1[1] = {'E'};
char enemy2[1] = {'E'};

string enemydirection = "right";
string enemydirection2 = "down";

string readmaze[MAX];
int idx = 0;
int score = 0;
int lives = 3;

int main() {
    system("Color 0E");

    showMenu();

    return 0;
}

void showMenu() {
    
    system("cls");
	Header();
	int select;
    cout << "1--> Play\n";
    cout << "2--> Instructions\n";
    cout << "3--> Keys\n";
    cout << "4--> Quit\n";
    cout << "Choose option from 1 to 4 " << endl;
    cout << "Enter your option = ";
    cin >> select;
     if (select == 1)
    {
        playGame();
    }
    else if (select == 2)
    {
        instructions();
    }
    else if (select == 3)
    {
    	keys();
	}

}
void playGame() {
    int pacmanX = 4;
    int pacmanY = 4;
    bool gamerunning = true;

    system("CLS");
    pattern();
    PrintPacman(pacmanX, pacmanY);
    gotoxy(50, 10);
    cout << "Score=" << score;
    gotoxy(50, 15);
    cout << "Lives Remaining: " << lives;

      while (gamerunning && lives > 0) {
        moveenemy();
        moveVerticalEnemy();

        if (GetAsyncKeyState(VK_LEFT)) {
            char nextLocation = getCharAtxy(pacmanX - 1, pacmanY);
            if (nextLocation == ' ') {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX - 1;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '&' || nextLocation == '#' || nextLocation == 'E') {
                gotoxy(50, 15);
                cout << "Lost a Life! Lives Remaining: " << lives - 1;
                lives--;
                Sleep(100);
            } else if (nextLocation == '.') {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX - 1;
                score += 1;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '*') {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX - 1;
                score += 4;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            }
            
        } else if (GetAsyncKeyState(VK_RIGHT)) {
            char nextLocation = getCharAtxy(pacmanX + 1, pacmanY);
            if (nextLocation == ' ') {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX + 1;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '&' || nextLocation == '#' || nextLocation == 'E') {
                gotoxy(50, 15);
                cout << "Lost a Life! Lives Remaining: " << lives - 1;
                lives--;
                Sleep(100);
            } else if (nextLocation == '.') {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX + 1;
                score += 1;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '*') {
                erase(pacmanX, pacmanY);
                pacmanX = pacmanX + 1;
                score += 4;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            }
            
        } else if (GetAsyncKeyState(VK_UP)) {
            char nextLocation = getCharAtxy(pacmanX, pacmanY - 1);
            if (nextLocation == ' ') {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY - 1;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '&' || nextLocation == '#' || nextLocation == 'E') {
                gotoxy(50, 15);
                cout << "Lost a Life! Lives Remaining: " << lives - 1;
                lives--;
                Sleep(100);
            } else if (nextLocation == '.') {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY - 1;
                score += 1;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '*') {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY - 1;
                score += 4;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            }
            
        } else if (GetAsyncKeyState(VK_DOWN)) {
            char nextLocation = getCharAtxy(pacmanX, pacmanY + 1);
            if (nextLocation == ' ') {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY + 1;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '&' || nextLocation == '#' || nextLocation == 'E') {
                gotoxy(50, 15);
                cout << "Lost a Life! Lives Remaining: " << lives - 1;
                lives--;
                Sleep(100);
            } else if (nextLocation == '.') {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY + 1;
                score += 1;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            } else if (nextLocation == '*') {
                erase(pacmanX, pacmanY);
                pacmanY = pacmanY + 1;
                score += 4;
                gotoxy(50, 10);
                cout << "Score=" << score;
                PrintPacman(pacmanX, pacmanY);
            }
            
        } else if (GetAsyncKeyState(VK_ESCAPE)) {
            gamerunning = false;
        }

        Sleep(100);
    }

    system("cls");
    if (lives == 0) {
        cout << "Game Over" << endl;
        cout << "Your Score: " << score << endl;
        cout << "You ran out of lives. Play Better Next Time";
    } else {
        cout << "Game Over" << endl;
        cout << "Your Score: " << score << endl;
        cout << "Lives Remaining: " << lives << endl;
        cout << "Play Better Next Time";
    }

   
}

void instructions() {
    system("cls");
	Header();
   
    cout << "- Use arrow keys to move Pacman" << endl;
    cout << "- Avoid enemies ('E'), walls ('#'), and other obstacles" << endl;
    cout << "- Collect dots ('.') for points" << endl;
    cout << "- Collect power-ups ('*') for bonus points" << endl;
    cout << "- Press ESC to quit the game" << endl;
    cout << "Press any key to return to the main menu...";
    getch();
    showMenu();
}
void keys()
{
	system("cls");
	Header();
	cout<<"-Left arrow key to move left\n";
	cout<<"-Right arrow key to move right\n";
	cout<<"-Up arrow key to move Up\n";
	cout<<"-Down arrow key to move Down\n";
	cout<<"Press any key to continue!";
	getch();
	showMenu();
}
void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void erase(int x, int y) {
    gotoxy(x, y);
    cout << " ";
}

char getCharAtxy(short int x, short int y) {
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void PrintPacman(int x, int y) {
    gotoxy(x, y);
    cout << "p";
}

void readpattern() {
    string record;
    fstream data;
    data.open("maze for pacman.txt", ios::in);
    while (getline(data, record)) {
        readmaze[idx] = pattern(record, 1);
        idx = idx + 1;
    }
    data.close();
}

string pattern(string record, int field) {
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++) {
        if (record[x] == ',') {
            commaCount = commaCount + 1;
        } else if (commaCount == field) {
            item = item + record[x];
        }
    }
    return item;
}

void pattern() {
    readpattern();
    for (int i = 0; i < idx; i++) {
        cout << readmaze[i];
        cout << endl;
    }
}

void moveenemy() {
    if (enemydirection == "right") {
        char next = getCharAtxy(enemyX + 1, enemyY);
        if (next == ' ') {
            eraseenemy();
            enemyX = enemyX + 1;
            printenemy();
        }
        if (next == '#' || next == '.') {
            enemydirection = "left";
        }
    } else if (enemydirection == "left") {
        char next = getCharAtxy(enemyX - 1, enemyY);
        if (next == ' ') {
            eraseenemy();
            enemyX = enemyX - 1;
            printenemy();
        }
        if (next == '#' || next == '.') {
            enemydirection = "right";
        }
    }
}

void moveVerticalEnemy() {
    if (enemydirection2 == "down") {
        char next = getCharAtxy(enemyX2, enemyY2 + 1);
        if (next == ' ') {
            eraseenemy();
            enemyY2 = enemyY2 + 1;
            printenemy();
        }
        if (next == '#' || next == '.') {
            enemydirection2 = "up";
        }
    } else if (enemydirection2 == "up") {
        char next = getCharAtxy(enemyX2, enemyY2 - 1);
        if (next == ' ') {
            eraseenemy();
            enemyY2 = enemyY2 - 1;
            printenemy();
        }
        if (next == '#' || next == '.') {
            enemydirection2 = "down";
        }
    }
}

void eraseenemy() {
    gotoxy(enemyX, enemyY);
    cout << " ";
    gotoxy(enemyX2, enemyY2);
    cout << " ";
}

void printenemy() {
    gotoxy(enemyX, enemyY);
    cout << enemy1[0];
    gotoxy(enemyX2, enemyY2);
    cout << enemy2[0];
}

void Header()
{
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^                                              PacMan                                                   ^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}
