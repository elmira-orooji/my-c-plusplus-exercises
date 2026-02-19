#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

void PredictTheGame();
void MakeNewGame();
void ShowResults();
void FirstMenu();
void SecondMenu();
void ThirdMenu();
void DefaultMenu();
void Edite();
void Menu();
void Exit();
fstream MakeNewGameFile("MakeNewGameFile.txt" , ios::in | ios::ate | ios::app);

 char ch;
 string UserGuess[16];
 string change[30];
 string PlayerTeam[16];
 string Group[16] = { 
  "Group A","Group B","Group C","Group D",
  "Group E","Group F","Group G","Group H",
  "Group I","Group J","Group K","Group L",
  "Group M","Group N","Group O","Group P" };
 string Result[16];
 int usedarray = 0 , Number , choice; 
  
  

int main(void)
{
    int exitcode = 10;

	do
	{
		    cout << endl;	
			cout << " 1 - Make New Game\n"; 
			cout << " 2 - Predict The Game\n";
			cout << " 3 - Show Results\n";                      //Menu.
			cout << " 4 - Edit Game\n";
			cout << " 5 - Exit\n";

		cout<< " Enter your choice please : ";
		cin >> choice;
		if(ch == choice){     
		    cout<<"**Error!Please try with a number of menu**";                 //Check if the input is character show error end exit.
			exit(exitcode);
		}
		
		else if (choice >=6){                  //for error if user enter the number greater that 5.
	  	cout<<"It's not valid please try again :"<<endl;
	  	cin>>choice;
	    }
		
		switch (choice)
		{
		case 1:
			MakeNewGame();
			break;
		case 2:
			PredictTheGame();
			break;
		case 3:
			ShowResults();
			break;
		case 4:
			Edite();
			break;
		case 5 :
		    Exit();
		    break;
}
	  } while (choice != 6);  
	  
return 0;
}
	

void MakeNewGame()   //for creating the games.
{
	
	int TeamNumber;
	int totalplay;
		
	do
	{
		cout << "Enter the number of teams : ";
		cin >> TeamNumber;
		
		
		if (!(TeamNumber % 2 == 0) || !(TeamNumber <= 32))  //To avoid entering numbers greater than32 and odd numbers fo teams.
		{
	cout << " It's not a valid choice Enter even Number And Smaller than 32 ,please try again ";

		}
	} while (!(TeamNumber % 2 == 0) || !(TeamNumber <= 32));

	totalplay = TeamNumber / 2;                  //to calculate group of teams. 
	
	fstream MakeNewGameFile("MakeNewGameFile.txt");
    if(MakeNewGameFile.is_open()){                  //Check whether the file is open or not
		
	for (int i = 0; i < totalplay; i++)
	{
		
		cout << " Enter Teams Name: " << endl;
		cin >> PlayerTeam[i];
		MakeNewGameFile<<PlayerTeam[i];              //send player teams to the text file
		
		cout << " Enter Result: " << endl;
		cin >> Result[i];
	    MakeNewGameFile<<Result[i];                 //send real result to the text file
	
	}
}
  
   }
           


void PredictTheGame()      // to get the user predicts.
{

	for (int i = 0; !(PlayerTeam[i].empty()); i++) // show the games have been created in MakeNewGame
	{


		cout << "_________ " + Group[i] + "____________" << endl;
		cout << i + 1 << "- " << PlayerTeam[i] << endl;


	}
	
	cout<<"How many games do you want to predict ?";
	cin>>Number;
	
	while (!PlayerTeam[usedarray].empty())
	{
		usedarray++;

	}
	int select=0;
	for  (int i = 0;i< usedarray; i++)
	{
		
		cout << "select the game : ";
		cin >> select;
		--select;
		if (!UserGuess[select].empty())
		{
			cout << "sorry,you can guess once"<<endl;
				
		
		}
		if (select>= usedarray)
		{
			cout << "enter a valid choise.";

		}
		if(MakeNewGameFile.is_open()){
		cout << "Enter your guess: ";
		cin >> UserGuess[select];
		MakeNewGameFile<<UserGuess[select];              //send User guess to the file.
	}
	}
      
      
}

