#include<iostream>
#include<fstream>

using namespace std;

//create a class as shopping, here p -> product
class shopping
{
   private:
        int pcode;
        float price;
        float discount;
        string pname;

        public:
            void menu();
            void administrative();
            void buyer();
            void add();
            void edit();
            void rem();
            void list();
            void receipt();
};

void shopping :: menu()
{
   m:
   int choice;
   string email;
   string password;

   cout<<"\t\t\t\t____________________________________\n";
   cout<<"\t\t\t\t                                    \n";
   cout<<"\t\t\t\t       Supermarket Main Menu        \n";
   cout<<"\t\t\t\t                                    \n";
   cout<<"\t\t\t\t____________________________________\n";
   cout<<"\t\t\t\t                                    \n";
   // create a menu in which the user/customer have to select whether he is an administrator or a buyer
   cout<<"\t\t\t\t|   1) Administrator   |\n";
   cout<<"\t\t\t\t|                      |\n";
   cout<<"\t\t\t\t|   2) Buyer           |\n";
   cout<<"\t\t\t\t|                      |\n";
   cout<<"\t\t\t\t|   3) Exit            |\n";
   cout<<"\t\t\t\t|                      |\n";
   cout<<"\t\t\t\t Please select! ";
   cin>> choice;

   switch(choice)
   {
      case 1: 
          cout<<"\t\t\t Please Login \n";
          cout<<"\t\t\t Enter Email  \n";
          cin>> email;
          cout<<"\t\t\t Password     \n";
          cin>> password;

          if(email=="code@email.com" && password=="code@123")
          {
             administrative();
          }
          else
          {
             cout<<"Invalid email/password";  
          }
          break;

   case 2:
       {
          buyer();
       }
   
   case 3:
       {
        exit(0);
       }

       default :
            {
               cout<< "Please select from the given options";
            }
    }
goto m;
}

void shopping :: administrative()
{
   m:
   int choice;
   cout<<"\n\n\n\t\t\t Administrative menu";
   cout<<"\n\t\t\t|___1) Add the product___ |";
   cout<<"\n\t\t\t|___                      |";
   cout<<"\n\t\t\t|___2) Modify the product_|";
   cout<<"\n\t\t\t|___                      |";
   cout<<"\n\t\t\t|___3) Delete the product_|";
   cout<<"\n\t\t\t|___                      |";
   cout<<"\n\t\t\t|___4) Back to main menu__|";

   cout<<"\n\n\t Please enter your choice : ";
   cin>>choice;

   switch(choice)
   {
      case 1:
         add();
         break;
      case 2:
         edit();
         break;
      case 3:
         rem();
         break;
      case 4:
         menu();
         break;
      default  :
         cout<<"Invalid choice!";
   }
   goto m;
}

void shopping :: buyer()
{  
   m:
   int choice;
   cout<<"\t\t\t Buyer \n";
   cout<<"\t\t\t _______________\n";
   cout<<"\t\t\t                \n";
   cout<<"\t\t\t 1) Buy Product \n";
   cout<<"\t\t\t 2) Go Back     \n";
   cout<<"\t\t\t 3) Enter your choice : ";

   cin>>choice;

   switch(choice)
   {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default :
        cout<<"Invalid choice";
   }
   
   goto m;
}

void shopping :: add()
{
   m:
   fstream data;
   int c;
   int token = 0;
   float p;
   float d;
   string n;

   cout<<"\n\n\t\t\t Add new product";
   cout<<"\n\n\t Product code of the product : ";
   cin>>pcode;
   cout<<"\n\n Name of the product : ";
   cin>>pname;
   cout<<"\n\n\t Price of the product :  ";
   cin>>price;
   cout<<"\n\n\t Discount on product : ";
   cin>>discount;

   data.open("database.txt",ios::in);

   if(!data)
   {
      data.open("database.txt", ios::app|ios::out);
      data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
      data.close();
   }
   else
   {
      data>>c>>n>>p>>d;

      while(!data.eof())
      {
         if(c == pcode)
         {
            token++;
         }
         data>>c>>n>>p>>d;
      }
      data.close();
   
   if(token==1)
    goto m;
   else{
        
      data.open("database.txt", ios::app|ios::out);
      data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<" "<<discount<<"\n";
      data.close();
      }
   }
      cout<<"\n\n\t\t Record Inserted !";
}

