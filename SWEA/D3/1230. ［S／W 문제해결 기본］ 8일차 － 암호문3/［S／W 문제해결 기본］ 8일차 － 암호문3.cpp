//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdio>
//
//struct Node {
//	int data;
//	Node* next;
//};
//
//constexpr size_t MAX_NODE = 1000;
//
//int node_count = 0;
//Node node_pool[MAX_NODE];
//
//Node* new_node(int data) {
//	node_pool[node_count].data = data;
//	node_pool[node_count].next = nullptr;
//
//	return &node_pool[node_count++];
//}
//
//class SinglyLinkedList {
//	Node head;
//
//public:
//	SinglyLinkedList() = default;
//
//	void init() {
//		head.next = nullptr;
//		node_count = 0;
//	}
//
//	void insert(int x) {
//		Node* node = new_node(x);
//
//		node->next = head.next;
//		head.next = node;
//	}
//
//	void remove(int x) {
//		Node* prev_ptr = &head;
//		
//		while (prev_ptr->next != nullptr && prev_ptr->next->data != x) {
//			prev_ptr = prev_ptr->next;
//		}
//
//		if (prev_ptr->next != nullptr) {
//			prev_ptr->next = prev_ptr->next->next;
//		}
//	}
//
//	bool find(int x) const {
//		Node* ptr = head.next;
//		while (ptr != nullptr && ptr->data != x) {
//			ptr = ptr->next;
//		}
//
//		return ptr != nullptr;
//	}
//
//	void print() const {
//		Node* ptr = head.next;
//		printf("[List] ");
//		while (ptr != nullptr) {
//			printf("%d", ptr->data);
//			if (ptr->next != nullptr) {
//				printf(" -> ");
//			}
//			ptr = ptr->next;
//		}
//		putchar('\n');
//	}
//};
//
//void init()
//{
//
//}
//
//void hire(int mID, int mTeam, int mScore)
//{
//}
//
//void fire(int mID)
//{
//}
//
//void updateSoldier(int mID, int mScore)
//{
//}
//
//void updateTeam(int mTeam, int mChangeScore)
//{
//}
//
//int bestSoldier(int mTeam)
//{
//	return 0;
//}
//
//int main() {
//	SinglyLinkedList slist;
//	int a, b;
//	for (;;) {
//		scanf("%d", &a);
//		switch (a) {
//		case 0:
//			slist.init();
//			slist.print();
//			break;
//		case 1:
//			scanf("%d", &b);
//			slist.insert(b);
//			slist.print();
//			break;
//		case 2:
//			scanf("%d", &b);
//			slist.remove(b);
//			slist.print();
//			break;
//		case 3:
//			scanf("%d", &b);
//			puts(slist.find(b) ? "found" : "not found");
//			break;
//		default:
//			return puts("wrong input"), 0;
//		}
//	}
//}

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int a;
	Node* next;

	Node(int data) : a(data), next(nullptr) { }
};

constexpr int node_max = 5000;

class singlyLinkedList {
	Node* head;
	Node* tail;
	vector<Node*> nodearr;
	int nodecnt;

public:
	singlyLinkedList() : head(nullptr), tail(nullptr), nodecnt(0) {
		nodearr.resize(node_max);
	}

	Node* getNewNode(int data) {
		nodearr[nodecnt] = new Node(data);

		return nodearr[nodecnt++];
	}

	void insert(int idx, vector<int>& nums) {
		int st = 0;

		if (idx == 0) {
			if (head != nullptr) {
				Node* newNode = getNewNode(nums[0]);
				newNode->next = head;
				head = newNode;
			}
			else {
				head = getNewNode(nums[0]);
			}

			idx = 1;
			st = 1;
		}

		Node* cur = head;
		for (int i = 1; i < idx; i++) {
			cur = cur->next;
		}

		for (int i = st; i < nums.size(); i++) {
			Node* newNode = getNewNode(nums[i]);
			newNode->next = cur->next;
			cur->next = newNode;
			cur = newNode;
		}

		if (cur->next == nullptr) {
			tail = cur;
		}
	}

	void remove(int idx, int cnt) {
		Node* cur = head;

		if (idx == 0) {
			for (int i = 0; i < cnt; i++) {
				cur = cur->next;
			}
			head = cur;
			return;
		}

		for (int i = 1; i < idx; i++) {
			cur = cur->next;
		}
		Node* anchor = cur;

		for (int i = 0; i < cnt; i++) {
			cur = cur->next;
		}
		anchor->next = cur->next;

		if (anchor->next == nullptr) {
			tail = anchor;
		}
	}

	void add(int data) {
		Node* cur = tail;
		Node* newNode = getNewNode(data);
		cur->next = newNode;
		tail = newNode;
	}

	void print() {
		int cnt = 10;
		Node* cur = head;
		while (cnt-- > 0) {
			cout << cur->a << " ";
			cur = cur->next;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int a = 0;
	for (int tc = 1; tc <= 10; tc++) {
		singlyLinkedList list;
		cout << "#" << tc << " ";

		int N;
		cin >> N;

		vector<int> initArr(N);
		for (int i = 0; i < N; i++) {
			cin >> initArr[i];
		}
		list.insert(0, initArr);

		int M;
		cin >> M;

		for (int i = 0; i < M; i++) {
			char cmd;
			cin >> cmd;

			int x, y;
			vector<int> temp;
			switch (cmd) {
			case 'I':
				cin >> x >> y;
				temp = vector<int>(y);
				for (int j = 0; j < y; j++) {
					cin >> temp[j];
				}
				list.insert(x, temp);
				break;
			case 'D':
				cin >> x >> y;
				list.remove(x, y);
				break;
			case 'A':
				cin >> y;
				for (int j = 0; j < y; j++) {
					int data;
					cin >> data;
					list.add(data);
				}
				break;
			}
		}

		list.print();
		cout << "\n";
	}

	return 0;
}