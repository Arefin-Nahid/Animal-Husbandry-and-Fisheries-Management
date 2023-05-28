#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
using namespace std;

class Animal_husbandry_and_fisheries_managerment{
    protected:
        string animal[2] = {
            "Animal husbandry",
            "Fishing"
        };

    void show(){
        cout << "\t\t\t\t\t\t\t""Animal_husbandry_and_fisheries_managerment""\n"<< "\t\t\t\t\t\t******************************************************\n";
        for(int i = 0, c = 1; i < 2; i++, c++) {
                cout << "\t\t" << i+1 << ". "<<animal[i] << " ";
                if(c == 3) {cout << "\t\n"; c = 0;}
        }
        cout<<endl;
        cout << "\t\t3. EXIT\n";
        cout << "\n\n\n";
    }

};


class selling : public Animal_husbandry_and_fisheries_managerment{
    public:
        vector <int> olist;
        vector <int> olist2;
        int  bull, cow, calf, carp_fish, pabda_fish, sheat_fish, key = 0;
        int total=0;
        string ans;

        int profit(int price, int item)
            {
                total += price*item;
                return total;
            }
        int profit(int prev_quantity, int new_quantity, int price)
            {
                total -= ((prev_quantity - new_quantity)*price);
                return total;
            }


        selling()
        {
            string animal[6] = {
                "BULL",
                "COW",
                "CALF",
                "CARP FISH",
                "PABDA FISH",
                "SHEAT FISH"

            };

            int price[6] = {80000, 60000, 40000, 600, 400, 1000};
            //int total;

            int listar[2] = {0};
            ofstream write;
            write.open("order.text");
            if(!write)
            {
                cout<<"file can not open"<<endl;
                exit (-1);
            }
            a:
                b:
                    cout << "\n\t\tENTER THE KEY OF MAIN SECTION OPTION (one option at a time): ";
                    cin >> key;

                        if(key == 1){

                            cout << "\n\t\t\t\t\t""Animal Husbandry""\n"<< "\t\t\t\t **************************\n";
                            for(int i = 0, c = 1; i < 3; i++, c++) {
                                cout << "\t\t" << i+1 << ". " << animal[i] <<" ";
                                if(c == 3) {cout << "\t\n"; c = 0;}
                            }cout<<endl;

                            int listar[3] = {0};
                            ofstream write;
                            write.open("order.text");
                            if(!write)
                            {
                                cout<<"file can not open"<<endl;
                                exit (-1);
                            }

                            d:
                                e:
                                    f:

                                    cout << "\n\t\tENTER THE KEY OF YOUR CHOICE (one option at a time): ";
                                    cin >> key;

                                    if(key == 1){
                                        int a;
                                        cout<<"\n\t\tHOW MANY BULL DO YOU WANT : ";
                                        cin>>bull;

                                        a = price[key-1];
                                        profit(a, bull);
                                        auto it = find(olist.begin(), olist.end(), key);
                                        if(olist.end() == it) olist.push_back(key);
                                        (listar[key-1] == 0)?listar[key-1] = bull : listar[key-1] += bull;

                                        cout<<"\n\t\t\tYOU CHOICE " << animal[key-1] <<endl<<"\n\t\tYOUR CHOICE WAS SUCCESSFULLY SAVED\n"<<endl;
                                    }

                                    else if(key == 2)
                                    {
                                        int b;
                                        cout<<"\n\t\tHOW MANY COW DO YOU WANT : ";
                                        cin>>cow;

                                        b = price[key-1];
                                        profit(b, cow);
                                        auto it = find(olist.begin(), olist.end(), key);
                                        if(olist.end() == it) olist.push_back(key);
                                        (listar[key-1] == 0)?listar[key-1] = cow : listar[key-1] += cow;

                                        cout<<"\n\t\t\tYOU CHOICE " << animal[key-1] <<endl<<"\n\t\tYOUR CHOICE WAS SUCCESSFULLY SAVED\n"<<endl;
                                    }

                                    else if(key == 3)
                                    {
                                        int p;
                                        cout<<"\n\t\tHOW MANY CALF DO YOU WANT : ";
                                        cin>>calf;

                                        p = price[key-1];
                                        profit(p, calf);
                                        auto it = find(olist.begin(), olist.end(), key);
                                        if(olist.end() == it) olist.push_back(key);
                                        (listar[key-1] == 0)?listar[key-1] = calf: listar[key-1] += calf;

                                        cout<<"\n\t\t\tYOU CHOICE " << animal[key-1] <<endl<<"\n\t\tYOUR CHOICE WAS SUCCESSFULLY SAVED\n"<<endl;
                                    }

                                    else{
                                        cout<<"\n\n\t\t\t\t\t\t\tYOU ENTER WRONG ORDER KEY !!!!! "<<endl;
                                        goto f;
                                    }


                                    cout<<"\n\t\tDO YOU HAVE ANOTHER CHOICE (yes/no) : ";
                                    cin>>ans;
                                    if(ans == "yes" || ans == "YES")
                                        goto d;

                                    else
                                    {
                                        cout << "\n\t\tYOU HAVE CHOICED : \n";
                                        sort(olist.begin(), olist.end());
                                        for(int i = 0; i < olist.size(); i++)
                                        {
                                            cout << "\t\t" << olist[i] << ". " << animal[olist[i]-1] <<"  - Quantity - " << listar[olist[i]-1]<< endl;
                                        }

                                        cout << "\n\t\tDO YOU WANT TO DELETE YOUR CHOICE (yes/no) :";
                                        cin>>ans;

                                        if(ans == "yes" || ans == "YES")
                                        {
                                            x:
                                                int del;
                                                cout << "\n\t\tENTER THE KEY OF YOUR CHOICE THAT YOU WANT TO DELETE(one option at a time) :";
                                                cin >> key;

                                                if(listar[key-1] > 0) {
                                                    cout << "\n\t\tHOW MANY " << animal[key-1] << " YOU WANT TO SELL: " ;
                                                    cin >> del;  cout << endl;

                                                    if(del == listar[key-1]){
                                                        auto it = find(olist.begin(), olist.end(), key);
                                                        olist.erase(it);
                                                    }

                                                    profit(listar[key-1],del,price[key-1]);
                                                    listar[key-1] = del;

                                                    cout << "\n\t\tDO YOU WANT TO DELETE MORE ? (yes/no) : ";
                                                    cin >> ans;

                                                    if(ans == "yes" || ans == "YES") goto x;
                                                }

                                                else
                                                    {
                                                        cout << "\nYOU HAVE NOT CHOICE THIS\n";
                                                        goto x;
                                                    }
                                        }
                                        cout << "\n\t\tYOU HAVE CHOICED : \n";
                                        sort(olist.begin(), olist.end());
                                        for(int i = 0; i < olist.size(); i++)
                                        {
                                            cout << "\t\t" << olist[i] << ". " << animal[olist[i]-1] <<"  - Quantity - " << listar[olist[i]-1]<< endl;
                                        }
                                    }
                        }


                        else if(key == 2)
                        {
                            cout << "\n\t\t\t\t\t""Fishing""\n"<< "\t\t\t\t*******************\n";
                            for(int i = 3, c = 1; i < 6; i++, c++) {
                            cout << "\t\t" << i+1 << ". " << animal[i] <<" ";
                            if(c == 3) {cout << "\t\n"; c = 0;}
                            }cout<<endl;

                            int listar2[3] = {0};
                            ofstream write;
                            write.open("order.text");
                            if(!write)
                            {
                                cout<<"file can not open"<<endl;
                                exit (-1);
                            }

                            ab:
                                cd:

                                    cout << "\n\t\tENTER THE KEY OF YOUR CHOICE (one option at a time): ";
                                    cin >> key;

                            if(key == 4)
                            {
                                int a;
                                cout<<"\n\t\tHOW MUCH(KG) CARP FISH DO YOU WANT TO SELL : ";
                                cin>>carp_fish;

                                a = price[key-1];
                                profit(a, carp_fish);
                                auto it = find(olist2.begin(), olist2.end(), key);
                                if(olist2.end() == it) olist2.push_back(key);
                                (listar2[key-1] == 0)?listar2[key-1] = carp_fish : listar2[key-1] += carp_fish;

                                cout<<"\n\t\t\tYOU CHOICE " << animal[key-1] <<endl<<"\n\t\tYOUR CHOICE WAS SUCCESSFULLY SAVED\n"<<endl;
                            }

                            else if(key ==5)
                            {
                                int b;
                                cout<<"\n\t\tHOW MUCH(KG) PABDA FISH DO YOU WANT TO SELL : ";
                                cin>>pabda_fish;

                                b = price[key-1];
                                profit(b, pabda_fish);
                                auto it = find(olist2.begin(), olist2.end(), key);
                                if(olist2.end() == it) olist2.push_back(key);
                                (listar2[key-1] == 0)?listar2[key-1] = pabda_fish : listar2[key-1] += pabda_fish;

                                cout<<"\n\t\t\tYOU CHOICE "<< animal[key-1] <<endl<<"\n\t\tYOUR CHOICE WAS SUCCESSFULLY SAVED\n"<<endl;
                            }

                            else if(key == 6)
                            {
                                int p;
                                cout<<"\n\t\tHOW MUCH(KG) SHEAT FISH DO YOU WANT TO SELL : ";
                                cin>>sheat_fish;

                                p = price[key-1];
                                profit(p, sheat_fish);
                                auto it = find(olist2.begin(), olist2.end(), key);
                                if(olist2.end() == it) olist2.push_back(key);
                                (listar2[key-1] == 0)?listar2[key-1] = sheat_fish: listar2[key-1] += sheat_fish;

                                cout<<"\n\t\t\tYOU CHOICE " << animal[key-1] <<endl<< "\n\t\tYOUR CHOICE WAS SUCCESSFULLY SAVED\n"<<endl;
                            }

                            else{
                                cout<<"\n\n\t\t\t\t\t\t\tYOU ENTER WRONG ORDER KEY !!!!! "<<endl;
                                goto cd;
                            }

                            cout<<"\n\t\tDO YOU HAVE ANOTHER CHOICE (yes/no) : ";
                            cin>>ans;
                            if(ans == "yes" || ans == "YES")
                                goto ab;

                            else
                            {
                                cout << "\n\t\tYOU HAVE ORDERED : \n";
                                sort(olist2.begin(), olist2.end());
                                for(int i = 0; i < olist2.size(); i++)
                                    {
                                        cout << "\t\t" << olist2[i] << ". " << animal[olist2[i]-1] << endl;
                                    }


                                cout << "\n\t\tDO YOU WANT TO DELETE YOUR CHOICE (yes/no) :";
                                cin>>ans;

                                if(ans == "yes" || ans == "YES")
                                {
                                    y:
                                        int del;
                                        cout << "\n\t\tENTER THE KEY OF YOUR CHOICE THAT YOU WANT TO DELETE(one option at a time) :";
                                        cin >> key;

                                        if(listar2[key-1] > 0) {
                                            cout << "\n\t\tHOW MUCH(KG) " << animal[key-1] << " YOU WANT TO SELL : " ;
                                            cin >> del;  cout << endl;

                                            if(del == listar2[key-1]){
                                                auto it = find(olist2.begin(), olist2.end(), key);
                                                olist2.erase(it);
                                            }

                                            profit(listar2[key-1],del,price[key-1]);
                                            listar2[key-1] = del;

                                            cout << "\n\t\tDO YOU WANT TO DELETE MORE ? (yes/no) : ";
                                            cin >> ans;

                                            if(ans == "yes" || ans == "YES") goto y;
                                        }

                                        else
                                        {
                                            cout << "\n\t\tYOU HAVE NOT CHOICE THIS ITEM\n";
                                            goto y;
                                        }
                                }

                                cout << "\n\t\tYOU HAVE ORDERED : \n";
                                sort(olist2.begin(), olist2.end());
                                for(int i = 0; i < olist2.size(); i++)
                                    {
                                        cout << "\t\t" << olist2[i] << ". " << animal[olist2[i]-1] << endl;
                                    }
                            }


                        }
                        else if(key == 3){
                            cout<<"\n\t\t\t\t\t\t\t *** THANK YOU ***";
                            exit(0);
                        }
                        else{
                            cout<<"\n\n\t\t\t\t\t\t\tYOU ENTER WRONG OPTION KEY !!!!! "<<endl;
                            goto b;
                        }

                        cout<<"\n\t\tDO YOU WANT TO GO MAIN SECTION OPTION (yes/no) : ";
                        cin>>ans;
                        if(ans == "yes" || ans == "YES"){
                            show();
                            goto a;
                        }


                        cout<<"\n\t\tTHANK YOU FOR YOUR CHOICE :) GENERATING YOUR SELLINF INFO ";
                        for(int i=1; i < 8; i++)
                        {
                            Sleep(500);
                            cout << "..";
                        }

                        cout<<"\n\t\t\t\t\t\t\t";
                        system("PAUSE");
                        system("CLS");

                        cout << "\n\t\t\t\t\t ================================================"<<endl;
						cout << "\t\t\t\t\t|               SELLING DETAILS                   |"<<endl;
						cout << "\t\t\t\t\t ================================================"<<endl;
						cout << endl;
						cout << endl;
                        int billno = rand(), orderno = rand();
						cout << "\t\t\t\t\t  Bill No : " << billno << "  SELLING ORDER : XYZ" << orderno <<endl;
						cout << endl;
						cout << endl;
						cout << "\t\t\t\t\t  MANAGER : Arefin Nahid"<<endl;
						cout << endl;
                        cout<<"\t\t\t\t\t  YOUR TOTAL SELLING INCOME TK. "<<total<<endl;
						cout << "\n\n\t\t\t\t\t ================================================"<<endl;

                        write.close();
        }
};


class log_in : public Animal_husbandry_and_fisheries_managerment
{
private:
    string Username = "arefin";
    string pass = "2007050";
public :
    log_in()
    {

        Iagain:
            string username;
            cout << "\n\n\n\t\t\t\t\t\tEnter Your User Name: ";
            cin >> username;

            if(username != Username){
                cout << "\n\t*** Wrong Username.  Enter the correct one. ***";
                goto Iagain;
            }

            again:
            string p = "";
            cout <<"\n\n\n\t\t\t\t\t\tEnter password : ";

            Pagain:

            char c;
            c = getch();
            cout << "*";
            if(c!=13)
                {
                    p=p+c;  //for concatenating the string
                    goto Pagain;
                }
            
            if(p == pass){
                cout << "\n\n\n\t\t\t\t\t\t   ---- Welcome ----";
                cout << "\n\n\n\t\t\t\t\t\t";
                    system("PAUSE");
                    system("CLS");
            }
            else {
                cout << "\n\t*** Wrong password.  Enter the correct one. ***";
                goto again;
            }
            
        show();
    }
};

int main(){
    log_in log;
    selling sell;
    return 0;
}