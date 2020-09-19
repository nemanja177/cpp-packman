using namespace std;

char field[100][100];
int sizeX, sizeY;

void level1() {
	sizeX = 15;
	sizeY = 15;
	for(int i = 0; i < sizeX; i++) {
		for(int j = 0; j < sizeY; j++) {
			field[i][j] = ' ';	
		}
	}
	for(int i = 0; i < sizeX; i++) {
		field[i][0] = '#';
		field[0][i] = '#';
		field[14][i] = '#';
		field[i][14] = '#';
	}
	for(int i = 2; i < sizeX - 2 ; i++) {
		field[i][2] = '#';
		field[2][i] = '#';
		field[12][i] = '#';
		field[i][12] = '#';
	}
	for(int i = 4; i < sizeX - 4 ; i++) {
		field[i][4] = '#';
		field[4][i] = '#';
		field[10][i] = '#';
		field[i][10] = '#';
	}
	for(int i = 6; i < sizeX - 6 ; i++) {
		field[i][6] = '#';
		field[6][i] = '#';
		field[8][i] = '#';
		field[i][8] = '#';
	}
	field[1][1] = '*';
	field[2][5] = ' ', field[4][5] = ' ', field[9][10] = ' ', field[9][12] = ' ', field[10][7] = ' ', field[12][5] = ' ',
	field[7][8] = ' ', field[6][7] = ' ', field[4][2] = ' ', field[3][12] = ' ', field[12][10] = ' ', field[10][2] = ' ',
	field[2][10] = ' ';
};
