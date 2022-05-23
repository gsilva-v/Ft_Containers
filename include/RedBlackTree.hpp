#if !defined(BST_ALGORTHM_HPP)
#define BST_ALGORTHM_HPP

#include <iostream>

namespace ft
{
	enum Color{
		Black,
		Red
	};

	template <typename T> struct Node
	{
		Node	*parent;
		T		value;
		Node	*left;
		Node	*right;
		Color 	color;
	};
	
	template <typename T> class BstAlgorithm
	{	
	public:
		typedef T value_type;
		Node<T> *root;

	public:
		BstAlgorithm(): root(NULL){};
		~BstAlgorithm(){};

		Node<value_type> *newNode(value_type value){

			Node<value_type> *new_node = new Node<value_type>;

			new_node->right = NULL;
			new_node->left = NULL;
			new_node->parent = NULL;
			new_node->color = Color::Black;
			new_node->value = value;
			return new_node;
		}

		Node<value_type>	*findSlot(Node<value_type> *node, Node<value_type> **root = NULL){	
			Node<value_type> *init;

			if (root == NULL)
				root = &this->root;
			if (*root == NULL){
				*root = node;
				return node;
			} else
				init = *root;
			while (init)
			{
				if (node->value < init->value){
					if (!init->left){
						node->parent = init;
						init->left = node;
					}
					init = init->left;
				}
				else if (node->value > init->value){
					if (!init->right){
						node->parent = init;
						init->right = node;
					}
					init = init->right;
				}
				else
					return init;
			}
			return node;
		};

		virtual value_type insert(value_type new_value){

			Node<value_type> *new_node = newNode(new_value);
			Node<value_type> *found;
			found = findSlot(new_node);
			if (!new_node->parent && new_node != this->root)
				delete new_node;	
			return found->value;
		};

		Node<value_type> *getHigherNode(Node<value_type> *node){
			while (node && node->right)
				node = node->right;
			return node;
		}

		Node<value_type> *getLowerNode(Node<value_type> *node){
			while (node && node.left)
				node = node.left;
			return node;
		}

		virtual void deleteNode(Node<value_type> *node){
			if (!node->left && !node->right){//se nao houver nenhum filho
				this->swapNode(node, NULL);
			} else if (node->left && node->right){ //caso tenham 2 filhos
				Node<value_type> *higher = this->getHigherNode(node->left);
				this->swapNode(higher, higher->left);
				this->swapNode(node, higher);
			} else if (node->left || node->right){ //caso tenha 1 filho
				if (node->left){
					this->swapNode(node, node->left);
				} else {
					this->swapNode(node, node->right);
				}
			}
			delete node;
		};

		void	swapNode(Node<value_type> *node, Node<value_type> *sub){
			
			if (!node)
					return;

			if (sub){
				sub->parent = node->parent;
				if (node->left != sub && node->left){
					sub->left = node->left;
					node->left->parent = sub;
				}
				if (node->right != sub && node->right){
					sub->right = node->right;
					node->right->parent = sub;
				}
			}
		
			if (node && node->parent){
				if (node->parent->left == node)
					node->parent->left = sub;
				else
					node->parent->right = sub;
			}		
			else
				this->root = sub;
		}

		Node<value_type> *find(value_type value, Node<value_type> *root = NULL){
			if (!root)
				root = this->root;			
			Node<value_type> *init = root;

			while (init)
			{
				if (value == init->value){
					return init;
				} else if (value < init->value)
					init = init->left;
				else if (value > init->value)
					init = init->right;
			}
			return NULL;
		};

		void remove(value_type value){
			Node<value_type> *node = this->find(value);

			if (node)
				this->deleteNode(node);
		};
	};

	enum Direction{
		Left,
		Right
	};

	template <typename T> class RedBlackTree : public BstAlgorithm<T>
	{
	public:
		typedef T value_type;

	public:
		RedBlackTree():BstAlgorithm<T>(){

		};
		~RedBlackTree(){};

		Direction getDirection(Node<value_type> *node){
			if (node->parent->right == node)
				return Direction::Right;
			return Direction::Left;
		};

		void mergeTrees(Node<value_type> *node, Node<value_type> **root = NULL){
			if (!node)
				return ;
			this->findSlot(node, root);
			this->mergeTrees(node->left);
			this->mergeTrees(node->right);
		};

		void rotate(Node<value_type> *node){
			if (getDirection(node) == Direction::Right){
				this->rotateLeft(node);
			} else
				this->rotateRight(node);
		}

		void rotateLeft(Node<value_type> *node){
			Node<value_type> *old_parent = node->parent;
			
			old_parent->right = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && getDirection(old_parent) == Direction::Right){
				node->parent->right = node;
			} else if (old_parent->parent)
				node->parent->left = node;

			Node<value_type> *leftTree = node->left;
			node->left = old_parent;
			old_parent->parent = node;
			this->mergeTrees(leftTree, &node->left);

			if (old_parent == this->root)
				this->root = node;
		};

