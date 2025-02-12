#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Prototypes
void p1Hero(int agent);
const char *p2Hero();
int playerDecision1(int decision1, int decision2, int *player1HP, int *player2HP, int health, int hero);
int playerDecision2(int decision1, int decision2, int *player1HP, int *player2HP, int health);
void slow_print(const char *str, int delay);
void attack(int agent);
void defend(int agent);
void healing(int agent);
void coinToss(int coinDecision);
void printRoundSummary(int round, int p1choice, int p2choice, int p1HP, int p2HP);

// Functions
void p1Hero(int agent) { 							// For Player 1 Hero Selection
    switch (agent) {
		case 1:
		    slow_print("\nYou are now the Sorcerer Supreme...", 25000);
		    slow_print("\nDESCRIPTION: 	The Sorcerer Supreme is a powerful mystical title bestowed upon the", 25000);
		    slow_print("\n		foremost magic-wielder and protector of Earth from supernatural threats.", 25000);
		    slow_print("\n		Chosen for their skill, wisdom, and dedication, the Sorcerer Supreme holds ", 25000);
		    slow_print("\n		immense responsibility over realms and dimensions, maintaining the delicate", 50000);
		    slow_print("\n		balance between mystical forces.", 50000);
		    break;
		case 2:
		    slow_print("\nYou are now the Paladin Vanguard...", 25000);
		    slow_print("\nDESCRIPTION:	The Paladin Vanguard is a valiant warrior imbued with divine powers", 25000);
		    slow_print("\n		and unmatched resilience, serving as a shield against evil forces.", 25000);
		    slow_print("\n		Known for their unbreakable spirit and strength, the Paladin Vanguard can", 25000);
		    slow_print("\n		withstand even the fiercest attacks, standing as the ultimate defender of the realm.", 25000);
		    break;
		case 3:
		    slow_print("\nYou are now the Warlock Sanctum...", 25000);
		    slow_print("\nDESCRIPTION:	The Warlock Sanctum is a master of dark magic and elemental forces,", 25000);
		    slow_print("\n		channeling the destructive wrath of ancient powers. Feared for their immense offensive", 25000);
		    slow_print("\n		capabilities, the Warlock Sanctum can unleash devastating attacks that shake", 25000);
		    slow_print("\n		the battlefield and overwhelm their opponents.", 25000);
		    break;
		case 4:
		    slow_print("\nYou are now the Celestial Bard...", 25000);
		    slow_print("\nDESCRIPTION:	The Celestial Bard is a mystical musician whose melodies heal and inspire,", 25000);
		    slow_print("\n		weaving magic into their music to bring hope and vitality. Renowned for their", 25000);
		    slow_print("\n		calming presence, the Celestial Bard's harmonic spells have the power to rejuvenate", 25000);
		    slow_print("\n		and uplift, restoring strength to those in need.", 25000);
		    break;
		case 5:
		    slow_print("\nYou are now the Rogue Phantom...", 25000);
		    slow_print("\nDESCRIPTION:	The Rogue Phantom is a stealthy and cunning assassin, a shadow in the", 25000);
		    slow_print("\n		night with unparalleled agility and deceptive techniques. With their mastery", 25000);
		    slow_print("\n		of illusion and evasion, the Rogue Phantom strikes swiftly and unpredictably,", 25000);
		    slow_print("\n		leaving foes confused and vulnerable.", 25000);
		    break;
    }
}
const char *p2Hero() {								// For Player 2 Hero Selection
    const char *oppHero[5] = {"Sorcerer", "Paladin", "Warlock", "Bard", "Rogue"};
    srand(time(0));
    int x = rand() % 5;
    return oppHero[x];
}
void slow_print(const char *str, int delay) {		// For slow printing
    while (*str) {
        putchar(*str++);
        fflush(stdout);
        usleep(delay);
    }
}
void attack(int agent) {							// For the attack namings
	switch (agent){
		case 1: 
			// For Sorcerer
			slow_print("unleash the Arcane Eruption!", 25000);
			break;
		case 2: 
			// For Paladin
			slow_print("unleash the Holy Retribution!", 25000);
			break;
		case 3:
			// For Warlock
			slow_print("unleash the Hellfire Surge!", 25000);
			break;
		case 4:
			// For Bard
			slow_print("unleash the Symphony of Sorrow!", 25000);
			break;
		case 5:
			// For Rogue
			slow_print("unleash the Phantom Fangs!", 25000);
			break;
			
	}
}
void defend(int agent) {							// For the defense namings
	switch (agent) {
		case 1: 
			// For Sorcerer
			slow_print("cast the Void Barrier!", 25000);
			break;
		case 2: 
			// For Paladin
			slow_print("cast the Aegis of the Light!", 25000);
			break;
		case 3:
			// For Warlock
			slow_print("cast the Hexguard Veil!", 25000);
			break;
		case 4:
			// For Bard
			slow_print("cast the Resonance Armor!", 25000);
			break;
		case 5:
			// For Rogue
			slow_print("cast the Veil of Dusk!", 25000);
			break;
	}
}
void healing(int agent) {							// For the heal namings
	switch (agent) {
		case 1: 
			// For Sorcerer
			slow_print("take the Nectar of the Sun!", 25000);
			break;
		case 2: 
			// For Paladin
			slow_print("take the Tears from the Heavens!", 25000);
			break;
		case 3:
			// For Warlock
			slow_print("cast the Cursed Restoration!", 25000);
			break;
		case 4:
			// For Bard
			slow_print("cast the Lullaby of Life!", 25000);
			break;
		case 5:
			// For Rogue
			slow_print("take the Elixir of Vitality!", 25000);
			break;
	}
}
int playerDecision1(int decision1, int decision2, int *player1HP, int *player2HP, int health, int hero) { 	// This is for the decision that was cast by Player 1
    int x, def = 3, heal = 2;
    switch (decision1) {
        case 1:
            // Attack
            slow_print(" Attack!", 25000);
            slow_print("\nYou ", 25000);
            attack(hero);
            srand(time(0));
            x = rand() % 6; 
            *player2HP -= x;
            printf("\n\n(Player 1) Health Left: %d", *player1HP);
            printf("\n(Player 2) Health Left: %d\n", *player2HP);
            break;
        case 2:
            // Defend
            slow_print(" Defend!", 25000);
            slow_print("\nYou ", 25000);
            defend(hero);
            if (def >= decision2) {
                def = 0;
                *player1HP += def;
            } else {
                x = def - decision2;
                *player1HP += x;
            }
            printf("\n\n(Player 1) Health Left: %d", *player1HP);
            printf("\n(Player 2) Health Left: %d\n", *player2HP);
            break;
        case 3:
            // Heal
            slow_print(" Heal!", 25000);
            slow_print("\nYou ", 25000);
            healing(hero);
            *player1HP += heal;
            if (*player1HP > health) {
                *player1HP = health;
            }
            printf("\n\n(Player 1) Health Left: %d", *player1HP);
            printf("\n(Player 2) Health Left: %d\n", *player2HP);
            break;
    }
    return decision1;
}
int playerDecision2(int decision1, int decision2, int *player1HP, int *player2HP, int health) { 	// This is for the decision that was cast by Player 2
    int x, def = 3, heal = 2;
    switch (decision2) {
        case 1:
            // Attack
            slow_print(" Attack!", 25000);
            srand(time(0));
            x = rand() % 6; 
            *player1HP -= x;
            printf("\n\n(Player 1) Health Left: %d", *player1HP);
            printf("\n(Player 2) Health Left: %d", *player2HP);
            break;
        case 2:
            // Defend
            slow_print(" Defend!", 25000);
            if (def >= decision1) {
                def = 0;
                *player2HP += def;
            } else {
                x = def - decision1;
                *player2HP += x;
            }
            printf("\n\n(Player 1) Health Left: %d", *player1HP);
            printf("\n(Player 2) Health Left: %d", *player2HP);
            break;
        case 3:
            // Heal
            slow_print(" Heal!", 25000);
            *player2HP += heal;
            if (*player2HP > health) {
                *player2HP = health;
            }
            printf("\n\n(Player 1) Health Left: %d", *player1HP);
            printf("\n(Player 2) Health Left: %d", *player2HP);
            break;
    }
    return decision2;
}
void coinToss(int coinChance){																		// For the coin toss
	switch (coinChance) {
        case 1:
            slow_print("You chose Heads!", 25000);
            break;
        case 2:
            slow_print("You chose Tails!", 25000);
            break;
    }
}
void printRoundSummary(int round, int p1choice, int p2choice, int p1HP, int p2HP) {					// This is for the summary of moves
    printf("R%d: Player 1 - ", round);
    switch (p1choice) {
        case 1:
            printf("Attack	");
            break;
        case 2:
            printf("Defend	");
            break;
        case 3:
            printf("Heal	");
            break;
    }
    printf(" (HP: %d),	Player 2 - ", p1HP);
    switch (p2choice) {
        case 1:
            printf("Attack");
            break;
        case 2:
            printf("Defend");
            break;
        case 3:
            printf("Heal	");
            break;
    }
    printf(" (HP: %d)\n", p2HP);
}

