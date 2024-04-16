#include <iostream>
#include <string> // to use std::string, std::to_string() and '+' operator
#include <cmath> // for the log2(x) function
#include <queue> // printing heap level by level
/*
 * min heap root == min
 * max heap root == max
 */

/*
 * need
 * bool isEmpty()
 * T/void peek()
 * insert(T item)
 * void remove(T item)
 * reHeap
 */
template <typename T>
class Heap {
	private:
		class Node {
			public:
				T data;
				Node* left;
				Node* right;

				Node(T d) {
					data = d;
					left = nullptr;
					right = nullptr;
				}

		};

		Node* root = nullptr;
		int size = 0;

	public:
		void Add(T item) {
			//Add a node containing (item) to the heap
			root = insertItem(root, item);
			size++;
		}

		void Remove(T item) {
			//Remove the node containing (item)
			if (size == 0){
				return;
			}
			root = deleteItem(root, item);
			size--;
		}

		void PrintHeap() {
			if (root == nullptr) {
				return;
			}

			std::queue<Node*> q;
			q.push(root);

			while (!q.empty()) {
				int levelSize = q.size();
				while (levelSize > 0) {
					Node* curr = q.front();
					q.pop();
					std::cout << curr->data << " ";

					if (curr->left != nullptr) {
						q.push(curr->left);
					}
					
					if (curr->right != nullptr) {
						q.push(curr->right);
					}

					levelSize--;
				}
				std::cout << std::endl;
			}
		}

	private:
		/*
		Node* Search(T item) {
			//return a pointer to the node containing item
			Node* curr = root;
			while(curr->data != item) {
				if (item > curr->data) {
					return nullptr;
				} else {
					if (item > curr->right->data){
					return curr->right;
					}
				}
			}
		}
		*/

		Node* Search(T item) {
			if (root == nullptr)
				return nullptr;

			std::queue<Node*> q;
			q.push(root);

			while (!q.empty()) {
				Node* curr = q.front();
				q.pop();

				if (curr->data == item) {
					return curr;
				}
				if (curr->left != nullptr){
					q.push(curr->left);
				}
				if (curr->right != nullptr){
					q.push(curr->right);
				}
			}
			return nullptr;
		}
		
		Node* insertItem(Node* root, T item) {	
			if (root == nullptr) {
				return new Node(item);
			}

			if (item > root->data) {
				swapData(item, root);
			}

			if (root->left == nullptr) {
				root->left = new Node(item);
			} else if (root->right == nullptr) {
				root->right = new Node(item);
			} else {
				if (size % 2 == 0) {
					root->left = insertItem(root->left, item);
				} else {
					root->right = insertItem(root->right, item);
				}
			}

			return root;
		}
		
		Node* deleteItem(Node* root, T item) {
			if (root == nullptr) {
				return nullptr;
			}
			if (root->left == nullptr && root->right == nullptr) {
				if (root->data == item) {
					delete root;
					return nullptr;
				}
				return root;
			}
			//find the item in the tree
			//get the deepest rightmost
			//replace the item with the deepest item
			//then delete the deepest rightmost node
			Node* tmp = Search(item);
			if (tmp != nullptr) {
				T lastItem = getLastNode(root)->data;
				deleteLastNode(root, getLastNode(root));
				tmp->data = lastItem;
				return root;
			}
			//if (tmp->left != nullptr)
				//nodes.push_back(tmp->left);
			//if (tmp->right != nullptr)
				//nodes.push_back(tmp->right);
			return root;
		}

		Node* deleteLastNode (Node* root, Node* deepest) {
			if (root == nullptr) {
				return nullptr;
			}

			if (root == deepest) {
				delete deepest;
				return nullptr;
			}
			root->right = deleteLastNode(root->right, deepest);
			return root;
		}

		Node* getLastNode(Node* root) {
			Node* tmp = root;
			while (tmp->right != nullptr) {
				tmp = tmp->right;
			}
			return tmp;
		}

		void swapData(T& item, Node* curr) {
			T tmp = curr->data;
			curr->data = item;
			item = tmp;
		}

};
