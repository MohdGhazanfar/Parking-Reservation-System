#include<iostream>     //This is basic input/output C++ Standard Library that implement stream-based input/output capabilities.
#include<fstream>      //This library represents the file stream generally, and has the capabilities of both ofstream and ifstream which means it can create files, write information to files, and read information from files.
#include<string>       //This C++ string class internally uses char array to store character but all memory management, allocation, and null termination is handled by string class itself that is why it is easy to use.
#include<ctime>        //The ctime library in C++ converts the given time since epoch to a calendar local time and then to a character representation
#include<string.h>     //h is the header in the C standard library for the C programming language which contains macro definitions, constants and declarations of functions and types used not only for string handling but also various memory handling functions
#include<sstream>      //A stringstream class in C++ is a Stream Class to Operate on strings.The stringstream class in C++ allows a string object to be treated as a stream. It is used to operate on strings.
#include<stdlib.h>     //stdlib.h is the header of the general purpose standard library of C++ programming language which includes functions involving memory allocation, process control, conversions and others.
#include <bits/stdc++.h> //The <bits/stdc++.h> is a header file. This file includes all standard library. Sometimes in some coding contests, when we have to save time while solving, then using this header file is helpful.
using namespace std;    // It is used because computer needs to know the code for the cout, cin functionalities and it needs to know which namespace they are defined.


// Funtion Prototype

string int_to_string(int v);

//--------------------------------

// We have created a class name parking lot

class Parking_Lot{

    // we have intiliaze some variables 

    int Time,c = 0;
    string car_owner,car_No;
    string Fname,Lname,Username,password,ATM_no; 
    int hour,min,sec,Ahour,Amin,Asec,Row,Col;
    char parkSpaces[10][10];
    string pName;
    static char status;
    static int Bill;


//----------------------------------------------------------

    public:
        
        Parking_Lot(char);
        friend void LoginCycle(Parking_Lot &p); //
        bool login(); //
        void getData(); //
        void Check_Car_No();
        void Check_Place_Name();
        void checkUsername();
        void avail_Spaces();
        void choose_Place(); //
        void changeStatus(int i); //
        void Store_in_file();
        void get_Time();
        bool signUp(); //
        void passwordValidity(void);
        void placeCheck(void);  //
        int PressurePads(void); //
        void CalculateArrivalTime(void);
        void delete_record(const char *file_name, int n);  //
        static int i;
        
        

};


//------------------------------------------------------------------------------------------------------------

    
    char Parking_Lot :: status =  'N';        // here we have set the status by default 'N' which means not arrived
    int Parking_Lot::Bill = 100;              // here we have set the bill by default 100rs




// We have created funtion named 'avail_spaces' which will show us how many seats are available in parking lot

    void Parking_Lot::avail_Spaces(void)     
{
        int rowh = 65;                           // we have intiliaze for vertical alphabetic row because ascii value of 65 is 'A'

        cout<<"Following are the available parking spots\n A : Available\n X : Not available"<<endl<<endl<<endl;

        for(int i=0;i<10;i++)                // we have used for loop to show the numbering of rows for ex [1] [2] [3]....
{
            cout<<"\t"<<" ["<<i+1<<"]";       
}
        cout<<endl<<endl;



        for(int i=0;i<10;i++)                               // we have used for loop to show the vertical alphabetic rows  for ex [A],[B],[C] (in vertical)
{
            cout<<"["<<static_cast<char>(rowh)<<"]";        // in this we have used static_cast<char> it will convert int value to its character equivalent of it
            for(int j=0;j<10;j++)
{
            cout<<"\t"<<"| "<<parkSpaces[i][j]<<" |";       // this will show the parkspaces 
}
        cout<<endl;
        cout<<endl;
        rowh++;                                             // here we increment rowh 
}


}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------



// we have created function named getData which will take information : Car plate no ,time.

void Parking_Lot::getData(void){
    cout<<"Hello Mr/Miss "<<Fname<<", please enter your Vehicle registration plate number: "<<endl<<"--> ";
    cin>>car_No;            // we will enter the car no 
    cout<<endl;
    Check_Car_No();         // this line will call the check car no function
    cout<<"Enter the time (in min) till which you want to reserve your parking spot: (Range: 5 min - 30 min)"<<endl<<"--> ";
    cin>>Time;             // we will enter the time
    cout<<endl;
    while(Time<5 || Time>30)    // here we use a condition that time will not be less than 5 minutes or greater that 30 minutes..  
    {
        cout<<"Reservation Time Limit exceeds! \n\nSorry Sir/Madam you cannot reserve a spot for more than 30 min or less than 5 min"<<endl;
        cout<<"Please Re-Enter the time "<<endl<<"--> ";
        cin>>Time;
        cout<<endl;
    }

}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// here we have created a constructor which will initialize all spots as available..


