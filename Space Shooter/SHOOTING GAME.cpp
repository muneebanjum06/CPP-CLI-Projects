#include<iostream>
#include<windows.h>
#include<fstream>
#include<conio.h>
using namespace std;

const int MAZE = 100;
string print[MAZE];

char ship1[6] = { ' ', '/', '^', '\\', ' ', ' ' };
char ship2[6] = { '<', '0', '0', '0', '>', ' ' };

char enemy1[6] = { ' ', ' ', '^', '^', ' ', ' ' };
char enemy2[6] = { '<', 'o', 'o', 'o', 'o', '>' };
char enemy3[6] = { ' ', '/', '-', '-', '\\', ' ' };
char enemy4[6] = { ' ', '-', '-', '-', '-', ' ' };

int shipX = 30;
int shipY = 23;
int enemyX = 30;
int enemyY = 10;
int timer = 0;
int score = 0;

// Bullets
const int maxBullets = 20;  // Set the maximum number of bullets

int bulletX[maxBullets];
int bulletY[maxBullets];
bool isBulletActive[maxBullets];
int bulletCount = 0;
string enemydirection = "right";
int targetScore = 10; // Set the target score for "Stage Clear"
bool isBulletBeingGenerated = false;
int idx = 0;

// Function prototypes
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void printship();
void printenemy();
void eraseship();
void eraseenemy();
void moveshipleft();
void moveshipright();
void moveenemy();
void erasebullet(int x, int y);
void makebulletinactive(int i);
void generatebullet();
void movebullet();
void printbullet(int x, int y);
void bulletcollision();
void addscore();
void printscore();
void pattern();
void gameover();
int bulletsleft();
string pattern(string record, int field);
void readpattern();

void showMenu();
void playGame();
void instructions();
void Header();
void keys();

int main() {
    system("cls");
    system("color 0E");
   	showMenu();

    return 0;
}