void ShowResults()   //to show the result of user and admin and give point.
{

	string userstr, resultstr;
	int userteamA = 0;
	int userteamB=0;
	int resultteamA = 0;
	int resultteamB = 0;
	int difference=0, Presence=0 ,s=0,sum=0 ,dw=0,df=0;
		
	for (int i = 0; i < usedarray; i++)
	{


		cout << "__________" + Group[i] + "____________" << endl;
		cout << "           " + PlayerTeam[i] << endl;
		cout << " Real Result " + Result[i] << endl;
		cout << " Your Predict " + UserGuess[i] << endl;

		cout << "\n";
		resultstr = Result[i];
		userstr = UserGuess[i];
		userteamA = (userstr[0] - '0');
		userteamB = (userstr[2] - '0');
		
		resultteamA = (resultstr[0] - '0');
		resultteamB = (resultstr[2] - '0');
		if (resultteamA>resultteamB  && userteamA>=resultteamB && userteamB<userteamA)
		{
			s +=3;
			if((resultteamA-resultteamB) == (userteamA-userteamB) || (resultteamB-resultteamA) == (userteamB-userteamA)){
				difference +=2;
			}
			 dw=s+difference;
		}
        else if( resultteamB>resultteamA && userteamB>=resultteamA && userteamA<userteamB ){
            s +=3;
            		if((resultteamA-resultteamB) == (userteamA-userteamB) || (resultteamB-resultteamA) == (userteamB-userteamA)){
                                difference +=2; 
	          }
	          dw=s+difference;
        }
        
        else if(resultteamB>resultteamA && userteamA > resultteamB ||userteamA < resultteamB )
	   {
            sum +=1;
            if(resultteamB>resultteamA && resultteamB-resultteamA == userteamA-userteamB){
                                difference +=2; 
            }
            df=sum+difference;
       }
       else if(resultteamA>resultteamB && resultteamB<userteamA ||resultteamB>userteamA )
	   {
            sum +=1;
            if((resultteamA-resultteamB) == (userteamA-userteamB) || (resultteamB-resultteamA) == (userteamB-userteamA)){
                                difference +=2; 
            }
            df=sum+difference;
       }
        else
       {
                   s;
                   dw;
                   sum;
                   df;
                   
       }
		if(MakeNewGameFile.is_open()){
		cout << "_________________________________\n";      // to show the result of predict
		cout << "Your Score :"<<endl;
		cout<< "Score for Predict Winner :" << s <<endl;
		MakeNewGameFile<<s<<endl;                           // send Score for Predict Winner to the file
		cout<< "Score for Predict difference of Goals & winner: " << dw <<endl;
		MakeNewGameFile<<dw <<endl;                         //send Score for Predict difference of Goals & winner
		cout<<"Score for Predict False winner & Attending to the poll & difference of goals :" <<df<<endl;
		MakeNewGameFile<<df<<endl;                          //send Score for Predict False winner & Attending to the poll & difference of goals to the file
		cout << "Your Total Score :"<<" "<<"%"<<((s/3)*100)/Number;
		MakeNewGameFile<<"%"<<((s/3)*100)/Number;           //send Total score to the file 
		cout <<"\n";
	}	
}
        MakeNewGameFile.close();                            //to close the file.
}
	
 void Edite(){
		int n;
	  switch(n)
	{
		
		case 1 :
			if(n==1){
			cout<<"This game is open"<<endl;
			}	
			break; 
			
		case 2:
			
			if(n==2){
				cout<<"This game is open"<<endl;
			}
			break;
			
		    case 3 :
		    if(n==3){
		    	cout<<"This game is open"<<endl;
			}	
			break;
		case 4:
		    if(n ==4){
			 cout<<"This game is closed ,please try another game : "<<endl;
		}
		break;
		case 5:
			  if(n==5){
			  cout<<"This game is closed ,please try another game :"<<endl;
			  
			  }
               break;
		case 6:
			  if(n==6)
			  cout<<"This game is open"<<endl;
	         break;
	    case 7: 
		    if(n==7)
		    cout<<"This game is open"<<endl;
	         break;
	    
		case 8: 
		      if(n==9)
		    cout<<"This game is open"<<endl;
	         break;
		case 9:
		      if(n==9)
		    cout<<"This game is open"<<endl;
	         break;	 
		case 10:
			  if(n==10)
		    cout<<"This game is open"<<endl;
	         break;
	         
	    case 11:
		     if(n==11)
		    cout<<"This game is open"<<endl;
	         break;
	         
	    case 12:
		     if(n==12)
		    cout<<"This game is open"<<endl;
	         break;
	         
	    case 13:
		     if(n==13)
		    cout<<"This game is open"<<endl;
	         break;
	         
	    case 14:
		     if(n==14)
		    cout<<"This game is open"<<endl;
	         break;
	         
	    case 15:
		     if(n==15)
		    cout<<"This game is open"<<endl;
	         break;
	    case 16:
		     if(n==16)
		    cout<<"This game is open"<<endl;
	         break;
}


}

