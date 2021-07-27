#include <bits/stdc++.h>
using namespace std;

#define nl      "\n"

bool ok = true, isfail = false;

void CGPA(double t_c, double t_p, bool isfail)
{
    if(isfail)
    {
        cout << "Sorry, you did not pass all exams. No CGPA!" << nl;
        cout << "\n----- Bye Bye -----" << nl;
        return;
    }

    double cgpa = t_p/t_c;

    // Minimum cgpa needed to pass
    if(cgpa >= 2.20)
    {
        cout << "Congratulations! You passed. ";
        cout << "Your CGPA is: " << cgpa << nl;
    }
    else
    {
        cout << "Sorry, You failed!" << nl;
    }

    cout << "\nTry again? (y/n) ";
    char c;
    cin>>c;
    if(c == 'y' or c == 'Y')
    {
        cout << "\nEnter Examination Type: " << nl;
        cout << "1. Semester" << nl;
        cout << "2. Yearly" << nl;
    }
    else
    {
        cout << "\n----- Bye Bye -----" << nl;
        ok = false;
    }
}

int main()
{
    cout << fixed << setprecision(2) << nl;
    cout << "\tWelcome to CGPA Calculator!" << nl;
    cout << "  -----------------------------------\n" << nl;
    cout << "Enter Examination Type: " << nl;
    cout << "1. Semester" << nl;
    cout << "2. Yearly" << nl;

    while(true)
    {

        char exam;
        cin >> exam;
        if(exam == '1')
        {
            double t_c=0, t_p=0;
            int sem, crs;
            cout << "How many semesters? ";
            cin>>sem;
            for(int i=1; i<=sem; i++)
            {
                cout << "How many courses for semester " << i << "? ";
                cin>>crs;
                double credits = 0, c;
                double point = 0, g, gpa = 0;
                cout << "\nEnter credits and GP per course: \n";
                cout << "\nCourse no. Credit GP" << nl;

                for(int i=1; i<=crs; i++)
                {
                    cout << "\t" << i <<"\t";
                    cin>>c>>g;
                    credits += c;
                    point += (c*g);
                }
                gpa = point/credits;

                // Minimum gpa needed to pass
                if(gpa < 2.2)
                {
                    cout << "Sorry, You failed. You need minimum 2.20" << nl;
                    cout << "You got: " << gpa << nl;
                    isfail = true;
                }
                else
                    cout << "\nSemester " << i << ", your GPA is: " << gpa << "\n" <<nl;

                // Count total credits and points
                t_c += credits;
                t_p += point;

                // If all semesters result checked
                if(i == sem)
                {
                    CGPA(t_c, t_p, isfail);
                }
            }
        }
        else if(exam == '2')
        {
            double t_c=0, t_p=0;
            int yr, crs;

            cout << "How many years? ";
            cin>>yr;
            for(int i=1; i<=yr; i++)
            {
                cout << "How many courses for year " << i << "? ";
                cin>>crs;
                double credits = 0, c;
                double point = 0, g, gpa = 0;
                cout << "\nEnter credits and GP per course: \n";
                cout << "\nCourse no. Credit GP" << nl;

                for(int i=1; i<=crs; i++)
                {
                    cout << "\t" << i <<"\t";
                    cin>>c>>g;
                    credits += c;
                    point += (c*g);
                }
                gpa = point/credits;

                // Minimum gpa needed to pass
                if(gpa < 2.2)
                {
                    cout << "Sorry, You failed. You need minimum 2.20" << nl;
                    cout << "You got: " << gpa << nl;
                    isfail = true;
                }
                else
                    cout << "\Year " << i << ", your GPA is: " << gpa << "\n" <<nl;

                // Count total credits and points
                t_c += credits;
                t_p += point;

                // If all years result checked
                if(i == yr)
                {
                    CGPA(t_c, t_p, isfail);
                }
            }

        }
        else
        {

            cout << "Wrong input! Try again? (y/n)" << nl;
            char c;
            cin>>c;
            if(c == 'y' or c == 'Y')
            {
                cout << "Enter Examination Type: " << nl;
                cout << "1. Semester" << nl;
                cout << "2. Yearly" << nl;
            }
            else
            {
                cout << "Canceled!" << nl;
                ok = false;
                break;
            }
        }
        if(!ok or isfail) break;
    }

    return 0;
}
