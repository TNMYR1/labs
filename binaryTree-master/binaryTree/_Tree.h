#pragma once
enum _Tree_child {
	_Right,
	_Left
};

template <class _Nodeptr>
struct _Tree_id {
	_Nodeptr _Parent; // the leaf node under which a new node should be inserted
	_Tree_child _Child;
};

enum class Redbl {       // colors
	_Black = 0,
	_Red = 1
};

template<class _Kty, class _Ty>
struct _Tree_node {
	using key_type   = _Kty;
	using value_type = _Ty;
	using _Nodeptr   = _Tree_node*;

	_Nodeptr _Parent;   // left subtree, or smallest element if head
	_Nodeptr _Right;   // right subtree, or largest element if head
	_Nodeptr _Left;    // parent, or root of tree if head
	Redbl _Color;       // _Red or _Black, _Black if head
	key_type _Mykey;
	value_type _Myval; // stored value

	_Tree_node(const _Tree_node&) = delete;
	_Tree_node& operator=(const _Tree_node&) = delete;

	_Tree_node() {
	}
};

template<class _Kty, class _Ty>
class _Tree {
public:
	using node_type       = _Tree_node<_Kty, _Ty>;
	using key_type        = _Kty;
using size_type       = unsigned int;
	using value_type      = _Ty;
	using _Nodeptr        = node_type*;
	using reference       = value_type&;
	using const_reference = const value_type&;
public:
	static _Nodeptr _Max(_Nodeptr _Pnode) noexcept { // return rightmost node in subtree at _Pnode
		while (_Pnode->_Right !=  nullptr) {
			_Pnode = _Pnode->_Right;
		}
		return _Pnode;
	}

	static _Nodeptr _Min(_Nodeptr _Pnode) noexcept { // return leftmost node in subtree at _Pnode
		while (_Pnode->_Left != nullptr) {
			_Pnode = _Pnode->_Left;
		}
		return _Pnode;
	}
private:
	_Nodeptr _Myhead; // pointer to head node
	size_type _Mysize; // number of elements
public:
	_Nodeptr getMyhead() {
		return _Myhead;
	}
protected:
	void _Lrotate(const _Nodeptr _Head) {
		const auto _Left = _Head->_Left;
		const auto _Right = _Head->_Right;
		const auto _Parent = _Head->_Parent;
	
		
		_Head->_Right = _Right->_Left;
		_Head->_Parent = _Right;
		_Right->_Left = _Head;
		_Right->_Parent = _Parent;
		
		if (_Myhead == _Head) {
			_Myhead = _Right;
			_Myhead->_Parent = nullptr;
		}
		else {
			
			if (_Parent->_Right == _Head)
				_Parent->_Right = _Right;
			else
				_Parent->_Left = _Right;
			
		}
 	}

	void _Rrotate(_Nodeptr _Head) {
		const auto _Left = _Head->_Left;
		const auto _Right = _Head->_Right;
		const auto _Parent = _Head->_Parent;

	
		_Head->_Left = _Left->_Right;
		_Head->_Parent = _Left;
		_Left->_Parent = _Parent;
		_Left->_Right = _Head;


		if (_Myhead == _Head) {
			_Myhead = _Left;
			_Myhead->_Parent = nullptr;
		}
		else {
			if (_Parent->_Right == _Head)
				_Parent->_Right = _Left;
			else
				_Parent->_Left = _Left;
		}
	}
public:

