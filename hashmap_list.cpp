#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Pair {
	public:
		int key;
		string val;
		Pair(int key, string val) {
			this->key = key;
			this->val = val;
		}
};

class ArrayHashMap {
	private:
		vector<Pair*> buckets;

	public:
		ArrayHashMap() {
			buckets = vector<Pair*>(100);
		}
		
		/* 哈希函数 */
		int hashFunc(int key) {
			int index = key % 100;
			return index;
		}	
		
		/* 查询操作 */
		string get(int key) {
			int index = hashFunc(key);
			Pair *pair = buckets[index];
			if (pair == nullptr) {
				return "";
			}
			return pair->val;
		}
		
		/* 添加键值对 */
		void put(int key, string val) {
			Pair* pair = new Pair(key, val);
			int index = hashFunc(key);
			buckets[index] = pair;
		}
		
		/* 删除键值对 */
		void remove(int key) {
			int index = hashFunc(key);
			delete buckets[index];
			buckets[index] = nullptr;
		}
		
		/* 获取所有键值对 */
		vector<Pair *> pairSet() {
			vector<Pair*> pairSet;
			for (Pair *pair : buckets) {
				if (pair != nullptr) {
					pairSet.push_back(pair);
				}
			}
			return pairSer;
		}
		
		/* 获取所有键 */
		vector<Pair *> keySet() {
			vector<Pair*> keySet;
			for (Pair *pair : buckets) {
				if (pair != nullptr) {
					pairSet.push_back(pair->key);
				}
			}
			return keySet;
		}
		
		/* 获取所有值 */
		vector<Pair *> valueSet() {
			vector<Pair*> valueSet;
			for (Pair *pair : buckets) {
				if (pair != nullptr) {
					pairSet.push_back(pair->val);
				}
			}
			return valueSet;
		}
		
		/* 打印键值对 */
		void print() {
			for (Pair *kv : PairSet()) {
				cout << kv->key << "->" << kv->val << endl;
			}
		}
		
		
		
		
};
int main() {
	unordered_map<int, string> map;
	map[12836] = "a";
	map[15937] = "b";
	map[16750] = "c";
	map[13276] = "d";
	map[10583] = "e";
	
	string name = map[12836];
	cout << name << endl;
	
	return 0;
}
