#include <iostream>
#include "player.h"
#include "GameRule.h"

/*
we can try to input:
a id = 1 nfc = 10 mcn = 4
b id = 2 nfc = 10 mcn = 2
c id = 3 nfc = 10 mcn = 3
d id = 4 nfc = 12 mcn = 1

so d has the biggest priority because the largest number of cities and because a b and c has same number of cities we compare the max plant card number

the plant card number order is a c b

so the priority is d is first, a is second, c is third and d is the last

*/
int main(){
	
	GameRule *g = new GameRule();

	g->initializeOrder();

	g->inGameOrder();	

	g->reverseGameOrder();	

	Player_ *p = new Player_();
	p->EarnMoney(0);

	return 1;
}