int main() {
    int hero, count = 45, compHero, p1Hp, p2Hp, countUlt = 0, p1choice, decisionP1, p2choice, decisionP2, x, heroUlt, coinDecision, chance, health, turn;
    int player1Moves[50]={0}, player2Moves[50]={0};
    const char *hero2;  

    slow_print("The stars have spoken, and the winds carry whispers of fate... your journey awaits....", 25000);
    slow_print("\n\nTHE GAME HAS BEGUN", 50000);
    
	while (1) {			//To let user select their champion
        slow_print("\n\nCHOOSE YOUR CHAMPION (1 - Sorcerer, 2 - Paladin, 3 - Warlock, 4 - Bard, 5 - Rogue): ", 25000);
        scanf("%d", &hero);
        
        if (hero >= 1 && hero <= 5) {
            p1Hero(hero);
            break;
        } else {
            slow_print("You are not following the rules. Cast a number from 1-5 only...", 25000);
        }
    }
    
    slow_print("\n\nYour foe picks... ", 50000);
    hero2 = p2Hero(); 
    printf("the %s", hero2);
    
	// Coin Toss
    slow_print("\nWe will perform a coin toss first...", 25000);
    while (1){
    		slow_print("\n\nWhich side do you choose? (1 - Heads, 2 - Tails): ", 25000);
    		scanf("%d", &coinDecision);
    		
    		if (coinDecision==1 || coinDecision==2){
    			coinToss(coinDecision);
    			
    			srand(time(0));
	    		chance = rand() % 2 + 1;
    			if (coinDecision == chance) {
	        	// Player 1 wins the coin toss
					slow_print("\nYou win the coin toss!", 25000);
			        slow_print("\nPlayer 1 Goes First", 25000);
			        turn = 1; 
	    		} 
				else {
		        // Player 2 wins the coin toss
		        slow_print("\nYou lose the coin toss!", 25000);
		        slow_print("\nPlayer 2 Goes First", 25000);
		        turn = 2;  
		    	}
    			break;
			}
			else{
				slow_print("You are not following the rules. Cast a number from 1-2 only...", 25000);
			}
	}
	
	//For determining the max health
	while(1){
	    slow_print("\n\nWhat shall be the maximum health of both players? (It should range from 50-200): ", 25000);
	    scanf("%d", &health);
	
	    if (health >= 50 && health <= 200) {
	        printf("\nMaximum Health: %d", health);
	        p1Hp = health;
	        p2Hp = health;
	        printf("\nMaximum Health(P1): %d", p1Hp);
	        printf("\nMaximum Health(P2): %d", p2Hp);
	        break;
	    } else {
	        slow_print("You are not following the rules. Cast a number from 50-200 only...", 25000);
	    }
	}
	
    slow_print("\n\nThis is a battle to determine the Ruler of All Realms... ", 25000);
    sleep(1);
    slow_print("Ready... Set... FIGHT!...", 50000);
    
// This is the counting of the game
	while (count <= 50) {
	    slow_print("\n\nRound ", 50000);
	    printf("%d...", count); sleep(0.5);
	    slow_print("Fight!", 50000);
	
			if (turn == 1) {
			    while(1){
			        slow_print("\n\nWhat would you like to do?(1 - Attack, 2 - Defend, 3 - Heal): ", 25000);
			        scanf("%d", &p1choice);
			
			        if (p1choice >= 1 && p1choice <= 3) {
			            player1Moves[count - 1] = p1choice;
			            slow_print("You chose to...", 50000);
			            decisionP1 = playerDecision1(p1choice, p2choice, &p1Hp, &p2Hp, health, hero);
			            
			            srand(time(0));
			            p2choice = rand() % 3 + 1;
			            player2Moves[count - 1] = p2choice;
			            slow_print("Player 2 chose to...", 50000);
			            decisionP2 = playerDecision2(p1choice, p2choice, &p1Hp, &p2Hp, health);
			            turn = 1; 
			            break; 
			        } 
					else {
			            slow_print("You are not following the rules. Cast a number from 1-3 only...", 25000);
			        }
			    }
			} 
			else if (turn == 2) {
			    slow_print("\n\nPlayer 2 chooses to...", 50000); 
			    srand(time(0));
			    p2choice = rand() % 3 + 1;
			    player2Moves[count - 1] = p2choice; 
			    decisionP2 = playerDecision2(p1choice, p2choice, &p1Hp, &p2Hp, health);
			
			    while(1){
			        slow_print("\n\nWhat would you like to do?(1 - Attack, 2 - Defend, 3 - Heal): ", 25000);
			        scanf("%d", &p1choice);
			
			        if (p1choice >= 1 && p1choice <= 3) {
			            player1Moves[count - 1] = p1choice; 
			            slow_print("You chose to...", 50000);
			            decisionP1 = playerDecision1(p1choice, p2choice, &p1Hp, &p2Hp, health, hero);
			
			            turn = 2; 
			            break; 
			        } 
					else {
			            slow_print("You are not following the rules. Cast a number from 1-3 only...", 25000);
			        }
			    }
			}
	    count++;
	}
	
	slow_print("\n\nGAME OVER!\n", 50000);
	while (count > 50) {
        if (p1Hp < p2Hp) {
            slow_print("\n\nNOOOOO GAME OVER! Player 2 wins...", 25000);
            break;
        } else {
            slow_print("\n\nVICTORY! You are now the Ruler of all Realms", 25000);
            break;
        }
    }
	
	// Final summary of Player 1's and Player 2's moves
	for (int i = 0; i < count; i++) {
	    if (player1Moves[i] != 0 && player2Moves[i] != 0) {
	        printRoundSummary(i + 1, player1Moves[i], player2Moves[i], p1Hp, p2Hp);
	    }
	}
	    
    return 0;
}