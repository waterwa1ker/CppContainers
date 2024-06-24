#include "SetNode.h"

namespace s21 {
    template<typename T>
    class Set {

        public:
            
            //Constructors
            Set();
            Set(const Set<T> &s);
            Set(Set<T> &&s);

            //Destructor
            ~Set();

            //Operators
            Set operator=(Set<T> &&s);

            //Capacity
            bool empty();

            //Getters & Setters
            void SetRoot(Node<T> * root_);
            Node<T>* GetRoot();

        private:
            Node<T>* root_;
    };
}