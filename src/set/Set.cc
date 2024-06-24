#include "Set.h"

s21::Set::Set() : root_(nullptr) {};

s21::Set::Set(const Set<T> &s) {

}

bool s21::Set::empty() {
    return root_ == nullptr;
}

Node<T>* s21::Set::GetRoot() {
    return root_;
}