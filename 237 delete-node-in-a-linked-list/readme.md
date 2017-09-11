## 移除链表中的node

```cpp
if (node->next) {
  node->val = node->next->val;
  node->next = node->next->next;
}
```
