class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int count = 0;
		queue<int> que;
		int root = findRoot(n, leftChild, rightChild);
		if(root < 0){
			return false;
		}
		que.push(root);
		while(count <= n && !que.empty()){
			int cur = que.front(); que.pop();
			count++;
			if(leftChild[cur] >= 0){
				que.push(leftChild[cur]);
			}
			if(rightChild[cur] >= 0){
				que.push(rightChild[cur]);
			}
		}
		if(count > n || !que.empty()){
			return false;
		}
		return true;
	}
	
	int findRoot(int n, vector<int> &leftChild, vector<int> &rightChild){
		vector<int> tmp(n,0);
		for(int i =0; i < n; i++){
			if(leftChild[i] >= 0){
				tmp[leftChild[i]]++;
			}
			if(rightChild[i] >= 0){
				tmp[rightChild[i]]++;
			}
		}
		int empty = 0;
		int root = 0;
		for(int i =0; i < n; i++){
			if(tmp[i] == 0){
				root = tmp[i];
				empty++;
			}
			if(empty > 1){
				return -1;
			}
			if(tmp[i] > 1){
				return -1;
			}
		}
		return root;
	}

};