	_Nodeptr _Insert_node(const _Tree_id<_Nodeptr> _Loc, const _Nodeptr _Newnode) noexcept {
		_Mysize++;
		_Newnode->_Parent = _Loc._Parent;
		// situation 1 Head
		if (nullptr == _Loc._Parent) { // _Head == _Parent == nullptr first node in tree
			_Myhead = new node_type();
			_Myhead->_Parent = nullptr;
			_Myhead->_Color = Redbl::_Black; // head is black
			_Myhead->_Myval = _Newnode->_Myval;
			_Myhead->_Mykey = _Newnode->_Mykey;
			_Myhead->_Left = _Newnode->_Left;
			_Myhead->_Right = _Newnode->_Right;
			return _Newnode;
		}

		if (_Loc._Child == _Tree_child::_Right) {
			_Loc._Parent->_Right = _Newnode;
		}

		if (_Loc._Child == _Tree_child::_Left) {
			_Loc._Parent->_Left = _Newnode;
		}

		// situation 2 Just insert
		if (_Loc._Parent->_Color == Redbl::_Black) {
			return _Newnode;
		}

		// situation 3 balance
		for (_Nodeptr _N_Node = _Newnode; (_N_Node != _Myhead && _N_Node->_Parent->_Color != Redbl::_Black);) {
			if (_N_Node->_Parent->_Parent == nullptr) {
				break;
			}
			auto granddad = _N_Node->_Parent->_Parent;

			if (granddad->_Right == _N_Node->_Parent) {
				if (_N_Node->_Parent->_Right == _N_Node) {
					_Lrotate(granddad);

					_N_Node->_Parent->_Color = Redbl::_Red;
					
					_N_Node->_Parent->_Right->_Color = Redbl::_Black;
					if (_N_Node->_Parent->_Left != nullptr)
						_N_Node->_Parent->_Left->_Color = Redbl::_Black;
					

					_N_Node = _N_Node->_Parent;
					continue;
				}
				else {
					_Rrotate(_N_Node->_Parent);
					_N_Node = _N_Node->_Right;

					continue;
				}
			}
			else {
				if (_N_Node->_Parent->_Left == _N_Node) {
					_Rrotate(granddad);
					_N_Node->_Parent->_Color = Redbl::_Red;
					_N_Node->_Parent->_Left->_Color = Redbl::_Black;
					if (_N_Node->_Parent->_Right != nullptr)
						_N_Node->_Parent->_Right->_Color = Redbl::_Black;
					if (_N_Node->_Parent == _Myhead) {
						break;
					}
					_N_Node = _N_Node->_Parent;
					continue;;
				}
				else {
					_Lrotate(_N_Node->_Parent);
					_N_Node = _N_Node->_Left;
					continue;
				}
			}
		}
		
		_Myhead->_Color = Redbl::_Black;

		return _Newnode;
	}


	_Nodeptr _Deleate_Node(const _Nodeptr _node) {
		if (_node == _Myhead && !_node->_Right && !_node->_Left) {
			delete(_Myhead);
			_Myhead = nullptr;
			return nullptr;
		}
		// _Red without children 
		if ((_node->_Color == Redbl::_Red) && (_node->_Right == nullptr) && (_node->_Left == nullptr)) {
			if (_node->_Parent->_Right == _node)
				_node->_Parent->_Right = nullptr;
			else
				_node->_Parent->_Left = nullptr;

			delete(_node);
			return nullptr;
		}
		// _Red with two children
		if (_node->_Color == Redbl::_Red) {
			_Nodeptr _node_max = _Tree::_Max(_node->_Left);
			_node->_Myval = _node_max->_Myval;
			_node->_Mykey = _node_max->_Mykey;
			_Deleate_Node(_node_max);
			return nullptr;
		}

		// _Black with two children 
		if (_node->_Color == Redbl::_Black && _node->_Right && _node->_Left) {
			_Nodeptr _node_max = _Tree::_Max(_node->_Left);
			_node->_Myval = _node_max->_Myval;
			_node->_Mykey = _node_max->_Mykey;
			_Deleate_Node(_node_max);
			return nullptr;
		}

		// _Black with one left children  
		if (_node->_Color == Redbl::_Black && _node->_Left) {
			_node->_Myval = _node->_Left->_Myval;
			_node->_Mykey = _node->_Left->_Mykey;
			delete(_node->_Left);
			_node->_Left = nullptr;
			return nullptr;
		}

		// _Black with one Right children  
		if (_node->_Color == Redbl::_Black && _node->_Right) {
			_node->_Myval = _node->_Right->_Myval;
			_node->_Mykey = _node->_Right->_Mykey;
			delete(_node->_Right);
			_node->_Right = nullptr;
			return nullptr;
		}

		// _Black without children
		auto _Parent = _node->_Parent;
		
		
		for (_Nodeptr _N_Node = _node;;) {
			if (_N_Node == _Myhead) {
				break;
			}
			auto _N_Parent = _N_Node->_Parent;
			if (_N_Parent->_Left == _node) {
				auto sibling = _N_Parent->_Right;
				if (!sibling) {
					_N_Parent->_Color = Redbl::_Black;
					_N_Node = _N_Parent;
					continue;
				}
				if (sibling->_Color == Redbl::_Black) {
					// sibling black right children red
					if (sibling->_Right && sibling->_Right->_Color == Redbl::_Red) {
						_N_Parent->_Color = Redbl::_Black;
						sibling->_Right->_Color = Redbl::_Black;
						sibling->_Color = Redbl::_Red;
						_Lrotate(_N_Parent);
						break;
					}
					// sibling black left children red
					if (sibling->_Left && sibling->_Left->_Color == Redbl::_Red) {
						sibling->_Left->_Color = Redbl::_Black;
						sibling->_Color = Redbl::_Red;
						_Rrotate(sibling);
						break;
					}
					// two children black
					sibling->_Color = Redbl::_Red;
					if (_N_Parent->_Color == Redbl::_Red) {
						_N_Parent->_Color = Redbl::_Black;
						break;
					}
					// recursion for father
					_N_Parent->_Color = Redbl::_Black;
					_N_Node = _N_Parent;
				}
				else {
					_N_Parent->_Color = Redbl::_Red;
					sibling->_Color = Redbl::_Black;
					_Lrotate(_N_Parent);
				}

			}
			else {
				auto sibling = _N_Parent->_Right;
				if (!sibling) {
					_N_Parent->_Color = Redbl::_Black;
					_N_Node = _N_Parent;
					continue;
				}
				if (sibling->_Color == Redbl::_Black) {
					// sibling black left children red
					if (sibling->_Left && sibling->_Left->_Color == Redbl::_Red) {
						sibling->_Right->_Color = Redbl::_Black;
						sibling->_Color = Redbl::_Red;
						_Lrotate(sibling);
						break;
					}
					// / sibling black right children red
					if (sibling->_Right && sibling->_Right->_Color == Redbl::_Red) {
						_N_Parent->_Color = Redbl::_Black;
						sibling->_Left->_Color = Redbl::_Black;
						sibling->_Color = Redbl::_Red;
						_Rrotate(_N_Parent);
						break;
					}

					// two children black
					sibling->_Color = Redbl::_Red;
					if (_N_Parent->_Color == Redbl::_Red) {
						_N_Parent->_Color = Redbl::_Black;
						break;
					}
					// recursion for Parent
					_N_Parent->_Color = Redbl::_Black;
					_N_Node = _N_Parent;
				}
				else {
					_N_Parent->_Color = Redbl::_Red;
					sibling->_Color = Redbl::_Black;
					_Rrotate(_N_Parent);
				}
			}
		}


			if (_node->_Parent->_Left == _node) {
				_Parent->_Left = nullptr;
			}
			else {
				_Parent->_Right = nullptr;
			}
			delete(_node);

			_Myhead->_Color = Redbl::_Black;
			return nullptr;
		}


