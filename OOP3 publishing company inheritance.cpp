#include<iostream>
#include<string>
using namespace std;

class publication
{
    public:
    string title;
    int price;

    void add()
    {
        cout << "-------------------------------" << endl;
        cout << "Enter the title of the publication." << endl;
        cin.ignore();
        getline(cin, title);
        cout << "Enter the price of publication." << endl;
        cin >> price;
    }

    void display()
    {
        cout << "Title of publication : " << title << endl;
        cout << "Price of publication : " << price << endl;
    }
};

class book : public publication
{
    public:
    int page_count;

    void add_book()
    {
        try
        {
            add();
            cout << "Enter the no. of pages in book." << endl;
            cin >> page_count;
            if(page_count<=0)
            {
                throw page_count;
            }
        }
        catch(...)
        {
            cout << "Invalid page count." << endl;
            page_count=0;
        }
    }

    void disp_book()
    {
        display();
        cout << "Page count : " << page_count << endl;
        cout << "-------------------------------" << endl;
    }
};

class tape : public publication
{
    public:
    float play_time;

    void add_tape()
    {
        try
        {
            add();
            cout << "Enter the play time of tape." << endl;
            cin >> play_time;
            if(play_time<=0)
            {
                throw play_time;
            }
        }
        catch(...)
        {
            cout << "Invalid play time." << endl;
            play_time=0;
        }
    }

    void disp_tape()
    {
        display();
        cout << "Play time : " << play_time << endl;
        cout << "------------------------------" << endl;
    }
};

int main()
{
    int ch, b_count=0, t_count=0;
    book b1[10];
    tape t1[10];

    do
    {
        cout << "**********MAIN MENU**********" << endl;
        cout << "1. Add Information to Books." << endl;
        cout << "2. Add Information to Tapes." << endl;
        cout << "3. Display Information from Books." << endl;
        cout << "4. Display Information from Tapes." << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice(1 to 5)" << endl;
        cin >> ch;

        switch(ch)
        {
            case 1:
                b1[b_count].add_book();
                b_count++;
                break;
            case 2:
                t1[t_count].add_tape();
                t_count++;
                break;

            case 3:
                for(int i=0;i<b_count;i++)
                {
                    b1[i].disp_book();
                }
                break;

            case 4:
                for(int i=0;i<t_count;i++)
                {
                    t1[i].disp_tape();
                }
                break;

            case 5:
                exit(0);
        }
    }
    while(ch!=5);
    return 0;
}
