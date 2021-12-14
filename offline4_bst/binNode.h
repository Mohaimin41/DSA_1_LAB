#pragma once

namespace dsa1
{
    template <typename Key, typename E>
    class binNode
    {
    private:
        Key m_k;
        E m_element;
        binNode *m_left;
        binNode *m_right;

    public:
        binNode() : m_left(nullptr), m_right(nullptr) {}
        binNode(Key &k, E element, binNode *left = nullptr, binNode *right = nullptr) : m_k(k), m_element(element), m_left(left), m_right(right) {}
        ~binNode()
        {
            delete m_right;
            delete m_left;
        }

    private:
    public:
        E &element() { return m_element; }
        setElement(const E &element) { m_element = element; }
        Key &getKey() { return m_k; }
        setKey(const Key &k) { m_k = k; }
        binNode *leftChild() { return m_left; }
        setLeftChild(binNode *node) { m_left = node; }
        binNode *rightChild() { return m_right; }
        setRightChild(binNode *node) { m_right = node; }
        bool isLeaf() { return (m_left == nullptr) && (m_right == nullptr); }
    };

} // namespace dsa1
