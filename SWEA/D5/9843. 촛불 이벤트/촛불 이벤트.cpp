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

long long N, temp, k;
long long result;
bool check;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		check = false;
		long long start = sqrt(N);
		long long end = INT_MAX;
		N *= 2;

		while (start <= end) {
			long long mid = ( start + end ) / 2;
			temp = mid * (mid + 1);

			if (temp < N) {
				start = mid + 1;
			}
			else if (temp > N) {
				end = mid - 1;
			}
			else {
				check = true;
				result = mid;
				break;
			}
		}

		if (check) {
			cout << "#" << tc << " " << result << "\n";
		}
		else {
			cout << "#" << tc << " " << -1 << "\n";
		}
	}

}