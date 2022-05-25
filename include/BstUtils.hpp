#pragma once

#include "BstAlgorithm.hpp"

namespace ft
{
	template<typename Key, typename T>
	void	swapNode(BstNode<Key, T> *node, BstNode<Key, T> *sub, BstNode<Key,T> **root){
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
		if (node->parent){
			if (node->parent->left == node)
				node->parent->left = sub;
			else
				node->parent->right = sub;
		}
		else{
			*root = sub;
		}
	};

	template<typename Key, typename T>
	void deleteNode(BstNode<Key, T> *node, BstNode<Key, T> **root){
		if (!node->left && !node->right){
			swapNode(node, static_cast<BstNode<Key, T> *>(NULL), root);
		} else if (node->left && node->right){
			BstNode<Key, T> *higher = (*root)->getHigherNode(node->left);
			swapNode(higher, higher->left, root);
			higher->left = NULL;
			higher->right = NULL;
			swapNode(node, higher, root);
		} else if (node->left || node->right){
			if (node->left){
				swapNode(node, node->left, root);
			} else {
				swapNode(node, node->right, root);
			}
		}
		delete node;
	};

	template<typename Key, typename T>
	bool removeNode(const Key key, BstNode<Key, T> **root){
		if (!*root)
			return false;
		BstNode<Key, T> *node = (*root)->find(key);
		
		if (node){
			deleteNode(node, root);
			if (*root)
				(*root)->size -= 1;
			return true;	
		}
		return false;	
	};



} // namespace ft


