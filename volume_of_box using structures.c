#include <stdio.h>
#include <stdlib.h>
struct box
{
	int height;
  int width;
  int length;
}b;

typedef struct box box;

int find_volume(box b) {

return b.length*b.width*b.height;
}

int lower_than_max_height(box b) {
 return b.height < 41 ? 1 : 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	box *boxes = malloc(n * sizeof(box));
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	}
	for (int i = 0; i < n; i++) {
		if (lower_than_max_height(boxes[i])) {
			printf("%d\n", find_volume(boxes[i]));
		}
	}
	return 0;
}
