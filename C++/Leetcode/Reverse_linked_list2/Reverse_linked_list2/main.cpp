#include <iostream>



  struct ListNode {
      int val;
      ListNode *next;

      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

  class list {
  public:
      ListNode* head, *cur;
      list() :head(nullptr), cur(nullptr) {}
      void add(ListNode* next) {
          if (head==nullptr)
          {
              head = next;
              cur = head;
          }
          else {
              cur->next = next;
              cur = cur->next;
          }
      }
      void add(int x)
      {
          if (head == nullptr)
          {
              head = new(ListNode);
              head->val = x;
              head->next = nullptr;
              cur = head;
          }
          else
          {
              cur->next = new(ListNode);
              cur = cur->next;
              cur->val = x;
              cur->next = nullptr;
          }
      }
      void print() {
          cur = head;
          while (cur->next != nullptr) {
              std::cout << cur->val << ' ';
              cur = cur->next;
          }
          std::cout << cur->val << std::endl;

      }
  };

  class Solution {
  public:
      static ListNode* reverseBetween(ListNode* head, int left, int right) {
          ListNode* el_left = head, * el_right;
          int val, raz = right - left;

          for (size_t i = 1; i < left; i++)
          {
              el_left = el_left->next;
          }
          el_right = el_left;
          for (size_t i = 0; i < raz; i++)
          {
              el_right = el_right->next;
          }

          for (int i = 0; i < raz/2+1; i++)
          {
              val = el_right->val;
              el_right->val = el_left->val;
              el_left->val = val;//1 4 9 99 3 2 5
              el_left = el_left->next;
              el_right = el_left;

              for (int j = 0; j < raz - (i+1)*2; j++)
              {
                  el_right = el_right->next;
              }
          }
          return head;
      }
  };

int main()
{
    list list1;
    list1.add(1);
    list1.add(4);
    list1.add(9);
    list1.add(99);
    list1.add(3);
    list1.add(2);
    list1.add(5);


    list1.print();
    Solution::reverseBetween(list1.head, 2, 6);
    list1.print();

	return 0;
}