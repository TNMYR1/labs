#include <vector>
#include <iostream>
template<typename T>
class VectorIterator;

template<typename T>
class Vector {
public:
    Vector();
    explicit Vector(int size) : data(size) {}
    Vector(const Vector& other) : data(other.data) {}
    Vector& operator=(const Vector& other) {
        data = other.data;
        return *this;
    }
    ~Vector() {};

    T& operator[](int index) {
        return data[index];
    }
    const T& operator[](int index) const {
        return data[index];
    }
     
    friend Vector operator + (const Vector& a, const Vector& b) {
        Vector result(a.size());
        for (int i = 0; i < a.size(); ++i) {
            result[i] = a[i] + b[i];
        }
        return result;
    }

    friend Vector operator + (const Vector& v, T x) {
        Vector result(v.size());
        for (int i = 0; i < v.size(); ++i) {
            result[i] = v[i] + x;
        }
        return result;
    }
    Vector operator + (const Vector& other) const {
        if (size != other.size) {
            throw std::invalid_argument("Vectors must be of equal size");
        }
        Vector<T> result(size);
        for (int i = 0; i < size; i++) {
            result[i] = data[i] + other.data[i];
        }
        return result;
    }
    VectorIterator<T> begin();
    VectorIterator<T> end();

    int size() const {
        return data.size();
    }

private:
    std::vector<T> data;
};

template<typename T>
class VectorIterator {
public:
    explicit VectorIterator(std::vector<T>& vec, int index) : vec(vec), index(index) {}
    VectorIterator& operator++() {
        ++index;
        return *this;
    }
    VectorIterator& operator--() {
        --index;
        return *this;
    }
    bool operator==(const VectorIterator& other) const {
        return index == other.index;
    }
    bool operator!=(const VectorIterator& other) const {
        return !(*this == other);
    }
    T& operator*() const {
        return vec[index];
    }

private:
    std::vector<T>& vec;
    int index;
};

template<typename T>
VectorIterator<T> Vector<T>::begin() {
    return VectorIterator<T>(data, 0);
}
template<typename T>
VectorIterator<T> Vector<T>::end() {
    return VectorIterator<T>(data, data.size());
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}