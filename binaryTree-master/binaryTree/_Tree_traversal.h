#pragma once
#include "_Tree.h"
#include <vector>
#include <iostream>

template<class _Kty, class _Ty>
class _Tree_traversal {
public:
	using tree_type       = _Tree<_Kty, _Ty>;
	using _Treeptr        = tree_type*;
	using _Tree_reference = tree_type&;
	using node_type       = _Tree_node<_Kty, _Ty>;
	using _Nodeptr        = node_type*;

	static std::vector<std::vector<_Nodeptr>*>* _Level_order(_Tree_reference _tree) {
		_Nodeptr _Head = _tree.getMyhead();
		if (_Head == nullptr)
			return nullptr;
		std::vector<_Nodeptr>* _traversal_set_level_first = new std::vector<_Nodeptr>{ _Head };
		std::vector<std::vector<_Nodeptr>*>* _traversal_set = new std::vector<std::vector<_Nodeptr>*>;
		_traversal_set->push_back(_traversal_set_level_first);
		bool f = false;
		while (true) {
			std::vector<_Nodeptr> _traversal_set_level;
			if (f) break;
			f = true;
			for (auto _nodeprt : *(_traversal_set->back())) {
				if (_nodeprt != nullptr) {
					f = false;
					_traversal_set_level.push_back(_nodeprt->_Right);
					_traversal_set_level.push_back(_nodeprt->_Left);
				}
				else {
					_traversal_set_level.push_back(nullptr);
					_traversal_set_level.push_back(nullptr);
				}
			}
		}
		return _traversal_set;
	}

	static std::vector<std::vector<_Nodeptr>>* _Level_order(_Treeptr _tree) {
		_Nodeptr _Head = _tree->getMyhead();
		if (_Head == nullptr)
			return nullptr;
		std::vector<_Nodeptr> _traversal_set_level_first =  std::vector<_Nodeptr>{ _Head };
		std::vector<std::vector<_Nodeptr>>* _traversal_set = new std::vector<std::vector<_Nodeptr>>;
		_traversal_set->push_back(_traversal_set_level_first);
		bool f = false;
		while (true) {
			std::vector<_Nodeptr> _traversal_set_level;
			if (f) break;
			f = true;
			for (_Nodeptr _nodeprt : _traversal_set->back()) {
				if (_nodeprt != nullptr) {
					f = false;
					_traversal_set_level.push_back(_nodeprt->_Left);
					_traversal_set_level.push_back(_nodeprt->_Right);
				}
				else {
					_traversal_set_level.push_back(nullptr);
					_traversal_set_level.push_back(nullptr);
				}
			}
			_traversal_set->push_back(_traversal_set_level);
		}
		return _traversal_set;
	}

	static std::vector<_Nodeptr>* _Direct_order (_Nodeptr node, std::vector< _Nodeptr>* _traversal_set) {
		if (node == nullptr)
			return nullptr;
		if (_traversal_set == nullptr)
			return nullptr;
		_traversal_set->push_back(node);
		if (node->_Left)
			_Direct_order(node->_Left, _traversal_set);
		if (node->_Right)
			_Direct_order(node->_Right, _traversal_set);
		return _traversal_set;
	}

	static std::vector<_Nodeptr>* _Symmetric_order(_Nodeptr node, std::vector<_Nodeptr>* _traversal_set) {
		if (node == nullptr)
			return nullptr;
		if (_traversal_set == nullptr)
			return nullptr;
		if (node->_Left)
			_Symmetric_order(node->_Left, _traversal_set);
		_traversal_set->push_back(node);
		if (node->_Right)
			_Symmetric_order(node->_Right, _traversal_set);
		return _traversal_set;
	}

	static std::vector<_Nodeptr>* _Revers_order(_Nodeptr node, std::vector<_Nodeptr>* _traversal_set) {
		if (node == nullptr)
			return nullptr;
		if (_traversal_set == nullptr)
			return nullptr;

		if (node->_Left)
			_Revers_order(node->_Left, _traversal_set);
		if (node->_Right)
			_Revers_order(node->_Right, _traversal_set);
		_traversal_set->push_back(node);
		return _traversal_set;
	}
};

