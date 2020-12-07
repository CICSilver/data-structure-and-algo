template <typename T>
class node
{
private:
    T val;
    int depth = 0;
    node *left;
    node *right;

public:
    node() : val(0), left(nullptr), right(nullptr) {}
    node(T v) : val(v), left(nullptr), right(nullptr) {}
    node(T v, node *l, node *r) : val(v), left(l), right(r){};
    ~node(){};
};