	void _Emplace(key_type key, value_type value) {
		_Nodeptr _node = new node_type();
		_node->_Right  = nullptr;
		_node->_Left   = nullptr;
		_node->_Parent = nullptr;
		_node->_Mykey  = key;
		_node->_Myval  = value;
		_node->_Color  = Redbl::_Red;
		_Nodeptr _now_node = _Myhead;

		// situation first
		if (_now_node == nullptr) {
			_Tree_id<_Nodeptr> _loc;
			_loc._Parent = nullptr;
			_Insert_node(_loc, _node);
			return;
		}

		_Tree_id<_Nodeptr> _loc;
	
		while (true) {
			if (_now_node->_Mykey < _node->_Mykey) {
				if (_now_node->_Right == nullptr) {
					_loc._Parent = _now_node;
					_loc._Child = _Tree_child::_Right;
					_Insert_node(_loc, _node);
					return;
				}
				_now_node = _now_node->_Right;
			}
			else {
				if (_now_node->_Left == nullptr) {
					_loc._Parent = _now_node;
					_loc._Child = _Tree_child::_Left;
					_Insert_node(_loc, _node);
					return;
				}
				_now_node = _now_node->_Left;
			}
		}
	}



	void _Extract(key_type _key) {
		_Nodeptr _now_node = _Myhead;

		while (true) {
			if (_now_node == nullptr)
				break;
			if (_now_node->_Mykey == _key) {
				_Deleate_Node(_now_node);
				break;
			}
			if (_now_node->_Mykey > _key) {
				_now_node = _now_node->_Left;
			}
			else {
				_now_node = _now_node->_Right;
			}
		}
 		
	}


	value_type _Get(key_type _key) {
		_Nodeptr _now_node = _Myhead;

		while (true) {
			if (_now_node == nullptr)
				break;
			if (_now_node->_Mykey == _key) {
				return _now_node->_Myval;
			}
			if (_now_node->_Mykey > _key) {
				_now_node = _now_node->_Left;
			}
			else {
				_now_node = _now_node->_Right;
			}
		}
	}
};

/*
template <class _Tree>
class _Tree_const_iterator {
	using _Nodeptr        = _Tree::_Nodeptr;
	using value_type      = typename _Tree::value_type;
	using reference       = value_type&;
	using const_reference = const value_type&;
	using pointer         = typename _Tree::pointer;


	_Tree_const_iterator operator++() {
		_Tree_const_iterator _Tmp = *this;
		++* this;
		return _Tmp;
	}

	_Tree_const_iterator operator--() {
		_Tree_const_iterator _Tmp = *this;
		--* this;
		return _Tmp;
	}
	

};
/*
template <class _Tree>
class _Tree_iterator : public _Tree_const_iterator {
	using _Nodeptr        = _Tree::_Nodeptr;
	using value_type      = typename _Tree::value_type;
	using reference       = value_type&;
	using const_reference = const value_type&;
};
*/