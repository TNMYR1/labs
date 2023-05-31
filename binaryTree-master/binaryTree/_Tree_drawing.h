#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <set>
#include "_Tree.h"
#include "_Tree_traversal.h"

template<class _Kty, class _Ty>
class _Tree_drawing : public sf::Drawable, public sf::Transformable{
public:

	using _My_Tree          = _Tree<_Kty, _Ty>;
	using _My_TreeSharedptr = std::shared_ptr<_My_Tree>;
	using node_type         = _Tree_node<_Kty, _Ty>;
	using size_type         = unsigned int;
	using color_type        = sf::Color;
	using coords_type       = sf::Vector2f;
	using font_type         = sf::Font;
	using value_type        = _Ty;
	using reference         = value_type&;
	using const_reference   = const value_type&;
	using _Nodeptr          = node_type*;

private:
	size_type _My_Level_Height = 100;
	size_type _My_Height       = 700;
	size_type _My_Width        = 700;
	size_type _My_Step_Height  = 50;
	size_type _My_Node_Radius  = 20;

	color_type _Black_color      =  color_type(0, 0, 0);
	color_type _Red_color        = color_type(255, 0, 0);
	color_type _Background_color = color_type(255, 255, 255);

	font_type _My_font;
private:
	std::set<int> bypassSet;
	_My_TreeSharedptr _my_tree;
public:
	_Tree_drawing(_My_TreeSharedptr _tree, font_type _font) {
		_my_tree = std::move(_tree);
		_My_font = _font;
	}

	void _Draw_node(sf::RenderTarget& target, sf::RenderStates states, _Nodeptr _node, coords_type _coords) const {
		if (_node == nullptr) {
			return;
		}
		sf::CircleShape* node = new sf::CircleShape(_My_Node_Radius);
		node->setOrigin(node->getRadius(), node->getRadius());
		node->setFillColor(_Color_converter(_node->_Color));
		node->setPosition(_coords);
		target.draw(*node, states);

		// text
		
		auto txt = new sf::Text();
		txt->setString(std::to_string(_node->_Mykey));
	
		txt->setFillColor(sf::Color(0, 255, 0));
		txt->setFont(_My_font);
		txt->setPosition(_coords);
		target.draw(*txt, states);
		
	}

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= getTransform();

		auto background = new sf::RectangleShape(sf::Vector2f(_My_Width, _My_Height));
		background->setFillColor(_Background_color);
		target.draw(*background, states);

		std::vector<std::vector<_Nodeptr>>* level_order_nodes = _Tree_traversal<_Kty, _Ty>::_Level_order(_my_tree.get());
		if (level_order_nodes == nullptr) {
			return;
		}
		size_type levels_count = level_order_nodes->size();
		size_type level_now = 1;
		for (auto level_ptr : *level_order_nodes) {
			size_type level_heigh = _My_Level_Height * level_now;
			size_type step_width = _My_Width / (pow(2, level_now - 1) + 1);
			size_type step_now = 1;
			for (_Nodeptr node_ptr : level_ptr) {
				
				if (node_ptr != nullptr) {
					coords_type coords = coords_type(step_now * step_width, level_now * _My_Step_Height);
					_Draw_node(target, states, node_ptr, coords);
				}
				step_now++;
			}
			level_now += 1;
		}
	}
protected:
	color_type _Color_converter(Redbl redbl) const {
		switch (redbl) {
		case Redbl::_Black:
			return _Black_color;
		case Redbl::_Red:
			return _Red_color;
		default:
			break;
		}
	}
};