#include "../SEM2_Project/Memory.h"

Memory::Memory(string id, string des, int d, int m, int y, Post& p)
    : Post(id,des,d,m,y)
{
    Post1 = &p;
}

Memory::~Memory() {
    delete Post1;
    Post1 = nullptr;
}

void Memory::View(User& poster) {
    cout << "*******************************************************************************************************" << endl;
    cout << "  " << poster.GetName() << " Shared Memory!               Posted on "; Post::GetDate().Print();
    
    cout <<"\n\t" << Post::GetDes();
    cout<<"\n\n\n\t\t\t" << Post::GetDate().getyear() - Post1->GetDate().getyear() << " Years Ago :" << endl;
    Post1->ViewPost(poster);

    Post::PrintComment();
      
    cout << "*******************************************************************************************************" << endl;
}