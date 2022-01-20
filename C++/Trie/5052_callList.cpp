#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int char_to_index(char c){
    return c - '0';
}

struct Trie {

    bool is_terminal;
    Trie * next[10];
    Trie(): is_terminal(false) {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for (int i = 0; i < 10; ++i) {
            if (next[i]) {
                delete next[i];
            }
        }
    }

    void insert(const char * key) {
        //cout << "key : "<< *key << " " << endl; //9, 1, 1 \0
        if (*key == '\0') {
            is_terminal = true;
        }
        else {
            int index = char_to_index(*key);
            if (next[index] == 0)
                next[index] = new Trie();
            next[index]->insert(key + 1); // 있으면 만득지 않고 다음 키 확인
        }
    }

    bool find(const char * key) {

        if (*key == '\0') return true;

        // Return false if there is already terminal node before string is the end.
        
        //while finding -> 마지막 노드 만나면 false 하게 함
        if (is_terminal) return false;

        int index = char_to_index(*key);
        return next[index]->find(key + 1);
    }
};

int main() {

    int t;//테스트 케이스
    char phone_books[10000][11];//전화부 / 전화번호 길이
    cin >> t;

    while (t--) {
        int n;
        cin >> n; //전화부 수

        Trie * root = new Trie();
        for (int i = 0; i < n; ++i) {
            cin >> phone_books[i];// 911, 97625999, 91125426
            //cout << phone_books[i] << " ";
            root->insert(phone_books[i]);
        }

        bool is_valid = true;
        
        for (int i = 0; i < n; ++i) {

            if (root->find(phone_books[i]) == false) {
                is_valid = false;
                break;
            }
        }
        
        delete root;
        printf("%s\n", is_valid ? "YES" : "NO");
    }
    return 0;
}
