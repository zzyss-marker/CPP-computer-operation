#include<iostream>
#include<string>
using namespace std;
class book
{
private:
    char name[64], writer[64], publisher[64];
    int price;
public:
    void setBook(char na[64], char wr[64], char pu[], float pr);
    void Display()
    {
        cout << name << endl;
        cout << writer << endl;
        cout << publisher << endl;
        cout << price << endl;
    }
};
void book::setBook(char na[64], char wr[64], char pu[64], float pr)
{
    strcpy(name, na);
    strcpy(writer, wr);
    strcpy(publisher, pu);
    price = pr;
}
int main()
{
    char na[64], wr[64], pu[64];
    float pr;
    book b[5];
    for (int i = 0; i < 5; i++)
    {
        cin >> na >> wr >> pu >> pr;
        b[i].setBook(na, wr, pu, pr);
    }
    for (int i = 0; i < 5; i++)
        b[i].display();
    return 0;
}
