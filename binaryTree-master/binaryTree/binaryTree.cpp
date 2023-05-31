#include "_Tree_drawing.h"
#include "_Tree.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "_Tree_traversal.h"


int main() {
    
    sf::Font font;
    if (!font.loadFromFile("CyrilicOld.TTF"))
        return -1;

    auto tree = std::make_shared<_Tree<int, int>>(_Tree<int, int>());
    _Tree_drawing<int, int> drawer(tree, font);

    sf::RenderWindow window(sf::VideoMode(700, 700), "Tree");
    window.setFramerateLimit(60);
  
    while (window.isOpen()) {
        sf::Event event;
      
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    std::cout << "add value:";
                    int value;
                    std::cin >> value;
                    int key;
                    //std::cout << "add key:";
                    //std::cin >> key;
                    tree->_Emplace(value, value);
                }

                if (event.key.code == sf::Keyboard::D) {
                    std::cout << "Deleat by key:";
                    int key;
                    std::cin >> key;
                    tree->_Extract(key);
                }


                if (event.key.code == sf::Keyboard::G) {
                    std::cout << "Find by key:";
                    int key;
                    std::cin >> key;
                    int a = tree->_Get(key);
                    std::cout << a << "\n";
                }

                if (event.key.code == sf::Keyboard::Num1) {
                    std::vector<_Tree_node<int, int>*>* travel = new std::vector<_Tree_node<int, int>*>();
                   _Tree_traversal<int, int>::_Revers_order(tree->getMyhead(), travel);
                   std::cout << "Revers order\n";
                   for (_Tree_node<int, int>* i : *travel) {
                       std::cout << i->_Myval << "\n";
                   }
                }

                if (event.key.code == sf::Keyboard::Num2) {
                    std::vector<_Tree_node<int, int>*>* travel = new std::vector<_Tree_node<int, int>*>();
                    _Tree_traversal<int, int>::_Symmetric_order(tree->getMyhead(), travel);
                    std::cout << "Symetric order\n";
                    for (_Tree_node<int, int>* i : *travel) {
                        std::cout << i->_Myval << "\n";
                    }
                }
                if (event.key.code == sf::Keyboard::Num3) {
                    std::vector<_Tree_node<int, int>*>* travel = new std::vector<_Tree_node<int, int>*>();
                    _Tree_traversal<int, int>::_Direct_order(tree->getMyhead(), travel);
                    std::cout << "Direct order\n";
                    for (_Tree_node<int, int>* i : *travel) {
                        std::cout << i->_Myval << "\n";
                    }
                }
            }
        }
         
  
        window.clear();
        window.draw(drawer);

        window.display();
        
    }
    return 0;
}