#pragma once

namespace dsa1 {
template <typename Key, typename E>
class binNode {
private:
    Key m_k;
    E m_element;
    binNode *m_left;
    binNode *m_right;

public:
    binNode() : m_left( nullptr ), m_right( nullptr ) {}
    binNode( Key k, E element, binNode *left = nullptr, binNode *right = nullptr ) : m_k( k ), m_element( element ), m_left( left ), m_right( right ) {}
    ~binNode() {
       // delete m_right;
        //delete m_left;
    }

private:
public:
    E &element() {
        return m_element;
    }
    void setElement( const E &element ) {
        m_element = element;
    }
    Key &getKey() {
        return m_k;
    }
    void setKey( const Key &k ) {
        m_k = k;
    }
    binNode *leftChild() {
        return m_left;
    }
    void setLeftChild( binNode *node ) {
        m_left = node;
    }
    binNode *rightChild() {
        return m_right;
    }
    void setRightChild( binNode *node ) {
        m_right = node;
    }
    bool isLeaf() {
        return ( m_left == nullptr ) && ( m_right == nullptr );
    }

//   friend std::ostream &operator<<(std::ostream &, binNode<Key, E> &);
};

template <typename Key, typename E>
std::ostream &operator<<( std::ostream &os, binNode<Key, E> *My_binNode ) {
    if ( My_binNode != nullptr ) {
        os << "node. key: " << My_binNode->getKey() << " .rightChild: ";

        if ( My_binNode->rightChild() )
            os << " .key: " << My_binNode->rightChild()->getKey() << '\n';
        else
            os << " NULL" << '\n';

        os << "\t\t\t .leftChild: ";

        if ( My_binNode->leftChild() )
            os << " .key: " << My_binNode->leftChild()->getKey() << '\n';
        else
            os << " NULL" << '\n';
    } else {
        os << "node: NULL" << "\n";
    }

    return os;
}

} // namespace dsa1