void Menu(){	   

       switch(choice){
	   	
	   	     case 1:
	   	     	  cout<<"**You can't enter to this section**";
				  break;
	   	     	     
	   	     case 2:
				  PredictTheGame();
				  break;
			 case 3:
			      cout<<"**You can't enter to this section**"; 
				  break;
			case 4:
			      Edite();
				  break;
			case 5:
			     Exit();
				 break;	  	  
				       
	   }
}

void SecondMenu(){
	
	   switch(choice){
	   	
	   	     case 1:
	   	     	  cout<<"You can't enter to this section twice.";
	   	     	     break;
	   	     case 2:
				  PredictTheGame();
				  break;
				  
			 case 3:
			      cout<<"**You can't enter to this section**"; 
				  break;
			 case 4:
			      cout<<"**You can't enter to this section**";
				  break;
			 case 5:
			     Exit();
				 break;	  	        
	   }
 }
void ThirdMenu(){      //to allow user just enter to the show result.

            cout << endl;	
			cout << " 1 - Make New Game\n"; 
			cout << " 2 - Predict The Game\n";
			cout << " 3 - Show Results\n";                      //Menu.
			cout << " 4 - Edit Game\n";
			cout << " 5 - Exit\n";

		cout<< " Enter your choice please : ";
		cin >> choice;

	   switch(choice){
	   
   	        case 1: if(choice==1)
	   	     	   cout<<"**You can't enter to this section .**";
	   	     	   break;
	   	    case 2: if(choice==2)
				  cout<<"**You can't enter to this section**";
				  break;
				  
			case 3: if(choice==3)
			      ShowResults(); 
				  break;
			case 4: if(choice==4)
			      Edite();
				  break;
			case 5:if (choice==5)
			     Exit();
				 break;	  	        
	   }
}

void FirstMenu()                   //to allow user just enter to the Make new game section.
{   
         cout << endl;	
			cout << " 1 - Make New Game\n"; 
			cout << " 2 - Predict The Game\n";
			cout << " 3 - Show Results\n";                      //Menu.
			cout << " 4 - Edit Game\n";
			cout << " 5 - Exit\n";
			
            switch(choice){
	   	
	   	    case 1: if(choice==1)
	   	            MakeNewGame();
	   	     	    break; 
	   	    case 2: if(choice==2)
				  cout<<"**You can't enter to this section**";
				  break;
				  
			case 3: if(choice==3)
			      cout<<"**You can't enter to this section**";
				  break;
			case 4:if(choice==4)
			      Edite();
			      break;
				  
			case 5: if(choice==5)
			     Exit();
				 break;	  
			}
		}
		


void DefaultMenu(){                                    //to show menu.

	cout << endl;	
			cout << " 1 - Make New Game\n"; 
			cout << " 2 - Predict The Game\n";
			cout << " 3 - Show Results\n";
			cout << " 4 - Edit Game\n";
			cout << " 5 - Exit\n";

		cout<< " Enter your choice please : ";
		cin >> choice;
}
void Exit(){                     //for exit of the program.
	
        exit(6);
}

	

	
	

	
	
    