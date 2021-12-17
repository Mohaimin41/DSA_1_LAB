#pragma once

#include <iostream>
#include <string>

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
        //returns the max node of given tree
        binNode<Key, E> *p_getMaxNode(binNode<Key, E> *);
        //returns the node containing given Key, nullptr otherwise
        binNode<Key, E> *p_find(binNode<Key, E> *, const Key &) const;

        //following return modified bst root
        binNode<Key, E> *p_removeMaxNode(binNode<Key, E> *);

        binNode<Key, E> *p_insert(binNode<Key, E> *, const Key &, const E &);
        binNode<Key, E> *p_remove(binNode<Key, E> *, const Key &);
        bool p_contains(binNode<Key, E> *, const Key &) const;
        void p_print(binNode<Key, E> *) const;

        //traversal functions
        void p_preOrder(binNode<Key, E> *) const;
        void p_postOrder(binNode<Key, E> *) const;
        void p_inOrder(binNode<Key, E> *) const;

    public:
        void insert(const Key &k, const E &element)
        {
            m_root = p_insert(m_root, k, element);
            m_nodeCount++;
            print();
        }

        void remove(const Key &k)
        {
            if (p_contains(m_root, k))
            {
                m_root = p_remove(m_root, k);
                m_nodeCount--;
                print();
            }
            else
            {
                throw "Invalid Operation";
            }
        }

        const char *find(const Key &k)
        {
            if (p_contains(m_root, k))
            {
                return "True";
            }
            else
            {
                return "False";
            }
        }

        void print() const
        {
            p_print(m_root);
            std::cout << std::endl;
        }

        void traverse(std::string order)
        {
            // order = std::to_string(order);
            if (!order.compare("In"))
            {
                p_inOrder(m_root);
            }
            else if (!order.compare("Pre"))
            {
                p_preOrder(m_root);
            }
            else if (!order.compare("Post"))
            {
                p_postOrder(m_root);
            }
            else
            {
                std::cout << "Incorrect order specified" << std::endl;
            }

            std::cout << std::endl;
        }
    };

    //clears given root's childs, then root
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

    //returns node with max key or rightmost node of given tree
    template <typename Key, typename E>
    binNode<Key, E> *BST<Key, E>::p_getMaxNode(
        binNode<Key, E> *root)
    {
        if (root->rightChild() == nullptr)
        {
            return root;
        }
        else
        {
            return p_getMaxNode(root->rightChild());
        }
    }

    //this method returns in a new root for bst, with max==rightmost node removed, not deleted/freed
    template <typename Key, typename E>
    binNode<Key, E> *BST<Key, E>::p_removeMaxNode(
        binNode<Key, E> *root)
    {
        if (root->rightChild() == nullptr)
        {
            return root->leftChild();
        }
        else
        {
            root->setRightChild(p_removeMaxNode(root->rightChild()));
            return root;
        }
    }

    template <typename Key, typename E>
    binNode<Key, E> *BST<Key, E>::p_find(
        binNode<Key, E> *root, const Key &k) const
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (k < root->getKey())
        {
            return p_find(root->leftChild(), k);
        }
        else if (k > root->getKey())
        {
            return p_find(root->rightChild(), k);
        }
        else
        {
            return root;
        }
    }

    //returns a new root for given bst
    template <typename Key, typename E>
    binNode<Key, E> *BST<Key, E>::p_insert(
        binNode<Key, E> *root, const Key &k, const E &element)
    {
        //root null: empty subtree, root created and returned
        if (root == nullptr)
        {
            return new binNode<Key, E>(k, element, nullptr, nullptr);
        }

        //if less then root.key(), send to left subtree
        if (k < root->getKey())
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
    binNode<Key, E> *BST<Key, E>::p_remove(binNode<Key, E> *root, const Key &k)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (k < root->getKey())
        {
            root->setLeftChild(p_remove(root->leftChild(), k));
        }
        else if (k > root->getKey())
        {
            root->setRightChild(p_remove(root->rightChild(), k));
        }
        else
        {
            binNode<Key, E> *temp = root;
            if (root->leftChild() == nullptr)
            {
                root = root->rightChild();
                delete temp;
            }
            else if (root->rightChild() == nullptr)
            {
                root = root->leftChild();
                delete temp;
            }
            else
            {
                binNode<Key, E> *temp = p_getMaxNode(root->leftChild());
                root->setKey(temp->getKey());
                root->setElement(temp->element());
                root->setLeftChild(p_removeMaxNode(root->leftChild()));
                delete temp;
            }
        }
        return root;
    }

    template <typename Key, typename E>
    bool BST<Key, E>::p_contains(binNode<Key, E> *root, const Key &k) const
    {
        if (root == nullptr)
        {
            return false;
        }

        if (k < root->getKey())
        {
            return p_contains(root->leftChild(), k);
        }

        if (k > root->getKey())
        {
            return p_contains(root->rightChild(), k);
        }
        //k == element then
        return true;
    }

    template <typename Key, typename E>
    void BST<Key, E>::p_print(binNode<Key, E> *root) const
    {
        if (root == nullptr)
        {
            return;
        }

        std::cout << root->getKey();
        if (root->leftChild() != nullptr || root->rightChild() != nullptr)
        {
            std::cout << "(";
            if (root->leftChild() != nullptr)
            {
                p_print(root->leftChild());
            }
            std::cout << ")(";
            if (root->rightChild() != nullptr)
            {
                p_print(root->rightChild());
            }
            std::cout << ")";
        }
    }

    template <typename Key, typename E>
    void BST<Key, E>::p_preOrder(binNode<Key, E> *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        std::cout << node->getKey() << ' ';
        p_preOrder(node->leftChild());
        p_preOrder(node->rightChild());
    }

    template <typename Key, typename E>
    void BST<Key, E>::p_postOrder(binNode<Key, E> *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        p_postOrder(node->leftChild());
        p_postOrder(node->rightChild());
        std::cout << node->getKey() << ' ';
    }

    template <typename Key, typename E>
    void BST<Key, E>::p_inOrder(binNode<Key, E> *node) const
    {
        if (node == nullptr)
        {
            return;
        }
        p_inOrder(node->leftChild());
        std::cout << node->getKey() << ' ';
        p_inOrder(node->rightChild());
    }

} // namespace dsa1
