#include "productlist.h"
#include <QDebug>

ProductList::ProductList() : head(nullptr) {}

ProductList::~ProductList() {
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

void ProductList::addProduct(const Product &product) {
    Node* newNode = new Node(product);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    qDebug() << "Product added:" << product.getName() << product.getPrice() << product.getQuantity();
}
Node* ProductList::getHead() const {
    return head;
}

bool ProductList::deleteProduct(const QString &name) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data.getName() != name) {
        previous = current;
        current = current->next;
    }

    if (current == nullptr) {
        return false; // Product not found
    }

    if (previous == nullptr) {
        // Deleting the head node
        head = current->next;
    } else {
        previous->next = current->next;
    }

    delete current;
    return true;
}
// void ProductList::addProduct(const Product &product) {
//     Node* newNode = new Node(product);
//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         Node* current = head;
//         while (current->next != nullptr) {
//             current = current->next;
//         }
//         current->next = newNode;
//     }
//     productStack.push(product);  // Push the product onto the stack
//     qDebug() << "Product added:" << product.getName() << product.getPrice() << product.getQuantity();
// }

// bool ProductList::undoLastAdd() {
//     if (productStack.isEmpty()) {
//         return false; // No products to undo
//     }

//     Product lastProduct = productStack.pop();
//     return deleteProduct(lastProduct.getName());
// }

// Node* ProductList::getHead() const {
//     return head;
// }


Product* ProductList::searchProduct(const QString &name) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.getName() == name) {
            return &current->data;
        }
        current = current->next;
    }
    return nullptr;
}

void ProductList::printProducts() const {
    Node* current = head;
    const Product& product = current->data;
    qDebug() << "Product:   " << product.getName() << "--- Price:   " << product.getPrice() << "--- Quantity:   " << product.getQuantity();
    current = current->next;
    }
void ProductList::sortProducts() {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        Node* prev = nullptr;
        Node* next = nullptr;

        while (current->next != nullptr) {
            next = current->next;
            if (current->data.getName() > next->data.getName()) {
                // Swap the nodes
                if (prev != nullptr) {
                    prev->next = next;
                } else {
                    head = next;
                }
                current->next = next->next;
                next->next = current;

                swapped = true;
            }
            prev = current;
            current = current->next;
        }
    } while (swapped);
}
void ProductList::bubbleSortByName() {
    if (!head) return; // Handle empty list case

    bool swapped;
    Node *ptr;
    Node *lptr = nullptr;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != lptr) {
            if (ptr->data.getName() > ptr->next->data.getName()) {
                // Swap data of adjacent nodes
                Product temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swapped);
}
double ProductList::calculateTotalPayments() const {
    double totalPayments = 0.0;
    Node* current = head;
    while (current != nullptr) {
        const Product& product = current->data;
        totalPayments += product.getPrice() * product.getQuantity();
        current = current->next;
    }
    return totalPayments;
}

bool ProductList::checkoutProduct(const QString &name, int quantityToCheckout) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.getName() == name) {
            int currentQuantity = current->data.getQuantity();
            if (currentQuantity >= quantityToCheckout) {
                current->data.setQuantity(currentQuantity - quantityToCheckout);
                return true; // Successfully checked out
            } else {
                return false; // Not enough quantity to checkout
            }
        }
        current = current->next;
    }
    return false; // Product not found
}
