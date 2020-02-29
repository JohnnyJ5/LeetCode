#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <algorithm>
#include <sstream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printAnswer(TreeNode *result, int val)
{
    std::stringstream ss;
    if (result)
    {
        ss << "Searching for " << val << " and result is " << result->val;
    }
    else
    {
        ss << "Searching for " << val << " and result is NULL";
    }
    std::cout << ss.str() << std::endl;
}

TreeNode *searchBSTRecursion(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val == val)
    {
        return root;
    }

    if (val < root->val)
    {
        return searchBSTRecursion(root->left, val);
    }
    else
    {
        return searchBSTRecursion(root->right, val);
    }
}

TreeNode *searchBSTIteration(TreeNode *root, int val)
{
    while (root != NULL)
    {
        if (root->val == val)
        {
            return root;
        }
        else if (val < root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return root;
}

void RunRecursion(TreeNode *root, const int val)
{
    TreeNode *result = searchBSTRecursion(root, val);
    printAnswer(result, val);
}

void RunIteration(TreeNode *root, const int val)
{
    TreeNode *result = searchBSTIteration(root, val);
    printAnswer(result, val);
}

int main(int argc, char *argv[])
{
    TreeNode four(4);
    TreeNode two(2);
    TreeNode seven(7);
    TreeNode one(1);
    TreeNode three(3);

    four.left = &two;
    four.right = &seven;
    two.left = &one;
    two.right = &three;

    TreeNode *root = &four;

    RunRecursion(root, 2);
    RunRecursion(root, 5);

    RunIteration(root, 2);
    RunIteration(root, 5);

    return 0;
}