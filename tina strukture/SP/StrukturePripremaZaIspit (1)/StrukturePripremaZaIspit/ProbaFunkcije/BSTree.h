#pragma once
#include "BSTNode.h"
#include <math.h>
using namespace std;
class BSTree
{
    BSTNode* root;
    int max(int n, int t) {
        return (n >= t) ? n : t;
    }
public:
    BSTree() { root = NULL; }
    BSTNode* insert(int x, BSTNode* t)
    {
        if (t == NULL)
        {
            t = new BSTNode();
            t->value = x;
            t->left = t->right = NULL;
        }
        else if (x < t->value)
            t->left = insert(x, t->left);
        else if (x > t->value)
            t->right = insert(x, t->right);
        return t;
    }
    void postorder(BSTNode* t) {
        if (t == NULL)
            return;
        postorder(t->left);
        postorder(t->right);
        cout << t->value << " ";
    }
    void postorder() {
        postorder(root);
    }
    void insert(int x) {
        root = insert(x, root);
    }
    /* int height(BSTNode* n) {
         if (n) {
             if (!n->left && !n->right)
                 return 0;
             else
                 return 1 + max(height(n->left), height(n->right));
         }
         else
             return -1;
     }*/
    BSTNode* getRoot() {
        return root;
    }
    int depth(int val) {
        BSTNode* p = root;
        int ctr = 0;
        while (p != nullptr && p->value != val) {
            if (val < p->value)
                p = p->left;
            else
                p = p->right;
            ctr++;
        }
        if (p == nullptr)
            throw exception("Node not found");

        else
            return ctr;
    }
    int kids(BSTNode* n) {
        if ((!n->left && !n->right))
            return 0;
        else if (n->left && n->right)
            return (n->left->value + n->right->value);
        else
            if (n->left)
                return n->left->value;
            else if (n->right)
                return n->right->value;
    }/*
    void maxChildren(BSTNode* n, BSTNode*& max) {
        if (n->left)
            maxChildren(n->left, max);
        if (n->right)
            maxChildren(n->right, max);
        if (kids(n) > kids(max))
            max = n;
    }*/
    BSTNode* maxChildren() {
        if (root) {
            //  BSTNode* max = root;
            return maxChildren(root/*, max*/);
            //return max;
        }
        return nullptr;
    }
    BSTNode* maxChildren(BSTNode* n) {
        if (n) {
            BSTNode* l = new BSTNode(), * r = new BSTNode();
            if (!n->left && !n->right)
                return n;
            else {
                if (n->left)
                    l = maxChildren(n->left);
                if (n->right)
                    r = maxChildren(n->right);

                return max(max(n, l), r);
            }
        }
    }
    BSTNode* max(BSTNode* n1, BSTNode* n2) {
        if (kids(n1) >= kids(n2))
            return n1;
        else return n2;
    }



    BSTNode* deepestLeaf(BSTNode* root) {
        int maxLvl = -1;
        BSTNode* result;
        deepestLeaf(root, maxLvl, 0, result);
        return result;
    }
    void deepestLeaf(BSTNode* root, int& maxLvl, int level, BSTNode*& result) {
        if (root) {
            deepestLeaf(root->left, maxLvl, ++level, result);
            if (level > maxLvl)
            {
                maxLvl = level;
                result = root;
            }
            deepestLeaf(root->right, maxLvl, level, result);
        }
    }

    int levelDif(int val1, int val2) {
        int first = unorderedDepth(root, val1);
        int second = unorderedDepth(root, val2);
        if (first == -1|| second==-1)
        {
            cout << "One of the nodes was not found." << endl;
            return 0;
        }
        return abs(first - second);
    }
    int unorderedDepth(BSTNode* node,int val) {
        if (node) {
            if (node->value == val)
                return 0;
            int left = unorderedDepth(node->left, val);
            int right = unorderedDepth(node->right, val);

            if (left >= 0)
                return left + 1;
            else if (right >= 0)
                return right + 1;
        }
            return -1;
    }
};

