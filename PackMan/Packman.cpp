#include<iostream>
#include<Windows.h>
#include<ctime>
#include<string.h>
#include "levels.h"
#include "player.h"
//#include "bot.h"

using namespace std;

main() {
	Player Igrac;
	Player Bot;
	level1();
	Igrac.loading("Igrac");
	Bot.loading("Bot");
	Igrac.playerPosition(sizeX, sizeY);
	Bot.playerPosition(sizeX, sizeY);
	while(1) {
		Igrac.playerMove();
		Bot.botMove();
	}
}
