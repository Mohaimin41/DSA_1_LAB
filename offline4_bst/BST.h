#pragma once

#include <iostream>

#include "binNode.h"

namespace dsa1
{
    template <typename Key, typename E>
    class BST
    {
    private:
        binNode<Key, E> *m_root; //root of tree
        int m_nodeCount;

    public:
        BST() : m_root(nullptr), m_nodeCount(0) {}
        ~BST() { p_clear(m_root); }

    private:
        void p_clear(binNode<Key, E> *);
        binNode<Key, E> *p_getMinNode(binNode<Key, E> *);
        binNode<Key, E> *p_deleteMinNode(binNode<Key, E> *);

        binNode<Key, E> *p_insert(binNode<Key, E> *, const Key &, const E &);
        binNode<Key, E> *p_remove(binNode<Key, E> *root, const Key &k) {}
        bool p_find(binNode<Key, E> *, const Key &) const;

    public:
        void insert(const Key &k, const E &element)
        {
            m_root = p_insert(m_root, k, element);
            m_nodeCount++;
        }
        void remove(const Key &k) {}
        bool find(const Key &k)
        {
            p_find(m_root, k);
        }
        void print(const binNode<Key, E> *root) const
        {
            if (root == nullptr)
            {
                return;
            }
            std::cout << root->getKey() << '(';
            print(root->leftChild());
            std::cout << ")(";
            print(root->rightChild());
            std::cout << ')' << std::endl;
        }
    };

    template <typename Key, typename E>
    void BST<Key, E>::p_clear(binNode<Key, E> *root)
    {
        if (root == nullptr)
        {
            return;
        }
        p_clear(root->leftChild());
        p_clear(root->rightChild());
        delete root;
    }

    template <typename Key, typename E>
    binNode<Key, E> *BST<Key, E>::p_getMinNode(
        binNode<Key, E> *root)
    {
        if (root->leftChild() == nullptr)
        {
            return root;
        }
        else
        {
            return p_getMinNode(root->leftChild());
        }
    }

    //this method returns in effect a new root for bst
    template <typename Key, typename E>
    binNode<Key, E> *BST<Key, E>::p_deleteMinNode(
        binNode<Key, E> *root)
    {
        if (root->leftChild() == nullptr)
        {
            return root->rightChild();
        }
        else
        {
            root->setLeftChild(p_deleteMinNode(root->leftChild()));
            return root;
        }
    }

    template <typename Key, typename E>
    binNode<Key, E> *BST<Key, E>::p_insert(
        binNode<Key, E> *root, const Key &k, const E &element)
    {
        //root null: empty tree, root created and returned
        if (root == nullptr)
        {
            return new binNode<Key, E>(k, element);
        }

        //if less then root.key(), send to left subtree
        if (K < root->getKey())
        {
            root->setLeftChild(p_insert(root->leftChild(), k, element));
        }
        else
        {
            root->setRightChild(p_insert(root->rightChild(), k, element));
        }

        return root;
    }

    template <typename Key, typename E>
    bool BST<Key, E>::p_find(binNode<Key, E> *root, const Key &k) const
    {
        if (root == nullptr)
        {
            return false;
        }

        if (k < root->getKey())
        {
            return p_find(root->leftChild(), k);
        }

        else
        {
            return p_find(root->rightChild(), k);
        }
        //k == element then
        return true;
    }

} // namespace dsa1
