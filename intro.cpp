#include <iostream>
#include <vector>
#include <map>
#include <string>
int main() {
        std::cout << "Welcome to Explore, a survial based game! " << std::endl;
        // Vector for  characters
        std::vector<Character> characters;

        std::string name;
        std::cout <<  "You woke up with no memory. You need to find a way out and survive.\n";
        std::cout <<  "You remember if lost in woods find water, find water to escape the woods.\n";
        std::cout << "Enter your character name: ";
        std::cin >> name; //lets player add name
        std::cout << "Here are your stats\n ";
        characters.push_back(Character(name, 100, 75));//Display input name

        for (auto& character : characters) {
                character.display();
        }//Display characters

        Map gameMap;
        gameMap.addLocation("Forest", {{"north", "Field"}, {"east", "River"}, {"south", "Plains"}, {"west", "Cave"}},
                        "You are in a forest. Paths lead in all directions.",
                        "You see paths that lead north to a field, east to a river, south to plains, and west to a cave.");

        gameMap.addLocation("Field", {{"south", "Forest"}},
                        "A field extends under the open sky.",
                        "The path back to the forest is clear, and you can see the forest to the south.");

        gameMap.addLocation("River", {{"west", "Forest"}},
                        "The river flows swiftly here.");

        gameMap.addLocation("Plains", {{"north", "Forest"}},
                        "The plains are wide and open.",
                        "You can see the forest to the north.");

        gameMap.addLocation("Cave", {{"east", "Forest"}},
                        "The entrance to the cave is dark.",
                        ".");

        // Don't forget to add an initial location setup for "Forest" if not already done:
        gameMap.addLocation("Forest", {{"north", "Field"}, {"east", "River"}, {"south", "Plains"}, {"west", "Cave"}},
                        "You are surrounded by thick trees and the sound of wildlife.",
                        "Paths lead in all directions through the dense forest. Which way will you go?");

        // Display setting
        // std::cout << "You woke up with no memory in the " << setting["arena"] << ". You need to find a way out and survive." << std::endl;

        char directionChar;
        std::string direction;
        do {
                std::cout << gameMap.describeCurrentLocation() << std::endl;
                std::cout << gameMap.getCurrentLocationDescription() << std::endl;
                std::cout << gameMap.getCurrentNarrative() << std::endl;
                std::cout << "Choose a direction to explore (N/E/S/W): ";
                std::cin >> directionChar;//input
                directionChar = std::toupper(directionChar);//uppercase

                switch (directionChar) {
                        case 'N':
                                direction = "north";
                                break;
                        case 'E':
                                direction = "east";
                                break;
                        case 'S':
                                direction = "south";
                                break;
                        case 'W':
                                direction = "west";
                                break;
                        case 'Q':  // Add a quit option
                                std::cout << "Exiting game. Thank you for playing!" << std::endl;
                                return 0;  // Exit the game
                        default:
                                std::cout << "Invalid direction. Try again." << std::endl;
                                continue;
                }
                if (!gameMap.move( direction)) {
                        std::cout << "Invalid direction. Try again." << std::endl;
                }
                if (gameMap == "River") {
                        std::cout << "You hear the sound of running water growing stronger. ";
                        std::cout << "Following it downstream, you find a small village.  You are safe again.\n";
                        return 0;
                }

        } while (true);

        return 0;
}

~                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ~                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ~                             
