#include <vector>
class VectorIterator; 

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

    int& operator[](int index) {
        return data[index];
    }
    const int& operator[](int index) const {
        return data[index];
    }

    friend Vector operator+(const Vector& a, const Vector& b) {
        Vector result(a.size());
        for (int i = 0; i < a.size(); ++i) {
            result[i] = a[i] + b[i];
        }
        return result;
    }

    friend Vector operator+(const Vector& v, int x) {
        Vector result(v.size());
        for (int i = 0; i < v.size(); ++i) {
            result[i] = v[i] + x;
        }
        return result;
    }

    VectorIterator begin();
    VectorIterator end();

    int size() const {
        return data.size();
    }

private:
    std::vector<int> data;
};

class VectorIterator {
public:
    explicit VectorIterator(Vector& vec, int index) : vec(vec), index(index) {}
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
    int& operator*() const {
        return vec[index];
    }

private:
    Vector& vec;
    int index;
};

VectorIterator Vector::begin() {
    return VectorIterator(*this, 0);
}

VectorIterator Vector::end() {
    return VectorIterator(*this, size());
}

std::ostream& operator<<(std::ostream& os, const Vector& v) {
    for (int i = 0; i < v.size(); ++i) {
        os << v[i] << ' ';
    }
    return os;
}