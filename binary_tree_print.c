#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

static int print_t(const binary_tree_t *tree, int offset, int depth,
char s[20][255])
{
char b[6];
int width = 5;
int left, right;
int i;

if (!tree)
return (0);

sprintf(b, "(%03d)", tree->n);

left = print_t(tree->left, offset, depth + 1, s);
right = print_t(tree->right, offset + left + width, depth + 1, s);

for (i = 0; i < width; i++)
s[depth][offset + left + i] = b[i];

if (depth && (offset + left + width / 2 < 255))
s[depth - 1][offset + left + width / 2] = '|';

return (left + width + right);
}

void binary_tree_print(const binary_tree_t *tree)
{
char s[20][255];
int i, j;

for (i = 0; i < 20; i++)
{
for (j = 0; j < 255; j++)
s[i][j] = ' ';
}

print_t(tree, 0, 0, s);

for (i = 0; i < 20; i++)
{
j = 254;
while (j >= 0 && s[i][j] == ' ')
j--;

if (j >= 0)
{
s[i][j + 1] = '\0';
printf("%s\n", s[i]);
}
}
}
