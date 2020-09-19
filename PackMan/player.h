#define up VK_UP
#define down VK_DOWN
#define left VK_LEFT
#define right VK_RIGHT

using namespace std;
int seed = 0;
void newSeed() {
//	--- Drugi nacin --- 
	while(1) {
		seed++;
		break;
	}
//	srand(time(0)); // Prvi nacin
	srand(seed);
	cout<<"DEBUG: "<<seed<<endl;
}

class Player {
	private:
		string playerName;
		int score, 
			playerX, playerY, 
			oldPlayerX, oldPlayerY, 
//			botX, botY, oldBotX, oldBotY,
			scorePointX, scorePointY;
	public:
		void loading(string name) {
			score = 0;
			playerName = name;
			srand(time(0));
			seed = rand() % 1000;
		}
		void playerPosition(int , int sizeY) {	
			if( playerName == "Igrac" ) {
		 		playerX = sizeX / 2;
				playerY = sizeY / 2;
			}
			else if ( playerName == "Bot") {
				newSeed();
				playerX = rand() % sizeX;
				playerY = rand() % sizeY;
				if ( field[playerX][playerY] == ' ')
					field[playerX][playerY] = 'E';
				else 
					playerPosition(sizeX, sizeY);
			}
		}
//		void botPositioning() { // out of function
//			newSeed();
//			cout<<"DEBUG: "<<seed<<endl;
//		}
		void newScorePoint() {
			newSeed();
//			cout<<"DEBUG: "<<seed<<endl;
			scorePointX = rand() % sizeX;
			scorePointY = rand() % sizeY;
			if ( field[scorePointX][scorePointY] == '#' ) {
				cout<<scorePointX<<" "<<scorePointY<<endl; //DEBUG
				newScorePoint();
			}
			else {
				field[scorePointX][scorePointY] = '*';
			}
			reWrite();
		}
		void updateScore() {
			if ( field[playerX][playerY] == '*' && playerName != "Bot") {
				score++;
				newScorePoint();
			}
		}
		void checkMovementUp() {
			if( field[playerX - 1][playerY] != '#') {
				oldPlayerX = playerX, oldPlayerY = playerY;
				playerX -= 1;
				updateScore();
			}	
		}
		void checkMovementDown() {
			if( field[playerX + 1][playerY] != '#') {
				oldPlayerX = playerX, oldPlayerY = playerY;
				playerX += 1;
				updateScore();
			}	
		}
		void checkMovementLeft() {
			if( field[playerX][playerY - 1] != '#') {
				oldPlayerX = playerX, oldPlayerY = playerY;
				playerY -= 1;
				updateScore();
			}
		}
		void checkMovementRight() {
			if( field[playerX][playerY + 1] != '#') {
				oldPlayerX = playerX, oldPlayerY = playerY;
				playerY += 1;
				updateScore();
			}
		}
		void playerMove() {
			Sleep(500);
			if( GetAsyncKeyState(up) ) {
				checkMovementUp();
			}
			else if( GetAsyncKeyState(down) ) {
				checkMovementDown();
			}
			else if( GetAsyncKeyState(left) ) {
				checkMovementLeft();
			}
			else if( GetAsyncKeyState(right) ) {
				checkMovementRight();
			}
			reWrite();
		}
		void reWrite() {
			system("cls");
			cout<<"Score: "<<score<<endl;
			if ( playerName == "Igrac") {
				field[oldPlayerX][oldPlayerY] = ' ';
				field[playerX][playerY] = 'O';
			}
			else if ( playerName == "Bot") {
				field[oldPlayerX][oldPlayerY] = ' ';
				field[playerX][playerY] = 'E';
				cout<<playerX<<playerY<<endl;
			}
			for(int i = 0; i < sizeX; i++) {
				for(int j = 0; j < sizeY; j++) {
					cout<<field[i][j];
					cout<<" ";
				}
				cout<<endl;
			}
//			playerMove();
		}
		void botMove() {
			newSeed();
			int movement = rand() % 32;
			cout<<movement<<endl;
			switch(movement) {
				case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: {
					checkMovementUp();
					reWrite();
					break;
				}
				case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15:{
					checkMovementDown();
					reWrite();
					break;
				}
				case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23: {
					checkMovementLeft();
					reWrite();
					break;
				}
				case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 31:{
					checkMovementRight();
					reWrite();
					break;
				}
			}
		}
};
