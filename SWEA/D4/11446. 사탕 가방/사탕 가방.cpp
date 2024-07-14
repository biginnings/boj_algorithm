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
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

long long N, M, temp, k;
long long result;
long long grid[100];
bool check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		long long end = 0;

		for (int i = 0; i < N; i++) {
			cin >> grid[i];
			end = end >= grid[i] ? end : grid[i];
		}

		check = false;
		long long start = 1;
		end++;
		result = 0;

		while (start <= end) {
			long long mid = (start + end) / 2;
			temp = 0;

			for (int i = 0; i < N; i++) {
				temp += grid[i] / mid;
			}

			if (check) {
				check = false;
				continue;
			}

			if (temp < M) {
				end = mid - 1;
			}
			else {
				result = mid;
				start = mid + 1;
			}
		}

		cout << "#" << tc << " " << result << "\n";
	}

}