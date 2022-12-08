/* Ten: HUYNH PHAM QUYNH NHU - 6251071067
  Email : 6251071067@st.utc2.edu.vn
  Ngay sinh: 15/10/2003*/

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

//*2. Viết chương trình:
//* a. Tạo cây nhị phân tìm kiếm chứa thông tin của cửa hàng (mỗi phần tử trên cây gồm: tên cửa hàng, địa chỉ, số điện thoại (số nguyên, khóa)). 
//* b. Xuất ra màn hình thông tin của các cửa hàng theo chiều giảm dần của khóa. 
//* c. Tìm cửa hàng biết số điện thoại của cửa hàng đó (số điện thoại do người dùng nhập vào từ bàn phím)

struct store {
    string name, address;
    int phone;
};

struct nodeTree {
    store data;
    nodeTree *left;
    nodeTree *right;
};

nodeTree *root;

void rootTree() {
    root = NULL;
}

nodeTree *makeNode (store info) {
    nodeTree *newNode = new nodeTree ();
    newNode->data = info;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

nodeTree *insertNode (nodeTree *root, store info) {
    nodeTree *temp = root;
    if (root == NULL) {
        nodeTree *tNode = makeNode(info);
        root = tNode;
        return root;
    }
    if (temp != NULL) {
        if (temp->data.phone == info.phone) {
            return temp;
        } else if (temp->data.phone > info.phone) {
            temp->left = insertNode(temp->left, info);
        } else {
            temp->right = insertNode(temp->right, info);
        }
    }
}

void browse_RNL (nodeTree *root) {
    if (root != NULL) {
        browse_RNL (root->right);
        cout << root->data.phone << " " << root->data.name << " " << root->data.address << endl;
        browse_RNL(root->left);
    }
}

bool searchPhone (nodeTree *root, store info) {
    nodeTree *temp = root;
    while (temp != NULL) {
        if (temp->data.phone == info.phone) {
            return true;
        }
        if (temp->data.phone > info.phone) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    store a[n];
    rootTree();
    for (int i=0; i<n; i++) {
        cin.ignore();
        cout << "Ten cua hang: ";
        getline(cin, a[i].name);
        cout << "Dia chi: ";
        getline(cin, a[i].address);
        cout << "So dien thoai: ";
        cin >> a[i].phone;
        root = insertNode(root, a[i]);
    }
    cout << "\t\tThong tin cac cua hang" << endl;
    browse_RNL(root);
    store ph;
    cout << "Nhap so dien thoai cua cua hang can tim: ";
    cin >> ph.phone;
    if (searchPhone(root, ph)) {
        browse_RNL(root);
    }
    system("pause");
    return 0;
}