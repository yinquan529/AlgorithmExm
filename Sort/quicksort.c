#include <stdio.h>

int a[101];
int n;

void quicksort(int left, int right) {
  int i,j,t,temp;

  if (left > right) {
    return;
  }

  temp = a[left];
  i = a[left];
  j = a[right];

  while (a[j] >= temp && i < j) {
    --j;
  }

  while (a[i] <= temp && i < j) {
    ++i;
  }

  if (i < j) {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }

  a[left] = a[i];
  a[i] = temp;

  quicksort(left, i - 1);
  quicksort(i + 1, right);
}

int main() {
  int i, j, t;
  printf("n = ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("a[%d] = ", i);
    scanf("%d",&a[i]);
  }

  quicksort(0,n);

  for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  return 0;
}
