#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

typedef struct treenode{
	int data;
	struct treenode *left;
	struct treenode *right;
} treeNode ;


int count = 0;

treeNode* treeInsert(treeNode *t, int x);
treeNode *treeSearch(treeNode *t, int x);

treeNode* treeInsert(treeNode *t, int x)
{
	treeNode *tmp;
	if (t == NULL) {
		tmp = new treeNode;
		tmp->data = x;
		tmp->left = tmp->right = NULL;
		return tmp;
	}
	if (t->data < x) {
		t->right = treeInsert(t->right, x);
		return t;
	}
	else if (t->data > x) {
		t->left = treeInsert(t->left, x);
		return t;
	}
	else  {
		printf("동일한 키 값은 입력이 안됩니다.  \n");
		return t;
	}
}


treeNode* deleteNode(treeNode* del)
{
	if ( del->right == NULL && del->left == NULL ) 
		return NULL;
	else if (del->right != NULL && del->left == NULL) 
		return del->right;
	else if (del->left != NULL && del->right == NULL) 
		return del->left;
	else {

		treeNode *s = del->right;
		treeNode* p=NULL;
		while (s->left != NULL){
			p = s;
			s = s->left;
		}
		del->data = s->data;
		if (s == del->right)
			del->right = s->right;
		else
			p->left = s->right;
		return del;
	}
}

void treeDelete(treeNode**t, treeNode*del, treeNode*parent)
{
	if (del == *t)  *t = deleteNode(*t); // r이 루트 노드인 경우     
	else if (del == parent->left)   		// r이 루트가 아닌 경우
		parent->left = deleteNode(del); 	// r이 p의 왼쪽 자식 
	else parent->right = deleteNode(del);  	// r이 p의 오른쪽 자식 
}



// 중위 순회
void inorder(treeNode *root){
	if (root){
		inorder(root->left); // 왼쪽서브트리 순회
		cout << root->data << " ";
		//printf("%3d", root->data); // 노드 방문
		inorder(root->right); //오른쪽서브트리 순회
	}
}


treeNode *treeSearch(treeNode *t, int x)
{
	if (t == NULL || t->data == x )
		return t;
	else if (t->data > x)
		treeSearch(t->left, x);
	else 
		treeSearch(t->right, x);

}


treeNode *treeParentSearch(treeNode *node, int key)
{
	treeNode *p;
	p = NULL;
	while (node != NULL){
		if (key == node->data) return p;
		else if (key < node->data)
		{
			p = node; node = node->left;
		}
		else
		{
			p = node;	node = node->right;
		}
	}
	return p;
}



int main()
{
	int i, *data;
	treeNode *root = NULL;
	treeNode *result;
	int count = 0;
	srand((unsigned int)time(NULL));
	data = new int[10];
	for (i = 0; i < 10; i++){
		data[i] = rand() % 100 + 1;
		cout << data[i] << " ";
		root = treeInsert(root, data[i]);
	}
	cout << "\n생성된 이진탐색트리:";
	inorder(root);

	int key = 0;
	while (key != -1) {
		cout << "\n삭제할 키를 입력하시오:" << endl;
		cin >> key; 
		treeNode* del, *pnode;
		del = treeSearch(root, key);
		if (del != NULL) {
			pnode = treeParentSearch(root, key);
			treeDelete(&root, del, pnode);
			cout << "삭제된 후 이진탐색트리:" << endl;;
			inorder(root);
		}
		else cout << "삭제할 키가 없습니다. \n";
	}
	getchar(); getchar();
	return 0;
}


