#include<iostream>
#include<stdio.h>
using namespace std;
class publication
{
    private:
      string title;
      float price;
    public:
      void add() {
          cout<<"\n\n-----------Enter the Publication Information------------"<<endl;
          cout<<"Enter Title of the Publication : ";
          cin.ignore();
          getline(cin,title);
          cout<<"Enter Price of Publication : ";
          cin>>price;
          
      }
    void display(){
        cout<<"\n\n------------------------------------";
        cout<<"\nTitle of Publication :"<<title;
        cout<<"\nPublication Price : "<<price;
    }
};
class book: public publication
{
    private:int page_count;
    public: void add_book(){
        try{
            add();
            cout << "Enter Page Count of Book : ";
            cin>>page_count;
            if (page_count <=0){
                throw page_count;
                
            }
        }   catch (...){
            cout << "\n Invalid Page Count !!!!";
            page_count=0;
            
        }
    }
    void display_book(){
        display();
        cout<<"\n Page Count : "<<page_count;
        cout<<"\n----------------------------\n";
    }
};

class tape: public publication
{
    private:float play_time;
    public: void add_tape(){
        try{
            add();
            cout<<"Enter Play Duration of the Tape : ";
            cin>> play_time;
            if(play_time<=0)
               throw play_time;
               
        } catch(...){
            cout<<"\n Invalid Play Time!!";
            play_time=0;
          }
    }

 void display_tape()
{
     display();
     cout << "\n Play Time : "<< play_time<<"min";
     cout<<"\n---------------------------------------\n";
}
    
};
int main(){
    book b1[10];
    tape t1[10];
    int ch,b_count=0,t_count=0;
    do{
        cout<<"\n---------Publication Database System--------";
        cout<<"\n---------Menu-----------";
        cout<<"\n1.Add Information to Books";
        cout<<"\n2.Add Information to Tapes";
        cout<<"\n3.Display Books Information";
        cout<<"\n4.Display Tapes Information";
        cout<<"\n5.Exit";
        cout<<"\n\nEnter Your Choice: ";
        cin>>ch;
        switch (ch){
        case 1:
             b1[b_count].add_book();
             b_count++;
             break;
        case 2:
             t1[t_count].add_tape();
             t_count++;
             break;
        case 3:
             cout<<"\n---------Book Publication Database System--------";
             for (int j=0; j<b_count; j++){
                 b1[j].display_book();
                 
             }
             break;
        case 4:
             cout<<"\n---------Tape Publication Database System--------";
             for (int j=0;j<t_count;j++){
                 t1[j].display_tape();
             }
             break;
        case 5:
             exit(0);
        }
    } while (ch != 5);
    return 0;
}
