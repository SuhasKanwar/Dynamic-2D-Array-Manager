#include<iostream>
#include<cstring>
using namespace std;
class Student_Database
{
    public:
    string data[10000][5]; //main 2d array in which all the data is bieng stored
    int index=1,i,j,sno,run=0;
    bool found2=false;
    int choice2,row_index,column_index,addrs;
    string rec;
    string data_for_filter;
    void Data_Input()
    {
        data[0][1] = "Admsn"; //pre declared column names as they are fixed along the code
        data[0][2] = "Name";
        data[0][3] = "Age";
        data[0][4] = "Marks";
        data[0][0] = " ";
        for (sno=1;sno<=run;sno++)
        {
            data[sno][0]=sno;
        }
        cout<<"Enter admission number: ";
        cin>>data[index][1];
        cout<<"Enter Name:  ";
        cin>>data[index][2];
        cout<<"Enter Age:  ";
        cin>>data[index][3];
        cout<<"Enter Marks:  ";
        cin>>data[index][4];
        index=index+1;
    }
    void Data_Output()
    {
        for(i=0;i<run;i++)
        {
            for(j=0;j<5;j++)
            {
                cout<<data[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void search() //function to search a record in the database
    {
        int row;
        bool found = false;
        cout<<"Enter the addmission number of the student you want to search: ";
        cin>>rec;
        for (i=1;i<=run;i++)
        {
            if (data[i][1] == rec)
            {
                found = true;
                if (found)
                {
                    row=i;
                }
            }
        }
        if (found)
        {
            cout<<"\tAdmsn\tName\tAge\tMarks"<<endl;
            cout<<data[row][0]<<"\t"<<data[row][1]<<"\t"<<data[row][2]<<"\t"<<data[row][3]<<"\t"<<data[row][4]<<endl;
        }
        else
        {
            cout<<"Data not found in the database."<<endl;
        }
    }
    void edit() //function to edit stored value in the database
    {
        string new_data;
        cout<<"Enter the addmision number whose data you want to change: ";
        cin>>rec;
        for (i=1;i<=run;i++)
        {
            if (data[i][1] == rec)
            {
                found2 = true;
                if (found2)
                {
                    row_index=i;
                }
            }
        }
        cout<<"Enter the data you want to change-\n1 = Name\n2 = Age\n3 = Marks"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice2;
        if (choice2 == 1)
        {
            column_index=2;
            cout<<"Enter the name you want to enter: ";
            cin>>new_data;
            data[row_index][column_index]=new_data;
            cout<<"Data modified successfully."<<endl;
        }
        else if (choice2 == 2)
        {
            column_index=3;
            cout<<"Enter the age you want to enter: ";
            cin>>new_data;
            data[row_index][column_index]=new_data;
            cout<<"Data modified successfully."<<endl;
        }
        else if (choice2 == 3) 
        {
            column_index=4;
            cout<<"Enter the marks you want to enter: ";
            cin>>new_data;
            data[row_index][column_index]=new_data;
            cout<<"Data modified successfully."<<endl;
        }
        else
        {
            cout<<"Enter 1,2 or 3."<<endl;
        }
    }
    void filter_name(int column) //comparison filter with only equal to operator for only data stored in the name column
    {
        bool found3=false;
        cout<<"Enter the value you want to filter: ";
        cin>>data_for_filter;
        cout<<"\tAdmsn\tName\tAge\tMarks"<<endl;
        for (i=1;i<=run;i++)
        {
            if (data[i][column]==data_for_filter)
            {
                found3=true;
                if (found3)
                {
                    cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<"\t"<<data[i][3]<<"\t"<<data[i][4]<<endl;
                }
            }
        }
    }
    void filter_comparison(int column) //comparison filter with all the comparison operators for the comparion in the marks and age column
    {
        string op;
        string range;
        bool found4=false;
        cout<<"Enter the operator (>,<,=,>=,<=): ";
        cin>>op;
        cout<<"Enter the start of range: ";
        cin>>range;
        if (op == ">")
        {
            cout<<"\tAdmsn\tName\tAge\tMarks"<<endl;
            for (i=1;i<=run;i++)
            {
                if (data[i][column]>range)
                {
                    found4=true;
                    if (found4)
                    {
                        cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<"\t"<<data[i][3]<<"\t"<<data[i][4]<<endl;
                    }
                }
            }
        }
        else if (op == "<")
        {
            cout<<"\tAdmsn\tName\tAge\tMarks"<<endl;
            for (i=1;i<=run;i++)
            {
                if (data[i][column]<range)
                {
                    found4=true;
                    if (found4)
                    {
                        cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<"\t"<<data[i][3]<<"\t"<<data[i][4]<<endl;
                    }
                }
            }
        }
        else if (op == "=")
        {
            cout<<"\tAdmsn\tName\tAge\tMarks"<<endl;
            for (i=1;i<=run;i++)
            {
                if (data[i][column]==range)
                {
                    found4=true;
                    if (found4)
                    {
                        cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<"\t"<<data[i][3]<<"\t"<<data[i][4]<<endl;
                    }
                }
            }
        }
        else if (op == ">=")
        {
            cout<<"\tAdmsn\tName\tAge\tMarks"<<endl;
            for (i=1;i<=run;i++)
            {
                if (data[i][column]>=range)
                {
                    found4=true;
                    if (found4)
                    {
                        cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<"\t"<<data[i][3]<<"\t"<<data[i][4]<<endl;
                    }
                }
            }
        }
        else if (op == "<=")
        {
            cout<<"\tAdmsn\tName\tAge\tMarks"<<endl;
            for (i=1;i<=run;i++)
            {
                if (data[i][column]<=range)
                {
                    found4=true;
                    if (found4)
                    {
                        cout<<data[i][0]<<"\t"<<data[i][1]<<"\t"<<data[i][2]<<"\t"<<data[i][3]<<"\t"<<data[i][4]<<endl;
                    }
                }
            }
        }
        else
        {
            cout<<"Enter >,<,=,>= or <="<<endl;
        }
    }
    void filter()
    {
        int option;
        cout<<"1 = Name\n2 = Age\n3 = Marks"<<endl;
        cout<<"Enter the type of data you want to filter: ";
        cin>>option;
        if (option == 1)
        {
            filter_name(2);
        }
        else if (option == 2)
        {
            filter_comparison(3);
        }
        else if (option == 3)
        {
            filter_comparison(4);
        }
        else
        {
            cout<<"Enter 1,2 or 3."<<endl;
        }
    }
};
int main()
{
    int choice;
    Student_Database record;
    do
    {
        record.run=record.run+1;
        cout<<"1 = Enter a student data\n2 = Show student database\n3 = Search a student data\n4 = Edit existing data\n5 = Filter existing data\n6 = Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        if(choice == 1)
        {
            record.Data_Input();
        }
        else if(choice == 2)
        {
            record.Data_Output();
        }
        else if(choice == 3)
        {
            record.search();
        }
        else if(choice == 4)
        {
            record.edit();
        }
        else if(choice == 5)
        {
            record.filter();
        }
        else if(choice == 6)
        {
            cout<<"Thanks for using the database."<<endl;
        }
        else 
        {
            cout<<"Enter 1,2,3,4,5 or 6."<<endl;
        }
    }
    while(choice!=6);
    return 0;
}