void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record ";
    cout<<"\n\t\t\t Product code : ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
       cout<<"\n\nFile doesn't exist! ";
    }
    else{

       data1.open("database1.txt", ios::app|ios::out);

       data>>pcode>>pname>>price>>discount;
       while(!data.eof())
       {
          if(pkey==pcode)
          {
             cout<<"\n\t\t Product new code : ";
             cin>>c;
             cout<<"\n\t\t Name of the product : ";
             cin>>n;
             cout<<"\n\t\t Price : ";
             cin>>p;
             cout<<"\n\t\t Discount : ";
             cin>>d;
             data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
             cout<<"\n\n\t\t Record edited ";
             token++;
          }
          else
          {
             data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
          }
          data>>pcode>>pname>>price>>discount;
       }
       data.close();
       data1.close();
       /* Rename the database1 back to the original name (database) so we use two functions remove()and rename()*/

       remove("database.txt");
       rename("database1.txt", "database.txt"); // changes to database

       if(token==0)
       {
          cout<<"\n\n Record not found sorry!";
       }
    }
}
// Create Remove function
void shopping :: rem()
{
   fstream data,data1;
   int pkey;
   int token = 0;
   cout<<"\n\n\t Delete product ";
   cout<<"\n\n\t Product code : ";
   cin>>pkey;
   data.open("database.txt", ios::in);
   if(!data)
   {
      cout<<"File doesn't exist";
   }
   else{
      data1.open("database1.txt", ios::app|ios::out);
      data>>pcode>>pname>>price>>discount;
      while(!data.eof())
      {
         if(pcode==pkey)
         {
            cout<<"\n\n\t Product deleted successfully";
            token++;
         }
         else
         {
            data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
         }
         data>>pcode>>pname>>price>>discount;
      }
      data.close();
      data1.close();
      remove("database.txt");
      rename("database1.txt", "database.txt");

      if(token==0)
      {
         cout<<"\n\n Record not found";
      }
   }
}

// Create a list - it help in showing the list to the customer or the buyer
void shopping :: list()
{
   fstream data;
   data.open("database.txt", ios::in);
   cout<<"\n\n|___________________________________________________\n";
   cout<<"ProNo\t\tName\t\tPrice\n";
   cout<<"\n\n|___________________________________________________\n";
   data>>pcode>>pname>>price>>discount;
   while(!data.eof())
   {
      cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
      data>>pcode>>pname>>price>>discount;
   }
   data.close();
}
// Create the Receipt function in which all the customer operations will take place
void shopping :: receipt()
{
   fstream data;

   int arrc[100]; // arrc[] - array of codes
   int arrq[100]; // arrq[] - array of quantity
   char choice;
   int c=0;
   float amount=0;
   float discount=0;
   float total=0;

   cout<<"\n\n\t\t\t  RECEIPT ";
   data.open("database.txt", ios::in);
   if(!data)
   {
      cout<<"\n\n Empty database";
   }
   else{
      data.close();
      /*call the list function because if the file is created then we've to call the list function and will show the useror the customer that these are the products available in the supermarket */

      list();
      cout<<"\n___________________________________________\n";
      cout<<"\n|                                          \n";
      cout<<"\n         Please place the order            \n";
      cout<<"\n|                                          \n";
      cout<<"\n___________________________________________\n";
      do
      { 
         m:
         cout<<"\n\nEnter Product code : ";
         cin>>arrc[c];
         cout<<"\n\nEnter the product quantity : ";
         cin>>arrq[c];
         /* check if the product code entered by the user matches with the product code i.e., being already entered then display the message that duplicate product code please try again */

         for(int i=0;i<c;i++)
         {
            if(arrc[c]==arrc[i])
            {
               cout<<"\n\n Duplicate product code. Please try again!";
               goto m;
            }
         }
         c++;
         cout<<"\n\n Do you want to buy another product? Press Y for yes and N for no : ";
         cin>>choice;
      }
      while(choice == 'Y');

      cout<<"\n\n\t\t\t___________________RECEIPT__________________\n";
      cout<<"\nProduct No\t Product Name\t Product Quantity\tPrice\tAmount\tAmount with discount\n";

      for(int i=0;i<c;i++)
      {
         data.open("database.txt", ios::in);
         data>>pcode>>pname>>price>>discount;
         while(!data.eof())
         {
            if(pcode==arrc[i])
            {
               amount = price*arrq[i];
               discount = amount-(amount*discount/100);
               total = total+discount;
               cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
            }
            data>>pcode>>pname>>price>>discount;
         }
      }
      data.close();
   }
   cout<<"\n\n________________________________________________";
   cout<<"\n Total Amount : "<<total;
}

int main()
{
   shopping s;
   s.menu();
  
}