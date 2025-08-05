#pragma once
#include "../SEM2_Project/Post.h" // MUST come before using Post

using namespace std;

class Memory : public Post {
    Post* Post1;
public:
    Memory(string id, string des, int d, int m, int y, Post&);
    ~Memory();
    void View(User&) override;
};
