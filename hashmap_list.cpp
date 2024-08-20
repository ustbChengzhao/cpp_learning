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
		
		/* ��ϣ���� */
		int hashFunc(int key) {
			int index = key % 100;
			return index;
		}	
		
		/* ��ѯ���� */
		string get(int key) {
			int index = hashFunc(key);
			Pair *pair = buckets[index];
			if (pair == nullptr) {
				return "";
			}
			return pair->val;
		}
		
		/* ��Ӽ�ֵ�� */
		void put(int key, string val) {
			Pair* pair = new Pair(key, val);
			int index = hashFunc(key);
			buckets[index] = pair;
		}
		
		/* ɾ����ֵ�� */
		void remove(int key) {
			int index = hashFunc(key);
			delete buckets[index];
			buckets[index] = nullptr;
		}
		
		/* ��ȡ���м�ֵ�� */
		vector<Pair *> pairSet() {
			vector<Pair*> pairSet;
			for (Pair *pair : buckets) {
				if (pair != nullptr) {
					pairSet.push_back(pair);
				}
			}
			return pairSer;
		}
		
		/* ��ȡ���м� */
		vector<Pair *> keySet() {
			vector<Pair*> keySet;
			for (Pair *pair : buckets) {
				if (pair != nullptr) {
					pairSet.push_back(pair->key);
				}
			}
			return keySet;
		}
		
		/* ��ȡ����ֵ */
		vector<Pair *> valueSet() {
			vector<Pair*> valueSet;
			for (Pair *pair : buckets) {
				if (pair != nullptr) {
					pairSet.push_back(pair->val);
				}
			}
			return valueSet;
		}
		
		/* ��ӡ��ֵ�� */
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
