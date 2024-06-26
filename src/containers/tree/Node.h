#ifndef CPP2_S21_CONTAINERS_1_SRC_TREE_NODE_H_
#define CPP2_S21_CONTAINERS_1_SRC_TREE_NODE_H_

#define DEFAULT_INT_VALUE 0

#include <stdio.h>

//–¿«¡≈–»—‹, œŒ◊≈Ã” Õ≈ œŒÀ”◊¿≈“—ﬂ ƒŒ¡¿¬»“‹ –≈¿À»«¿÷»ﬁ ¬ .cc Ù‡ÈÎ
namespace s21 {
    template<typename T>
    class Node {

        public:

            //Constructors
            Node() : key_(DEFAULT_INT_VALUE), value_(DEFAULT_INT_VALUE), left_(nullptr), right_(nullptr) {};
            Node(T key, T value): key_(key), value_(value), left_(nullptr), right_(nullptr) {};

            //Destructor
            ~Node() {
                FreeNode();             
            };

            //Getters & Setters
            T GetKey() { return key_; };
            T GetValue() { return value_; };
            Node<T>* GetLeft() { return left_; }
            Node<T>* GetRight() { return right_; }
            void SetLeft(Node<T>* left) { left_ = left; }
            void SetRight(Node<T>* right) { right_ = right; }

            //Main Functions
            void Insert(Node<T> *node, T key, T value) {
                if (key < node->GetKey()) {
                    if (node->GetLeft() == nullptr) {
                        node->SetLeft(new Node(key, value));
                    } else {
                        this->Insert(node->GetLeft(), key, value);
                    }
                } else {
                    if (node->GetRight() == nullptr) {
                        node->SetRight(new Node(key, value));
                    } else {
                        this->Insert(node->GetRight(), key, value);
                    }
                }
            }

            Node<T>* GetMax(Node<T> &node) {
                if (node.right_ == nullptr) {
                    return &node;
                }
                return GetMax(*node.right_);
            }

            Node<T>* GetMin(Node<T> &node) {
                if (node.left_ == nullptr) {
                    return &node;
                }
                return GetMin(*node.left_);
            }


            //Operators
            bool operator==(const Node& other) {
                return this->key_ == other.key_ && this->value_ == other.value_;
            }

            Node<T> operator=(const Node& other) {
                FreeNode();
                key_ = other.key_;
                value_ = other.value_;
                left_ = other.left_;
                right_ = other.right_;
                return *this;
            }

            //Support
            void FreeNode() {
                if (left_ != nullptr) {
                    delete left_;
                }
                if (right_ != nullptr) {
                    delete right_;
                }  
            }

        private:

            T key_;
            T value_;
            Node<T> *left_;
            Node<T> *right_;


    };

} // namespace s21

#endif //CPP2_S21_CONTAINERS_1_SRC_TREE_NODE_H_