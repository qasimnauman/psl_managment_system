#include <iostream>
#include <unistd.h>
#include <string>
#include<cstdlib>

using namespace std;
void seatsavailable(int,int,int);
void signup(string &name,string &num,string &usrname,string &password);
void price(int num,int &kids,int &audlt,int &family);

int main ()
{
	string matches[3];					//stores match schedule
	int match=0,match1=0,match2=0;  	//stores number of tickets booked of each match
	bool flag2=0;						//bool to make sure first ticket is booked so next time user can view his bookings used at line 159
	int rs[100];						//stores payable amount of total bill
	double sum=0;
	
    cout << "\t PAKISTAN SUPER LEAGUE 2023" <<endl<<endl;
    cout << "You have to sign up First" <<endl;
    
    int check=0;						// variable for forever continutiy of program
    bool flag=0;						//used at line 42 and 47 to make sure user first SIGN UP at the start of Program
    string name,usrnme,password;		//Variables to Store username , name and password for login
    string  num;							//variable stores phone number
    while (check!=1)
    {
        
        string sign;
        cout << "a.Sign in | b. Sign Up | (Press 1 to Exit) "<<endl;

        getline(cin,sign);
        cout <<endl;
        
        
        
        if (sign=="sign up" || sign=="Sign up" || sign =="up" || sign=="signup")
        {
            signup(name,num,usrnme,password);  //function
            
            
            flag+=1;
        system("CLS");    				//clears the console output screen
    	}
    	else if (sign=="sign in" || sign=="Sign in" || sign =="in" || sign=="signin")
    	{
    		if (flag==0)
    		{
    			cout << "NOT YET REGISTERED! Please Sign UP First "<<endl;
    			
    		}
    		else
    		{
    			string in_usrname;
    			cout << "Enter Username: ";
    			getline(cin,in_usrname);
    			string in_password;
    			cout << "Enter Password: ";
    			getline(cin,in_password);
    			cout << endl;
    			system("CLS");
    			if (usrnme==in_usrname && password==in_password)
    			{
    				string flag1="0"; 		// flag1 variable to run the booking and view menu till the user wants used on line 161
    				while(flag1== "0")
    				{
	    				cout << "Welcome to your profile "<<endl
							<<"1. Booking  2.View  3.Clear Record  4.Exit: ";
	    				string menu;
	    				cin >>menu;
	    				
	    				int i=0; 		// will be used on RS arry variable
	    				if(menu=="1")
		    			{
		    				
		    				int pr,vip,eco;
		    				
		    			    cout << "Hi, "<<name<<" WELCOME TO PSL TICKETING PORTAL"<<endl <<endl;
		    			    {	
		    			    	
		    			    	cout << "Date \t\t\t\t\t Match \t\t\t\t\t Venue" <<endl;
		    					matches[0]="1. Thu, 27 Jan \t\t Karachi Kings vs Multan Sultans \t\t National Stadium, Karachi";
		    					matches[1]="2. Fri, 28 Jan \t\t Multan Sultans vs Lahore Qalandars \t\t Gaddafi Stadium, Lahore";
		    					matches[2]="3. Sun, 6 Feb \t\t Karachi Kings vs Islamabad United \t\t Cricket Stadium, Rawalpindi";
		    					cout << matches[0]<<endl <<matches[1]<<endl <<matches[2] <<endl;
		    					
		    						int choice;  		//choice variable to select Particular match
		    						cin >> choice;
		    						while (choice<=0 || choice>3)
		    						{
		    							cout << "ERROR!!! Enter again: ";
		    							cin >> choice;
		    						}
		    						if(choice==1)
		    						{
		    							match+=1;
									}
									else if(choice==2)
		    						{
		    							match1+=1;
									}
									else if(choice==3)
		    						{
		    							match2+=1;
									}
									else 
		    						system("CLS");
		    						seatsavailable(pr,vip,eco); 	//FUNCTION
		    						cout <<"CHOOSE FROM ABOVE: ";
		    						cin >> choice;
		    						while(choice>3 || choice <=0)
		    						{
		    							cout << "Enter again: ";
		    							cin >> choice;
									}
		    						
									int kids,audlt, family;			//VARIABLES to Show PRICES OF EACH Category
									
									price(choice,kids,audlt,family); //function 
									cout <<"Which Category you wanna buy? "<<endl;
									cout <<"CHOOSE FROM ABOVE: ";
									cin >> choice;
									cout <<endl;
									while (choice>3 || choice<=0)
									{
										cout <<"Invalid Choice--ENTER AGAIN: ";
										cin >>choice;
									}
									int count;			// number of Tickets
									cout <<"HOW MANY TICKETS YOU WANT TO BUY? " <<endl
										<<"Note You can avail Discount of 10% if you buy more than 5 of any category"<<endl;
								
									cin >> count;
									cout <<endl;
									
									if (choice==1)
									{
										rs[i]=count*kids;  // num of tickets x Kids Price  and i currently=0
									}
									else if(choice==2)
									{
										rs[i]=audlt*count;
									}
									else
									{
										rs[i]=family*count;
									}
									if (count>5)     // discouny calculation
									{
										rs[i]=rs[i]-((rs[i]/100)*10);
									}
									
									sum+=rs[i];
									
									cout << "BOOKED SUCESSFULLY"<<endl;
									cout <<"Final Payable amount: "<<rs[i] <<endl;
									i++;				//increment in i used in RS Variable
									flag2+=1; 			// reference on line 15
									
									cout << "Press 0 to continue and any key to EXIT: ";
									cin >> flag1;		//reference on line 64
									system("CLS");
						}
    				}
    				
    				
    				else if(menu=="2")
    				{
    					
    					if (flag2>0)
    					{
    						cout << "Your Previous Purchase was of: "<< rs[i] <<endl;
	    					
    						
							cout << "Total amount spent: " <<sum <<endl;
    						cout<< "Tickets of first match " <<" are " <<match<<endl;
							cout<< "Tickets of second match" <<" are " <<match1<<endl;
							cout<< "Tickets of third match " <<" are " <<match2<<endl;
							
						}
						else
						{
							cout << "Currently no purchase has been made" <<endl; 
						}
					}
					
					else if(menu=="3")
					{
						sum=0;
						match=0;
						match1=0;
						match2=0;
						rs[i]=0;
						cout << "Data Cleared Sucessfully"<<endl;
					}
					else if(menu=="4")
					{
						cout << "Exit Sucessfully" <<endl;
						return 0;
					}
					
					
					else
					{
						cout <<"Wrong Input" <<endl;
					}
				}
			}
    			else 
    			{
    			    cout << "Wrong password"<<endl
    			    	<< "Forget passwrod? (yes/no): ";
    			    string forget;
    			    getline(cin,forget);
    			    if(forget=="yes")
    			    {
    			    	cout << "Username is: " <<usrnme <<endl
    			    		<<"Password is: "<<password <<endl;
    			    		sleep(3);
    			    		system("CLS");
    			    }
    			    else
    			    {
    			    	cout <<"Program Finished";
    			    	return 0;
					}
    			    
    			    
    			}
    			
    			
    		}
    	}
    	else if (sign=="1")
    	{
    		return 0;
		}
		else 
		{
			continue;
		}
    	
    }
    return 0;
}


void seatsavailable (int pr, int vip, int eco)
{
	pr=rand()%1000;		//PREMIUM
	vip=rand()%1000;   //VIP
	eco=rand()%1000;  //ECONOMY
	
	cout<<endl <<"SEATS AVAILABILITY" <<endl
		<<"1. PREMIUM: "<<pr <<endl
		<<"2. VIP: "<<vip <<endl
		<<"3. ECONOMY: "<<eco <<endl;
}





void signup(string &name, string &num, string &username, string &password)
{
	cout << "Enter your name: ";
    getline(cin,name);
    cout << "Enter Phone number: ";
    cin >>num;
    cin.ignore();
        
    cout << "Enter Username: ";
    getline(cin,username);
        
    cout << "Enter Password: ";
    getline(cin,password);
}

void price(int num,int &kids,int &audlt,int &family)
{
		
		if(num==1 ||num==2)
		{
			kids=3500;
			audlt=8000;
			family=5000;
		}
	
		if(num==3)
		{
			kids=1500;
			audlt=3000;
			family=2500;
			}
		cout << endl;
		cout <<"1. KIDS: "<<kids <<endl
			<< "2. AUDLTS: "<<audlt <<endl
			<< "3. FAMILY: "<<family <<endl;	
}
