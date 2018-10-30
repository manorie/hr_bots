#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

struct position {
    int posr;
    int posc;

    std::string to_str() {
        return std::to_string(posr) + std::to_string(posc);
    }
    position right() {
        return position{this->posr, this->posc+1};
    }
    position left() {
        return position{this->posr, this->posc-1};
    }
    position up() {
        return position{this->posr-1, this->posc};
    }
    position down() {
        return position{this->posr+1, this->posc};
    }
    bool valid() {
        return (posr >= 0 && posr < 5 && posc >=0 && posc < 5);
    }
};

bool is_dirty(position pos, const vector <string> board) {
    return board[pos.posr][pos.posc] == 'd';
}

bool did_seen(position pos) {
    std::ifstream file;
    file.open(pos.to_str().c_str());

    if(file){
        file.close();
        return true;
    }
    return false;
}

void visited(position pos) {
    std::ofstream file;
    file.open(pos.to_str().c_str());
    file << "x";
    file.close();
}

void next_move(position pos, const vector <string> board) {
    visited(pos);

    if (is_dirty(pos, board)) {
        std::cout << "CLEAN" << std::endl;
        return;
    }

    position rightMove = pos.right();
    if (!did_seen(rightMove) && rightMove.valid()) {
        std::cout << "RIGHT" << std::endl;
        return;
    }

    position downMove = pos.down();
    if (!did_seen(downMove) && downMove.valid()) {
        std::cout << "DOWN" << std::endl;
        return;
    }

    position leftMove = pos.left();
    if (!did_seen(leftMove) && leftMove.valid()) {
        std::cout << "LEFT" << std::endl;
        return;
    }

    std::cout << "UP" << std::endl;
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(position{pos[0], pos[1]}, board);
    return 0;
}
