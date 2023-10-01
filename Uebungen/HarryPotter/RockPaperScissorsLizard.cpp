//#include <iostream>
//#include <string>
//#include <ctype.h>
//#include <stdlib.h>
//
//int main() {
//
//	srand(time(NULL));
//
//	int computer = rand() % 5 + 1;
//	int user = 0;
//	int win1;
//	int win2;
//	bool stop = false;
//	char Cstop;
//
//	while (!stop) {
//		std::cout << "=================================\n";
//		std::cout << "Rock Paper Scissors Lizzard Spock\n";
//		std::cout << "================================= \n";
//		std::cout << "1) Schere \n";
//		std::cout << "2) Papier \n";
//		std::cout << "3) Stein \n";
//		std::cout << "4) Lizard \n";
//		std::cout << "5) Spock \n";
//		std::cout << "=================================\n";
//		std::cout << "Lets go!\n";
//		std::cout << "=================================\n";
//		std::cin >> user;
//
//		if (user < 1 || user > 5) {
//			std::cout << "Bitte zahl zwischen 1 und 5 eingeben du dummkopf\n";
//			return 0;
//		}
//
//		std::cout << "Computer sagt:" << computer << "\n";
//
//		// Logik 
//
//		// Plus 1 Win Conditions 
//
//		win1 = user + 1;
//
//
//		// Minus 2 Win Condition
//
//		win2 = (user - 2 + 5) % 5; // User - 2 (als Win Condition) +5%5 um minus bereich zu vermeiden
//
//		if (win2 == 0) {			// Falls user 2 nimmt würde man auf 0 rauskommen, setzen es deshalb manuell auf 5
//			win2 = 5;
//
//		}
//
//		if (win1 == computer || win2 == computer) {
//			// Win Conditions
//			std::cout << "Win\n";
//		}
//
//		else if (user == computer) {
//			// Draw Condition
//			std::cout << "Draw\n";
//
//		}
//
//		else {
//			// Lose Condition
//			std::cout << "Lose\n";
//		}
//
//
//
//		std::cout << "=================================\n";
//		std::cout << "=================================\n";
//		std::cout << "=================================\n";
//		std::cout << "=================================\n";
//		// Stop Condition
//		std::cout << "Want to quit? J/N\n";
//		std::cin >> Cstop;
//		Cstop = tolower(Cstop);
//		if (Cstop == 'j') {
//			stop = true;
//		}
//		else {
//			stop = false;
//		}
//		//std::cout << "DEBUG\n";
//		//std::cout << "Computer sagt:" << computer << "\n";
//		//std::cout << "userWrap " << win2 << "\n";
//	}
//	/* Switch System Falls umsortierung der Values von nöten
//	switch (user) {
//
//	case 1:
//		userValue = 3;
//		break;
//	case 2:
//		userValue = 2;
//		break;
//	case 3:
//		userValue = 1;
//		break;
//	case 4:
//		userValue = 4;
//		break;
//	case 4:
//		userValue = 4;
//		break;
//
//	default:
//		std::cout << "Fehlerhafte Eingabe du fotze!\n";
//		return 0;
//		break;
//
//	}
//
//	switch (computer) {
//
//	case 1:
//		computerValue = 3;
//		break;
//	case 2:
//		computerValue = 2;
//		break;
//	case 3:
//		computerValue = 1;
//		break;
//	case 4:
//		computerValue = 4;
//		break;
//
//	default:
//		std::cout << "Fehlerhafte Eingabe du fotze!\n";
//		return 0;
//		break;
//	*/
//
//}