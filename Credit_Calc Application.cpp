#include<iostream> 
#include<conio.h>
#include<string> 
#include<stdlib.h>
#include<windows.h>
using namespace std;  
/* function declaration definition for setting cursor position in the console 
window */ 
void gotoxy(int x ,int y){
	COORD coord;
	coord.X=x; 
	coord.Y=y; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); 
}
 
 //class definition 
 class applicant 
 {
 	//defining data members for storing applicant details 
 	string name; 
 	int age; 
 	string address; 
 	int m_sal; 
 	int h_loan; 
 	int p_loan; 
 	int no_chq_bounce; 
 	char own_house; 
 	char spouce_working; 
 	char dependent_parents; 
 	int company_tier; 
 	
 	public:
 		//class function declaration 
 		void get_data(); 
 		int calc_liability();
 		void display_score();
 }; 
 //function for receiving and storing data loan applicant details
 void applicant::get_data() 
 {
 	system("cls"); 
 	cout<<"Name of Applicant : "; 
 	getline(cin,name); 
 	cout<<"Age: "; 
 	cin>>age; 
 	
 	cin.clear();
 	cin.ignore(1000,'\n'); 
 	
 	cout<<"Address: "; 
 	getline(cin,address); 
 	
 	cin.clear();
 	cin.ignore(1000,'\n');  
 	
 	cout<<"Monthly Salary: "; 
 	cin>>m_sal; 
 	cout<<"Total Home Loan EMI: "; 
 	cin>>h_loan; 
 	cout<<"Total Personal Loan EMI: "; 
 	cin>>p_loan;  
 	cout<<"Number of the Cheques bounces in the last Six Months: "; 
 	cin>>no_chq_bounce; 
 	cout<<"Own House ? (Y or N) : "; 
 	cin>>own_house; 
 	cout<<"Spouce working? (Y or N) : "; 
 	cin>>spouce_working; 
	cout<<"Dependent Parents?(Y or N) : ";  
	cin>>dependent_parents; 
	cout<<"Company Tier ? (1 , 2 or 3 ) : "; 
	cin>>company_tier;
	  }  //end of get data()
	  
	  //function for calculating credit score; 
	int applicant::calc_liability()
	{
	 int score=0; //initializing the score variable for storing credit score 
	 
	 int liability; 
	 
	 if(age>22 && age<=30) 
	  score+=2; 
	  else if(age>30 && age<=35) 
	  score+=1; 
	  else 
	  score-=1; 
	  liability=h_loan+p_loan; 
	  if(liability <=m_sal/4) 
	  score+=5; 
	  if(liability >m_sal/4 && liability <=m_sal/3) 
	  score+=3; 
	  if(liability >m_sal/3 && liability <=m_sal/2)
	  score+=1;  
	  if(liability >m_sal/2)
	  score-=1; 
	  if(no_chq_bounce>1) 
	  score-=2; 
	  if(no_chq_bounce==1) 
	  score-=1; 
	  if(no_chq_bounce==0) 
	  score+=1; 
	  if(p_loan >h_loan) 
	  score+=1; 
	  else 
	  score+=1; 
	  if(own_house=='y'||own_house=='Y') 
	  score+=1; 
	  if(spouce_working=='y'||spouce_working=='Y') 
	  score+=1;  
	  if(dependent_parents=='y'||dependent_parents=='Y') 
	  ;
	  else 
	  score+=1; 
	  if(company_tier==1) 
	  score+=3; 
	  if(company_tier==2) 
	  score+=2;  
	  else 
	  score+=1; 
	  return(score);
	} //end of calc_liability()
	//function for displaying credit score and applicant rating 
	void applicant::display_score()
	{
		int sc=calc_liability(); //calling function for calculating score
		
		system("cls"); 
		
		//Displaying the results 
		if(sc>9)
		cout<<"The applicant "<<name<<" is at low risk. \n Credit score ="<<sc<<"\n Credit can be given."; 
		else {
			if(sc>5 &&sc<=9) 
			cout<<"The applicant "<<name<<" is at average risk. \n Credit score ="<<sc<<"\n Credit can be given with due precaution."; 
	        else 
	        cout<<"The applicant "<<name<<" is at high risk. \n Credit score ="<<sc<<"\n Credit can not be given."; 
	 	} 
	 	getch();
	 } //end of dispaly_score()
  
  //main function 
  int main()
  {
  	char flag='f'; 
  	applicant a; 
  	char ch; 
  	while(1){
  		system("cls"); 
  		gotoxy(31,8);
  		cout<<"Credit Calc"; 
  		gotoxy(31,9); 
  		cout<<"____________________";
  		gotoxy(22,12); 
  		cout<<"1 -Enter loan applicant's details"; 
  		gotoxy(22,13); 
  		cout<<"2 -Display credit Score"; 
  		gotoxy(22,14); 
  		cout<<"3 -Exit"; 
  		gotoxy(22,16); 
  		cout<<"Select an action by typing the numeric code: "; 
  		ch=getch(); 
  		switch(ch){
  			case('1'):
  				{
  					a.get_data(); 
  					flag='t'; 
  					break;
				  } 
			case('2'):
				{
					if(flag=='f'){
						gotoxy(22,18); 
						cout<<"Loan Applicant's details not yet entered ! press any key to continue...."; 
						getch();
					} 
					else 
					a.display_score(); 
					break;
				 } 
			case('3'):
				{
					exit(1); 
					break;
				} 
		    default: { 
		    gotoxy(22,18); 
		    cout<<"Invalid Choice ! press any key to continue...."; 
		    getch();
		    	
			}
		  }
	  } 
	  return 0;
  }
 
 
 	 

 
 
 
 
 
 
 
 
 
 
