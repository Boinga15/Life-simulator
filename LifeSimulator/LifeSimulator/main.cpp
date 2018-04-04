#include <iostream>
#include <Windows.h>
#include<math.h>
#include<ctime>
using namespace std;

void home();
void outside();
void boxing();

bool isAware = false;
int playerTurn = true;
int maxHealth = 20;
int health = 20;
int defense = 0;
int gameTime = 6;
int money = 20;
int jobLevel = 1;
int strength = 0;
int stamina = 0;
int intelligence = 0;
int endurance = 0;
int day = 1;
int minutes = 0;
int playerClass = 1;
int opStrength = 0;
int opStamina = 0;
int opEndurance = 0;
int opHealth = 0;
int opDefeated = 0;
bool opDefending = false;
int rank = 0;

void incrementTime(int amount) {
	minutes += amount;
	while (minutes >= 60) {
		gameTime++;
		minutes -= 60;
	}
}

void fight() {
	int defense = strength - 3;
	system("cls");
	while(health > 0 && opHealth > 0) {
		int currentStamina = stamina;
		int op;
		while (currentStamina >= 20) {
			cout << "Your turn!" << endl;
			cout << "Your health: " << health << endl;
			cout << "Your defense: " << defense << endl;
			cout << "Enemy health: " << opHealth << endl;
			cout << "Stamina left: " << currentStamina << endl;
			cout << "1: Punch (-20 stamina, 4 damage)" << endl;
			cout << "2: Kick (-30 stamina, 6 damage)" << endl;
			cout << "3: KO hook (-50 stamina, 12 damage)" << endl;
			cout << "4: Kamehameha (-100 stamina, 30 damage)" << endl;
			cout << "5: Restore (-40 stamina, +5 health)" << endl;
			cout << "6: Block (-30 stamina, +9 defense)" << endl;
			cin >> op;
			system("cls");
			switch (op) {
			case 1:
				if (currentStamina > 20) {
					cout << "You punched your opponent!" << endl;
					cout << "4 damage!" << endl;
					opHealth -= 4;
					if (opDefending) {
						defense -= 4 / 4;
					}
					currentStamina -= 20;
				}
				else {
					cout << "You don't have enough stamina!" << endl;
				}
				break;
			case 2:
				if (currentStamina > 30) {
					cout << "You kicked your opponent!" << endl;
					cout << "6 damage!" << endl;
					opHealth -= 6;
					if (opDefending) {
						defense -= 6 / 4;
					}
					currentStamina -= 30;
				}
				else {
					cout << "You don't have enough stamina!" << endl;
				}
				break;
			case 3:
				if (currentStamina > 50) {
					cout << "You hit your opponent with a powerful KO hook!" << endl;
					cout << "12 damage!" << endl;
					opHealth -= 12;
					if (opDefending) {
						defense -= 12 / 4;
					}
					currentStamina -= 50;
				}
				else {
					cout << "You don't have enough stamina!" << endl;
				}
				break;
			case 4:
				if (currentStamina > 100) {
					cout << "You shot a khamehameha beam at your opponent!" << endl;
					cout << "30 damage!" << endl;
					opHealth -= 30;
					if (opDefending) {
						defense -= 30 / 4;
					}
					currentStamina -= 100;
				}
				else {
					cout << "You don't have enough stamina!" << endl;
				}
				break;
			case 5:
				if (currentStamina > 40) {
					cout << "You rested quickly." << endl;
					cout << "+5 health!" << endl;
					health += 5;
					currentStamina -= 40;
				}
				else {
					cout << "You don't have enough stamina!" << endl;
				}
				break;
			case 6:
				if (currentStamina > 30) {
					cout << "You put your guard up!" << endl;
					cout << "+9 defense!" << endl;
					defense += 9;
					currentStamina -= 30;
				}
				else {
					cout << "You don't have enough stamina!" << endl;
				}
				break;
			default:
				cout << "You did nothing." << endl;
				break;
			}
			opDefending = false;
			cout << endl;
			cout << endl;
			cout << endl;
		}
			Sleep(1500);
			srand(time(0));
			int enemyOp = 1 + rand() % 3;
			if (enemyOp < 3) {
				srand(time(0));
				if (rand() % 2 == 0) {
					cout << "You dodged your opponent's attack!" << endl;
				}
				else {
					if (enemyOp == 1) {
						cout << "Your opponent punched you!" << endl;
						cout << "-" << 2 * opStrength << " health!" << endl;
						health -= 2 * opStrength;
						cout << "-" << opStrength << " defense!" << endl;
						defense -= opStrength;
					} else {
						cout << "Your opponent kicked you!" << endl;
						cout << "-" << opStrength << " health!" << endl;
						health -= opStrength;
						cout << "-" << 2 * opStrength << " defense!" << endl;
						defense -= 2 * opStrength;
					}
				}
				isAware = false;
			} else {
				cout << "Your oppponent is blocking!" << endl;
				cout << "a quater of the damage you deal next turn will be directed to you!" << endl;
				opDefending = true;
			}
			cout << endl;
			cout << endl;
			cout << endl;
			if (defense < 1) {
				cout << "You took some damage since your defense went to low!" << endl;
				health -= maxHealth / 3;
				defense = strength / 2;
			}
			cout << endl;
			cout << endl;
			cout << endl;
	}
	Sleep(2000);
	system("cls");
	if (health <= 0) {
		cout << "You lost!" << endl;
		if (playerClass == 4) {
			cout << "+30 endurance!" << endl;
			endurance += 30;
		} else {
			cout << "+10 endurance!" << endl;
			endurance += 10;
		}
		health = 1;
	} else {
		cout << "You win!" << endl;
		cout << "+10 endurance!" << endl;
		endurance += 10;
		opDefeated++;
	}
	Sleep(2000);
	system("cls");
	incrementTime(240);
	boxing();
}