		void rotateRight(Node<value_type> *node){
			Node<value_type> *old_parent = node->parent;
			
			old_parent->left = NULL;
			node->parent = node->parent->parent;
			if (old_parent->parent && getDirection(old_parent) == Direction::Right){
				node->parent->right = node;
			} else if (old_parent->parent)
				node->parent->left = node;

			Node<value_type> *right = node->right;
			node->right = old_parent;
			old_parent->parent = node;
			this->mergeTrees(right, &node->right);

			if (old_parent == this->root)
				this->root = node;
		};

		Node<value_type> *getSibling(Node<value_type> *node){
			
			if (!node->parent)
				return NULL;
			if(node->parent->left != node)
				return node->parent->left;
			return node->parent->right;
		};

		Color getSiblingColor(Node<value_type> *node){
			
			if (!node->parent)
				return Color::Black;
			if (node->parent->left != node){
				if (node->parent->left)
					return node->parent->left->color;
				return Color::Black;
			}
			if (node->parent->right)
				return node->parent->right->color;
			return Color::Black;
		};

		void	reddish(Node<value_type> *node){
			node->color = Color::Red;

			if (node->parent->color == Color::Black){
				return ;
			} else if (node->parent->color == Color::Red){
				Color parentSiblingColor = getSiblingColor(node->parent);
				if (parentSiblingColor == Color::Black){
					if (this->getDirection(node) == this->getDirection(node->parent)){
						this->rotate(node->parent);
						node->parent->color = Color::Black;
						node->color = Color::Red;
						this->getSibling(node)->color = Color::Red;
					} else {
						this->rotate(node);
						this->rotate(node);
						node->color = Color::Black;
						if (node->left)
							node->left->color = Color::Red;
						if (node->right)
							node->right->color = Color::Red;
					}
				} else if (parentSiblingColor == Color::Red){
					node->parent->color = Color::Black;
					this->getSibling(node->parent)->color = Color::Black;
					if (node->parent->parent != this->root){
						this->reddish(node->parent->parent);
					}
				}	
			}
		};

		Direction opositeDirection(Direction dir){
			if (dir == Direction::Left)
				return Direction::Right;
			return Direction::Left;			
		}

		Node<value_type> *getChild(Node<value_type> *node, Direction dir){
			if (dir == Direction::Left)
				return node->left;
			return node->right;
		}


		bool isBlack(Node<value_type> *node){
			return(!node || node->color == Color::Black);
		};

		bool isRed(Node<value_type> *node){
			return(node && node->color == Color::Red);
		};

		void	repassBlack(Node<value_type> *node){
			// Case 2
			if (node == this->root)
				return ;
			Node<value_type> *sibling = this->getSibling(node);
			// Case 3
			if (isBlack(sibling) && isBlack(sibling->left) && isBlack(sibling->right)){
				sibling->color = Color::Red;
				if (node->parent->color == Color::Red)
					node->parent->color == Color::Black;
				else
					repassBlack(node->parent);
			}
			// Case 4
			else if (isRed(sibling)){
				sibling->color = node->parent->color;
				node->parent->color = Color::Red;
				rotate(sibling);
				repassBlack(node);
			}
			// Case 5 
			else if (isBlack(sibling) &&
				isBlack(getChild(sibling, opositeDirection(getDirection(node)))) && 
				isRed(getChild(sibling,getDirection(node)))){
					Node<value_type> *nearChild = getChild(sibling,getDirection(node));
					sibling->color = Color::Red;
					nearChild->color = Color::Black;
					rotate(nearChild);				
			}
			// Case 6
			if (isBlack(sibling) &&
				isRed(getChild(sibling, opositeDirection(getDirection(node))))){
				sibling->color = node->parent->color;
				node->parent->color = Color::Black;
				rotate(sibling);
				getChild(sibling, opositeDirection(getDirection(node)))->color = Color::Black;
			}
		};

		void deleteNode(Node<value_type> *node){
			// case 1
			if (!node->left && !node->right){
				if (node->color == Color::Black){
					this->repassBlack(node);
				}
				this->swapNode(node, NULL);
				delete node;
			} else if (node->left && node->right){
				Node<value_type> *higher = this->getHigherNode(node->left);

				node->value = higher->value;
				deleteNode(higher);
			} else if (node->left || node->right){
				if (node->left){
					node->value = node->left->value;
					deleteNode(node->left);
				} else {
					node->value = node->right->value;
					deleteNode(node->right);
				}
			}
		};

		value_type insert(value_type new_value){
			Node<value_type> *node = this->newNode(new_value);
			Node<value_type> *found;

			found = this->findSlot(node);
			if (found->value != node->value){
				delete node ;
				return found->value;
			}

			if (!node->parent && node != this->root){//caso ja exista
				delete node ;
				return found->value;
			}
			else if (node == this->root){// se for o proprio root
				return found->value;
			}
			this->reddish(node);
			return found->value;
		};
	};
}; // namespace ft

#endif // BST_ALGORTHM_HPP
