#include <iostream>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;

class Tree {
public:
	char data;
	Tree* left;
	Tree* right;

	Tree(char c) : data(c), left(nullptr), right(nullptr) {}
};

Tree* Build_Tree_Prefix(string& prefix) {
	if (prefix.empty()) { return nullptr; }
	char root = prefix[0];
	prefix.erase(0, 1);
	Tree* node = new Tree(root);
	if (root == '+' || root == '-' || root == '*' || root == '/') {
		node->left = Build_Tree_Prefix(prefix);
		node->right = Build_Tree_Prefix(prefix);
	}

	return node;
}

void print_Tree(Tree* p, int level)
{
	if (p)
	{
		print_Tree(p->left, level + 1);
		for (int i = 0; i < level; i++) cout << "   ";
		cout << p->data << endl;
		print_Tree(p->right, level + 1);
	}
}


int Height_Tree(string& st) {
	int k = 0;
	for (auto  c:  st) {
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			k++;
		}
	}
	return k;
}

Tree* Build_Tree_FromPostfix(string& postfix) {
	stack<Tree*> st;

	for (char c : postfix) {
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			Tree* node = new Tree(c);
			node->right = st.top();
			st.pop();
			node->left = st.top(); 
			st.pop();
			st.push(node);
		}
		else {
			st.push(new Tree(c));
		}
	}

	return st.top();
}

void Free_Tree(Tree* root) {
	if (!root) return;

	Free_Tree(root->left);
	Free_Tree(root->right);
	delete root;
}


/*int main() {
	setlocale(LC_ALL, "Russian");
	//string prefix = "+12";
	string post = "ab+c+d+";
	/*Tree* prefixTree = Build_Tree_Prefix(prefix);
	cout << "Дерево по префиксной форме: ";
	cout << endl;
	print_Tree(prefixTree, Height_Tree(post));
	Tree* postfixTree = Build_Tree_FromPostfix(post);
	cout << "В постфиксной";
	cout << endl;
	print_Tree(postfixTree, Height_Tree(post));

	
	cout << endl;
} */