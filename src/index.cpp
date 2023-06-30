#include <iostream>
#include <vector>

using namespace std;

class Item {
public:
    string name;
    int quantity;

    Item(string itemName, int itemQuantity) {
        name = itemName;
        quantity = itemQuantity;
    }
};

class Player {
public:
    string playerName;
    int sanity;
    int vitality;
    vector<Item> inventory;
    int money;

    Player(string name) {
        playerName = name;
        sanity = 100;
        vitality = 100;
        money = 300;
    }

    void addItemToInventory(Item item) {
        inventory.push_back(item);
    }

    void removeItemFromInventory(int index) {
        inventory.erase(inventory.begin() + index);
    }

    void displayInventory() {
        cout << "Inventory:" << endl;
        for (int i = 0; i < inventory.size(); i++) {
            cout << i + 1 << ". " << inventory[i].name << " x" << inventory[i].quantity << endl;
        }
    }

    void displayStatus() {
        cout << "Player Name: " << playerName << endl;
        cout << "Sanity: " << sanity << endl;
        cout << "Vitality: " << vitality << endl;
        cout << "Money: " << money << endl;
    }
};

class Game {
public:
    Player player;
    int currentDay;

    Game(string playerName) : player(playerName) {
        currentDay = 1;
    }

    void start() {
        while (currentDay <= 30 && player.sanity > 0 && player.vitality > 0) {
            cout << "Day " << currentDay << endl;
            cout << "What do you want to do?" << endl;
            cout << "1. Explore the surroundings." << endl;
            cout << "2. Visit the store." << endl;
            cout << "3. Check inventory." << endl;
            cout << "4. Rest and recover." << endl;

            int choice;
            cin >> choice;

            switch (choice) {
                case 1:
                    exploreSurroundings();
                    break;
                case 2:
                    visitStore();
                    break;
                case 3:
                    player.displayInventory();
                    break;
                case 4:
                    restAndRecover();
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    continue;
            }

            currentDay++;
        }

        if (currentDay > 30) {
            cout << "Congratulations! You survived for 30 days." << endl;
        } else {
            cout << "Game over. You died." << endl;
        }
    }

    void exploreSurroundings() {
        cout << "You go out to explore the surroundings..." << endl;
        // Lógica da exploração
        // Pode haver eventos aleatórios, descoberta de recursos, etc.
        cout << "You return to the bunker." << endl;
    }

    void visitStore() {
        cout << "Welcome to the store!" << endl;
        // Lógica da loja
        // O jogador pode comprar e vender itens com seu dinheiro
        cout << "You leave the store." << endl;
    }

    void restAndRecover() {
        cout << "You decide to rest and recover..." << endl;
        // Lógica do descanso teste

}
