#include<iostream>
using namespace std;

//bool is(int arr[], int n, int x) {
//    if (arr[n / 2] != x)
//        return false;
//    int newN = n / 2;
//    if (newN == 1)
//        return true;
//    return is(arr, newN, x) || is(&arr[newN + 1], n - newN, x);
//}

struct node {
	int key;
	node* left;
	node* right;
};

int LCA(node* root, int k1, int k2) {
	if (root == NULL) return -1;
	if (k1 == root->key || k2 == root->key) return -1;
	if (k1 <= root->key && k2 <= root->key) {
		if (root->left == NULL) return -1;
		return LCA(root->left, k1, k2);
	}
	else if (k1 >= root->key && k2 >= root->key) {
		if (root->right == NULL) return -1;
		return LCA(root->right, k1, k2);
	}

}

int main() {
    int arr[] = { 1,2,3,3,3,3,5,7 };
    //cout << is(arr, 8, 2);
}