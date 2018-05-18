#include <iostream>
#include "linklist.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    LinkList*    pLinkList = LinkList::Create();
    unsigned int totalNumInStream;
    unsigned int newNumber;
    
    cin >> totalNumInStream;
    
    for (unsigned int j = 0; j < totalNumInStream; j++)
    {
        cin >> newNumber;
        pLinkList->AddNode(newNumber);
    }
    
    pLinkList->PrintLinkList();
    pLinkList->ReverseLinklist();
    pLinkList->PrintLinkList();
    pLinkList->Destroy();
    
    return 0;
}
