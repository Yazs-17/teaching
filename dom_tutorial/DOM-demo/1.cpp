#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 定义一个B树节点
struct BTreeNode {
    vector<int> keys;             // 节点中的键
    vector<BTreeNode*> children;  // 孩子的指针
    bool isLeaf;                  // 是否为叶子节点

    BTreeNode(bool leaf)
        : isLeaf(leaf) {}
};

// 插入B树节点
void insertNonFull(BTreeNode* node, int key, int t);
void splitChild(BTreeNode* node, int i, int t);

class BTree {
    int t;            // B-树的阶数
    BTreeNode* root;  // 根节点

   public:
    BTree(int _t)
        : t(_t), root(nullptr) {}

    // 插入键
    void insert(int key) {
        if (!root) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
        } else {
            if (root->keys.size() == 2 * t - 1) {  // 如果根满了
                BTreeNode* s = new BTreeNode(false);
                s->children.push_back(root);
                splitChild(s, 0, t);
                root = s;
            }
            insertNonFull(root, key, t);
        }
    }

    // 获取树的深度
    int getDepth() {
        BTreeNode* current = root;
        int depth = 0;
        while (current) {
            depth++;
            if (!current->children.empty())
                current = current->children[0];
            else
                break;
        }
        return depth;
    }
};

// 插入一个非满节点
void insertNonFull(BTreeNode* node, int key, int t) {
    int i = node->keys.size() - 1;

    if (node->isLeaf) {  // 如果是叶子节点
        node->keys.push_back(0);
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
    } else {  // 如果是内部节点
        while (i >= 0 && key < node->keys[i])
            i--;
        i++;
        if (node->children[i]->keys.size() == 2 * t - 1) {
            splitChild(node, i, t);
            if (key > node->keys[i])
                i++;
        }
        insertNonFull(node->children[i], key, t);
    }
}

// 分裂节点
void splitChild(BTreeNode* node, int i, int t) {
    BTreeNode* y = node->children[i];
    BTreeNode* z = new BTreeNode(y->isLeaf);

    // 分裂 y
    for (int j = 0; j < t - 1; j++)
        z->keys.push_back(y->keys[j + t]);

    if (!y->isLeaf) {
        for (int j = 0; j < t; j++)
            z->children.push_back(y->children[j + t]);
    }

    y->keys.resize(t - 1);
    y->children.resize(t);

    // 插入到父节点
    node->children.insert(node->children.begin() + i + 1, z);
    node->keys.insert(node->keys.begin() + i, y->keys[t - 1]);
}

// 主函数
int main() {
    int n;
    cin >> n;

    vector<int> keys(n);
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    BTree tree(3);  // 创建3阶B-树
    for (int key : keys) {
        tree.insert(key);
    }

    cout << tree.getDepth() << endl;

    return 0;
}
