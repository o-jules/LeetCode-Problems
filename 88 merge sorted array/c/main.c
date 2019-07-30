

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
  int j = m + n - 1;
  m--;
  n--;

  while (m >= 0 || n >= 0) {
    if (m < 0) {
      *(nums1 + j) = *(nums2 + n);
      n--;
    } else if (n < 0) {
      *(nums1 + j)= *(nums1 + m);
      m--;
    } else {
      if (*(nums1 + m) > *(nums2 + n)) {
        *(nums1 + j)= *(nums1 + m);
        m--;
      } else {
        *(nums1 + j)= *(nums2 + n);
        n--;
      }
    }
    j--;
  }
}



