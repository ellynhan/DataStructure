#include <bits/stdc++.h>
using namespace std;
enum Boolean { FALSE, TRUE };
ofstream out("bst.out");
class BstNode {
	friend class BST;
private:
	string data;
	BstNode *LeftChild, *RightChild;
public:
	int depthprint(int i,int d,int& c);
	void leafprint(int i);
};
class BST {
private:
	BstNode * root;
public:
	BST(BstNode *init = 0) { root = init; }
	Boolean Insert(const string& str);
	BstNode* Search(BstNode* b1, BstNode* b2, const string&);
	BstNode* Search(const string&);
	string Searchleaf(BstNode*);
	void leafprint() {
		root->leafprint(1);
	}
	int depthprint(int d) {
	    int check=0;
		check=root->depthprint(1,d,check);
		return check;
	}
};
void BstNode::leafprint(int l) {
	if (this) {
		(this->LeftChild)->leafprint(l + 1);
		if (!this->RightChild&&!this->LeftChild)
			out << this->data<<" ";
		(this->RightChild)->leafprint(l + 1);
	};
}
int BstNode::depthprint(int l, int d,int& c) {
	if (this) {
		if (l== d) {
			out << this->data<<" ";
			c++;
		}
		(this->LeftChild)->depthprint(l + 1, d,c);
		(this->RightChild)->depthprint(l + 1, d,c);
	}
	return c;
}
BstNode* BST::Search(BstNode* b,BstNode* b2, const string& str) {
	BstNode* past=b2, *current = b;
	string leafdata;
	if (!b) return 0;
	if (str == b->data) {
		if (past == nullptr) {
			if (!b->LeftChild && !b->RightChild) {
				this->root = nullptr;
			}
			else {
				leafdata = this->Searchleaf(b);
				b->data = leafdata;
			}
		}
		else if (!b->RightChild && !b->LeftChild) {
			if (past->LeftChild == current) {
				past->LeftChild = nullptr;
			}
			else {
				past->RightChild = nullptr;
			}
		}
		else {
			leafdata=this->Searchleaf(b);
			b->data = leafdata;
		}
	}
	past = current;
	current = b->LeftChild;
	if (str<b->data) return Search(current,past, str);
	current = b->RightChild;
	Search(current, past, str);
}
BstNode* BST::Search(const string& str) {
	return Search(root,nullptr, str);
}
string BST::Searchleaf(BstNode* b) {
	BstNode* past, *current=b;
	string tmp;
	int leftiszero=0;
	if (b->LeftChild) {//leftchild가 있는 경우
		past = current;
		current = b->LeftChild;
		while (current->RightChild) {
			leftiszero = 1;
			past = current;
			current = current->RightChild;
		}
	}
	else if(b->RightChild){//없는 경우
		past = current;
		current = b->RightChild;
		leftiszero = 1;
		while (current->LeftChild) {
			leftiszero = 0;
			past = current;
			current = current->LeftChild;
		}
	}
	tmp = current->data;
	if (leftiszero) {
		if (current->LeftChild) {
			past->RightChild = current->LeftChild;
		}
		else {
			past->RightChild = current->RightChild;
		}
	}
	else {
		if (current->RightChild) {
			past->LeftChild = current->RightChild;
		}
		else {
			past->LeftChild = current->LeftChild;
		}
	}
	return tmp;
}
Boolean BST::Insert(const string& x) {
	BstNode* p = root;
	BstNode* q = 0;
	while (p) {
		q = p;
		if (x == p->data)
			return FALSE;
		if (x< p->data)
			p = p->LeftChild;
		else
			p = p->RightChild;
	};
	p = new BstNode;
	p->LeftChild = p->RightChild = 0;
	p->data = x;
	if (!root) {
		root = p;
	}
	else if (x< q->data) {
		q->LeftChild = p;
	}
	else
		q->RightChild = p;
	return TRUE;
}

int getOpCode(string cmd) { //complete don't touch this
	string command[] = { "+","-", "depth", "leaf" };
	int i;
	int arraySize = sizeof(command) / sizeof(command[0]);
	for (i = 0; i < arraySize; i++) {
		if (command[i] == cmd)
			return i;
	}
	return -1;
}

int main() {
    ifstream in("bst.inp");
	BST m;
	int n, OpCode, d;
	string cmd, leaf;
	in >> n;
	for (int i = 0; i<n; i++) {
		in >> cmd;
		OpCode = getOpCode(cmd);
		switch (OpCode) {
		case 0://+//
			if (in >> leaf) {//
				m.Insert(leaf);
			}
			break;
		case 1://-//
			if (in >> leaf) {//
				m.Search(leaf);
			}
			break;
		case 2://depth//
			in >> d;
			if(m.depthprint(d)==0){
                out << "NO";
			}
			out<<"\n";
			break;
		case 3://leaf//
			m.leafprint();
			out<<"\n";
			break;
/*		default:
			cout << "Invaild command\n";
			i -= 1;*/
		}
	}
}
