#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"


/**
 * print_t - A function that Stores recursively each level
 * in an array of strings
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 * Return: length of printed tree after process
 */
static int print_t(const binary_tree_t *tree, int offset, int depth, char **s)
{
char b[6];
int width, left, right, is_left, x;
if (!tree)
return (0);
is_left = (tree->parent && tree->parent->left == tree);
width = sprintf(b, "(%03d)", tree->n);
left = print_t(tree->left, offset, depth + 1, s);
right = print_t(tree->right, offset + left + width, depth + 1, s);
x = 0;
while (x < width)
{
s[depth][offset + left + x] = b[x];
x++;
}
if (depth && is_left)
{
x = 0;
while (x < width + right)
{
s[depth - 1][offset + left + width / 2 + x] = '-';
x++;
}
s[depth - 1][offset + left + width / 2] = '.';
}
else if (depth && !is_left)
{
x = 0;
while (x < left + width)
{
s[depth - 1][offset - width / 2 + x] = '-';
x++;
}
s[depth - 1][offset + left + width / 2] = '.';
}
return (left + width + right);
}

/**
 * _height - A function that Measures the height of a binary tree
 *
 * @tree: Pointer to the node to measures the height
 *
 * Return: The height of the tree starting at @node
 */
static size_t _height(const binary_tree_t *tree)
{
size_t height_l;
size_t height_r;

height_l = tree->left ? 1 + _height(tree->left) : 0;
height_r = tree->right ? 1 + _height(tree->right) : 0;
return (height_l > height_r ? height_l : height_r);
}
/**
 * binary_tree_print - A function that  Prints a binary tree
 *
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
char **s;
size_t h, x, y;
if (!tree)
return;
h = _height(tree);
s = malloc(sizeof(*s) * (h + 1));
if (!s)
return;
for (x = 0; x < h + 1; x++)
{
s[x] = malloc(sizeof(**s) * 255);
if (!s[x])
return;
memset(s[x], 32, 255);
}
print_t(tree, 0, 0, s);
x = 0;
while (x < h + 1)
{
y = 254;
while (y > 1)
{
if (s[x][y] != ' ')
break;
s[x][y] = '\0';
y--;
}
printf("%s\n", s[x]);
free(s[x]);
x++;
}
free(s);
}