void findOpponent() {
	int op;
	cout << "Do you want to fight this opponent?" << endl;
	cout << "Strength: " << opStrength << endl;
	cout << "Stamina: " << opStamina << endl;
	cout << "Endurance: " << opEndurance << endl;
	cout << "1: Check your current stats!" << endl;
	cout << "2: Fight!" << endl;
	cout << "3: Next opponent" << endl;
	cout << "4: Back" << endl;
	cin >> op;
	system("cls");
	switch (op) {
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		findOpponent();
		break;
	case 2:
		if (gameTime < 18) {
			opHealth = opEndurance + 20;
			fight();
		} else {
			cout << "It's too late to fight!" << endl;
			findOpponent();
		}
		break;
	case 3:
		srand(time(0));
		opStrength = opDefeated * 5 + rand() % (opDefeated * 5 + 4);
		srand(time(0));
		opStamina = opDefeated * 5 + rand() % (opDefeated * 5 + 40);
		srand(time(0));
		opEndurance = opDefeated * 5 + rand() % (opDefeated * 5 + 15);
		findOpponent();
		break;
	case 4:
		boxing();
		break;
	default:
		findOpponent();
		break;
	}
}

void boxing() {
	int op;
	cout << "You're at the boxing place, what do you want to do?" << endl;
	cout << "Day: " << day << endl;
	if (gameTime > 12) {
		cout << "Time: " << gameTime - 12 << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " PM." << endl;
	}
	else {
		cout << "Time: " << gameTime << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " AM." << endl;
	}
	cout << "1: Check your current stats." << endl;
	cout << "2: Go outside." << endl;
	cout << "3: Start a fight." << endl;
	cin >> op;
	system("cls");
	switch (op) {
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		boxing();
		break;
	case 2:
		outside();
		break;
	case 3:
		srand(time(0));
		opStrength = opDefeated + rand() % (opDefeated + 10);
		srand(time(0));
		opStamina = opDefeated + rand() % (opDefeated + 40);
		srand(time(0));
		opEndurance = opDefeated + rand() % (opDefeated + 15);
		findOpponent();
		break;
	default:
		boxing();
		break;
	}
}

