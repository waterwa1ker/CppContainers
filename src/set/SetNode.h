namespace s21 {
    template<typename T>
    struct Node {
        T value;
        Node* left;
        Node* right;
        Node(T value) : value(value), left(nullptr), right(nullptr) {}
    }Node;
}