#ifndef CPP2_S21_CONTAINERS_1_SRC_TREE_NODE_H_
#define CPP2_S21_CONTAINERS_1_SRC_TREE_NODE_H_

#define DEFAULT_INT_VALUE 0

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
                if (left_ != nullptr) {
                    delete left_;
                }
                if (right_ != nullptr) {
                    delete right_;
                }                    
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

        private:

            T key_;
            T value_;
            Node<T> *left_;
            Node<T> *right_;


    };

} // namespace s21

#endif //CPP2_S21_CONTAINERS_1_SRC_TREE_NODE_H_