Parking_Lot::Parking_Lot(char avail)
{
    for(int k = 0;k<10;k++)
{
        for(int l=0;l<10;l++)
{
            parkSpaces[k][l] = avail;

}
}

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// we have created a funtion which will help user to choose place 



void Parking_Lot::choose_Place(void)
{
    while(1)
{
        char row;
        int roww;
        int column;
        cout<<"Which spot do you want to reserve?\n"<<endl;
        cout<<"Select Row (A,B,C,D,E,F,G,H,I,J)"<<endl<<"--> ";
        cin>>row;
        roww = (int)((toupper(row))-65);     // here we are converting the row by using int and then subtracting by 65 (ascii value of A) and also we have used toupper 
                                             //to access indices of the parkspace array

        cout<<"Select column(1,2,3,4,5,6,7,8,9,10)"<<endl<<"--> ";
        cin>>column;
        cout<<endl;
        column =column-1;         // we have subtract 1 because in arrays index start from 0
        pName = (char)toupper(row) + int_to_string(column+1);    // This will store the place name like A4 , B5 etc
        Check_Place_Name();           // here we call check_place_name function ....

        if(toupper(row)>64 && toupper(row)<75 && column>=0 && column<10) // This will check that rows are between A to J and column are between 1 to 10 then it will execute
{
            parkSpaces[roww][column] = 'x';       // This will put x as a occupied seat in parkspaces array..
            Row = roww;  // this will globally assign the row value to use in another function
            Col = column;  // this will globally assing the column value to use in another function
            cout<<"Mr/Miss "<<Fname<<" You have successfully reserved "<<(char)toupper(row)<<column+1<<" spot for "<<Time<<" minutes "<<endl;
            cout<<endl;
            break;
}
        else
            cout<<"Spot "<<row<<column+1<<" does not exist!! please choose a valid spot (e.g A1/B3)"<<endl<<"--> ";
}
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// We have created function named store in file which store our name, car no,place name and status in file names 'parkingrecord'..


void Parking_Lot:: Store_in_file(void)
{
    ofstream fout;     //ofstream is used to create files and to write information to files.

    fout.open("parkingrecord.csv",std::ios_base::app);
    


    fout<<Fname<<" "<<Lname<<","<<car_No<<","<<pName<<","<<status<<",";    // here we use fout because we have to output the data in file
    if (hour < 10)                  // here we have apply a check if hours less than 10 then
	    fout << '0';                // it will put 0 before the time for ex using this -> 09:38 and not using this 9:38 and same goes for below statements
	fout << hour << ':';

	if (min < 10)
	    fout << '0';                 
	fout << min << ':';

	if (sec < 10)
	   fout << '0';
	fout << sec;
    fout<<',';
    if (Ahour < 10)
	    fout << '0';
	fout << Ahour << ':';

	if (Amin < 10)
	    fout << '0';
	fout << Amin << ':';

	if (Asec < 10)
	   fout << '0';
	fout << Asec<<","<<Row<<","<<Col<<endl;            // here we also have store the row and column in file 
    fout.close();           // closes file
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------




// we have created funtion named signup it will create account for new user and will take other details 


bool Parking_Lot::signUp(void)
{
    char choi;
    int length;
    cout<<"------------------------------SIMPLE AND QUICK ACCOUNT SIGN UP------------------------------\n"<<endl;
    cout<<"Enter your First Name "<<endl<<"--> ";
    cin>>Fname;
    cout<<"Enter your Last Name"<<endl<<"--> ";
    cin>>Lname;
    cout<<"Enter your Username (E.g: "<<Fname<<Lname<<"213)"<<endl<<"--> ";
    cin>>Username;
    checkUsername();        // this will call checkusername funtion 
    cin.ignore();           //this function is used to ignore or clear one or more characters from the input buffer.
    cout<<"Enter your Password "<<endl<<"--> ";
    getline(cin,password);  // this will take the password
    passwordValidity();     // here we call password validity function to check the password is valid or not
    cout<<"Enter your 16 digits Permanent Account Number (E.g: XXXXXXXXXXXXXXXX)"<<endl<<"--> ";
    getline(cin,ATM_no);    // this will take the atm card no
    for(length=0;ATM_no[length]!='\0';length++);
    while(1)
{
        if(length<16 || length>16)               // here we used a check that atm card number is 16 digits number
{
            cout<<"PAN must be of 16 digits \n Please enter a valid PAN"<<endl<<"--> ";
            getline(cin,ATM_no);
}
        for(int i=0;i<length;i++)
            {
            if(!(isdigit(ATM_no[i])))          // here we used a check that atm card does not contain any special characters
{
                cout<<"PAN cannot contain alphabets or special characters! Please enter a valid PAN"<<endl<<"--> ";
                getline(cin,ATM_no);
}

            }
        break;
}
// here we have store Fname,Lname,Usename,Password accounts.csv


    fstream fout;
    fout.open("accounts.csv",std::ios_base::app);
    fout<<Fname<<","<<Lname<<","<<Username<<","<<password<<endl;
    fout.close();
    cout<<"Congratulation!! You have successfully created Free Parking_Lot Account! Do you want to Login to your Account? y/n"<<endl<<"--> ";
    cin>>choi;
    if(choi=='y' || choi =='Y')
        return 1;
    else
        return 0;

}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// We have created function which will check the that the corresponding car no is already reserved at place or not....



void Parking_Lot :: Check_Car_No(void)
{
string f,l,stat,pn,cN,line;
int h,m,ah,am,as,ro,co;
char take,s;
ifstream fin;
fin.open("parkingrecord.csv");
getline(fin,line);
while(fin>>f)
{   
    
    fin.ignore();
    getline(fin,l,',');
    getline(fin,cN,',');
    getline(fin,pn,',');
    getline(fin,stat,',');
    fin>>h;
    fin.clear();
    fin>>take;
    fin>>m;
    fin.clear();
    fin>>take;
    fin>>s;
    fin.clear();
    fin>>take;
    fin>>ah;
    fin.clear();
    fin>>take;
    fin>>am;
    fin.clear();
    fin>>take;
    fin>>as;
    fin.clear();
    fin>>take;
    fin>>ro;
    fin.clear();
    fin>>take;
    fin>>co;
    fin.clear();
    while(cN==car_No)
    {
        cout<<"INVALID PLATE NUMBER! Vehicle with this Plate Number is already parked or reserved! \nEnter your own Vehicle resgitration plate number:   "<<endl<<"--> ";
        cin>>car_No;
    }
    
   
}
fin.close();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// we have created check place name that the corresponding place in already reserved or not..


void Parking_Lot :: Check_Place_Name(void)
{
    string f,l,stat,pn,cN,line;
int h,m,ah,am,as,ro,co;
char take,s;
ifstream fin;
fin.open("parkingrecord.csv");
getline(fin,line);
while(fin>>f)
{   
    
    fin.ignore();
    getline(fin,l,',');
    getline(fin,cN,',');
    getline(fin,pn,',');
    getline(fin,stat,',');
    fin>>h;
    fin.clear();
    fin>>take;
    fin>>m;
    fin.clear();
    fin>>take;
    fin>>s;
    fin.clear();
    fin>>take;
    fin>>ah;
    fin.clear();
    fin>>take;
    fin>>am;
    fin.clear();
    fin>>take;
    fin>>as;
    fin.clear();
    fin>>take;
    fin>>ro;
    fin.clear();
    fin>>take;
    fin>>co;
    fin.clear();
    
    while(pn==pName)
    {
        cout<<"This spot is already reserved! Please choose another spot!"<<endl;
        choose_Place();
    }
}
fin.close();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// we have created function named login which login the user account and it checks that user account is avaialble or not
bool Parking_Lot::login(void)
{
    cout<<"------------------------------LOGIN TO YOUR ACCOUNT------------------------------\n"<<endl;
    string Usname,Pass;
    cout<<"Enter your Username"<<endl<<"--> ";
    cin>>Username;
    cout<<"Enter your Password"<<endl<<"--> ";
    cin>>password;
    ifstream fin;
    fin.open("accounts.csv");
    while(!fin.eof())
{
        getline(fin,Fname,',');
        getline(fin,Lname,',');
        getline(fin,Usname,',');
        getline(fin,Pass,'\n');
        if(Usname.compare(Username)==0 && Pass.compare(password)==0)
{
            cout<<"\nMr/Miss "<<Fname<<" you have successfully logged in to your account"<<endl;
            fin.close();
            return 1;

}

}
    fin.close();
    return 0;



}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// This function will check that username is already taken or not


void Parking_Lot :: checkUsername(void)
{
    string fname,lname,Usname,Pass;
    ifstream fin;
    fin.open("accounts.csv");
    while(!fin.eof())
{
    getline(fin,fname,',');
    getline(fin,lname,',');
    getline(fin,Usname,',');
    getline(fin,Pass,'\n');
    while(1)
    {
    if(Username.compare(Usname)==0)
{
        cout<<Username<<" is already taken! Please Enter another Username"<<endl<<"--> ";
        cin>>Username;

}
else
break;
}

}
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// this function will check that the password entered by user fullfill the limit or not ...

void Parking_Lot::passwordValidity(void)
{
    while(password.length()<=6)
    {
        cout<<"Your Password must contain more than 6 characters! Please Re-Enter your Password "<<endl<<"--> ";
        getline(cin,password);
    }


}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// This function will get the time from operating system ..
void Parking_Lot :: get_Time(void)
{   time_t t = time(0);
    tm* tmp = localtime(&t);
    hour =  tmp->tm_hour;
    min =  tmp->tm_min;
    sec =  tmp->tm_sec;

}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// this function will calculate the arrival time tby adding min entered by user to actual time(min) of the system
void Parking_Lot::CalculateArrivalTime(void)
{
    if (min+Time>59)
    {
       Ahour = hour+1;
       Amin=(min+Time)-60;
       Asec=0;

    }
    else
    {
    Amin = min+Time;
    Ahour = hour;
    Asec = 0;

    }
    cout<<"Arrival Time--> "<<Ahour<<":"<<Amin<<":0"<<Asec<<"\n"<<endl;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// This function will generate random values between 1 to 10 


int Parking_Lot :: PressurePads(void)
{
srand(time(NULL));
int ran=(rand() % 10)+1;
return ran;

}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// This funtion will check and delete the record
void Parking_Lot :: placeCheck(void)
{
    
string f,l,pn,cN,line;
int h,m,s,ah,am,as,random,hr,mi,se,ro,co;
int i = 1;
char take,stat;
ifstream fin;
fin.open("parkingrecord.csv");
getline(fin,line);
while(fin>>f)
{   
    
    fin.ignore();
    getline(fin,l,',');
    getline(fin,cN,',');
    getline(fin,pn,',');
    fin>>stat;
    fin>>take;
    fin>>h;
    fin.clear();
    fin>>take;
    fin>>m;
    fin.clear();
    fin>>take;
    fin>>s;
    fin.clear();
    fin>>take;
    fin>>ah;
    fin.clear();
    fin>>take;
    fin>>am;
    fin.clear();
    fin>>take;
    fin>>as;
    fin.clear();
    fin>>take;
    fin>>ro;
    fin.clear();
    fin>>take;
    fin>>co;
    fin.clear();
    random = PressurePads();
    random = 4;
    time_t t = time(0);
    tm* tmp = localtime(&t);
    hr =  tmp->tm_hour;
    mi =  tmp->tm_min;
    se =  tmp->tm_sec;
    
    if(hr >= ah && mi >= am && random<=5 && stat == 'N' || stat == 'A')
    {   cout<<"Record deleted: Car No.-->"<<cN<< "\nSpot "<<pn<<" is availabe now"<<endl;
        if(stat == 'N')
        cout<< 15 <<" Rs have been deducted from Mr/Miss "<< f <<" Account"<<endl;
        else if(stat == 'A')
        cout<< Bill <<" Rs have been deducted from Mr/Miss "<< f <<" Account "<<endl;
        parkSpaces[ro][co] = 'A';
        delete_record("parkingrecord.csv", i);
        
    }
    else if(hr >= ah && mi >= am && random>=5 && stat == 'N')
    {   
        changeStatus(i);
    }
    
    

    

  ++i;  

}

fin.close();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void Parking_Lot :: delete_record(const char *file_name, int n)
{
    // open file in read mode or in mode
    ifstream is(file_name);
  
    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("temp.txt", ofstream::out);
  
    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
        line_no++;
  
        // file content not to be deleted
        if (line_no != n)
            ofs << c;
    }
  
    // closing output file
    ofs.close();
  
    // closing input file
    is.close();
  
    // remove the original file
    remove(file_name);
  
    // rename the file
    rename("temp.txt", file_name);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// This funtion will change the status of file 


void Parking_Lot::changeStatus(int i)
{
    string f,l,pn,cN,line;
int h,m,s,ah,am,as,random,hr,mi,se,ro,co;
int line_no = 1;
char take,stat;
ifstream fin;
ofstream fout;
fin.open("parkingrecord.csv");
fout.open("tem.csv");
getline(fin,line);
fout<<line<<endl;
while(fin>>f)
{   fout<<f;
    fout<<' ';
    fin.ignore();
    getline(fin,l,',');
    fout<<l<<',';
    getline(fin,cN,',');
    fout<<cN<<',';
    getline(fin,pn,',');
    fout<<pn<<',';
    fin>>stat;
    if(line_no==i)
        stat = 'A';
    fout<<stat;
    fin>>take;
    fout<<take;
    fin>>h;
    if(h<10)
    fout<<0;
    fout<<h;
    fin.clear();
    fin>>take;
    fout<<take;
    fin>>m;
    if(m<10)
    fout<<0;
    fout<<m;
    fin.clear();
    fin>>take;
    fout<<take;
    fin>>s;
    if(s<10)
    fout<<0;
    fout<<s;
    fin.clear();
    fin>>take;
    fout<<take;
    fin>>ah;
    if(ah<10)
    fout<<0;
    fout<<ah;
    fin.clear();
    fin>>take;
    fout<<take;
    fin>>am;
    if(am<10)
    fout<<0;
    fout<<am;
    fin.clear();
    fin>>take;
    fout<<take;
    fin>>as;
    if(as<10)
    fout<<0;
    fin.clear();
    fout<<as;
    fin>>take;
    fout<<take;
    fin>>ro;
    fout<<ro;
    fin.clear();
    fin>>take;
    fout<<take;
    fin>>co;
    fout<<co;
    fout<<endl;
    line_no++;
}
fin.close();
fout.close();
remove("parkingrecord.csv");
  
    // rename the file
    rename("tem.csv", "parkingrecord.csv");

}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------


// In Main function we have used while loop so the program will run for multiple user


int main()
{ 
    int k;
    bool confirm;
    Parking_Lot p('A');
    while(1){
        cout<<"Welcome to our Parking Lot!\n--------------------------\n\n Press 1 to Log into your account\n Press 2 to Sign Up for a free account "<<endl<<"--> ";
        cin>>k;
        cout<<endl;
        switch(k)
{
            case 1:
{
                LoginCycle(p);
                break;
}
            case 2:
{
                confirm = p.signUp();
                if(confirm==1)
                    LoginCycle(p);
                else
                    break;



}
}
}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// In this funtion we have set the fucntions step by step and also we have put some checks for username or password etc
//used recurison and conditon whenever login fails or is required 

void LoginCycle(Parking_Lot &p)
{
    bool confirm;
    int n;
    char ch;
    confirm = p.login();
    if (confirm==1)
{
        cout<<"\nPress 1 to check the available parking spaces and reserve your desired spot\nPress 2 to quit"<<endl;
        cin>>n;
        cout<<endl;
        switch(n)
{
            case 1:
{

                 p.avail_Spaces();
                cout<<"Please confirm if you want to continue with the reservation?y/n"<<endl<<"--> ";
                cin>>ch;
                if (ch == 'y' || ch== 'Y')
{
                    p.getData();
                    p.get_Time();
                    p.CalculateArrivalTime();
                    p.choose_Place();
                    p.Store_in_file();
                    p.placeCheck();
                    cout<<endl<<endl;
}
                break;
}

            case 2:
{
                break;
}
            default:
{
                cout<<"Option does not exists!"<<endl;
}
}

        cout<<"Thank you for choosing our service! Take care!!\n";
        cout<<endl<<endl<<endl;
}
    else
{
        cout<<"Login failed! Invalid username or password!! Please make sure your account exists\n "<<endl;
        cout<<"Do you want to create a free new account? Press 1 to create a free account\n Press 2 to enter login details again"<<endl<<"--> ";
        cin>>ch;
        if (ch == '1')
{
            confirm = p.signUp();
            if(confirm==1)
                LoginCycle(p);



}
        else
            LoginCycle(p);

}




}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------

// This fucntion will convert integer to string 
string int_to_string(int v) {
    stringstream ss;
    ss << v;
    return ss.str();


}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
