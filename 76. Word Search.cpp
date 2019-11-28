#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <limits>
#include <thread>
#include <mutex>
#include <fstream>
#include <memory>
using namespace std;

bool dfs(const vector<vector<char>>& board, const string& word, int row, int col) {
		stack< tuple<int, int, int, pair<int, int> > > stk;
		stk.push( std::make_tuple(row, col, 0, std::make_pair(row,col) ) );
		
		while (!stk.empty()) {
			auto [r, c, idx, prev] = stk.top(); stk.pop();
			cout << r << " "<< c << " " << idx << " " << board[r][c] << endl;
			if (idx == word.size() - 1) {
				return true;    
			}    
			
			if (r > 0 && std::make_pair(r - 1, c) != prev && board[r - 1][c] == word[idx + 1]) {
				stk.push( std::make_tuple(r - 1, c, idx + 1, std::make_pair(r, c) ) );
			}   

			if (r < board.size() - 1 && std::make_pair(r + 1, c) != prev &&  board[r + 1][c] == word[idx + 1]) {
				stk.push( std::make_tuple(r + 1, c, idx + 1, std::make_pair(r, c) ) );
			}

			if (c > 0 && std::make_pair(r, c - 1) != prev && board[r][c - 1] == word[idx + 1]) {
				stk.push( std::make_tuple(r, c - 1, idx + 1, std::make_pair(r, c) ) );
			}

			if (c < board[0].size() - 1 && std::make_pair(r, c + 1) != prev && board[r][c + 1] == word[idx + 1]) {
				stk.push( std::make_tuple(r, c + 1, idx + 1, std::make_pair(r, c) ) );
			}       
		}
		return false;
	}
	
	bool exist(vector<vector<char>>& board, string word) {
		for (int row = 0; row < board.size(); ++row) {
			for (int col = 0; col < board[0].size(); ++col) {
				if (board[row][col] == word.at(0) && dfs(board, word, row, col)) {
					return true;
				}
			}
		}
							   
		return false;
	}

int main(int argc, char *argv[]) {
//	vector<vector<char>> board{
//		{'A','B','C','E'},
//		{'S','F','C','S'},
//		{'A','D','E','E'}
//	};
//	
//	string word1("ABCCED");
//	string word2("SEE");
//	string word3("ABCB");
//	if (exist(board, word1)) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
//	}
//	
//	if (exist(board, word2)) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
//	}
//		
//	if (exist(board, word3)) {
//		cout << "YES\n";
//	}
//	else {
//		cout << "NO\n";
//	}
	
	vector<vector<char>> board 
	{
		{'a','a','a','a'},
		{'a','a','a','a'},
		{'a','a','a','a'}
		
	};
	string word("aaaaaaaaaaaaa");
	if (exist(board, word)) { 
		cout << "YES\n"; 
	}	
}