void store() {
	int op;
	cout << "'Welcome to snack and crack! How may I help you?'" << endl;
	cout << "Day: " << day << endl;
	if (gameTime > 12) {
		cout << "Time: " << gameTime - 12 << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " PM." << endl;
	}
	else {
		cout << "Time: " << gameTime << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " AM." << endl;
	}
	cout << "1: Check your current stats." << endl;
	cout << "2: Go outside." << endl;
	cout << "3: Buy a packet of french fries (10 pounds, +5 health)." << endl;
	cout << "4: Buy a double decker burger (30 pounds, +30 health)." << endl;
	cout << "5: Buy a protien bar (15 pounds, +5 stamina)." << endl;
	cout << "6: Buy a bottle of sugar (30 pounds, +10 stamina, +15 health)." << endl;
	cin >> op;
	system("cls");
	switch (op) {
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		store();
		break;
	case 2:
		outside();
		break;
	case 3:
		if (money >= 10) {
			cout << "'Thank you for your purchase!'" << endl;
			cout << "+5 health!" << endl;
			health += 5;
			cout << "-10 money!" << endl;
			money -= 10;
		}
		else {
			cout << "'Sorry, but you don't have enough money to buy this.'" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		store();
		break;
	case 4:
		if (money >= 30) {
			cout << "'Thank you for your purchase!'" << endl;
			cout << "+30 health!" << endl;
			health += 30;
			cout << "-30 money!" << endl;
			money -= 30;
		}
		else {
			cout << "'Sorry, but you don't have enough money to buy this.'" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		store();
		break;
	case 5:
		if (money >= 15) {
			cout << "'Thank you for your purchase!'" << endl;
			cout << "+5 stamina!" << endl;
			stamina += 5;
			cout << "-15 money!" << endl;
			money -= 15;
		}
		else {
			cout << "'Sorry, but you don't have enough money to buy this.'" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		store();
		break;
	case 6:
		if (money >= 30) {
			cout << "'Thank you for your purchase!'" << endl;
			cout << "+5 health!" << endl;
			health += 15;
			cout << "+10 stamina!" << endl;
			stamina += 10;
			cout << "-30 money!" << endl;
			money -= 30;
		}
		else {
			cout << "'Sorry, but you don't have enough money to buy this.'" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		store();
		break;
	default:
		store();
		break;
	}
}

void gym() {
	int op;
	cout << "Your now at the gym, what do you want to do?" << endl;
	cout << "Day: " << day << endl;
	if (gameTime > 12) {
		cout << "Time: " << gameTime - 12 << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " PM." << endl;
	}
	else {
		cout << "Time: " << gameTime << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " AM." << endl;
	}
	cout << "1: Check your current stats." << endl;
	cout << "2: Go outside." << endl;
	cout << "3: Go lift some weights (15 pounds)." << endl;
	cout << "4: Do some sparing (10 pounds)." << endl;
	cin >> op;
	system("cls");
	switch (op) {
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		gym();
		break;
	case 2:
		outside();
		break;
	case 3:
		if (money >= 15) {
			if (gameTime < 18) {
				cout << "You lifted some weights!" << endl;
				if (playerClass == 3) {
					cout << "+4 strength!" << endl;
					strength += 4;
				}
				else {
					cout << "+2 strength!" << endl;
					strength += 2;
				}
				cout << "-15 money!" << endl;
				money -= 15;
				incrementTime(90);
			} else {
				cout << "It's way too late to exersise!" << endl;
			}
		} else {
			cout << "You don't have enough money!" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		gym();
		break;
	case 4:
		if (money >= 10) {
			if (gameTime < 16) {
				cout << "You did some sparing!" << endl;
				cout << "+1 endurance!" << endl;
				endurance += 1;
				cout << "-10 money!" << endl;
				money -= 10;
				incrementTime(90);
			}
			else {
				cout << "It's way too late to do some sparing!" << endl;
			}
		}
		else {
			cout << "You don't have enough money!" << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		gym();
		break;
	default:
		gym();
		break;
	}
}

void university() {
	int op;
	cout << "Your at university, what do you want to do?" << endl;
	cout << "Day: " << day << endl;
	if (gameTime > 12) {
		cout << "Time: " << gameTime - 12 << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " PM." << endl;
	}
	else {
		cout << "Time: " << gameTime << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " AM." << endl;
	}
	cout << "1: Check your current stats." << endl;
	cout << "2: Go outside." << endl;
	cout << "3: Go to class (Costs 10 pounds)." << endl;
	cout << "4: Study." << endl;
	cin >> op;
	system("cls");
	switch (op) {
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		university();
		break;
	case 2:
		outside();
		break;
	case 3:
		if (money >= 10) {
			if (gameTime < 16) {
				cout << "You learned some new things!" << endl;
				if (playerClass == 2) {
					cout << "+5 intelligence!" << endl;
					intelligence += 5;
				} else {
					cout << "+3 intelligence!" << endl;
					intelligence += 3;
				}
				cout << "-10 money!" << endl;
				money -= 10;
				incrementTime(90);
				cout << endl;
				cout << endl;
				cout << endl;
			}
			else {
				cout << "University is closed!" << endl;
				cout << endl;
				cout << endl;
				cout << endl;
			}
		}
		else {
			cout << "You don't have enough money!" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
		university();
		break;
	case 4:
		if (gameTime < 20) {
			cout << "You studied on some topics." << endl;
			cout << "+1 intelligence" << endl;
			intelligence++;
			incrementTime(60);
			cout << endl;
			cout << endl;
			cout << endl;
		}
		else {
			cout << "Your too tired to study!" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
		university();
		break;
	default:
		university();
		break;
	}

}

void job() {
	int op;
	cout << "Your now at your job place, what do you want to do?" << endl;
	cout << "Day: " << day << endl;
	if (gameTime > 12) {
		cout << "Time: " << gameTime - 12 << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " PM." << endl;
	}
	else {
		cout << "Time: " << gameTime << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " AM." << endl;
	}
	cout << "1: Check your current stats." << endl;
	cout << "2: Go outside." << endl;
	cout << "3: Work." << endl;
	cout << "4: Ask for a promotion." << endl;
	cin >> op;
	system("cls");
	switch (op) {
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		job();
		break;
	case 2:
		outside();
		break;
	case 3:
		if (gameTime < 20) {
			cout << "It was another boring hour at work." << endl;
			cout << "+" << jobLevel * 3 << " money!" << endl;
			money += jobLevel * 3;
			incrementTime(60);
			cout << endl;
			cout << endl;
			cout << endl;
		} else {
			cout << "It's super late to work now." << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
		job();
		break;
	case 4:
		if (intelligence > 35 * jobLevel) {
			cout << "'Hmmm... I guess you can have a promotion.'" << endl;
			jobLevel++;
			cout << "You have been promoted! Your wage per hour is now " << jobLevel * 3 << " pounds!" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		} else {
			cout << "'I'm sorry, but I cannot give you a promotion'." << endl;
			cout << "Required intelligence for next promotion is " << 35 * jobLevel << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
		job();
		break;
	default:
		job();
		break;
	}
}

void outside() {
	int op;
	cout << "Your now outside, what do you want to do?" << endl;
	cout << "Day: " << day << endl;
	if (gameTime > 12) {
		cout << "Time: " << gameTime - 12 << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " PM." << endl;
	}
	else {
		cout << "Time: " << gameTime << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " AM." << endl;
	}
	cout << "1: Check your current stats." << endl;
	cout << "2: Go home." << endl;
	cout << "3: Go to university." << endl;
	cout << "4: Go to the gym." << endl;
	cout << "5: Go to the store." << endl;
	cout << "6: Go to the boxing area." << endl;
	cout << "7: Go to your job place." << endl;
	cout << "8: Have a run." << endl;
	cin >> op;
	system("cls");
	switch (op){
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		outside();
		break;
	case 2:
		home();
		break;
	case 3:
		university();
		break;
	case 4:
		gym();
		break;
	case 5:
		store();
		break;
	case 6:
		if (stamina < 20 || strength < 15 || endurance < 5) {
			cout << "'Hold on! You ain't going into that ring till ya get strong!'" << endl;
			cout << "You need:" << endl;
			cout << "20 or more stamina." << endl;
			cout << "15 or more strength" << endl;
			cout << "5 or more endurance" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			outside();
		}
		else {
			boxing();
		}
		break;
	case 7:
		job();
		break;
	case 8:
		if (gameTime < 19) {
			cout << "You ran around the neighbour hood." << endl;
			cout << "+1 stamina!" << endl;
			stamina++;
			cout << endl;
			cout << endl;
			cout << endl;
			incrementTime(60);
		}
		else {
			cout << "It's too dark to have a run! And your tired. That too." << endl;
			cout << endl;
			cout << endl;
			cout << endl;
		}
		outside();
		break;
	default:
		outside();
		break;
	}
}

void home() {
	int op;
	cout << "Your at home, what do you want to do?" << endl;
	cout << "Day: " << day << endl;
	if (gameTime > 12) {
		cout << "Time: " << gameTime - 12 << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " PM." << endl;
	}
	else {
		cout << "Time: " << gameTime << ":";
		if (minutes < 10) {
			cout << "0";
		}
		cout << minutes << " AM." << endl;
	}
	cout << "1: Check your current stats." << endl;
	cout << "2: Go to bed." << endl;
	cout << "3: Go outside." << endl;
	cin >> op;
	system("cls");
	switch (op) {
	case 1:
		cout << "Health: " << health << "/" << maxHealth << endl;
		cout << "Strength: " << strength << endl;
		cout << "Stamina: " << stamina << endl;
		cout << "Intelligence: " << intelligence << endl;
		cout << "Endurance: " << endurance << endl;
		cout << "Money: " << money << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		home();
		break;
	case 2:
		Sleep(3000);
		if (playerClass == 5) {
			health = maxHealth;
		}
		day++;
		if (playerClass == 5) {
			gameTime = 9;
		} else {
			gameTime = 6;
		}
		if (playerClass == 6) {
			float amount = money * 0.2;
			money += round(amount);
		}
		minutes = 0;
		home();
		break;
	case 3:
		outside();
		break;
	default:
		home();
		break;
	}
}

int main() {
	int points = 20;
	int op;
	cout << "Welcome to life simulator! You've been given 20 stat points to start with." << endl;
	cout << "Out of " << points << " points, how many do you want to put in strength?" << endl;
	cout << "Your current stats: " << strength << " strength, " << intelligence << " intelligence, and " << endurance <<  " endurance." << endl;
	cin >> op;
	if (op < 0) {
		op = 0;
	} else if (op > points) {
		op = points;
	}
	strength = op;
	points -= op;
	system("cls");
	cout << "Out of " << points << " points, how many do you want to put in intelligence?" << endl;
	cout << "Your current stats: " << strength << " strength, " << intelligence << " intelligence, and " << endurance << " endurance." << endl;
	cin >> op;
	if (op < 0) {
		op = 0;
	}
	else if (op > points) {
		op = points;
	}
	intelligence = op;
	points -= op;
	system("cls");
	cout << "Out of " << points << " points, how many do you want to put in endurance?" << endl;
	cout << "Your current stats: " << strength << " strength, " << intelligence << " intelligence, and " << endurance << " endurance." << endl;
	cin >> op;
	if (op < 0) {
		op = 0;
	}
	else if (op > points) {
		op = points;
	}
	endurance = op;
	maxHealth += endurance;
	health = maxHealth;
	points -= op;
	system("cls");
	cout << "One last thing: from the list, select a class (each have their own custom attributes)" << endl;
	cout << "1: Normal: No special attributes." << endl;
	cout << "2: Nerd: Get more intelligence when in class." << endl;
	cout << "3: Brute: Get more strength when at the gym." << endl;
	cout << "4: Punching bag: Get more endurance when losing a fight." << endl;
	cout << "5: Sleeper: Your health is restored when you go to sleep, but you wake up late." << endl;
	cout << "6: Invester: Get some extra money depending on how much money you have per day." << endl;
	cin >> op;
	if (op < 1 || op > 6) {
		op = 1;
	}
	playerClass = op;
	system("cls");
	home();
}