void gotoxy(int x, int y) {
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y) {
    CHAR_INFO ci;
    COORD xy = { 0, 0 };
    SMALL_RECT rect = { x, y, x, y };
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void printship() {
    gotoxy(shipX, shipY);
    for (int i = 0; i < 6; i++) {
        cout << ship1[i];
    }
    gotoxy(shipX, shipY + 1);
    for (int i = 0; i < 6; i++) {
        cout << ship2[i];
    }
}

void printenemy() {
    gotoxy(enemyX, enemyY);
    for (int i = 0; i < 6; i++) {
        cout << enemy1[i];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int i = 0; i < 6; i++) {
        cout << enemy2[i];
    }
    gotoxy(enemyX, enemyY + 2);
    for (int i = 0; i < 6; i++) {
        cout << enemy3[i];
    }
    gotoxy(enemyX, enemyY + 3);
    for (int i = 0; i < 6; i++) {
        cout << enemy4[i];
    }
}

void eraseship() {
    gotoxy(shipX, shipY);
    for (int i = 0; i < 6; i++) {
        cout << " ";
    }
    gotoxy(shipX, shipY + 1);
    for (int i = 0; i < 6; i++) {
        cout << " ";
    }
}

void eraseenemy() {
    gotoxy(enemyX, enemyY);
    for (int i = 0; i < 6; i++) {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int i = 0; i < 6; i++) {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 2);
    for (int i = 0; i < 6; i++) {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 3);
    for (int i = 0; i < 6; i++) {
        cout << " ";
    }
}

void moveshipleft() {
    char next = getCharAtxy(shipX - 1, shipY);
    if (next == ' ') {
        eraseship();
        shipX = shipX - 1;
        printship();
    }
}

void moveshipright() {
    char next = getCharAtxy(shipX + 6, shipY);
    if (next == ' ') {
        eraseship();
        shipX = shipX + 1;
        printship();
    }
}

void moveenemy() {
    int randomMove = rand() % 3;

    if (randomMove == 0) {
        // Do nothing, stay in the same position
    } else if (randomMove == 1) {
        char next = getCharAtxy(enemyX - 1, enemyY);
        if (next == ' ') {
            eraseenemy();
            enemyX = enemyX - 4;
            printenemy();
        }
        if (next == '#') {
            // Change direction if hitting a boundary
            enemydirection = "right";
        }
    } else if (randomMove == 2) {
        char next = getCharAtxy(enemyX + 6, enemyY);
        if (next == ' ') {
            eraseenemy();
            enemyX = enemyX + 4;
            printenemy();
        }
        if (next == '#') {
            // Change direction if hitting a boundary
            enemydirection = "left";
        }
    }
    
}

void erasebullet(int x, int y) {
    gotoxy(x, y);
    cout << " ";
}

void makebulletinactive(int i) {
    isBulletActive[i] = false;
}

void generatebullet() {
    bulletX[bulletCount] = shipX + 1;
    bulletY[bulletCount] = shipY - 1;
    isBulletActive[bulletCount] = true;
    bulletCount++;
	Sleep(100);
}

void movebullet() {
    for (int x = 0; x < bulletCount; x++) {
        if (isBulletActive[x] == true) {
            char next = getCharAtxy(bulletX[x], bulletY[x] - 1);
            if (next != ' ') {
                erasebullet(bulletX[x], bulletY[x]);
                makebulletinactive(x);
            }
            else {
                erasebullet(bulletX[x], bulletY[x]);
                bulletY[x] = bulletY[x] - 1;
                printbullet(bulletX[x], bulletY[x]);
            }
        }
    }
}

void printbullet(int x, int y) {
    gotoxy(x, y);
    cout << ".";
}

void bulletcollision() {
    for (int x = 0; x < bulletCount; x++) {
        if (isBulletActive[x]) {
            for (int i = 0; i < 6; i++) {
                // Check if the bullet position overlaps with any part of the enemy
                if (bulletX[x] >= enemyX && bulletX[x] < enemyX + 6  && bulletY[x] == enemyY + 4) {
                    erasebullet(bulletX[x], bulletY[x]);
                    makebulletinactive(x);
                    addscore();
                    break;  // Break the loop if collision is detected to avoid double-scoring
                }
            }
        }
    }
}

void gameover() {
    system("cls");
    cout << "###############################################################################################\n";
    cout << "#                                                                                             #\n";
    cout << "#                                      GAME OVER                                              #\n";
    cout << "#                                      Score: " << score<<"                                               #\n";
    cout << "#                                                                                             #\n";
    cout << "#                                                                                             #\n";
    cout << "###############################################################################################\n";
    Sleep(2000);  // Delay for 2 seconds before exiting
}

void addscore() {
    score++;
}

void printscore() {
    gotoxy(100, 8);
    cout << "Score = " << score;
}

void readpattern() {
    string record;
    fstream data;
    data.open("maze.txt", ios::in);
    while (getline(data, record)) {
        print[idx] = pattern(record, 1);

        idx = idx + 1;
    }
    data.close();
}

void pattern() {
    readpattern();
    for (int i = 0; i < idx; i++) {
        cout << print[i] ;
        cout << endl;
    }
}

int bulletsleft() {
    gotoxy(100, 6);
    cout << "               ";  // Clear the area before printing the updated count
    gotoxy(100, 6);
    cout << "bullets left=" << maxBullets - bulletCount;
    return 0;
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

void Header()
{
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^                                              MegaMania                                                ^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}
void instructions() {
    system("cls");
	Header();
   
    cout << "- Use arrow keys to move spaceship" << endl;
    cout << "- Use space bar to shoot" << endl;
    cout << "- Hit 10 times out of 20 to clear the stage" << endl;
    cout << "Press any key to return to the main menu...";
    getch();
    showMenu();
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
void playGame()
{
	system("cls");
	 pattern();
    printship();
    printenemy();
    gotoxy(100,10);
	cout<<"Target score = 10";
   while (true) {
        printscore();
        bulletsleft();
        if (GetAsyncKeyState(VK_LEFT)) {
            moveshipleft();
        }
        if (GetAsyncKeyState(VK_RIGHT)) {
            moveshipright();
        }
        if (GetAsyncKeyState(VK_SPACE)) {
            generatebullet();
            
        }
        if (timer == 2) {
            moveenemy();
            timer = 0;
        }
        movebullet();
        bulletcollision();
        timer++;
        Sleep(50);
		
        // Check if the score reaches the target
        if (score >= targetScore) {
            system("cls");
            cout << "###############################################################################################\n";
            cout << "#                                                                                             #\n";
            cout << "#                                      STAGE CLEAR                                            #\n";
            cout << "#                                      Score: " << score<<"                                              #\n";
            cout << "#                                                                                             #\n";
            cout << "#                                                                                             #\n";
            cout << "###############################################################################################\n";
            Sleep(2000);  // Delay for 2 seconds before exiting
            
        }
          else if (bulletCount >= maxBullets) {
           
            gameover();
            break;
        }

    }
}
void keys()
{
	system("cls");
	Header();
	cout<<"-Left arrow key to move left\n";
	cout<<"-Right arrow key to move right\n";
	cout<<"-Space Bar key to shoot Up\n";

	cout<<"Press any key to continue!";
	getch();
	showMenu();
}
