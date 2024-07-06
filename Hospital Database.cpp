/*
CODED BY :
  █████╗    ██████╗     █████╗
 ██╔══██╗  ██╔═══██╗   ██╔══██╗
 ╚█████╔╝  ██║   ██║   ╚█████╔╝
 ██╔══██╗  ██║   ██║   ██╔══██╗
 ╚█████╔╝  ╚██████╔╝   ╚█████╔╝
  ╚════╝    ╚═════╝     ╚════╝
*/

#include <iostream>
#include <deque>
#include <map>
#include <windows.h>
using namespace std;

#define GoodThings ios_base::sync_with_stdio(0);
#define Are cin.tie(0);
#define Coming cout.tie(0);

/*

                                                  Surah Al-Mu'minun Verses [ 84 -> 89 ]

                        Say, [O Muhammad], "To whom belongs the earth and whoever is in it, if you should know?" (84)
                        They will say, "Allah's". Ask them, "Then why do you not understand this"? (85)
                        Say, "Who is Lord of the seven heavens and Lord of the Great Throne?" (86)
                        They will say, "[They belong] to Allah." Say, "Then will you not fear Him?" (87)
                        Say, "In whose hand is the realm of all things - and He protects while
                        none can protect against Him - if you should know?" (88)
                        They will say, "[All belongs] to Allah." Say, "Then how are you deluded?" (89)

*/


struct Patients_Data
{
    int specialization;     // 1-20
    string name;            // name
    int status;             // 1-0

    void Read_Patients_Data()
    {
        cin >> specialization >> name >> status;
    }
};

void more()
{
    cout << "\n\n Would you like to do something else ?\n\n";
}


void menu()
{
    cout << "\nOption Menu :\n";
    cout << "========================\n";
    cout << "1) Add new patient    ||\n";
    cout << "2) Print all patients ||\n";
    cout << "3) Get next patient   ||\n";
    cout << "4) Exit               ||\n";
    cout << "========================\n\n";
    cout << "Choice :";
}

int main()
{
    // GoodThings Are Coming

    cout << "Welcome to an 808 Software [ Hospital System ] <3 \n\n";

    map<int, deque<Patients_Data>> patients_queue;

    while (true)
    {
        menu();
        int choice; cin >> choice;

        if (choice == 4)
        {
            cout << "Thanks for using an 808 Software <3\n\n";
            cout << "Rate the work <3 :";
            double rate;
            cin >> rate;
            cout << "Rate : " << rate << "\\10";
            cout << "\nThanks alot\nYou can go now !";
            Sleep(100000000);

        }

        if (choice == 1)
        {
            cout << "\nEnter specialization, name, status: ";
            Patients_Data patient;
            patient.Read_Patients_Data();
            if (patients_queue[patient.specialization].size() >= 5)
            {
                cout << "\n\nNo more patients can be added to this specialization\n\n";
            }
            else
            {
                if (patient.status == 0)
                {
                    patients_queue[patient.specialization].push_back(patient);
                }
                else
                {
                    patients_queue[patient.specialization].push_front(patient);
                }
            }

            more();
        }
        else if (choice == 2)
        {
            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "-"; Sleep(1);}

            if (patients_queue.empty())
            {
                cout << "\nNo patients at all\n";
            }
            else
            {
                bool anyPatients = false;
                for (const auto& entry : patients_queue)
                {
                    int specialization = entry.first;
                    const auto& queue = entry.second;

                    if (!queue.empty())
                    {
                        anyPatients = true;
                        cout << "\nSpecialization " << specialization << ":\n";

                        for (const auto& patient : queue)
                        {
                            cout << patient.name << " (" << (patient.status ? "urgent" : "regular") << ")\n";
                        }
                    }
                }
                if (!anyPatients)
                {
                    cout << "\nNo patients at all\n";
                }
            }

            for (int i = 0; i < 45; i++) {cout << "-"; Sleep(1);}
            cout << endl;
            more();
        }
        else if (choice == 3)
        {
            int specialization;
            cout << "Enter specialization to get the next patient: ";
            cin >> specialization;

            cout << endl;
            for (int i = 0; i < 45; i++) {cout << "-"; Sleep(1);}

            if (patients_queue[specialization].empty())
            {
                cout << "\nNo patients in specialization " << specialization << "\n";
            }
            else
            {
                auto& queue = patients_queue[specialization];
                cout << endl << queue.front().name << " please go with the doctor\n";
                queue.pop_front();

                if (queue.empty())
                {
                    patients_queue.erase(specialization);
                }
            }
            for (int i = 0; i < 45; i++) {cout << "-"; Sleep(1);}
            cout << endl;
            more();
        }
    }
}
