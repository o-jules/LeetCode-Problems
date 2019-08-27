# LeetCode Coding Tricks

- `sync_with_stdio` in C++ code

  Some people use it to speed up the test.

  See submission of [590. N-ary Tree Postorder Traversal](https://leetcode.com/problems/n-ary-tree-postorder-traversal/)

- Address sanitizer

  ```bash
  gcc -fsanitize=address SOURCE_FILE
  ```

  **There are other sanitizer options: `kernel-address`, `pointer-compare`, `thread`, `leak` etc.**
